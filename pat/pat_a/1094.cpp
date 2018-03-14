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
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    int id,layer;
    vector<int> child;
};
node t[110];
int book[110]={0};
void dfs(int v){
    book[t[v].layer]++;//额，这方面的技巧还得加强
    for(int i=0;i<t[v].child.size();++i){
            t[t[v].child[i]].layer=t[v].layer+1;
        dfs(t[v].child[i]);
    }
}
bool cmp(node a,node b){
    return a.layer<b.layer;
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
    t[1].layer=1;
    dfs(1);
    int maxm=0,level=0;
    for(int i=1;i<=n;++i){
        if(book[i]>maxm){
            maxm=book[i];
            level=i;
        }
    }
    printf("%d %d\n",maxm,level);/*
    sort(t+1,t+n+1,cmp);
    int cmax=0,clevel,countm=0,clayer=1;
    for(int i=1;i<=n;++i){
        if(t[i].layer==clayer){
            countm++;
        }
        else{
            if(countm>cmax){
                cmax=countm;
                clevel=clayer;
            }
            clayer++;
            countm=1;
        }
    }
    printf("%d %d",cmax,clevel);*/
    return 0;
}
