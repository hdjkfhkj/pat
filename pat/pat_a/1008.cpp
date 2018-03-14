/*Output Specification:

For each test case, print the total time on a single line.

Sample Input:
3 2 3 1
Sample Output:
41*/
#include <stdio.h>
int main(){
    int n,a,b,sum=0;
    scanf("%d",&n);
    b=0;
    for(int i=0;i<n;++i){
        scanf("%d",&a);
        if(a>=b){
            sum+=(a-b)*6+5;
        }
        else if(a<b){
            sum+=(b-a)*4+5;
        }
        b=a;
    }
    printf("%d",sum);
    return 0;
}
