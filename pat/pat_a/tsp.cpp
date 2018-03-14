/*Procedure TSP_USE_SIMULATED_ANNEALING;
begin
INITIALIZE;   { 初始化i0= π1 … πn, t0=100, L= 20000 }
randomize;    { 初始化随机数种子 }
Repeat
    bChange:=0;
    for l:=1 to L do
    begin
       GENERATE;         { 采用2变换法产生新的路径 }
       CALCULATE(df);   { 计算 df = f(j)-f(i) 的值 }
       if ACCEPT(t, df) then { 根据Metropolis准则判断是否接受新的路径 }
       begin
           f: = f + df;      { 计算已接受的路径的长度 }
           bChange := 1;
       end;
    end;
    t:=t * 0.9;    { 衰减函数 α(t)=0.9 * t }
    if (bChange = 0) then s:=s+1 else s:=0;
until s = 2     { 停止准则为连续两个Mapkob链路径无变化 }
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define inf 1000000000
#define random(x) (rand()%x)
int g[10000][10000];
int path[10010],path1[10010],n=10,l=20000;
double t=100;
void init(){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            g[i][j]=inf;//任意给定。。。
            path[i]=i;
           // printf("sssssssssssseeeeeeeeeeeeeeeee%d \n",path[i]);
        }
    }
    for(int i=0;i<n-1;++i){
        g[i][i+1]=i+1;
        g[i+1][i]=i;
    }
    g[n-1][0]=n;
    g[0][n-1]=n-1;
}
int sum(int path[]){
    int dis=0;
    for(int i=0;i<n-1;++i){
            int j=path[i+1];
        dis+=g[path[i]][j];
      //  printf("%lf ",dis);
    }
    dis+=g[path[n-1]][path[0]];
    //  printf("\n");
    return dis;
}
int main(){
    init();

   //  printf("wwwwwwwwwwwwwwwwwwsssssssssssseeeeeeeeeeeeeeeee%lf %d\n",g[0][1],1);
    int bchange,s=0;
    double tf=0.1;
    int f;
  //  scanf("%lf %d",tf,n);
   // double f=sum(path);
    while(t>tf){
       //     printf("fdgfdh");
          //  bchange=0;
          s=0;
    f=sum(path);
  // printf("ssssssssssssss%lf  %d %d %d\n",f,path[0],path[1],path[2]);
    for(int i=0;i<l;++i){
         //  printf("%d %lf %d\n",i,t,s);
            bchange=0;
        int u=random(n);
        int v=random(n);
        if(u>v){
            int temp=u;
            u=v;
            v=temp;
        }
        if(u==v){
            u=rand()%v;
        }
      //  u=1,v=2;
     // u=0,v=99;
      printf("u=%d v=%d\n",u,v);
        for(int i=0;i<=n-1;++i){
            path1[i]=path[i];
   // printf(" %d ",path[i]);
    }
     // printf("\n");
        for(int i=u,j=v;i<j;++i,--j){
            int temp=path[i];
            path[i]=path[j];
            path[j]=temp;
        //   printf("%d %d %d %d\n",path[i],path[j],u,v);
        }
        int newf=sum(path);
        int dif=newf-f;
          printf("newf=%d f=%d  %d %lf\n",newf,f,dif,t);
        if(dif<=0){
            f=newf;
            bchange=1;
        }
        else{
            if(exp(-dif/t)>rand()%100/100.00){
                    printf("%d %d  %d %lf %lf %lf\n",newf,f,dif,t,exp(-dif/t),rand()%100/100.00);
                f=newf;
                bchange=1;
            }
        }
    if(bchange==0){
           for(int i=0;i<=n-1;++i){
            path[i]=path1[i];
           // printf("aaaaaaa %d ",path[i]);
    }
 //   printf("\n");
        s++;
    }
    else{
        s=0;
    }
    if(s==2){
        break;
    }
    }
    t=0.9*t;
    }

    for(int i=0;i<=n-1;++i){
            printf("%d ",path[i]);
    }
    printf("%d",path[0]);
    printf("\n");
    printf("f=%d ",f);
    return 0;
}
