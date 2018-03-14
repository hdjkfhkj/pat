/*Sample Input:
9 1.80 1.00
1 5 4 4 -1 4 5 3 6
Sample Output:
1.85 2*/
#include <stdio.h>
#include <vector>
#include <math.h>
#define maxn 100000
using namespace std;
struct node{
    int father;
    int layer;
    bool leaf;
    vector<int> child;
};
node tree[maxn];
int n;
void init(){
    for(int i=0;i<n;++i){
       tree[i].leaf=true;
    }
}
void dfs(int root){
   // tree[root].layer=0;
        for(int j=0;j<tree[root].child.size();++j){
            tree[tree[root].child[j]].layer=tree[root].layer+1;
            dfs(tree[root].child[j]);
        }
}
int main(){
    double p,r;
    scanf("%d %lf %lf",&n,&p,&r);
    init();
    int root;
    for(int i=0;i<n;++i){
        int f;
        scanf("%d",&f);
        tree[i].father=f;
        if(f!=-1){
        tree[f].leaf=false;
        tree[f].child.push_back(i);
        }
        else{
            root=i;
        }
    }
    tree[root].layer=0;
    dfs(root);
    int maxmum=0,countn=0;
    for(int i=0;i<n;++i){
        if(tree[i].layer>maxmum){
            maxmum=tree[i].layer;
            countn=1;
        }
        else if(tree[i].layer==maxmum){
            countn++;
        }
    }
    double ans=p*pow(1+r/100.00,maxmum);
    printf("%.2f %d",ans,countn);
    return 0;
}
