/*To obtain the maximum profit, one must buy W for the 3rd game, T for the 2nd game, and T for the 1st game. If each bet takes 2 yuans, then the maximum profit would be (4.1*3.0*2.5*65%-1)*2 = 37.98 yuans (accurate up to 2 decimal places).

Input

Each input file contains one test case. Each case contains the betting information of 3 games. Each game occupies a line with three distinct odds corr
Sample Input
1.1 2.5 1.7
1.2 3.0 1.6
4.1 1.2 1.1
Sample Output
T T W 37.98*/
#include <stdio.h>
char map[5]={"WTL"};
int ans[5];
int main(){
    double max=0,a,sum=1.0;
    int k;
    for(int j=0;j<3;++j){
            max=0;//////oh my god!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!这道题错的实在是不好意思说出口，太丢人了。。。。。。。。。。。。
    for(int i=0;i<3;++i){
       scanf("%lf",&a);
       if(a>max){
        max=a;
        k=i;
       }
    }
    ans[j]=k;
    sum*=max;
    }
   // sum=(sum*0.65-1)*2;
     //printf("%f ",sum);

    printf("%c %c %c %.2f",map[ans[0]],map[ans[1]],map[ans[2]],(sum*0.65-1)*2);
    return 0;
}
