/*火星人是以13进制计数的：

地球人的0被火星人称为tret。
地球人数字1到12的火星文分别为：jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec。
火星人将进位以后的12个高位数字分别称为：tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou。
例如地球人的数字“29”翻译成火星文就是“hel mar”；而火星文“elo nov”对应地球数字“115”。为了方便交流，请你编写程序实现地球和火星数字之间的互译。

输入格式：

输入第一行给出一个正整数N（<100），随后N行，每行给出一个[0, 169)区间内的数字 —— 或者是地球文，或者是火星文。

输出格式：

对应输入的每一行，在一行中输出翻译后的另一种语言的数字。

输入样例：
4
29
5
elo nov
tam
输出样例：
hel mar
may
115
13*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
char ge[13][5]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
char shi[13][5]={"fd","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
int main(){
    int n;
    scanf("%d",&n);
    char in1[10],in2[10],inn;

    for(int i=0;i<n;++i){
        //scanf("%s",in1)
         scanf("%s%c",in1,&inn);
        if(in1[0]>='0'&&in1[0]<='9'){
            int value=atoi(in1);
            if(value/13){
                printf("%s %s\n",shi[value/13],ge[value%13]);
            }
            else{
                printf("%s\n",ge[value%13]);
            }
        }
        else{
                int flag=0;
                    for(int k=0;k<13;++k){
                        if(strcmp(in1,ge[k])==0){//shi
                            printf("%d\n",k);
                            flag=1;
                          break;
                    }
                    }
                //scanf("%s",in1);
                if(flag==0){
                int count=0;
            for(int j=1;j<13;++j){

                if(strcmp(in1,shi[j])==0){//shi
                    count=j*13;
               // scanf("%s",in2);
               break;
                }
            }
            if(count!=0){
               if(inn==' '){
                    scanf("%s",in2);
                    for(int k=0;k<13;++k){
                        if(strcmp(in2,ge[k])==0){
                                count+=k;
                                break;
                        }
                    }
               }
                    printf("%d\n",count);
            }
        }
        }
    }
    return 0;
}
