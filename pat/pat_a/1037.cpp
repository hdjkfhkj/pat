/*Sample Input:
4
1 2 4 -1
4
7 6 -2 -3
Sample Output:
43*/
#include <stdio.h>
#include <algorithm>
using namespace std;
int c[100010];
int p[100010];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int nc,np;
    scanf("%d",&nc);
    for(int i=0;i<nc;++i){
        scanf("%d",&c[i]);
    }
    scanf("%d",&np);
    for(int i=0;i<np;++i){
        scanf("%d",&p[i]);
    }
    sort(c,c+nc,cmp);
    sort(p,p+np,cmp);
    long long ans=0;
    for(int i=0;c[i]>0&&p[i]>0;++i){
           // if(c[i]>0&&p[i]>0)
        ans+=c[i]*p[i];
    }
    for(int i=nc-1,j=np-1;c[i]<0&&p[j]<0;--i,--j){//駆��珊頁女風泣杏。。。。。。。。。。。。。。。。。。
        ans+=c[i]*p[j];
    }
    printf("%lld\n",ans);
    return 0;
}
