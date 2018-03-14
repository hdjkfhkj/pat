#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define maxn 1020
#define inf 1000000000
struct station{
    int mini;
    int avg;
    int index;
};
station zz[11];
int g[maxn][maxn],seted[maxn],lowcost[maxn];
int sum=0,mini=0,flag=0,n,m,d;
bool cmp(station a,station b){
    if(a.mini!=b.mini){
        return a.mini>b.mini;
    }
    else{
        if(a.avg!=b.avg){
            return a.avg<b.avg;
        }
        else{
            return a.index<b.index;
        }
    }
}
void init1(){
    for(int i=0;i<maxn;++i){
            seted[i]=0;
            lowcost[i]=inf;
        for(int j=0;j<maxn;++j){
            g[i][j]=inf;
        }
    g[i][i]=0;
    }
}
void init2(){
    for(int i=0;i<maxn;++i){
        seted[i]=0;
        lowcost[i]=inf;
    }
}
bool dijkstra(int v){
   // init();
   init2();
    lowcost[v]=0;
    for(int i=1;i<=n+m;++i){
            int minimum=inf,curr;
        for(int j=1;j<=n+m;++j){
            if(lowcost[j]<minimum&&seted[j]==0){
                minimum=lowcost[j];
                curr=j;
            }
        }
        seted[curr]=1;
        if(curr<=n&&flag!=-1){
                    mini=lowcost[curr];//the nearest house;
                  //  printf("mini=%d\n",mini);
                    flag=-1;
                }
        if(curr<=n){
            sum+=lowcost[curr];
        }
    //    printf("%d curr=%d\n",lowcost[curr],curr);
        for(int j=1;j<=n+m;++j){
            if(seted[j]==0&&g[curr][j]<inf){
                if(lowcost[curr]+g[curr][j]<lowcost[j]){
                    lowcost[j]=lowcost[curr]+g[curr][j];
                  //  printf("%d d=%d\n",lowcost[j],d);
                    if(lowcost[j]>d&&j<=n){
                        return false;
                    }

                }
            }
        }
    }
    return true;
}
int main(){
    int k;
    scanf("%d %d %d %d",&n,&m,&k,&d);
    init1();
    for(int i=0;i<k;++i){
        char end1[5],end2[5];
        int distance,r1,r2;
        scanf("%s %s %d",end1,end2,&distance);
        if(end1[0]=='G'){
            if(end1[2]=='0'){
                r1=n+10;
            }
            else{
                r1=n+end1[1]-'0';
            }
        }
        else{
            r1=atoi(end1);
        }
        if(end2[0]=='G'){
            if(end2[2]=='0'){
                r2=n+10;
            }
            else{
                r2=n+end2[1]-'0';
            }
        }
        else{
            r2=atoi(end2);
        }
        g[r1][r2]=distance;
        g[r2][r1]=distance;
        //printf("%d %d %d\n",r1,r2,g[r1][r2]);
    }
    int gas=-1,mdzz=inf,eeee,counta=0;
    for(int i=n+1;i<=n+m;++i){
        sum=0,mini=0,flag=0;
        if(dijkstra(i)==true){
             //   printf("sum=%d mini=%d\n",sum,mini);
            zz[counta].index=i;
            zz[counta].avg=sum;
            zz[counta].mini=mini;
            counta++;
        }
    }
    sort(zz,zz+counta,cmp);
    if(counta==0){
        printf("No Solution");
    }
    else{
            gas=zz[0].index;
    eeee=zz[0].mini;
    mdzz=zz[0].avg;
          //  printf("%d %d\n",dijkstra(gas)==true?1:0,gas);
        printf("%c%d\n",'G',gas-n);
        printf("%.1f %.1f",eeee*1.00,mdzz*1.00/n);
    }
    return 0;
}
