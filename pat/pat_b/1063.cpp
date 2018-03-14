/*输入样例：
5
0 1
2 0
-1 0
3 3
0 -3
输出样例：
4.24*/
#include <stdio.h>
#include <math.h>
int main(){
    int n;
    scanf("%d",&n);
    double maxmum=0;
    for(int i=0;i<n;++i){
        int a,b;
        scanf("%d %d",&a,&b);
        if(maxmum<a*a+b*b){
            maxmum=a*a+b*b;
        }
    }
    maxmum=sqrt(maxmum);
    printf("%.2f",maxmum);
    return 0;
}
