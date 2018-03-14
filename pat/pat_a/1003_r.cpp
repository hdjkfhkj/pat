/*Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output
2 4*/
#include <stdio.h>
#define inf 100000000
int road[500][500]={0},sum=0,count=0,num=inf,dis=0,set[500]={0},number[510]={0},w[510]={0},n,c[510],start;
void dijkstra(int start,int goal){
    int lowcost[500];
    for(int i=0;i<n;++i){//initial
        if(road[start][i]!=0){
            lowcost[i]=road[start][i];
        }
        else{
            lowcost[i]=inf;
        }
    }

    lowcost[start]=0;
    w[start]=c[start];
    for(int i=0;i<n;++i){//n-1 times joint
            int min=inf,u=-1;
        for(int i=0;i<n;++i){
            if(lowcost[i]<min&&set[i]==0){
                min=lowcost[i];
                u=i;
            }
        }//find the node that  is nearest to current
        set[u]=1;
        for(int i=0;i<n;++i){//update lowcost
                if(set[i]==0&&road[u][i]!=0){
            if(road[u][i]+lowcost[u]<lowcost[i]){
                lowcost[i]=road[u][i]+lowcost[u];
                w[i]=w[u]+c[i];
                number[i]=number[u];
            }
            else if(road[u][i]+lowcost[u]==lowcost[i]){
                if(w[u]+c[i]>w[i]){
                    w[i]=w[u]+c[i];
                }
                number[i]+=number[u];
            }
        }
        }
    }


}
int main(){
    int m,goal,c1,c2,weight;
    scanf("%d %d %d %d",&n,&m,&start,&goal);
    for(int i=0;i<n;++i){
        scanf("%d",&c[i]);//weight of node
    }
    for(int i=0;i<m;++i){
        scanf("%d %d %d",&c1,&c2,&weight);
        road[c1][c2]=weight;
        road[c2][c1]=weight;
    }
    number[start]=1;
    dijkstra(start,goal);
    printf("%d %d",number[goal],w[goal]);
    return 0;
}
