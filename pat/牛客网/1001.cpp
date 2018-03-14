/*Sample Input:
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1
Sample Output:
3 0->2->3 0

10 4 4 5
4 8 9 0
0 1 1
1 2 1
1 3 2
2 3 1
3 4 1

*/
#include <stdio.h>
#include <stack>
using namespace std;
#define inf 1000000000
#define maxn 510
int n;
int dis[maxn],seted[maxn],path[maxn],c[maxn],w[maxn],need[maxn],g[maxn][maxn];
void init(){
    for(int i=0;i<=n;++i){
        for(int j=0;j<=n;++j){
            g[i][j]=inf;
        }
        g[i][i]=0;
        dis[i]=inf;
        seted[i]=0;
        path[i]=-1;
        need[i]=-1;
        w[i]=0;
    }
}
void dijkstra(){
    dis[0]=0;
    w[0]=0;
    for(int i=0;i<=n;i++){
        int mini=inf,k=-1;
        for(int j=0;j<=n;++j){
             //   printf("fgfgfgfgyhyh%d\n",j);
        if(dis[j]<mini&&seted[j]==0){
            mini=dis[j];
            k=j;
          //  printf("ffgbgnfg%d %d\n",k,dis[k]);
        }
        }
        int u=k;
        seted[u]=1;
       // printf("%d %d\n",u,seted[u]);
        for(int j=0;j<=n;++j){
            if(seted[j]==0&&dis[u]+g[u][j]<=dis[j]){
                if(dis[u]+g[u][j]<dis[j]){
                    path[j]=u;
                    dis[j]=dis[u]+g[u][j];
                    w[j]=w[u]-c[j];
                    need[j]=max(w[j],need[u]);
                }
                else if(dis[u]+g[u][j]==dis[j]&&dis[j]<inf){
                       // printf("cch%d %d %d\n",u,g[u][j],dis[j]);
                    int current=w[u]-c[j],newneed=max(need[u],current);
                   // printf("ddffgdtghtfh%d %d %d %d %d\n",j,newneed,need[j],w[u],current);
                    if(newneed<need[j]){
                        path[j]=u;
                        w[j]=current;
                    }
                    else if(newneed==need[j]){
//printf("dfffgbgjhnjhjhn%d %d\n",current,w[j]);
                        if(current>w[j]){
                            w[j]=current;
                            path[j]=u;
                        }
                    }
                }
            }
        }
    }
}
void print(int v){
    int num=1;
    stack<int> s;
    for(int p=v;p!=0;p=path[p]){
        s.push(p);
        num++;
    }
    printf("%d 0",w[v]);
    while(!s.empty()){
        int cur=s.top();
        printf("->%d",cur);
        s.pop();
    }
    if(w[v]>=0){
        printf(" 0");
    }
    else{
        printf(" %d",-w[v]);
    }
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
    print(sp);
    return 0;
}
