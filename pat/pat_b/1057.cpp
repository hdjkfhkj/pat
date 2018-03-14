/*给定一串长度不超过105的字符串，本题要求你将其中所有英文字母的序号（字母a-z对应序号1-26，不分大小写）相加，得到整数N，然后再分析一下N的二进制表示中有多少0、多少1。例如给定字符串“PAT (Basic)”，其字母序号之和为：16+1+20+2+1+19+9+3=71，而71的二进制是1000111，即有3个0、4个1。

输入格式：

输入在一行中给出长度不超过105、以回车结束的字符串。

输出格式：

在一行中先后输出0的个数和1的个数，其间以空格分隔。

输入样例：
PAT (Basic)
输出样例：
3 4*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
    char c;
    int n=0;
    char a[40];
    for(int i=0;;++i){
        scanf("%c",&c);
        if(c=='\n'){
            break;
        }
        if(c>='a'&&c<='z'||c>='A'&&c<='Z'){

        c=tolower(c);
        n+=(c-'a'+1);
        }
        else{
            continue;
        }
    }
    int i;
   for(i=0;n!=0;++i){
    a[i]=n%2;
    n/=2;
   }
   int count0=0,count1=0;
   //printf("%d",n);
   for(int j=0;j<i;++j){
      //  printf("%c ",a[i]);
    if(a[j]==0)
        count0++;
    else
        count1++;
   }
   //printf("\n");
   printf("%d %d",count0,count1);
   return 0;
}
