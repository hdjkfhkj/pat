/*Sample Input 1:
3 12300 12358.9
Sample Output 1:
YES 0.123*10^5
Sample Input 2:
3 120 128
Sample Output 2:
NO 0.120*10^3 0.128*10^3*/
#include <string.h>
#include <stdio.h>
#define maxn 10010
using namespace std;
bool ling(char s[]){
    for(int i=0;s[i]!='\0';++i){
        if(s[i]=='0'||s[i]=='.'){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    char s1[maxn],s2[maxn];
    scanf("%d %s %s",&n,s1,s2);
    char s3[maxn],s4[maxn];
    int e1=0,e2=0;
    int i=0,j=0;
    for(i=0;i<strlen(s1);++i){
         //   printf("aaaaaaaaaaaaaaaaaaaaaaaaa%d %d %c\n",i,j,s1[i]);
        if(s1[i]!='0'){
            break;
        }
    }
  //  printf("fgfgg%d %d\n",j,i);
    if(s1[i]=='.'){//less than 1
         //   printf("ddddddddddddddddddddddddddfgffffh%d %d\n",j,e1);
            ++i;
        for(;s1[i]!='\0';++i){
            if(s1[i]=='0'){
                e1--;
              //   printf("aaaaaaaaaaaaaaaaaaaaaaaafgffffh%d %d\n",j,e1);
            }
            else{
                break;
            }
        }
        for(;s1[i]!='\0';++i){
             //  printf("fgffffh%d %d\n",j,e1);
                if(j<n)
            s3[j++]=s1[i];
        }
    }
    else{//greater than 1
        for(;s1[i]!='\0';++i){
            if(s1[i]!='.'){
                    e1++;
                if(j<n){
                    s3[j++]=s1[i];
                }
              //  printf("ddddddddddddddddddd%d\n",j);
            }
            else{
                break;
            }
        }
        ++i;
        for(;s1[i]!='\0';++i){
            if(j<n){
                s3[j++]=s1[i];
              //  printf("eeeeeeeeeeeeeeeeee%d\n",j);
            }
        }
    }
   // printf("hhhhhhhhhhhhhhhhhhhhhhhhhhh%d\n",j);
    if(j==0){
        e1=0;
        for(int iz=0;iz<n;++iz){
            s3[iz]='0';
        }
      //  printf("fgfgghghghh %s\n",s3);
       //  printf("YES 0.%s*10^%d",s3,e1);
    }
    else{
        if(j<n){
            for(;j<n;++j){
                s3[j]='0';
            }
        }
    }
   // s3[j]='\0';
    strcpy(s1,s2);
j=0;
    for(i=0;s1[i]!='\0';++i){
        if(s1[i]!='0'){
            break;
        }
    }
    if(s1[i]=='.'){//less than 1
            ++i;
        for(;s1[i]!='\0';++i){
            if(s1[i]=='0'){
                e2--;
            }
            else{
                break;
            }
        }
        for(;s1[i]!='\0';++i){
                if(j<n)
            s4[j++]=s1[i];
        }
    }
    else{//greater than 1
        for(;s1[i]!='\0';++i){
            if(s1[i]!='.'){
                    e2++;
                if(j<n){
                    s4[j++]=s1[i];
                }
            }
            else{
                break;
            }
        }
        ++i;
        for(;s1[i]!='\0';++i){
            if(j<n){
                s4[j++]=s1[i];
            }
        }
    }
 //   printf("%d\n",j);
    if(j==0){
        e2=0;
        for(int iz=0;iz<n;++iz){
            s4[iz]='0';
        }
    }
    else{
        if(j<n){
            for(;j<n;++j){
                s4[j]='0';
            }
        }
    }
   // s4[j]='\0';
    // printf(" 0.%s*10^%d\n",s3,e1);
    if(strcmp(s3,s4)==0&&e1==e2){
        printf("YES 0.%s*10^%d",s3,e1);
    }
    else{
        printf("NO 0.%s*10^%d 0.%s*10^%d",s3,e1,s4,e2);
    }
    return 0;
}
