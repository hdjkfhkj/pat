/*Sample Input 1:
8 9
5 9 8 7 2 3 4 1
Sample Output 1:
1 3 5
Sample Input 2:
4 8
7 2 4 3
Sample Output 2:
*/
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int in[10010],ans[10010];
int main(){
    int n,num=0;
    int m,sum=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%d",&in[i]);
        d[i]=in[i];
      //  printf(" %d %d ",in[i],m);
    }
    sort(in,in+n);
    for(int s=0;s<n;++s){
             //printf("q%d %\n",sum,m);
            if(sum==m){
                break;
            }
    for(int i=s;i<n;++i){
            // printf("p%lf %lf\n",sum,m);
    if(sum==m){
         //   printf("fgbbn\n");
                break;
            }
            else{
                sum=0;
                num=0;
    sum=in[s];
 //    printf("t %d\n",sum);
            ans[num++]=in[s];
            }
    for(int j=i+1;j<n;++j){
      //  printf("a %d %d\n",sum,j);
                if(sum<m){
            sum+=in[j];
            ans[num++]=in[j];
        }
        else if(sum==m){
            break;
        }
        else{
                sum=sum-in[j-2]-in[j-1];
                for(int md=j-1;md<n;++md){
                      //    printf("a %d %d\n",sum,md);
                    if(sum+in[md]==m){
                        num-=2;
            ans[num++]=in[md];
            sum+=in[md];
          //   printf("a %d %d\n",sum,md);
            break;
                    }
                    // printf("a %d %d\n",sum,md);
                }
            break;
        }
            }
        }
    }
    if(sum==m)
    for(int i=0;i<num;++i){
            if(i<num-1)
        printf("%d ",ans[i]);
    else{
        printf("%d",ans[i]);
    }
    }
    if(sum!=m){
        printf("No Solution");
    }
    return 0;
}
