#include <stdio.h>
int main(){
    char s[100010];
    long long count=0;
    scanf("%s",s);
    int p=0,t=0,j=0,k=0;
    for(int i=0;s[i]!='\0';++i){
        if(s[i]=='P'){
            p++;
        }
        else if(s[i]=='A'){
            j=i+1;
            k=i+1;
            break;
        }
    }
    // printf("%d %d %d %d",j,p,t,k);
    for(;s[j]!='\0';++j){
        if(s[j]=='T'){
            t++;
        }
    }
    if(k!=0){
     count=count%1000000007;
     count+=p*t;
     for(;s[k]!='\0';++k){
        if(s[k]=='P'){
            p++;
        }
        else if(s[k]=='T'){
            t--;
        }
        else{
     count=count%1000000007;
    count+=p*t%1000000007;
        }
     }
    printf("%lld",count);
    }
    else{
         printf("0");
    }
    return 0;
}

