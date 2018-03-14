/*Sample Input:
10 3 5 7 2 6 4 9 0 8 1
Sample Output:
9*/
#include <stdio.h>
#include <algorithm>
using namespace std;
int in[100010],po[100010];
int n,countn=0,w=0;
int main(){
    int mark,left=0,k=1;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&in[i]);
        po[in[i]]=i;//牺牲空间换取大量时间
        if(in[i]==0){
            mark=i;
        }
        if(in[i]!=i&&in[i]!=0){//0在换别人的时候把自己也最终换到了正确的位置上
            left++;
        }
      //  printf(" %d ",in[i]);
    }
    while(left>0){
        if(0==in[0]){
            for(int i=k;i<n;++i){
                  //  printf(" %d ",i);
                if(in[i]!=i){
                    k=i;
                    break;
                }
            }
           // in[k]=0;
            in[0]=in[k];
            in[k]=0;
          //  in[k]=0;
            po[0]=k;
            po[in[0]]=0;
            mark=k;
        //   printf("%d %d\n",mark,in[0]);
            k++;
            //left--;
            countn++;
        }
        //for(int i=0;i<n;++i){
       int i= po[mark];
           // if(mark==in[i]){
               //     printf("aaaaa%d %d\n",mark,i);
                in[mark]=mark;
                in[i]=0;
                po[mark]=mark;
                po[0]=i;
                mark=i;
                left--;
                countn++;
            }


    printf("%d",countn);
    return 0;
}
