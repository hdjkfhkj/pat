/*Sample Input:
helloworld!
Sample Output:
h   !
e   d
l   l
lowor*/
#include <stdio.h>
#include <string.h>
using namespace std;
int main(){
    char in[90];
    scanf("%s",in);
    int n=strlen(in);
    int n1=(n+2)/3;
    int n3=n1;
    int n2=n+2-n1-n3;
    for(int i=0;i<n1;++i){


            if(i<n1-1){
                     for(int j=0;j<n2;++j){
                if(j==0){
                    printf("%c",in[i]);
                }
                else if(j==n2-1){
                    printf("%c",in[n-1-i]);
                }
                else{
                    printf(" ");
                }
                     }
                     printf("\n");
            }
            else{
                 for(int j=0;j<n2;++j)
                printf("%c",in[i+j]);
            }
        }

    return 0;
}
