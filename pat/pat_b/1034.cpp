/*����Ҫ���д���򣬼���2���������ĺ͡�������̡�

�����ʽ��

������һ���а��ա�a1/b1 a2/b2���ĸ�ʽ��������������ʽ�������������з��Ӻͷ�ĸȫ�����ͷ�Χ�ڵ�����������ֻ���ܳ����ڷ���ǰ����ĸ��Ϊ0��

�����ʽ��

�ֱ���4���а��ա�������1 ����� ������2 = ������ĸ�ʽ˳�����2���������ĺ͡�������̡�ע�������ÿ�������������Ǹ��������������ʽ��k a/b��������k���������֣�a/b�����������֣���Ϊ��������������ţ���������ĸΪ0���������Inf������Ŀ��֤��ȷ�������û�г������ͷ�Χ��������

��������1��
2/3 -4/2
�������1��
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
��������2��
5/3 0/6
�������2��
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
�ύ����*/
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
