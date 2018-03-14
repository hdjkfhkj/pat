/*Sample Input 1:
50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300
Sample Output 1:
749.17
Sample Input 2:
50 1300 12 2
7.10 1
7.00 600
Sample Output 2:
The maximum travel distance = 1200.00*/
#include <stdio.h>
#include <algorithm>
#define inf 1000000000
using namespace std;
struct station{
    double p;
    double d;
};
int cmax,davg,n;
double distance1;
station s[510];
bool cmp(station s1,station s2){
    return s1.d<s2.d;
}
int main(){
    scanf("%d %lf %d %d",&cmax,&distance1,&davg,&n);
  //  printf("oooooooo%lf\n",distance1);
    for(int i=0;i<n;++i){
        scanf("%lf %lf",&s[i].p,&s[i].d);
    //    printf("qqqqqqqqq%lf",s[i].d);
    }
    double money=0,dis=0;
    double gas=0;
   // int flag=0;
    double cre;
    sort(s,s+n,cmp);
    s[n].d=distance1;
    s[n].p=inf;
    for(int i=0;i<n;++i){
            if(s[i+1].d-s[i].d>cmax*davg){//can't finish
                    dis=s[i].d+cmax*davg;
                break;
            }
            if(s[0].d>1e-6){
                dis=0;
                break;
            }
            int flag=0;
         for(int j=i+1;j<=n;++j){//找600里内最便宜的
            if(s[j].d-s[i].d<=cmax*davg){
                if(s[j].p<s[i].p){
                        if(dis<s[j].d){//not enough,add oil
                    cre=(s[j].d-dis)/davg;
                    gas+=cre;
                    money+=cre*s[i].p;
                    dis=s[j].d;
                   // gas=0;
                 //   printf("wwwwwwwwwww%lf",s[j].d);
                        }
                    //i=j;
                    flag=1;
                    break;
                }
            }
         }
         if(flag==0){
                if(distance1-s[i].d>=cmax*davg){
            cre=(s[i].d+cmax*davg-dis)/davg;
            gas=cmax;
            money+=cre*s[i].p;
            dis+=cre*davg;

         //   printf("%lf %lf\n",money,dis);
                }
                else{
                    cre=(distance1-dis)/davg;
                    gas+=cre;
                    money+=cre*s[i].p;
                    dis=distance1;
                 //   printf("mbjsrg jhn%lf\n",money);
                }
         }
       //  printf("monry%lf  dis%lf\n",money,dis);
         gas=0;
    }
  //  printf("%lf %lf\n",dis,distance1);
    if(dis<distance1){
        printf("The maximum travel distance = %.2f",dis);
    }
    else{
        printf("%.2f",money);
    }
    return 0;
}
