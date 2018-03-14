/*Sample Input:
23 13
21 1 23
01 4 03 02 04 05
03 3 06 07 08
06 2 12 13
13 1 21
08 2 15 16
02 2 09 10
11 2 19 20
17 1 22
05 1 11
07 1 14
09 1 17
10 1 18
Sample Output:
9 4*/
#include <vector>
#include <stdio.h>
#define maxn 110
using namespace std;
struct node{
    int layer;
    vector<int> child;
};
node t[maxn];
int countm[maxn]={0};
void dfs(int v){
    countm[t[v].layer]++;
    for(int i=0;i<t[v].child.size();++i){
        int kk=t[v].child[i];
        t[kk].layer=t[v].layer+1;
        dfs(kk);
    }
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;++i){
        int id,k;
        scanf("%d %d",&id,&k);
        for(int j=0;j<k;++j){
            int kid;
            scanf("%d",&kid);
            t[id].child.push_back(kid);
        }
    }
    int root=1;
    t[root].layer=1;
    dfs(root);
    int maxm=0,ge;
    for(int i=1;i<=maxn;++i){
        if(countm[i]>maxm){
            maxm=countm[i];
            ge=i;
        }
    }
    printf("%d %d",maxm,ge);
    return 0;
}
