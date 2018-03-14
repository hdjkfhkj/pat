/*
本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，使得A = B * Q + R成立。

输入格式：

输入在1行中依次给出A和B，中间以1空格分隔。

输出格式：

在1行中依次输出Q和R，中间以1空格分隔。

输入样例：
123456789050987654321 7
输出样例：
17636684150141093474 3*/
#include <stdio.h>
int main(){
    char a[1010];
    int b,r=0,i=1,agent=0,q;
    scanf("%s %d",a,&b);
    if((a[0]-'0')>=b){
        q=(a[0]-'0')/b;
        r=(a[0]-'0')%b;
        printf("%d",q);
    }
    else{
        r=a[0]-'0';
        if(a[1]=='\0')//商为零
            printf("0");
    }
    while(a[i]!='\0'){//细节！！！！
            agent=r*10+a[i]-'0';
            q=agent/b;
            r=agent%b;
            printf("%d",q);
        ++i;
    }
    printf(" %d",r);
   // printf("%s %d",q,r);
    return 0;
}
