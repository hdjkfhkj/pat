#include <stdio.h>
#include <algorithm>
using namespace std;
int stripe;
int order[210];
int strip[10010];
int dp[10010];
void init(){
    for(int i=0;i<210;++i){
        order[i]=-1;
    }
}
int main(){
    init();
    int n,m,l;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;++i){
            int md;
        scanf("%d",&md);
        order[md]=i;
    }
    scanf("%d",&l);
    int num=0;
    for(int i=0;i<l;++i){
        scanf("%d",&stripe);
        if(order[stripe]>=0)
        strip[num++]=order[stripe];
    }
  int maxm=1;
  for(int i=0;i<num;++i){
        dp[i]=1;//定一个，动一个
    for(int j=0;j<i;++j){
        if(strip[j]<=strip[i]&&dp[i]<dp[j]+1){
            dp[i]=dp[j]+1;
        }
    }
    maxm=max(maxm,dp[i]);
  }
    printf("%d",maxm);
    return 0;
}

