/*Sample Input
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
Sample Output
0 2 3 3 40*/
#include <stdio.h>
#include <stack>
using namespace std;
#define inf 1000000000
int visited[510],path[510],lowdis[510],lowcost[510],cost[510][510],g[510][510];
int n,m,s,d;
void init(){
    for(int i=0;i<n;++i){
        visited[i]=0;
        path[i]=-1;
        lowcost[i]=inf;
        lowdis[i]=inf;
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            g[i][j]=inf;
            g[j][i]=inf;
            cost[i][j]=inf;
            cost[j][i]=inf;
        }
    }
}
void dijkstra(int v){
   //  printf("aaaaaaaaaaaa%d\n",v);
    lowcost[v]=0;
    lowdis[v]=0;
    for(int i=0;i<n;++i){
            int mind=inf,k;
        //    printf("wwwwwwwwwwww%d \n",n);
        for(int j=0;j<n;++j){
           //     printf("jjh%d %d\n",j,visited[j]);
            if(visited[j]==0){
              //  printf("lllllllll%d\n",lowcost[j]);
                if(lowdis[j]<mind){
                    mind=lowdis[j];
                    k=j;
                  //   printf("rrttyyuyuyu%d %d %d\n",k,visited[k],j);
                }
            }
        }
    //     printf("qqqqqqqqq%d %d\n",k,visited[k]);
        visited[k]=1;
       //  printf("eeeeeeee%d %d\n",k,visited[k]);
        for(int j=0;j<n;++j){
             //   printf("mdzz%d %d %d %d %d %d\n",k,j,visited[j],g[k][j],lowdis[k],lowdis[j]);
            if(visited[j]==0&&lowdis[k]+g[k][j]<=lowdis[j]){
                 //   printf("whywww\n");
                if(lowdis[k]+g[k][j]<lowdis[j]){
                    //    printf("mdccccccccccc\n");
                    lowdis[j]=lowdis[k]+g[k][j];
                    lowcost[j]=lowcost[k]+cost[k][j];//更新啊！！！！！！！！！！！！！！！！！sb！！！！！！！！！！！！！！！！！！！！！！！！
                    path[j]=k;
              //    printf("aaaaaaaaaaaa %d %d %d %d\n",k,j,lowcost[j]);
                }
                else if(lowdis[k]+g[k][j]==lowdis[j]){
                //    printf("mdgbz\n");
           //     printf("%d %d %d\n",lowcost[k],cost[k][j],lowcost[j]);
                    if(lowcost[k]+cost[k][j]<lowcost[j]){
                        path[j]=k;
                        lowcost[j]=lowcost[k]+cost[k][j];
                   //   printf("ooooooooooooo%d %d\n",lowdis[j],lowcost[j]);
                    }
                }
         //   printf("'ghghghghgh);'");
            }
        }
    }
}
int main(){
    scanf("%d %d %d %d",&n,&m,&s,&d);
    init();//初始化的位置！！！！！！！！！！！！！！！！！！！！！！
    for(int i=0;i<m;++i){
        int a,b;
        int md;
        scanf("%d %d",&a,&b);
        scanf("%d %d",&g[a][b],&cost[b][a]);
        g[b][a]=g[a][b];
        cost[a][b]=cost[b][a];//能不能不要犯无谓的错误！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
     //   printf("ccccccccccccccccccc%d %d %d %d\n",cost[a][b],g[a][b],b,a);
    }
    dijkstra(s);
    stack<int> p;
    int destination =d;
    for(int i=0;path[d]!=-1;++i){
        p.push(d);
       // printf("sssssssssssss%d \n",d);
        d=path[d];
    }
    p.push(s);
    for(int i=0;!p.empty();++i){
        printf("%d ",p.top());
        p.pop();
    }
    printf("%d %d",lowdis[destination],lowcost[destination]);//attention!!!!!!!!!!!!!!
    return 0;
}
