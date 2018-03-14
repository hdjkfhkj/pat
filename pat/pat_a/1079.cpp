/*Sample Input:
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
Sample Output:
42.4*/
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
struct node{
    int weight,layer,leaf,father;
    vector<int> child;
};
node v[100010];
double sum=0,p,r;
void dfs(int c){
    if(c!=0){
        v[c].layer=v[v[c].father].layer+1;
    }
    if(v[c].leaf==1){
            sum+=v[c].weight*p*pow((1+r/100),v[c].layer);
            return;
        }
    for(int i=0;i<v[c].child.size();++i){
        dfs(v[c].child[i]);
    }
}
int main(){
    int n;
    scanf("%d %lf %lf",&n,&p,&r);
    v[0].layer=0;
    for(int i=0;i<n;++i){
        int k;
        scanf("%d",&k);
        if(k==0){
            scanf("%d",&v[i].weight);
            v[i].leaf=1;
        }
        else
        for(int j=0;j<k;++j){
            int kid;
            scanf("%d",&kid);
            v[i].child.push_back(kid);
            v[kid].father=i;
           // v[kid].layer=v[i].layer+1;;
        }
    }
    dfs(0);
    printf("%.1lf",sum);
    return 0;
}

