/*1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。

现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。
输入格式： 每个测试输入包含1个测试用例。第1行给出一个自然数n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过100，且不包含空格。

输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。

输入样例：
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA*/
#include <stdio.h>
using namespace std;
bool judge(char s[100]){
    int i=0,p1=-1,p2=-1,len=0;
    while(s[i]!='\0'){
        if(s[i]=='A')
            i++;
        else if(s[i]=='P'&&p1==-1)
            p1=i++;
        else if(s[i]='T'&&p2==-1)
            p2=i++;
        else
            return false;
    }
    len=(i-1);
    if((p2-p1)==2){
        if(p1==(len-p2))
            return true;
        else
            return false;
    }
    else if((p2-p1)>2){
        int m=(p2-p1-2);
        while(m--){
            p2--;
            len-=p1;
        }
        if(p1==(len-p2))
            return true;
        else
            return false;
    }
    else
        return false;
}

int main()
{
    int n;
    char s[100];
    scanf("%d",&n);
    while(n--){
        //gets(s);
        scanf("%s",s);
        if(judge(s)){
            printf("答案正确\n");
        }
        else
            printf("答案错误\n");
    }
    return 0;
}
