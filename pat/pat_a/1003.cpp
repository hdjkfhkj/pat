/*As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

Input

Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1), M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C1 to C2.

Output

For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.
All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1*/
#include <stdio.h>
#include <algorithm>
using namespace std;
#define inf 100000000
#define maxv 510;
int re2=0,sum=0,num=0,re1=inf,start,c[500],n,recu=0,w[500]={0},d[510];
int visited[500]={0},road[500][500]={0};
int count1=0;
void dfs(int v,int goal){
    //printf("sum=%d num=%d v=%d\n",sum,num,v);
    w[start]=c[start];
    //sum+=c[v];
    visited[v]=1;
    visited[goal]=0;
    //printf("v=%d d=%d w=%d\n",v,num,w[v]);
    if(v==goal){
            if(num<re1){
                re1=num;
                count1=1;
            }
        else if(num==re1){
        count1++;
    }
    //printf("d=%d w=%d\n",d[v],w[v]);
    return;
    }
    else{
    for(int i=0;i<n;++i){
        if(road[v][i]>0&&visited[i]==0){
                num=d[v]+road[v][i];
           // recu++;
           // w[i]=w[v]+c[i];
           if(num<d[i]){
            d[i]=num;
            w[i]=w[v]+c[i];
           }
           else if(d[v]+road[v][i]==d[i]){
    if(w[v]+c[i]>w[i]){
         w[i]=w[v]+c[i];
    }
           }
            dfs(i,goal);
            //path[i][recu]=v;
          // printf("i=%d w=%d v=%d\n",i,w[i],v);
        }
    }
    }
}
int main(){
    int m,goal,c1,c2,weight;
    //fill(d,d+maxv,inf);
    for(int i=0;i<510;++i){
        d[i]=inf;
    }
    scanf("%d %d %d %d",&n,&m,&start,&goal);
    d[start]=0;
    //int c[n];
    //int road[500][500]={0};
    //int visit[n]={0}
    for(int i=0;i<n;++i){
        scanf("%d",&c[i]);
    }
    for(int i=0;i<m;++i){
        scanf("%d %d %d",&c1,&c2,&weight);
        road[c1][c2]=weight;
        road[c2][c1]=weight;
    }
    dfs(start,goal);
    printf("%d %d",count1,w[goal]);
    return 0;
}
