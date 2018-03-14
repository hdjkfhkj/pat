/*Sample Input 1:
3 12300 12358.9
Sample Output 1:
YES 0.123*10^5
Sample Input 2:
3 120 128
Sample Output 2:
NO 0.120*10^3 0.128*10^3*/
#include <stdio.h>
#include <string.h>
int main(){
    char s1[11000],s2[11000],s3[11000],s4[11000];
    int n,e1=0,e2=0;
    scanf("%d %s %s",&n,s1,s2);
    int i;
    for(i=0;s1[i]!='\0';++i){
        if(s1[i]=='0'&&s1[i+1]!='.'){
            continue;
        }
        else{
            break;
        }
    }
    int j=0;
    if(s1[i]=='0'&&s1[i+1]=='.'){
            i+=2;
            for(;s1[i]!='\0';++i){
            if(s1[i]=='0'){
                e1--;
            }
            else{
                    break;
            }
            }
            for(;s1[i]!='\0';++i){
                        if(j<n)
                s3[j++]=s1[i];
                }

        }
        else{
                for(;s1[i]!='\0';++i){
            if(s1[i]!='.'){
                e1++;
                if(j<n)
                s3[j++]=s1[i];
            }
            else{
                break;
            }
                }
                ++i;//跳过小数点
                for(;s1[i]!='\0';++i){
                        if(j<n)
                s3[j++]=s1[i];
                }
        }
    s3[j]='\0';
    int i1;
    for(i1=0;s2[i1]!='\0';++i1){
        if(s2[i1]=='0'&&s2[i1+1]!='.'){
            continue;
        }
        else{
            break;
        }
    }
    int j1=0;
    if(s2[i1]=='0'&&s2[i1+1]=='.'){
            i1+=2;
            for(;s2[i1]!='\0';++i1){
            if(s2[i1]=='0'){
                e2--;
            }
            else{
                    break;
            }
            }
            for(;s2[i1]!='\0';++i1){
                        if(j1<n)
                s4[j1++]=s2[i1];
                }
//printf("aaaaaaaaaa%s\n",s4);
        }
        //printf("aaaaaaaaaa%s\n",s4);
        else{
                for(;s2[i1]!='\0';++i1){
            if(s2[i1]!='.'){
                e2++;
                 if(j1<n)
                s4[j1++]=s2[i1];
            }
            else{
                break;
            }
                }
                ++i1;
                for(;s2[i1]!='\0';++i1){
                         if(j1<n)
                s4[j1++]=s2[i1];
                }
        }
    s4[j1]='\0';
   // printf("aaaaaaaaaa%s\n",s4);
   if(j==0){
    e1=0;
    for(int z=0;z<n;++z){
        s3[z]='0';
    }
   }
   if(j1==0){
    e2=0;
    for(int z=0;z<n;++z){
        s4[z]='0';
    }
   }
    if(strcmp(s3,s4)==0&&e1==e2){
        printf("YES 0.%s*10^%d",s3,e1);
    }
    else{
        printf("NO 0.%s*10^%d 0.%s*10^%d %d %d",s3,e1,s4,e2,j,j1);
    }
    return 0;
}
