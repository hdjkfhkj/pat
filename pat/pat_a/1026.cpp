/*Sample Input:

Sample Output:
9
08:00:00 08:00:00 0
08:01:30 08:01:30 0
08:02:00 08:02:00 0
08:12:00 08:16:30 5
08:10:00 08:20:00 10
20:50:00 20:50:00 0
20:51:00 20:51:00 0
20:52:00 20:52:00 0
3 3 2
#include <stdio.h>9
20:52:00 10 0
08:00:00 20 0
08:02:00 30 0
20:51:00 10 0
08:10:00 5 0
08:12:00 10 1
20:50:00 10 0
08:01:30 15 1
20:53:00 10 1
3 1
2*/
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
struct player{
    int ah,am,as,atime,sh,sm,ss,st,pt,tag,wt;
    int served;
    int id,qid;
};
struct table{
    int eh,em,es,et;
    int sp;
    int vip;
    int id;
};
table t[110];
player p[10010];
queue<player> vp;
bool cmp1(player a,player b){
    if(a.ah!=b.ah){
        return a.ah<b.ah;
    }
    else{
        if(a.am!=b.am){
            return a.am<b.am;
        }
        else{
            return a.as<b.as;
        }
    }
}
bool cmpt(table a,table b){
    return a.et<b.et;
}
bool cmptd(table a,table b){
    return a.id<b.id;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d:%d:%d %d %d",&p[i].ah,&p[i].am,&p[i].as,&p[i].pt,&p[i].tag);
        p[i].atime=(p[i].ah-8)*3600+p[i].am*60+p[i].as;
        p[i].served=0;
    }
    int k,m;
    scanf("%d %d",&k,&m);
    for(int i=1;i<=k;++i){
        t[i].id=i;
    }
    for(int i=0;i<m;++i){
            int vt;
        scanf("%d",&vt);
        t[vt].vip=1;
    }
    sort(p,p+n,cmp1);
    int j=0;
    for(int i=0;i<n;++i){
        p[i].id=i;
        if(p[i].tag==1){
                p[i].qid=j;
            vp.push(p[i]);
        ++j;
        }
    }
    for(int i=0;i<k;++i){

            t[i+1].sp=1;
        p[i].wt=0;
        p[i].atime=(p[i].ah-8)*3600+p[i].am*60+p[i].as;
        p[i].st=p[i].atime;
       // p[i].served=1;
        player first=vp.front();
        if(cmp1(p[i],first)==0)
            vp.pop();
        p[i].served=1;
        t[i+1].et=p[i].st+p[i].pt*60;
      //  printf("%d %d\n",t[i+1].sp,i+1);
       // printf("%d:%d:%d %d",t[i+1].et/3600+8,t[i+1].et/60%60,t[i+1].et%60,i+1);
       // printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",p[i].ah,p[i].am,p[i].as,p[i].ah,p[i].am,p[i].as,p[i].wt);
        if(p[i].st<13*60*60)
             printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",p[i].ah,p[i].am,p[i].as,p[i].ah,p[i].am,p[i].as,p[i].wt);
            // printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",p[i].ah,p[i].am,p[i].as,8+p[i].st/3600,(p[i].st/60)%60,p[i].st%60,p[i].wt);
        else{
            t[i+1].sp--;
        }
    }
    //sort(t,t+k,cmpt);//按球台结束时间排序
    for(int i=k;i<n;++i){
          //sort(t+1,t+k+1,cmpt);
          int j=1;
          int mine=14*60*60;
          for(int i=1;i<=k;++i){
            if(t[i].et<mine){
                mine=t[i].et;
                j=i;
            }
          }



          //t[j].sp++;
          //printf("%d %d\n",t[j].sp,t[j].id);
            if(t[j].vip==1){
                player first=vp.front();
                if(first.atime<=t[j].et&&first.served==0){
                    first.wt=t[j].et-first.atime;
                    if(first.wt%60>=30){
                        first.wt=first.wt/60+1;
                    }
                    else{
                        first.wt=first.wt/60;
                    }
                    first.st=t[j].et;
                    int mdzz=first.id;
                    p[mdzz].served=1;
                  //  printf("mdzz%d \n",mdzz);
                           // printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",first.ah,first.am,first.as,8+first.st/3600,(first.st/60)%60,first.st%60,first.wt);
                    t[j].et=t[j].et+first.pt*60;
                    vp.pop();
                    t[j].sp++;
                    // printf("%d %d\n",t[j].sp,t[j].id);
if(first.st<13*60*60)
             printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",first.ah,first.am,first.as,8+first.st/3600,(first.st/60)%60,first.st%60,first.wt);
        else{
            t[j].sp--;
        }
                    --i;
                    continue;
                }
            }
if(p[i].served==0){
//printf("p[i].served=%d \n",p[i].served);
            if(p[i].atime<t[j].et){
                p[i].wt=t[j].et-p[i].atime;
                p[i].st=t[j].et;
                t[j].et=t[j].et+p[i].pt*60;
            }
            else{
                p[i].wt=0;
                p[i].st=p[i].atime;
                t[j].et=p[i].atime+p[i].pt*60;
            }
            t[j].sp++;
            p[i].served=1;
            if(p[i].wt%60>=30){
                        p[i].wt=p[i].wt/60+1;
                    }
                    else{
                        p[i].wt=p[i].wt/60;
                    }
                    player first=vp.front();
        if(cmp1(p[i],first)==0)
            vp.pop();
        p[i].served=1;
        // printf("%d %d\n",t[j].sp,t[j].id);
        if(p[i].st<13*60*60)
             printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",p[i].ah,p[i].am,p[i].as,8+p[i].st/3600,(p[i].st/60)%60,p[i].st%60,p[i].wt);
        else{
            t[j].sp--;
        }
        // printf("%d %d\n",t[j].sp,t[j].id);
}
//printf("%d %d\n",t[j].sp,t[j].id);
    }
    sort(t+1,t+k+1,cmptd);
    for(int i=1;i<=k;++i){
        if(i<k){
            printf("%d ",t[i].sp);
        }
        else{
            printf("%d",t[i].sp);
        }
    }
          return 0;
    }


