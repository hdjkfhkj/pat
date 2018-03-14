#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#include <pthread.h>
//#include "kd_tree.h"

#define SQ(x)           ((x) * (x))
//超平面结构体，
struct kdhyperrect {
    int dim;//超平面的维数
    double *min, *max;    //每一维对应的最大最小坐标，一共有dim维，即min和max向量长度为dim          /* minimum/maximum coords */
};
//kd树的一个结点，
struct kdnode {
    double *pos;//坐标
    int dir;//split，方向轴序号，
    void *data;//每个结点存放的数据

    struct kdnode *left, *right;    /* negative/positive side */
};
//结果集结点，用一个单链表存放所得结果
struct res_node {
    struct kdnode *item;//树的结点
    double dist_sq;//与要查询点的距离
    struct res_node *next;
};
//kdtree树结点，所有的东西都在这里面
struct kdtree {
    int dim;//维数
    struct kdnode *root;//kdnode的根节点
    struct kdhyperrect *rect;//超平面
    void (*destr)(void*);
};
//kdtree返回结果
struct kdres {
    struct kdtree *tree;
    struct res_node *rlist, *riter;
    int size;
};
/* create a kd-tree for "k"-dimensional data */
struct kdtree *kd_create(int k);

/* free the struct kdtree */
void kd_free(struct kdtree *tree);

/* remove all the elements from the tree */
void kd_clear(struct kdtree *tree);

/* if called with non-null 2nd argument, the function provided
 * will be called on data pointers (see kd_insert) when nodes
 * are to be removed from the tree.
 */
void kd_data_destructor(struct kdtree *tree, void (*destr)(void*));

/* insert a node, specifying its position, and optional data */
int kd_insert(struct kdtree *tree, const double *pos, void *data);

/* Find the nearest node from a given point.
 *
 * This function returns a pointer to a result set with at most one element.
 */
struct kdres *kd_nearest(struct kdtree *tree, const double *pos);

/* Find the N nearest nodes from a given point.
 *
 * This function returns a pointer to a result set, with at most N elements,
 * which can be manipulated with the kd_res_* functions.
 * The returned pointer can be null as an indication of an error. Otherwise
 * a valid result set is always returned which may contain 0 or more elements.
 * The result set must be deallocated with kd_res_free after use.
 */
/*
struct kdres *kd_nearest_n(struct kdtree *tree, const double *pos, int num);
struct kdres *kd_nearest_nf(struct kdtree *tree, const float *pos, int num);
struct kdres *kd_nearest_n3(struct kdtree *tree, double x, double y, double z);
struct kdres *kd_nearest_n3f(struct kdtree *tree, float x, float y, float z);
*/

/* Find any nearest nodes from a given point within a range.
 *
 * This function returns a pointer to a result set, which can be manipulated
 * by the kd_res_* functions.
 * The returned pointer can be null as an indication of an error. Otherwise
 * a valid result set is always returned which may contain 0 or more elements.
 * The result set must be deallocated with kd_res_free after use.
 */
struct kdres *kd_nearest_range(struct kdtree *tree, const double *pos, double range);

/* frees a result set returned by kd_nearest_range() */
void kd_res_free(struct kdres *set);

/* returns the size of the result set (in elements) */
int kd_res_size(struct kdres *set);

/* rewinds the result set iterator */
void kd_res_rewind(struct kdres *set);

/* returns non-zero if the set iterator reached the end after the last element */
int kd_res_end(struct kdres *set);

/* advances the result set iterator, returns non-zero on success, zero if
 * there are no more elements in the result set.
 */
int kd_res_next(struct kdres *set);

/* returns the data pointer (can be null) of the current result set item
 * and optionally sets its position to the pointers(s) if not null.
 */
void *kd_res_item(struct kdres *set, double *pos);

/* equivalent to kd_res_item(set, 0) */
void *kd_res_item_data(struct kdres *set);
static void clear_rec(struct kdnode *node, void (*destr)(void*));
static int insert_rec(struct kdnode **node, const double *pos, void *data, int dir, int dim);
static int rlist_insert(struct res_node *list, struct kdnode *item, double dist_sq);
static void clear_results(struct kdres *set);

static struct kdhyperrect* hyperrect_create(int dim, const double *min, const double *max);
static void hyperrect_free(struct kdhyperrect *rect);
static struct kdhyperrect* hyperrect_duplicate(const struct kdhyperrect *rect);
static void hyperrect_extend(struct kdhyperrect *rect, const double *pos);
static double hyperrect_dist_sq(struct kdhyperrect *rect, const double *pos);
//创建kd_tree
struct kdtree *kd_create(int k)
{
    struct kdtree *tree;//声明一个kdtree tree

    if(!(tree = new kdtree)) {//分配内存不成功
        return 0;
    }

    tree->dim = k;
    tree->root = 0;
    tree->destr = 0;
    tree->rect = 0;

    return tree;
}
//释放kd_tree
void kd_free(struct kdtree *tree)
{
    if(tree) {
        kd_clear(tree);
        delete tree;
    }
}
//释放超平面，每一个kdnode结点是一个超平面。
static void clear_rec(struct kdnode *node, void (*destr)(void*))
{
    if(!node) return;

    clear_rec(node->left, destr);
    clear_rec(node->right, destr);

    if(destr)
    {//当destr函数不为NULL时，用来释放超平面里的数据，
        destr(node->data);
    }
    delete[] node->pos;
    delete node;
}
//清除kd_tree
void kd_clear(struct kdtree *tree)
{
    clear_rec(tree->root, tree->destr);//从tree的根节点开始清除kdnode结点
    tree->root = 0;

    if (tree->rect) {
        hyperrect_free(tree->rect);//清除kd_tree结构里的超平面rect结构
        tree->rect = 0;
    }
}
//data析构
void kd_data_destructor(struct kdtree *tree, void (*destr)(void*))
{
    tree->destr = destr;
}

//插入一个超平面，即一个kdnode结点。
static int insert_rec(struct kdnode **nptr, const double *pos, void *data, int dir, int dim)
{
    int new_dir;
    struct kdnode *node;

    if(!*nptr) {//如果节点为空，即走到了叶子节点,创建结点，并在结点放入要插入的数据
        if(!(node = new kdnode)) {
            return -1;
        }
        if(!(node->pos = new double[dim])) {
            delete[] node;
            return -1;
        }
        //下面把数据放入结点中
        memcpy(node->pos, pos, dim * sizeof *node->pos);
        node->data = data;
        node->dir = dir;
        node->left = node->right = 0;
        *nptr = node;
        return 0;
    }
    //如果结点不为空，
    node = *nptr;
    new_dir = (node->dir + 1) % dim;//新的分离split方向+1，比如三维，则是x，y，z，x....此处不是根据方差来判断的，因此树一般不平衡

    if(pos[node->dir] < node->pos[node->dir]) {//如果在这个方向上的坐标小于已有结点，向左插入
        return insert_rec(&(*nptr)->left, pos, data, new_dir, dim);
    }
    return insert_rec(&(*nptr)->right, pos, data, new_dir, dim);
}
//插入结点时，更新kdtree结构体，首先要更新kdtree结构里的root内容，然后 是超平面范围会改变，需要更新。
int kd_insert(struct kdtree *tree, const double *pos, void *data)
{
    if (insert_rec(&tree->root, pos, data, 0, tree->dim)) {//每次更新超平面范围
        return -1;
    }

    if (tree->rect == 0) {//如果是第一次在空树里插入，rect为0 ，创建rect结构
        tree->rect = hyperrect_create(tree->dim, pos, pos);
    } else {//否则，更新即扩展超平面范围
        hyperrect_extend(tree->rect, pos);
    }

    return 0;
}
//找到最近邻接点
//输入：树结点指针，查找坐标，阈值，bool型排序，维数
//输出：结果集list，加入结果集的个数。
static int find_nearest(struct kdnode *node, const double *pos, double range, struct res_node *list, int ordered, int dim)
{
    double dist_sq, dx;
    int i, ret, added_res = 0;//added_res代表增加的个数

    if(!node) return 0;//

    dist_sq = 0;
    for(i=0; i<dim; i++) {
        dist_sq += SQ(node->pos[i] - pos[i]);//算出正在查询的kdnode结点与pos坐标之间距离的平方
    }
    if(dist_sq <= SQ(range)) {//在范围内，就加入结果集
        if(rlist_insert(list, node, ordered ? dist_sq : -1.0) == -1) {
            return -1;
        }
        added_res = 1;//
    }

    dx = pos[node->dir] - node->pos[node->dir];
    //这里不明白，为什么求最短距离不是用半径来判断是否查询另一边，而是通过阈值来判断。
    ret = find_nearest(dx <= 0.0 ? node->left : node->right, pos, range, list, ordered, dim);//递归寻找
    if(ret >= 0 && fabs(dx) < range) {//如果在其中一边找到了最近的坐标，且dx在阈值内，则在另一边继续找。
        added_res += ret;//查找到的结果增加ret个


        //这里不明白，为什么求最短距离不是用半径来判断是否查询另一边，而是通过阈值来判断。有人知道求告知。
        //而且这里不是求最近邻吗，为什么把满足阈值的都放进结果集了。
 //原来这里的最近邻就是指满足阈值的点。。。
        ret = find_nearest(dx <= 0.0 ? node->right : node->left, pos, range, list, ordered, dim);
    }
    if(ret == -1) {
        return -1;
    }
    added_res += ret;

    return added_res;//加入结果集的个数
}
//找到最近邻的n个结点，此处结果加入堆中，num代表n
//此处用堆维护n个结点

static int find_nearest_n(struct kdnode *node, const double *pos, double range, int num, struct rheap *heap, int dim)
{
    double dist_sq, dx;
    int i, ret, added_res = 0;

    if(!node) return 0;

    /* if the photon is close enough, add it to the result heap */
    dist_sq = 0;
    for(i=0; i<dim; i++) {
        dist_sq += SQ(node->pos[i] - pos[i]);
    }
    if(dist_sq <= SQ(range)/*range_sq*/) {
        if(heap->size >= num) {//如果堆的数目已经达到n个，即num个
            /* get furthest element */
            struct res_node *maxelem = rheap_get_max(heap);//求出堆中最大的那个元素

            /* and check if the new one is closer than that */
            if(maxelem->dist_sq > dist_sq) {
                rheap_remove_max(heap);//如果堆中最大的那个元素比正在比较的数大，移除那个最大值
                //并将正在比较的结点加入堆中
                if(rheap_insert(heap, node, dist_sq) == -1) {
                    return -1;
                }
                added_res = 1;

                range_sq = dist_sq;

            }
        } else {//没达到n个值，直接插入
            if(rheap_insert(heap, node, dist_sq) == -1) {
                return =1;
            }
            added_res = 1;
        }
    }


    /* find signed distance from the splitting plane */
    dx = pos[node->dir] - node->pos[node->dir];
    //这里和find_nearest函数一样
    ret = find_nearest_n(dx <= 0.0 ? node->left : node->right, pos, range, num, heap, dim);
    if(ret >= 0 && fabs(dx) < range) {
        added_res += ret;
        ret = find_nearest_n(dx <= 0.0 ? node->right : node->left, pos, range, num, heap, dim);
    }

}

//查找最近邻的结点,先找近子树，然后计算本身，然后计算远子树。
static void kd_nearest_i(struct kdnode *node, const double *pos, struct kdnode **result, double *result_dist_sq, struct kdhyperrect* rect)
{
    int dir = node->dir;
    int i;
    double dummy, dist_sq;
    struct kdnode *nearer_subtree, *farther_subtree;
    double *nearer_hyperrect_coord, *farther_hyperrect_coord;

    /* Decide whether to go left or right in the tree */
    dummy = pos[dir] - node->pos[dir];
    if (dummy <= 0) {//如果小于等于0，左子树更近
        nearer_subtree = node->left;
        farther_subtree = node->right;
        nearer_hyperrect_coord = rect->max + dir;//&rect->max[dir]
        farther_hyperrect_coord = rect->min + dir;
    } else {
        nearer_subtree = node->right;
        farther_subtree = node->left;
        nearer_hyperrect_coord = rect->min + dir;
        farther_hyperrect_coord = rect->max + dir;
    }

    if (nearer_subtree) {//如果近子树没有到叶子结点，继续递归，深度优先查询。
        /* Slice the hyperrect to get the hyperrect of the nearer subtree */
        dummy = *nearer_hyperrect_coord;
        *nearer_hyperrect_coord = node->pos[dir];
        /* Recurse down into nearer subtree */
        kd_nearest_i(nearer_subtree, pos, result, result_dist_sq, rect);
        /* Undo the slice */
        *nearer_hyperrect_coord = dummy;
    }

    /* Check the distance of the point at the current node, compare it
     * with our best so far */
    dist_sq = 0;//计算本结点与原最近结点的大小关系
    for(i=0; i < rect->dim; i++) {
        dist_sq += SQ(node->pos[i] - pos[i]);
    }
    if (dist_sq < *result_dist_sq) {
        *result = node;
        *result_dist_sq = dist_sq;
    }

    if (farther_subtree) {//递归遍历远子树。
        /* Get the hyperrect of the farther subtree */
        dummy = *farther_hyperrect_coord;
        *farther_hyperrect_coord = node->pos[dir];
        /* Check if we have to recurse down by calculating the closest
         * point of the hyperrect and see if it's closer than our
         * minimum distance in result_dist_sq. */
        if (hyperrect_dist_sq(rect, pos) < *result_dist_sq) {//pos在超平面内或在超平面外距离小于 *result_dist_sq都可以继续递归
            /* Recurse down into farther subtree */
            kd_nearest_i(farther_subtree, pos, result, result_dist_sq, rect);
        }
        /* Undo the slice on the hyperrect */
        *farther_hyperrect_coord = dummy;
    }
}

//查找最近邻的结点，从root开始查找，返回结果集
struct kdres *kd_nearest(struct kdtree *kd, const double *pos)
{
    struct kdhyperrect *rect;
    struct kdnode *result;
    struct kdres *rset;
    double dist_sq;
    int i;

    if (!kd) return 0;
    if (!kd->rect) return 0;

    /* Allocate result set */
    if(!(rset = new kdres)) {
        return 0;
    }
    if(!(rset->rlist = new res_node)) {
        delete rset;
        return 0;
    }
    rset->rlist->next = 0;
    rset->tree = kd;

    /* Duplicate the bounding hyperrectangle, we will work on the copy */
    if (!(rect = hyperrect_duplicate(kd->rect))) {
        kd_res_free(rset);
        return 0;
    }

    /* Our first guesstimate is the root node */
    result = kd->root;
    dist_sq = 0;
    for (i = 0; i < kd->dim; i++)
        dist_sq += SQ(result->pos[i] - pos[i]);

    /* Search for the nearest neighbour recursively */
    kd_nearest_i(kd->root, pos, &result, &dist_sq, rect);

    /* Free the copy of the hyperrect */
    hyperrect_free(rect);

    /* Store the result */
    if (result) {
        if (rlist_insert(rset->rlist, result, -1.0) == -1) {
            kd_res_free(rset);
            return 0;
        }
        rset->size = 1;
        //只取结果集中的第一个。
        kd_res_rewind(rset);
        return rset;
    } else {
        kd_res_free(rset);
        return 0;
    }
}

//查找在阈值内的所有结点
struct kdres *kd_nearest_range(struct kdtree *kd, const double *pos, double range)
{
    int ret;
    struct kdres *rset;

    if(!(rset = new kdres)) {
        return 0;
    }
    if(!(rset->rlist = new res_node)) {
        delete rset;
        return 0;
    }
    rset->rlist->next = 0;
    rset->tree = kd;

    if((ret = find_nearest(kd->root, pos, range, rset->rlist, 0, kd->dim)) == -1) {
        kd_res_free(rset);
        return 0;
    }
    rset->size = ret;
    kd_res_rewind(rset);
    return rset;
}
//释放kdtree的结果集
void kd_res_free(struct kdres *rset)
{
    clear_results(rset);
    delete rset->rlist;
    delete rset;
}
//返回kdtree结果集的个数
int kd_res_size(struct kdres *set)
{
    return (set->size);
}

void kd_res_rewind(struct kdres *rset)
{
    rset->riter = rset->rlist->next;
}
//判断是否到了链表尾
int kd_res_end(struct kdres *rset)
{
    return rset->riter == 0;
}

int kd_res_next(struct kdres *rset)
{
    rset->riter = rset->riter->next;
    return rset->riter != 0;
}

void *kd_res_item(struct kdres *rset, double *pos)
{
    if(rset->riter) {
        if(pos) {
            memcpy(pos, rset->riter->item->pos, rset->tree->dim * sizeof *pos);
        }
        return rset->riter->item->data;
    }
    return 0;
}

void *kd_res_item_data(struct kdres *set)
{
    return kd_res_item(set, 0);
}

/* ---- hyperrectangle helpers ---- */
//创建超平面结构
static struct kdhyperrect* hyperrect_create(int dim, const double *min, const double *max)
{
    size_t size = dim * sizeof(double);
    struct kdhyperrect* rect = 0;

    if (!(rect = new kdhyperrect)) {
        return 0;
    }

    rect->dim = dim;
    if (!(rect->min = new double[size])) {
        delete rect;
        return 0;
    }
    if (!(rect->max = new double[size])) {
        delete[] rect->min;
        delete rect;
        return 0;
    }
    memcpy(rect->min, min, size);
    memcpy(rect->max, max, size);

    return rect;
}
//清除kd_tree结构里的超平面rect结构
static void hyperrect_free(struct kdhyperrect *rect)
{
    delete[] rect->min;
    delete[] rect->max;
    delete rect;
}
//复制rect
static struct kdhyperrect* hyperrect_duplicate(const struct kdhyperrect *rect)
{
    return hyperrect_create(rect->dim, rect->min, rect->max);
}
//，更新即扩展超平面范围
static void hyperrect_extend(struct kdhyperrect *rect, const double *pos)
{//超平面不是空，则每次改变超平面的范围
    int i;

    for (i=0; i < rect->dim; i++) {//更新每一维的最小值和最大值，
        if (pos[i] < rect->min[i]) {
            rect->min[i] = pos[i];
        }
        if (pos[i] > rect->max[i]) {
            rect->max[i] = pos[i];
        }
    }
}
//计算pos与rect超平面的距离，如果pos在超平面内，返回0
static double hyperrect_dist_sq(struct kdhyperrect *rect, const double *pos)
{
    int i;
    double result = 0;

    for (i=0; i < rect->dim; i++) {
        if (pos[i] < rect->min[i]) {
            result += SQ(rect->min[i] - pos[i]);
        } else if (pos[i] > rect->max[i]) {
            result += SQ(rect->max[i] - pos[i]);
        }
    }

    return result;
}

/* inserts the item. if dist_sq is >= 0, then do an ordered insert */
/* TODO make the ordering code use heapsort */
//将item加入结果集，如果dist_sq>=0，则按大小排序插入
static int rlist_insert(struct res_node *list, struct kdnode *item, double dist_sq)
{
    struct res_node *rnode;

    if(!(rnode = new res_node)) {
        return -1;
    }
    rnode->item = item;
    rnode->dist_sq = dist_sq;
    //链表的按照大小排序插入，这里是从小到大的顺序
    if(dist_sq >= 0.0) {
        while(list->next && list->next->dist_sq < dist_sq) {
            list = list->next;
        }
    }
    rnode->next = list->next;
    list->next = rnode;
    return 0;
}
//清除kdtree的返回结果集
static void clear_results(struct kdres *rset)
{
    struct res_node *tmp, *node = rset->rlist->next;

    while(node) {
        tmp = node;
        node = node->next;
        delete tmp;
    }

    rset->rlist->next = 0;
}
