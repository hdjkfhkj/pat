/*Sample Input:
printf(" %d %d %d ",v,tree[v].child[i],sw[v]);
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19
Sample Output:
10 5 2 7
10 4 10
10 3 3 6 2
10 3 3 6 2*/
#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;//数组会比结构体慢吗？
struct node{
    int id;
    int father;
    int weight;
    vector<int> child;
};
node tree[100010];
int w=0,sum;
int wa[100010];
int sw[100010]={0};
bool cmp(int a,int b){
    return wa[a]>wa[b];
}
void print(int v){
    stack<int> f;
    for(int i=v;i!=0;i=tree[i].father){
        f.push(i);
    }
    printf("%d",tree[0].weight);
    while(!f.empty()){
        printf(" %d",tree[f.top()].weight);
        f.pop();
    }
    printf("\n");
}
void dfs(int v){//每一段路上的权重单独计算
    if(v!=0)
    sw[v]=sw[tree[v].father]+tree[v].weight;
    else{
        sw[0]=tree[0].weight;
    }
    if(sw[v]==sum){
        if(tree[v].child.size()==0){
                 //w-=tree[v].weight;
               //  printf("aaaaaaaaa %d %d %d \n",v,sw[v]);
            print(v);
            return;
        }
        else{
              //  w-=tree[v].weight;
            return;
        }
    }
    else if(sw[v]>sum){
           //  w-=tree[v].weight;
        return;
    }
    else{
        for(int i=0;i<tree[v].child.size();++i){
               // printf(" %d %d %d ",v,tree[v].child[i],sw[v]);
            dfs(tree[v].child[i]);
        }
    }
  //  printf("\n");
}
int main(){
    int n,notl;
    scanf("%d %d %d",&n,&notl,&sum);
    for(int i=0;i<n;++i){
        scanf("%d",&tree[i].weight);
      // tree[i].weight=wa[i];
       wa[i]=tree[i].weight;
    }
    for(int i=0;i<notl;++i){
        int id,child1;
        scanf("%d %d",&id,&child1);
        for(int j=0;j<child1;++j){
            int kid;
            scanf("%d",&kid);
            tree[kid].father=id;
            tree[id].child.push_back(kid);
        }
        sort(tree[id].child.begin(),tree[id].child.end(),cmp);
    }
    tree[0].father=-1;
    dfs(0);
    return 0;
}
