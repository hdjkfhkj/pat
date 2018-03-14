/*输入格式：

每个输入包含1个测试用例。每个测试用例分别在2行中先后给出摊主的珠串和小红想做的珠串，两串都不超过1000个珠子。

输出格式：

如果可以买，则在一行中输出“Yes”以及有多少多余的珠子；如果不可以买，则在一行中输出“No”以及缺了多少珠子。其间以1个空格分隔。

输入样例1：
ppRYYGrrYBR2258
YrR8RrY
输出样例1：
Yes 8
输入样例2：
ppRYYGrrYB225
YrR8RrY
输出样例2：
No 2
*/
#include <stdio.h>
int main(){
    char s1[1010],s2[1010];
    int count[128]={0},c=0;
    scanf("%s %s",s1,s2);
    for(int i=0;s1[i]!='\0';++i){
        count[s1[i]]++;
        c++;
    }
    for(int i=0;s2[i]!='\0';++i){
        count[s2[i]]--;
        c--;
    }
    int que=0;
    for(int i=0;i<128;++i){
        if(count[i]<0){
            que+=count[i];
        }
    }
    if(que==0){
        printf("Yes %d",c);
    }
    else{
        printf("No %d",-que);
    }
    return 0;
}
