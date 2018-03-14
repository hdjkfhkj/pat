/*Sample Input
2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7
Sample Output
08:07
08:06
08:10
17:00
Sorry*/
#include <stdio.h>
#include <queue>
using namespace std;
queue<int> q[25];
int t[1010],p[1010]={0},n,sum[25]={0};
int minq(){
    int mini=1000000,minq;
    for(int i=0;i<n;++i){
        if(q[i].front()<mini){
            mini=q[i].front();
            minq=i;
        }
    }
    q[minq].pop();
    return minq;
}
int main(){
    int m,k,qu;
    scanf("%d %d %d %d",&n,&m,&k,&qu);//数组和变量不能重名！！！！！！！！！！！！！！！！
    for(int i=1;i<=k;++i){
        scanf("%d",&t[i]);
        if(i<=m*n){//n be assigned to queue 0
                int curr=i%n;
            //q[curr].push_back(i);
            sum[i%n]+=t[i];
            p[i]=sum[i%n];
            q[curr].push(p[i]);
        }
        else{
            int j=minq();//哪一队最短排到哪一队
            //q[j].push_back(i);
            sum[j]+=t[i];
            p[i]=sum[j];
             q[j].push(p[i]);
        }
    }
    for(int i=0;i<qu;++i){
        int query,h,m;
        scanf("%d",&query);
        h=p[query]/60+8;
        m=p[query]%60;
        if(h>=8&&h<17||(h==17&&m==0)){
            printf("%02d:%02d\n",h,m);
        }
        else{
            printf("Sorry\n");
        }
       // printf("%02d:%02d\n",h,m);
    }
    return 0;
}
