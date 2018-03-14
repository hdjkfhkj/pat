/*Sample Input:
7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10
Sample Output:
8.2*/
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
struct customer{
    int h,m,s,p,finish,mdzz;
};
queue<customer> line[101];
customer c[10010],start,endr;
int k;
void init(){
    start.h=8;
    start.m=0;
    start.s=0;
    endr.h=17;
    endr.m=0;
    endr.s=1;
    endr.finish=9*60*60+1;
}
bool cmp(customer c1,customer c2){
    if(c1.h!=c2.h){
        return c1.h<c2.h;
    }
    else{
        if(c1.m!=c2.m){
            return c1.m<c2.m;
        }
        else{
            return c1.s<c2.s;
        }
        }
    }
int cal(customer c1,customer c2){
    int time=0;
    if(cmp(c1,c2)==false){
        return 0;
    }
    while(c1.h<c2.h||c1.m<c2.m||c1.s<c2.s){
        time++;
        c1.s++;
        if(c1.s==60){
            c1.m++;
            c1.s=0;
        }
        if(c1.m==60){
            c1.h++;
            c1.m=0;
        }
    }
    //printf(" time=%d ",time);
    return time;
}
int  finde()
{
    int j=0;
    for(int i=0;i<k;++i){
            //printf("duitou%d ",line[i].front().h);
        customer temp,early;
        early=endr;
        if(!line[i].empty())
          temp=line[i].front();

        if(temp.finish<early.finish){
            early=temp;
            j=i;
            //printf("j1=%d ",j);
        }
    }
    //printf("j2=%d ",j);
return j;
}

int main(){
    int n,k;
    init();
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%d:%d:%d %d",&c[i].h,&c[i].m,&c[i].s,&c[i].p);
        //printf("%d\n",c[i].p);
    }
    sort(c,c+n,cmp);
    int wait=0,count=0;
    for(int i=0;i<k;++i){
           // printf("%d %d\n",start.h,i);
        if(cmp(c[i],start)==true){
                //printf("%d:%d:%d  ",c[i].h,c[i].m,c[i].s);
           wait=wait+cal(c[i],start);
           //printf("%d ",cal(c[i],start));
           //printf("hehehheh %d\n",c[i].mdzz);
//add(start,c[i].p);
            c[i].finish=c[i].p;
            c[i].mdzz=0;
            count++;
             line[i].push(c[i]);
        }
        else{
                if(cmp(c[i],endr)==true){
                c[i].mdzz=cal(start,c[i]);
           c[i].finish=c[i].mdzz+c[i].p;
          // printf("mdzz %d ",c[i].mdzz);
           count++;
                 line[i].push(c[i]);
                }
        }
       // printf("duitou=%d:%d:%d \n",line[i].front().h,line[i].front().m,line[i].front().s);
      // printf("%d %d ",c[i].finish,i);
    }
    int curr=k-1;
    for(int i=0;i<n-k;++i){
            curr++;
            //printf("%d ",wait);
    int first;//the available window
    customer temp,early;
    early=endr;
    for(int i=0;i<k;++i){
        if(!line[i].empty()){
          temp=line[i].front();
         // printf("fgfhh %d %d\n",i,temp.finish);
        }

        if(temp.finish<early.finish){
            early=temp;
            first=i;
           // printf("j1=%d ",first);
        }
    }
    //printf(" first=%d ",first);
    customer last=line[first].front();
    c[curr].mdzz=cal(start,c[curr]);
   // printf("lastfinish %d ",last.finish);
    line[first].pop();
    if(last.finish>9*60*60||c[curr].mdzz>9*60*60){
        break;
    }
    count++;
    int interval=last.finish*60-c[curr].mdzz;
    if(interval>0){
        wait+=interval;
        c[curr].finish=last.finish+c[curr].p;
    }
    else
    c[curr].finish=c[curr].mdzz+c[curr].p;

    line[first].push(c[curr]);
    }
    printf("%.1f\n",wait/60.00/count);
    return 0;
}
