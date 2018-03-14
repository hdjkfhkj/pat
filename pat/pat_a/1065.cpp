/*Sample Input:
3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0
Sample Output:
Case #1: false
Case #2: true
Case #3: false*/
#include <stdio.h>
int main(){
    long long int a,b,c,h;
    long long int t;
    scanf("%lld",&t);
    for(long long int i=1;i<=t;++i){
        scanf("%lld %lld %lld",&a,&b,&c);
           h=a+b;
           if(a>0&&b>0&&h<=0){
            printf("Case #%lld: true\n",i);
           }
            else if(a<0&&b<0&&h>=0){
                printf("Case #%lld: false\n",i);
            }
           else
            printf("Case #%lld: %s\n",i,h>c?"true":"false");
    }
    return 0;
}
