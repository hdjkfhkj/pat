/*输入例子:
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0 7
2 6 1
1 8
0 9
0 4
0 3

输出例子:
42.4*/
#include <stdio.h>
#include <vector>
#include <math.h>
#define maxn 100010
using namespace std;
struct node{
    int id;
    vector<int> child;
    int data;
    int layer;
};
node t[maxn];
double total=0,p,r;
void dfs(int v){
    if(t[v].data!=0){
        total+=t[v].data*p*pow(1+r/100,t[v].layer);
        //printf("%lf %d %lf %lf %d\n",total,t[v].data,p,r,t[v].layer);
    }
    else
    for(int i=0;i<t[v].child.size();++i){
            t[t[v].child[i]].layer=t[v].layer+1;
        dfs(t[v].child[i]);
    }
}
int main(){
    int m;
    scanf("%d %lf %lf",&m,&p,&r);
    for(int i=0;i<m;++i){
        int k;
        scanf("%d",&k);
        if(k==0){
            scanf("%d",&t[i].data);
        }
        else
        for(int j=0;j<k;++j){
            int kid;
            scanf("%d",&kid);
            t[i].child.push_back(kid);
        }
    }
    int root=0;
    t[root].layer=0;
    dfs(root);
    printf("%.1f",total);
    return 0;
}
