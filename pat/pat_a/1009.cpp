/*Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 3 3.6 2 6.0 1 1.6*/
#include <stdio.h>
int main(){
    double a1[3000]={0},ans[3000]={0};
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;++i){
        int ex;
        double co;
       scanf("%d %lf",&ex,&co);
        a1[ex]=co;
    }
    scanf("%d",&k);
    for(int i=0;i<k;++i){
        int ex,ex2;
        double co,co2;
         scanf("%d %lf",&ex,&co);
         //printf("%.1f",co);
         for(int j=0;j<1001;++j){
            if(a1[j]>0||a1[j]<0){
                ex2=ex+j;
                co2=co*a1[j];//不要改变输入的值！！！！！！！！！！！！！！宁愿多声明变量
               // printf("%.1f %.1f\n",co2,a1[j]);
                ans[ex2]+=co2;
              //  printf("%d %.1f\n",ex,co2);
            }
         }
    }
    int count=0;
    for(int i=0;i<2002;++i){
        if(ans[i]>0||ans[i]<0)
            count++;
    }
    printf("%d",count);
    for(int i=2001;i>=0;--i){
        if(ans[i]>0||ans[i]<0)
            printf(" %d %.1f",i,ans[i]);
    }
    return 0;
}
