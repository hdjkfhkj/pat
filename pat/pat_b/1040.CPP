/*输入格式：

输入只有一行，包含一个字符串，长度不超过105，只包含P、A、T三种字母。

输出格式：

在一行中输出给定字符串中包含多少个PAT。由于结果可能比较大，只输出对1000000007取余数的结果。

输入样例：
APPAPT
输出样例：
2*/
#include <stdio.h>
int main(){
    char s[100010];
    int count=0;
    scanf("%s",s);
    for(int i=0;s[i]!='\0';++i){
        if(s[i]=='P'){
            for(int j=i+1;s[j]!='\0';++j){
                if(s[j]=='A'){
                    for(int k=j+1;s[k]!='\0';++k){
                        if(s[k]=='T'){
                                count=count%1000000007;
                            count++;
                        }
                    }
                }
            }
        }
    }
    printf("%d",count);
    return 0;
}
