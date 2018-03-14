/*Sample Input:
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
5
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:02:00:02 off-line
Sample Output:
CYJJ 01
01:05:59 01:07:00 61 $1*/
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct record{
    char na[30];
    int mo,d,h,mi;
    int on;
    int visit;
};
int charge[24];
bool cmp(record r1,record r2){
    if(strcmp(r1.na,r2.na)!=0){
        return strcmp(r1.na,r2.na)<0;
    }
    else{
        if(r1.d!=r2.d){
        return r1.d<r2.d;
    }
    else{
        if(r1.h!=r2.h){
            return r1.h<r2.h;
        }
        else{
            return r1.mi<r2.mi;
        }
    }
    }
}/*
double cal1(record r1,record r2){
    double money=0;
    int time=r1.d*24*60+r1.h*60+r1.mi-(r2.d*24*60+r2.h*60+r2.mi);
    int hour=time/60;
    int day=r1.d-r2.d-1;
    if(time<=(60-r2.mi)){
        money=time*charge[r2.h];
    }
    else if(r1.d==r2.d){
            money=(60-r2.mi)*charge[r2.h];
           // printf("%.2f ",money);
            int i;
        for(i=0;i<r1.h-r2.h-1;++i){
            money+=60*charge[r2.h+i+1];
            //printf("%.2f ",money);
        }
        money+=r1.mi*charge[r1.h];
       // printf("%.2f %d",money,r2.mi);
    }
    else{
        money=(60-r2.mi)*charge[r2.h];
        for(int j=r2.h+1;j<24;++j){
            money+=60*charge[j];
        }
        for(int i=0;i<day;++i){
            for(int j=0;j<24;++j){
            money+=60*charge[j];
        }
        }
        for(int j=0;j<r1.h;++j){
            money+=60*charge[j];
        }
        money+=r1.mi*charge[r1.h];
    }
    return money/100;
}*/
void cal2(record r1,record r2,double money,int time){
    money=0;
    time=0;
     printf("%02d:%02d:%02d %02d:%02d:%02d %d %c%.2f\n",r1.d,r1.h,r1.mi,r2.d,r2.h,r2.mi,time,36,money);
    while(r1.d<r2.d||r1.h<r2.h||r1.mi<r2.mi){
        r1.mi++;
        time++;
        money+=charge[r1.h];
        if(r1.mi==60){
            r1.h++;
            r1.mi=0;
        }
        if(r1.h==24){
            r1.d++;
            r1.h=0;
        }
    }
    money/=100.00;
      printf("%02d:%02d:%02d %02d:%02d:%02d %d %c%.2f\n",r1.d,r1.h,r1.mi,r2.d,r2.h,r2.mi,time,36,money);
}

int main(){
    for(int i=0;i<24;++i){
        scanf("%d",&charge[i]);
    }
    int n;
    char line[10];
    scanf("%d",&n);
    record r[n];
    for(int i=0;i<n;++i){
        scanf("%s %d:%d:%d:%d %s",r[i].na,&r[i].mo,&r[i].d,&r[i].h,&r[i].mi,line);
        if(strcmp(line,"on-line")==0)
            r[i].on=1;
        else
            r[i].on=0;
        r[i].visit=0;
    }
    sort(r,r+n,cmp);
    int flag1=0,flag2=0;
    int sum=0;
    for(int i=0;i<n-1;++i){
            if(strcmp(r[i].na,r[i+1].na)!=0){
                    if(sum>0)
                    printf("Total amount: %c%.2f\n",36,sum/100.00);
                    flag2=0;
                flag1=0;
                sum=0;
            continue;
            }
           if(r[i].on==1&&r[i+1].on==0&&strcmp(r[i].na,r[i+1].na)==0){
            if(flag1==0){
                printf("%s %02d\n",r[i].na,r[i].mo);
                            flag1=1;
            }
            int k=i+1,j=i;

                    //cal2(r[j],r[k],money,time);
                    record r1=r[j],r2=r[k];
                    int money=0;
                    int count=0;
                    while(r1.d<r2.d||r1.h<r2.h||r1.mi<r2.mi){
        r1.mi++;
        count++;
        money+=charge[r1.h];
        if(r1.mi==60){
            r1.h++;
            r1.mi=0;
        }
        if(r1.h==24){
            r1.d++;
            r1.h=0;
        }
    }
    //money/=100.00;
                    sum+=money;
                    printf("%02d:%02d:%02d %02d:%02d:%02d %d %c%.2f\n",r[j].d,r[j].h,r[j].mi,r[k].d,r[k].h,r[k].mi,count,36,money/100.00);
           }
    }
    if(sum>0)
printf("Total amount: %c%.2f\n",36,sum/100.00);
    return 0;
}
