#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#include <pthread.h>
//#include "kd_tree.h"

#define SQ(x)           ((x) * (x))
//��ƽ��ṹ�壬
struct kdhyperrect {
    int dim;//��ƽ���ά��
    double *min, *max;    //ÿһά��Ӧ�������С���꣬һ����dimά����min��max��������Ϊdim          /* minimum/maximum coords */
};
//kd����һ����㣬
struct kdnode {
    double *pos;//����
    int dir;//split����������ţ�
    void *data;//ÿ������ŵ�����

    struct kdnode *left, *right;    /* negative/positive side */
};
//�������㣬��һ�������������ý��
struct res_node {
    struct kdnode *item;//���Ľ��
    double dist_sq;//��Ҫ��ѯ��ľ���
    struct res_node *next;
};
//kdtree����㣬���еĶ�������������
struct kdtree {
    int dim;//ά��
    struct kdnode *root;//kdnode�ĸ��ڵ�
    struct kdhyperrect *rect;//��ƽ��
    void (*destr)(void*);
};
//kdtree���ؽ��
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
//����kd_tree
struct kdtree *kd_create(int k)
{
    struct kdtree *tree;//����һ��kdtree tree

    if(!(tree = new kdtree)) {//�����ڴ治�ɹ�
        return 0;
    }

    tree->dim = k;
    tree->root = 0;
    tree->destr = 0;
    tree->rect = 0;

    return tree;
}
//�ͷ�kd_tree
void kd_free(struct kdtree *tree)
{
    if(tree) {
        kd_clear(tree);
        delete tree;
    }
}
//�ͷų�ƽ�棬ÿһ��kdnode�����һ����ƽ�档
static void clear_rec(struct kdnode *node, void (*destr)(void*))
{
    if(!node) return;

    clear_rec(node->left, destr);
    clear_rec(node->right, destr);

    if(destr)
    {//��destr������ΪNULLʱ�������ͷų�ƽ��������ݣ�
        destr(node->data);
    }
    delete[] node->pos;
    delete node;
}
//���kd_tree
void kd_clear(struct kdtree *tree)
{
    clear_rec(tree->root, tree->destr);//��tree�ĸ��ڵ㿪ʼ���kdnode���
    tree->root = 0;

    if (tree->rect) {
        hyperrect_free(tree->rect);//���kd_tree�ṹ��ĳ�ƽ��rect�ṹ
        tree->rect = 0;
    }
}
//data����
void kd_data_destructor(struct kdtree *tree, void (*destr)(void*))
{
    tree->destr = destr;
}

//����һ����ƽ�棬��һ��kdnode��㡣
static int insert_rec(struct kdnode **nptr, const double *pos, void *data, int dir, int dim)
{
    int new_dir;
    struct kdnode *node;

    if(!*nptr) {//����ڵ�Ϊ�գ����ߵ���Ҷ�ӽڵ�,������㣬���ڽ�����Ҫ���������
        if(!(node = new kdnode)) {
            return -1;
        }
        if(!(node->pos = new double[dim])) {
            delete[] node;
            return -1;
        }
        //��������ݷ�������
        memcpy(node->pos, pos, dim * sizeof *node->pos);
        node->data = data;
        node->dir = dir;
        node->left = node->right = 0;
        *nptr = node;
        return 0;
    }
    //�����㲻Ϊ�գ�
    node = *nptr;
    new_dir = (node->dir + 1) % dim;//�µķ���split����+1��������ά������x��y��z��x....�˴����Ǹ��ݷ������жϵģ������һ�㲻ƽ��

    if(pos[node->dir] < node->pos[node->dir]) {//�������������ϵ�����С�����н�㣬�������
        return insert_rec(&(*nptr)->left, pos, data, new_dir, dim);
    }
    return insert_rec(&(*nptr)->right, pos, data, new_dir, dim);
}
//������ʱ������kdtree�ṹ�壬����Ҫ����kdtree�ṹ���root���ݣ�Ȼ�� �ǳ�ƽ�淶Χ��ı䣬��Ҫ���¡�
int kd_insert(struct kdtree *tree, const double *pos, void *data)
{
    if (insert_rec(&tree->root, pos, data, 0, tree->dim)) {//ÿ�θ��³�ƽ�淶Χ
        return -1;
    }

    if (tree->rect == 0) {//����ǵ�һ���ڿ�������룬rectΪ0 ������rect�ṹ
        tree->rect = hyperrect_create(tree->dim, pos, pos);
    } else {//���򣬸��¼���չ��ƽ�淶Χ
        hyperrect_extend(tree->rect, pos);
    }

    return 0;
}
//�ҵ�����ڽӵ�
//���룺�����ָ�룬�������꣬��ֵ��bool������ά��
//����������list�����������ĸ�����
static int find_nearest(struct kdnode *node, const double *pos, double range, struct res_node *list, int ordered, int dim)
{
    double dist_sq, dx;
    int i, ret, added_res = 0;//added_res�������ӵĸ���

    if(!node) return 0;//

    dist_sq = 0;
    for(i=0; i<dim; i++) {
        dist_sq += SQ(node->pos[i] - pos[i]);//������ڲ�ѯ��kdnode�����pos����֮������ƽ��
    }
    if(dist_sq <= SQ(range)) {//�ڷ�Χ�ڣ��ͼ�������
        if(rlist_insert(list, node, ordered ? dist_sq : -1.0) == -1) {
            return -1;
        }
        added_res = 1;//
    }

    dx = pos[node->dir] - node->pos[node->dir];
    //���ﲻ���ף�Ϊʲô����̾��벻���ð뾶���ж��Ƿ��ѯ��һ�ߣ�����ͨ����ֵ���жϡ�
    ret = find_nearest(dx <= 0.0 ? node->left : node->right, pos, range, list, ordered, dim);//�ݹ�Ѱ��
    if(ret >= 0 && fabs(dx) < range) {//���������һ���ҵ�����������꣬��dx����ֵ�ڣ�������һ�߼����ҡ�
        added_res += ret;//���ҵ��Ľ������ret��


        //���ﲻ���ף�Ϊʲô����̾��벻���ð뾶���ж��Ƿ��ѯ��һ�ߣ�����ͨ����ֵ���жϡ�����֪�����֪��
        //�������ﲻ�����������Ϊʲô��������ֵ�Ķ��Ž�������ˡ�
 //ԭ�����������ھ���ָ������ֵ�ĵ㡣����
        ret = find_nearest(dx <= 0.0 ? node->right : node->left, pos, range, list, ordered, dim);
    }
    if(ret == -1) {
        return -1;
    }
    added_res += ret;

    return added_res;//���������ĸ���
}
//�ҵ�����ڵ�n����㣬�˴����������У�num����n
//�˴��ö�ά��n�����

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
        if(heap->size >= num) {//����ѵ���Ŀ�Ѿ��ﵽn������num��
            /* get furthest element */
            struct res_node *maxelem = rheap_get_max(heap);//������������Ǹ�Ԫ��

            /* and check if the new one is closer than that */
            if(maxelem->dist_sq > dist_sq) {
                rheap_remove_max(heap);//������������Ǹ�Ԫ�ر����ڱȽϵ������Ƴ��Ǹ����ֵ
                //�������ڱȽϵĽ��������
                if(rheap_insert(heap, node, dist_sq) == -1) {
                    return -1;
                }
                added_res = 1;

                range_sq = dist_sq;

            }
        } else {//û�ﵽn��ֵ��ֱ�Ӳ���
            if(rheap_insert(heap, node, dist_sq) == -1) {
                return =1;
            }
            added_res = 1;
        }
    }


    /* find signed distance from the splitting plane */
    dx = pos[node->dir] - node->pos[node->dir];
    //�����find_nearest����һ��
    ret = find_nearest_n(dx <= 0.0 ? node->left : node->right, pos, range, num, heap, dim);
    if(ret >= 0 && fabs(dx) < range) {
        added_res += ret;
        ret = find_nearest_n(dx <= 0.0 ? node->right : node->left, pos, range, num, heap, dim);
    }

}

//��������ڵĽ��,���ҽ�������Ȼ����㱾��Ȼ�����Զ������
static void kd_nearest_i(struct kdnode *node, const double *pos, struct kdnode **result, double *result_dist_sq, struct kdhyperrect* rect)
{
    int dir = node->dir;
    int i;
    double dummy, dist_sq;
    struct kdnode *nearer_subtree, *farther_subtree;
    double *nearer_hyperrect_coord, *farther_hyperrect_coord;

    /* Decide whether to go left or right in the tree */
    dummy = pos[dir] - node->pos[dir];
    if (dummy <= 0) {//���С�ڵ���0������������
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

    if (nearer_subtree) {//���������û�е�Ҷ�ӽ�㣬�����ݹ飬������Ȳ�ѯ��
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
    dist_sq = 0;//���㱾�����ԭ������Ĵ�С��ϵ
    for(i=0; i < rect->dim; i++) {
        dist_sq += SQ(node->pos[i] - pos[i]);
    }
    if (dist_sq < *result_dist_sq) {
        *result = node;
        *result_dist_sq = dist_sq;
    }

    if (farther_subtree) {//�ݹ����Զ������
        /* Get the hyperrect of the farther subtree */
        dummy = *farther_hyperrect_coord;
        *farther_hyperrect_coord = node->pos[dir];
        /* Check if we have to recurse down by calculating the closest
         * point of the hyperrect and see if it's closer than our
         * minimum distance in result_dist_sq. */
        if (hyperrect_dist_sq(rect, pos) < *result_dist_sq) {//pos�ڳ�ƽ���ڻ��ڳ�ƽ�������С�� *result_dist_sq�����Լ����ݹ�
            /* Recurse down into farther subtree */
            kd_nearest_i(farther_subtree, pos, result, result_dist_sq, rect);
        }
        /* Undo the slice on the hyperrect */
        *farther_hyperrect_coord = dummy;
    }
}

//��������ڵĽ�㣬��root��ʼ���ң����ؽ����
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
        //ֻȡ������еĵ�һ����
        kd_res_rewind(rset);
        return rset;
    } else {
        kd_res_free(rset);
        return 0;
    }
}

//��������ֵ�ڵ����н��
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
//�ͷ�kdtree�Ľ����
void kd_res_free(struct kdres *rset)
{
    clear_results(rset);
    delete rset->rlist;
    delete rset;
}
//����kdtree������ĸ���
int kd_res_size(struct kdres *set)
{
    return (set->size);
}

void kd_res_rewind(struct kdres *rset)
{
    rset->riter = rset->rlist->next;
}
//�ж��Ƿ�������β
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
//������ƽ��ṹ
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
//���kd_tree�ṹ��ĳ�ƽ��rect�ṹ
static void hyperrect_free(struct kdhyperrect *rect)
{
    delete[] rect->min;
    delete[] rect->max;
    delete rect;
}
//����rect
static struct kdhyperrect* hyperrect_duplicate(const struct kdhyperrect *rect)
{
    return hyperrect_create(rect->dim, rect->min, rect->max);
}
//�����¼���չ��ƽ�淶Χ
static void hyperrect_extend(struct kdhyperrect *rect, const double *pos)
{//��ƽ�治�ǿգ���ÿ�θı䳬ƽ��ķ�Χ
    int i;

    for (i=0; i < rect->dim; i++) {//����ÿһά����Сֵ�����ֵ��
        if (pos[i] < rect->min[i]) {
            rect->min[i] = pos[i];
        }
        if (pos[i] > rect->max[i]) {
            rect->max[i] = pos[i];
        }
    }
}
//����pos��rect��ƽ��ľ��룬���pos�ڳ�ƽ���ڣ�����0
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
//��item�������������dist_sq>=0���򰴴�С�������
static int rlist_insert(struct res_node *list, struct kdnode *item, double dist_sq)
{
    struct res_node *rnode;

    if(!(rnode = new res_node)) {
        return -1;
    }
    rnode->item = item;
    rnode->dist_sq = dist_sq;
    //����İ��մ�С������룬�����Ǵ�С�����˳��
    if(dist_sq >= 0.0) {
        while(list->next && list->next->dist_sq < dist_sq) {
            list = list->next;
        }
    }
    rnode->next = list->next;
    list->next = rnode;
    return 0;
}
//���kdtree�ķ��ؽ����
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
