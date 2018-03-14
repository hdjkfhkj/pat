/*Sample Input 1:
16 15
3 2 1 5 4 6 8 7 16 10 15 11 9 12 14 13
Sample Output 1:
1-5
4-6
7-8
11-11
Sample Input 2:
5 13
2 4 5 7 9
Sample Output 2:
2-4
4-5*/
#include <stdio.h>
int chain[100010]={0},d[100010]={0},p[100010]={0};
int main(){
    int m;
    int n;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%d",&chain[i]);
        if(d[0]<m&&d[0]>=0)
        d[0]+=chain[i];
        if(d[0]>=m){
                d[0]=-d[0];
            p[0]=i+1;
        //printf("mdgb%d",i+1);
        }
    }
    d[0]=-d[0];
    int flag=0;
    for(int i=0;i<n;++i){


        // printf("mmmmm%d-%d %d\n",i+1,p[i],d[i]);
            if(d[i]==m){
                flag=1;
               printf("%d-%d\n",i+1,p[i]);
                d[i+1]=d[i]-chain[i];
                for(int j=p[i];j<=n;++j){
                        if(d[i+1]>=m){
                                p[i+1]=j;
                              //  printf("fvbjkjkjkkj   %d %d %d\n",i+1,p[i],d[i]);
                            break;
                        }
                        else{
                             //   printf("jhhgghgh \n");
                d[i+1]+=chain[j];
                p[i+1]=j+1;
                        }
                }
            }
            else if(d[i]>m){
                d[i+1]=d[i]-chain[i];
                for(int j=p[i];j<=n;++j){
                        if(d[i+1]>=m){
                            p[i+1]=j;
                          //  printf("mdzz              ");
                           //  printf("qqqqqqqqqqqqqqqqqfvbjkjkjkkj   %d %d %d\n",i+1,p[i],d[i]);
                            break;
                        }
                        else{
                              //  printf("vbbhbhbh %d %d %d\n",i+1,p[i],d[i]);
                d[i+1]+=chain[j];
                p[i+1]=j+1;
                        }
                }
            }
    }
    if(flag==0){
        int mini=1000000000;
        for(int i=0;i<n;++i){
            if(d[i]>=m&&d[i]<mini){
                mini=d[i];
            }
        }
        for(int i=0;i<n;++i){
            if(d[i]==mini){
                 printf("%d-%d\n",i+1,p[i]);
            }
        }
    }
    return 0;
}
