/*萌萌哒表情符号通常由“手”、“眼”、“口”三个主要部分组成。简单起见，我们假设一个表情符号是按下列格式输出的：

[左手]([左眼][口][右眼])[右手]
现给出可选用的符号集合，请你按用户的要求输出表情。

输入格式：

输入首先在前三行顺序对应给出手、眼、口的可选符号集。每个符号括在一对方括号[]内。题目保证每个集合都至少有一个符号，并不超过10个符号；每个符号包含1到4个非空字符。

之后一行给出一个正整数K，为用户请求的个数。随后K行，每行给出一个用户的符号选择，顺序为左手、左眼、口、右眼、右手——这里只给出符号在相应集合中的序号（从1开始），数字间以空格分隔。

输出格式：

对每个用户请求，在一行中输出生成的表情。若用户选择的序号不存在，则输出“Are you kidding me? @\/@”。

输入样例：
[╮][╭][o][~\][/~]  [<][>]
 [╯][╰][^][-][=][>][<][@][⊙]
[Д][▽][_][ε][^]  ...
4
1 1 2 2 2
6 8 1 5 5
3 3 4 3 3
2 10 3 9 3
输出样例：
╮(╯▽╰)╭
<(@Д=)/~
o(^ε^)o
Are you kidding me? @\/@
*/
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(){
    string s1,s2,s3;
    //scanf("%s %s %s",s1,s2,s3);
    //cin>>s1>>s2>>s3;
    char s4[15][10],s5[15][10],s6[15][10];
     //scanf("%s %s %s",s1,s2,s3);
     getline(cin,s1);
     getline(cin,s2);
     getline(cin,s3);
     int l1;
    for(int i=0,j=0;s1[i]!='\0';++i){
        if(s1[i]=='['){//meet[
                int k=0;
        for(i=i+1;s1[i]!=']'&&s1[i]!='\0';++i){
            s4[j][k++]=s1[i];

        }
        s4[j][k]='\0';
        ++j;
        }
        l1=j;
    }
int l2;
    for(int i=0,j=0;s2[i]!='\0';++i){
        if(s2[i]=='['){//meet[
                int k=0;
                //++j;
        for(i=i+1;s2[i]!=']'&&s2[i]!='\0';++i){
            s5[j][k++]=s2[i];

        }
         s5[j][k]='\0';
        ++j;
        }
        l2=j;
    }
    int l3;
    for(int i=0,j=0;s3[i]!='\0';++i){
        if(s3[i]=='['){//meet[
                int k=0;
                //j;
        for(i=i+1;s3[i]!=']'&&s3[i]!='\0';++i){
            s6[j][k++]=s3[i];

        }
         s6[j][k]='\0';
        ++j;
        }
        l3=j;
    }
    int a,b,c,d,e;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
         if(a>=1&&a<=l1&&b>=1&&b<=l2&&c>=1&&c<=l3&&d>=1&&d<=l2&&e>=1&&e<=l1){
            printf("%s(%s%s%s)%s\n",s4[a-1],s5[b-1],s6[c-1],s5[d-1],s4[e-1]);
            //for(int i=0;s4[e-1][i]!='\0')
         }
        else{
            printf("Are you kidding me? @\\\/@\n");
            continue;
        }
    }
    return 0;
}
