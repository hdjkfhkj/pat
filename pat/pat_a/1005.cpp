/*Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

Input Specification:

Each input file contains one test case. Each case occupies one line which contains an N (<= 10100).

Output Specification:

For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

Sample Input:
12345
Sample Output:
one five
*/
#include <stdio.h>
char out[10][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int main(){
    char in[110];
    int sum=0;
    scanf("%s",in);
    for(int i=0;in[i]!='\0';++i){
        sum+=in[i]-'0';
    }
    //printf("%d",sum);
    if(sum<10){
        printf("%s",out[sum]);
    }
    else if(sum<100){
        printf("%s %s",out[sum/10],out[sum%10]);
    }
    else{
         printf("%s %s %s",out[sum/100],out[sum/10%10],out[sum%10]);
    }
    return 0;
}
