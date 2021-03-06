/*科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式[+-][1-9]"."[0-9]+E[+-][0-9]+，即数字的整数部分只有1位，小数部分至少有1位，该数字及其指数部分的正负号即使对正数也必定明确给出。

现以科学计数法的格式给出实数A，请编写程序按普通数字表示法输出A，并保证所有有效位都被保留。

输入格式：

每个输入包含1个测试用例，即一个以科学计数法表示的实数A。该数字的存储长度不超过9999字节，且其指数的绝对值不超过9999。

输出格式：

对每个测试用例，在一行中按普通数字表示法输出A，并保证所有有效位都被保留，包括末尾的0。

输入样例1：
+1.23400E-03
输出样例1：
0.00123400
输入样例2：
-1.2E+10
输出样例2：
-12000000000*/
#include <stdio.h>
int main(){
    int e;
    char s[10000];
    int i=0;
    while(~scanf("%c",&s[i])){
        if(s[i]=='E'){
            break;
        }
        ++i;
    }
    scanf("%d",&e);
    if(s[0]=='-'){
        printf("-");
    }
    if(e==0)
        printf("1");
    else if(e<0){
        printf("0.");
        e=-e;
        while(--e){
            printf("0");
        }
        //printf("%d",s[1]);
        for(int j=1;j<i;++j){
                if(s[j]=='.')
                continue;
            printf("%c",s[j]);
        }
    }
    else{
           printf("%d",s[1]-'0');//注意类型
        if(e>=(i-3)){
           // printf("1");
            for(int j=3;j<i;++j){
            printf("%c",s[j]);
        }
        int k=e-(i-3);
        while(k--){
            printf("0");
         }
        }
        else{
            for(int j=0;j<e;++j){
            printf("%c",s[3+j]);
         }
         printf(".");
         for(int j=3+e;j<i;++j){
            printf("%c",s[j]);
        }
        }
    }
   return 0;
}
