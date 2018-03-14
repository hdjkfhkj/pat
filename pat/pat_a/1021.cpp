/*Sample Input 1:
5
1 2
1 3
1 4
2 5
Sample Output 1:
3
4
5
Sample Input 2:
5
1 3
1 4
2 5
3 4
Sample Output 2:
Error: 2 components*/
#include <stdio.h>
#include <vector>
using namespace std;
int visited[10010]={0},depth[10010]={0};
vector<int> adj[10010];
int n;
void init(){
    for(int i=1;i<=n;++i){
        visited[i]=0;
        depth[i]=0;
    }
}
int dfs(int v,int h){
    visited[v]=1;
    int maxd=h;
    for(int i=0;i<adj[v].size();++i){
        int child=adj[v][i];
       // printf("%d's child =%d",v,child);
        if(visited[child]==0){
                 //printf("%d's child =%d ",v,child);
            int d=dfs(child,h+1);
            if(d>maxd){
                maxd=d;
            }
        }
    }
  // printf("%d's maxd=%d\n",v,maxd);
    return maxd;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;++i){
        int a,b;
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    init();
    int maxl=0,block=0,j=0;
    for(int i=1;i<=n;++i){
         if(visited[i]==0){
            dfs(i,1);
            block++;
         }

    }
    if(block>1){
        printf("Error: %d components",block);
    }
    else if(block==1){
        for(int i=1;i<=n;++i){
            //init();
            for(int i=1;i<=n;++i){
        visited[i]=0;
    }
           // printf("visited[i]=%d",visited[i]);
            int deep=dfs(i,1);
            //printf("i=%d deep=%d\n",i,deep);
            if(maxl<deep){
                maxl=deep;
                j=0;
                depth[j++]=i;
            }
            else if(maxl==deep){
                depth[j++]=i;
                //printf("maxl=%d deep=%d\n",maxl,deep);
            }
        }
        for(int i=0;i<j;++i){
                printf("%d\n",depth[i]);
        }
    }

    return 0;
}
