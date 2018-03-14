/*Sample Input:
5 1 2 4 14 9
3
1 3
2 5
4 1
Sample Output:
3
10
7*/
#include <stdio.h>
#include <algorithm>
using namespace std;
int d[100010],ma[100010]={0};
int main(){
    int n;
    int sum=0;
    scanf("%d",&n);
    ma[1]=0;
    for(int i=1;i<=n;++i){
        scanf("%d",&d[i]);
        sum+=d[i];
        ma[i+1]=ma[i]+d[i];
    }
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;++i){
        int a,b,ans=0;
        scanf("%d %d",&a,&b);
        if(a>b){
            swap(a,b);
        }
        ans=ma[b]-ma[a];
        ans=min(ans,sum-ans);
        printf("%d\n",ans);
    }
    return 0;
}
