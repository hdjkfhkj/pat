/*Sample Input:
7 4 20
20 25 25 30
00002 2 12
00007 4 17
00005 1 19
00007 2 25
00005 1 20
00002 2 2
00005 1 15
00001 1 18
00004 3 25
00002 2 25
00005 3 22
00006 4 -1
00001 2 18
00002 1 20
00004 1 15
00002 4 18
00001 3 4
00001 4 2
00005 2 -1
00004 2 0
Sample Output:
1 00002 63 20 25 - 18
2 00005 42 20 0 22 -
2 00007 42 - 25 - 17
2 00001 42 18 18 4 2
5 00004 40 15 0 25 -*/
#include <stdio.h>
#include <algorithm>
using namespace std;
struct user{
    int id;
    int p[10];
    int r,total,q;
    int valid;
};
int pf[10];
user u[10010];
int n,k;
void init(){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=k;++j){
            u[i].p[j]=-2;
            u[i].q=0;
            u[i].total=0;
            u[i].valid=0;
        }
    }
}
bool cmp(user a,user b){
    if(a.valid!=b.valid){
            return a.valid>b.valid;
    }
    else{
    if(a.total!=b.total){
        return a.total>b.total;
    }
    else{
        if(a.q!=b.q){
            return a.q>b.q;
        }
        else{
            return a.id<b.id;
        }
    }
    }
}
int main(){
    int m;
    scanf("%d %d %d",&n,&k,&m);
    init();
    for(int i=1;i<=k;++i){
        scanf("%d",&pf[i]);
    }
    for(int i=0;i<m;++i){
        int id,problem,score;
        scanf("%d %d %d",&id,&problem,&score);
        u[id].id=id;
        if(score>u[id].p[problem]){
            u[id].p[problem]=score;
        }
    }
    for(int i=1;i<=n;++i){
            for(int j=1;j<=k;++j){
                if(u[i].p[j]==pf[j]){
                    u[i].q++;
                }
                //u[i].total+=u[i].p[j];
                if(u[i].p[j]>=0){
                    u[i].valid=1;
                    u[i].total+=u[i].p[j];
                }
            }
    }
    sort(u+1,u+n+1,cmp);
 //   u[0].r=0;
    for(int i=1;i<=n;++i){
        if(u[i].valid==1){
            if(u[i].total==u[i-1].total&&i>1){
                u[i].r=u[i-1].r;
            }
            else{
                u[i].r=i;
            }
            printf("%d %05d %d",u[i].r,u[i].id,u[i].total);
            for(int j=1;j<=k;++j){
                if(u[i].p[j]>=-1){
                        if(u[i].p[j]>=0)
                    printf(" %d",u[i].p[j]);
                else{
                    printf(" 0");
                }
                }
                else{
                    printf(" -");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
