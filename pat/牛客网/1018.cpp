/*输入例子:
3.2.1 10.16.27

输出例子:
14.1.28*/
#include <stdio.h>
int main(){
    long long int a,b,c,d,e,f;
    scanf("%lld.%lld.%lld %lld.%lld.%lld",&a,&b,&c,&d,&e,&f);
    long long int num1=a*17*29+b*29+c;
    long long int num2=d*17*29+e*29+f;
    num1+=num2;
    long long int a1,a2,a3;
    a1=num1/29/17;
    a2=num1/29%17;
    a3=num1%29;
    printf("%lld.%lld.%lld",a1,a2,a3);
    return 0;
}
