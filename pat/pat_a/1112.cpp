/*Sample Input:
3
caseee1__thiiis_iiisss_a_teeeeeest
Sample Output:
ei
case1__this_isss_a_teest*/
#include <stdio.h>
#include <string.h>
char in[1100];
int out[128];
int flag[128]={0};
void init(){
    for(int i=0;i<128;++i){
        out[i]=-1;
    }
}
int main(){
    init();
    int k,start,endd;
    scanf("%d %s",&k,in);
    for(int i=0;in[i]!='\0';++i){
          // printf("aaaaaaaaaa %c %d\n",in[i-1],out[in[i-1]]);
        if(in[i]!=in[i+1]){
                out[in[i]]=0;
            continue;
        }
        else if(in[i]==in[i+1]&&out[in[i]]!=0){
              // printf("rgffhnmj %d %d\n",i,j);
                int j;
            for(j=i;in[j]!='\0';++j){
                if(in[j]==in[i]){
                    continue;
                }
                else{
                    break;
                }
            }
         //  printf("rgffhnmj %d %d\n",i,j);
        if((j-i)%k==0&&out[in[j-1]]!=0){
            out[in[j-1]]=1;
       /* for(j=i+(j-i+1)/k;j<n;++j){
                in[j]='A'
            }*/
        }
        else{
            out[in[j-1]]=0;
         //  printf("aaaaaaaa %c %d\n",in[j-1],out[in[j-1]]);
        }
        i=j-1;
        }
    }
    for(int i=0;in[i]!='\0';++i){
        if(out[in[i]]==1&&flag[in[i]]==0){
            printf("%c",in[i]);
            flag[in[i]]=1;
        }
    }
    printf("\n");
    for(int i=0;in[i]!='\0';++i){
        if(out[in[i]]==0){
            printf("%c",in[i]);
        }
        else{
            printf("%c",in[i]);
             i=i+k-1;
        }
    }
    return 0;
}
