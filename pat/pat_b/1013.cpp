/*令Pi表示第i个素数。现任给两个正整数M <= N <= 10e4，请输出PM到PN的所有素数。

输入格式：

输入在一行中给出M和N，其间以空格分隔。

输出格式：

输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103*/
#include <stdio.h>
#include <math.h>
int p[10000];
bool isPrime(int n){
    for(int i=2;i<=sqrt(n);++i){
        if(n%i==0)
            return false;
    }
    return true;
}
void prime(){
   // int p[10010];
    p[1]=2;
    for(int i=3,j=2;j<=10000;i+=2){
        if(isPrime(i)){
            p[j++]=i;
        }

    }
}
int main(){
    int m,n,prime,count=0;
   // prime();//为什么不能调用？
    p[1]=2;
    for(int i=3,j=2;j<=10000;i+=2){
        if(isPrime(i)){
            p[j++]=i;
        }

    }
    scanf("%d %d",&m,&n);
    for(int i=m;i<=n;++i){
        if(count%10==0)
         printf("%d",p[i]);
        else if(count%10==9){
            printf(" %d\n",p[i]);
        }
        else{
            printf(" %d",p[i]);
        }
        count++;
    }
    return 0;
}

