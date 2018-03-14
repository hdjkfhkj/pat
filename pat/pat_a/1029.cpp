#include <stdio.h>
#include <algorithm>
using namespace std;
long long s1[1000010],s2[1000010],s[2000020];
int main(){
    int n1,n2;
    scanf("%d",&n1);
    for(int i=0;i<n1;++i){
        scanf("%lld",&s1[i]);
        s[i]=s1[i];
    }
    scanf("%d",&n2);
    int j=n1;
    for(int i=0;i<n2;++i){
        scanf("%lld",&s2[i]);
        s[j++]=s2[i];
    }
   // printf("%d %d ",n1,n2);
    int m=(n1+n2-1)/2,medium=1;
    for(int i=0,j=0,k=0;i<=m;++i){
        //    printf("%d %d ",s1[j],s2[k]);
        if(s1[j]<=s2[k]){
            medium=s1[j];
            j++;
        }
        else{
            medium=s2[k];
            k++;
        }
    }
    sort(s,s+n1+n2);
    printf("%lld",s[m]);
    medium=s[m];
   // printf("%lld",medium);
    return 0;
}
