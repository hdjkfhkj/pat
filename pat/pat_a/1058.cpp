/*
Sample Input:
3.2.1 10.16.27
Sample Output:
14.1.28*/
#include <stdio.h>
int main(){
    long long int g1,s1,k1,g2,s2,k2;
    scanf("%lld.%lld.%lld %lld.%lld.%lld",&g1,&s1,&k1,&g2,&s2,&k2);
    long long int sum=g1*29*17+s1*29+k1+g2*29*17+s2*29+k2;
    printf("%lld.%lld.%lld",sum/(29*17),sum/29%17,sum%29);
    return 0;
}
