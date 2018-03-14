#include <stdio.h>
#include <vector>
#include <math.h>
#define maxn 100010
using namespace std;
struct node{
    int father,layer;
    vector<int> child;
};
node t[maxn];
int maxm=0,countm=1;
void dfs(int v){
    for(int i=0;i<t[v].child.size();++i){
        int k=t[v].child[i];
        t[k].layer=t[v].layer+1;
        if(t[k].layer>maxm){
            maxm=t[k].layer;
            countm=1;
        }
        else if(t[k].layer==maxm){
            countm++;
        }
        dfs(k);
    }
}
int main(){
    int n,root;
    double p,r;
    scanf("%d %lf %lf",&n,&p,&r);
    for(int i=0;i<n;++i){
            int id;
        scanf("%d",&id);
        t[i].father=id;
        t[id].child.push_back(i);
        if(id==-1){
            root=i;
        }
    }
    t[root].layer=0;
    dfs(root);
    printf("%.2f %d",p*pow(1+r/100,maxm),countm);
    return 0;
}
