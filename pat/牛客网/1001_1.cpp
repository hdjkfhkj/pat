/*Sample Input:
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1
Sample Output:
3 0->2->3 0*/
#include <stdio.h>
#include <vector>
#include <stack>
#define inf 1000000000
#define maxn 510
using namespace std;
int n,g[maxn][maxn],dis[maxn],minneed=inf,minremain=inf,c[maxn]={0},seted[maxn];
vector<int> pre[maxn],temppath,path;
void init(){
    for(int i=0;i<=n;++i){
        for(int j=0;j<=n;++j){
            g[i][j]=inf;
        }
        g[i][i]=0;
        dis[i]=inf;
        seted[i]=0;
    }
}
void dijkstra(){
    dis[0]=0;
    for(int i=0;i<=n;++i){
        int mini=inf,k;
        for(int j=0;j<=n;++j){
              //  printf("%d %d\n",j,dis[j]);
            if(seted[j]==0&&dis[j]<mini){
                mini=dis[j];
                k=j;
            }
        }
        int u=k;
     //   printf("%d \n",u);
        seted[u]=1;
        for(int j=0;j<=n;++j){
            if(seted[j]==0&&g[u][j]<inf){
                 //   printf("sdffvfgbg%d %d\n",j,g[u][j]);
                if(dis[u]+g[u][j]<dis[j]){
                    dis[j]=dis[u]+g[u][j];
                    pre[j].clear();
                    pre[j].push_back(u);
                }
                else if(dis[u]+g[u][j]==dis[j]){
                    pre[j].push_back(u);
                }
            }
        }
    }
}
void dfs(int v){
    if(v==0){
        temppath.push_back(v);
        int need=0,remain=0,cur=0;
        for(int i=temppath.size()-1;i>=0;--i){
            int id=temppath[i];
            cur=cur-c[id];
          //  printf("cur=%d c[id]=%d\n",cur,c[id]);
            need=max(cur,need);
        }
        if(need<minneed){
                minneed=need;
            path=temppath;
            if(-cur+minneed>0){
            remain=-cur+minneed;
        }
            minremain=remain;
           // printf("%d %d\n",need,minneed);
        }
        if(-cur+minneed>0){
            remain=-cur+minneed;
        }
        if(need==minneed){
            if(remain<minremain){
                minremain=remain;
                path=temppath;
              //  printf("%d\n",remain);
            }
        }
        temppath.pop_back();
        return;
    }
    temppath.push_back(v);
    for(int i=0;i<pre[v].size();++i){
        dfs(pre[v][i]);
    }
    temppath.pop_back();
}
int main(){
    int cmax,sp,r;
    scanf("%d %d %d %d",&cmax,&n,&sp,&r);
    init();
    for(int i=1;i<=n;++i){
        scanf("%d",&c[i]);
        c[i]-=cmax/2;
    }
    for(int i=0;i<r;++i){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        g[a][b]=c;
        g[b][a]=c;
    }
    dijkstra();
    dfs(sp);
    printf("%d 0",minneed);
    for(int i=path.size()-2;i>=0;--i){
        printf("->%d",path[i]);
    }
    printf(" %d",minremain);
    return 0;
}
