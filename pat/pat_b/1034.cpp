/*本题要求编写程序，计算2个有理数的和、差、积、商。

输入格式：

输入在一行中按照“a1/b1 a2/b2”的格式给出两个分数形式的有理数，其中分子和分母全是整型范围内的整数，负号只可能出现在分子前，分母不为0。

输出格式：

分别在4行中按照“有理数1 运算符 有理数2 = 结果”的格式顺序输出2个有理数的和、差、积、商。注意输出的每个有理数必须是该有理数的最简形式“k a/b”，其中k是整数部分，a/b是最简分数部分；若为负数，则须加括号；若除法分母为0，则输出“Inf”。题目保证正确的输出中没有超过整型范围的整数。

输入样例1：
2/3 -4/2
输出样例1：
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
输入样例2：
5/3 0/6
输出样例2：
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
提交代码*/
#include <stdio.h>
#include <stdlib.h>
int gcd(long a,long b){
    if(a%b==0){
        return b;
    }
    else
        return gcd(b,a%b);
}
void print(long a,long b){
    if(a*b<0){
            a=abs(a);
            b=abs(b);
    if(a>b&&(a%b!=0))
        printf("(-%ld %ld/%ld) ",a/b,a%b/gcd(b,a%b),b/gcd(b,a%b));
    else if(abs(a)%b==0){
        printf("(-%ld) ",a/b);
    }
    else{
            printf("(-%ld/%ld) ",a/gcd(b,a),b/gcd(b,a));
    }
    }
    else{
            a=abs(a);
            b=abs(b);
        if(a>b&&(a%b!=0))
        printf("%ld %ld/%ld ",a/b,a%b/gcd(b,a%b),b/gcd(b,a%b));
    else if(abs(a)%b==0){
        printf("%ld ",a/b);
    }
    else{
            printf("%ld/%ld ",a/gcd(b,a),b/gcd(b,a));
    }
    }
}
void printl(long a,long b){
    if(a*b<0){
            a=abs(a);
            b=abs(b);
    if(a>b&&(a%b!=0))
        printf("(-%ld %ld/%ld)",int(a/b),a%b/gcd(b,a%b),b/gcd(b,a%b));
    else if(abs(a)%b==0){
        printf("(-%ld)",a/b);
    }
    else{
            printf("(-%ld/%ld)",a/gcd(b,a),b/gcd(b,a));
    }
    }
    else{
            a=abs(a);
            b=abs(b);
        if(a>b&&(a%b!=0))
        printf("%ld %ld/%ld",int(a/b),a%b/gcd(b,a%b),b/gcd(b,a%b));
    else if(abs(a)%b==0){
        printf("%ld",a/b);
    }
    else{
            printf("%ld/%ld",a/gcd(b,a),b/gcd(b,a));
    }
    }
}
int main(){
    int a,b,c,d;
    scanf("%d/%d %d/%d",&a,&b,&c,&d);
    //printf("%d/%d %d/%d,a,b,c,d");
    print(a,b);
    printf("+ ");
    print(c,d);
    printf("= ");
    printl(a*d+b*c,b*d);
    printf("\n");
   // scanf("%d/%d %d/%d,&a,&b,&c,&d");
    print(a,b);
    printf("- ");
    print(c,d);
    printf("= ");
    printl(a*d-b*c,b*d);
    printf("\n");
    //scanf("%d/%d %d/%d,&a,&b,&c,&d");
    print(a,b);
    printf("* ");
    print(c,d);
    printf("= ");
    printl(a*c,b*d);
    printf("\n");
    //scanf("%d/%d %d/%d,&a,&b,&c,&d");
    print(a,b);
    printf("/ ");
    print(c,d);
    printf("= ");
    if(c==0)
        printf("Inf");
    else
    printl(a*d,b*c);
    printf("\n");
    return 0;
}
