/*Sample Input 1:
8 15
1 2 8 7 2 4 11 15
Sample Output 1:
4 11
Sample Input 2:
7 14
1 8 7 2 4 11 15
Sample Output 2:
No Solution*/
#include <stdio.h>
#include <algorithm>
using namespace std;
int in[100010];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%d",&in[i]);
    }
    sort(in,in+n);
    int flag=0;
    for(int i=0,j=n-1;j>i;){
        if(in[i]+in[j]==m){
                flag=1;
            printf("%d %d",in[i],in[j]);
        break;
        }
        else if(in[i]+in[j]>m){
            --j;
        }
        else{
            ++i;
        }
    }
    if(flag==0){
        printf("No Solution");
    }
    return 0;
}
