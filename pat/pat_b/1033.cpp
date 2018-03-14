/*旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及坏掉的那些键，打出的结果文字会是怎样？

输入格式：

输入在2行中分别给出坏掉的那些键、以及应该输入的文字。其中对应英文字母的坏键以大写给出；每段文字是不超过105个字符的串。可用的字符包括字母[a-z, A-Z]、数字0-9、以及下划线“_”（代表空格）、“,”、“.”、“-”、“+”（代表上档键）。题目保证第2行输入的文字串非空。

注意：如果上档键坏掉了，那么大写的英文字母无法被打出。

输出格式：

在一行中输出能够被打出的结果文字。如果没有一个字符能被打出，则输出空行。

输入样例：
7+IE.
7_This_is_a_test.
输出样例：
_hs_s_a_tst
*/
#include <stdio.h>
int main(){
    char s[100010];
    char w[128];
    int hash[128]={0};
    scanf("%s %s",w,s);//和%c好像不太一样，不用getchar()来吸收换行符
   // getchar();
    //scanf("%s",s);
    for(int i=0;w[i]!='\0';++i){
        hash[w[i]]=1;//wrong
    }
    int c=0;
    for(int i=0;s[i]!='\0';++i){
        if(hash[s[i]]==1){
            continue;
        }
        else {
                if(s[i]>='A'&&s[i]<='Z'){
            if(hash['+']==0){
                printf("%c",s[i]);
                c=1;
            }
            else
                continue;
        }
        else if(s[i]>='a'&&s[i]<='z'){
            if(hash[s[i]-32]==0){
                printf("%c",s[i]);
                c=1;
            }
            else
                continue;
        }
        else{
            printf("%c",s[i]);
            c=1;
        }
    }
    }
    if(c==0)
        printf("\n");
    return 0;
}
