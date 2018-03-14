/*Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input

Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.

Output

For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input
-1000000 9
Sample Output
-999,991
是我没有常识。。。。。不会动脑
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    int a,b,c;
    scanf("%d %d",&a,&b);
    char s[10];
    c=a+b;
    sprintf(s,"%d",abs(c));
    if(c<0)
        printf("-");
        int l;
        for(l=0;s[l]!='\0';++l);
    for(int i=0,j=l;s[i]!='\0';++i,--j){
        if(j!=l&&j%3==0){
            printf(",%d",s[i]-'0');
        }
        else{
            printf("%d",s[i]-'0');
        }
    }
    return 0;
}
