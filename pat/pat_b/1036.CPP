/*输入格式：

输入在一行中给出正方形边长N（3<=N<=20）和组成正方形边的某种字符C，间隔一个空格。

输出格式：

输出由给定字符C画出的正方形。但是注意到行间距比列间距大，所以为了让结果看上去更像正方形，我们输出的行数实际上是列数的50%（四舍五入取整）。

输入样例：
10 a
输出样例：
aaaaaaaaaa
a        a
a        a
a        a
aaaaaaaaaa*/
#include <stdio.h>
#include <math.h>
int main(){
    int n;
    char c;
    scanf("%d %c",&n,&c);
    for(int i=0;i<n;++i){
        printf("%c",c);
    }
    printf("\n");
    for(int i=1;i<ceil(n/2.0)-1;++i){
        for(int j=0;j<n;++j){
            if(j==0||j==n-1){
                printf("%c",c);
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    for(int i=0;i<n;++i){
        printf("%c",c);
    }
    return 0;
}
