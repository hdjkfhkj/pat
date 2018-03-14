/*Sample Input 1:
67 3
Sample Output 1:
484
2
Sample Input 2:
69 3
Sample Output 2:
1353
3*/
#include <stdio.h>
#include <string.h>
char out[110];
void revers(char a[],char b[]){
    int l=strlen(a);
    for(int i=0;i<l;++i){
        b[i]=a[l-1-i];
      //  printf("reverse %c ",b[i]);
    }
    b[l]='\0';//不加结束符的恶果！！！！！！！！！！！！！！！！！！！！！！！！！！！
  //  printf("\n");
}
bool isp(char a[]){/*
    int i=strlen(a);
    for(int j=0;j<i;++j){
        if(a[j]!=a[i-1-j]){
            return false;
        }
    }
    return true;*/
    char b[110];
    revers(a,b);
    if(strcmp(a,b)==0){
        return true;
    }
    else {
        return false;
    }
}
/*void init(char c[],int n){
    for(int i=0;i<n;++i){
        c[i]='0';
    }
}*/
void add(char a[],char b[],char c[]){
    int l=strlen(a);
    //init(c,l+1);
    int carry=0;
    for(int i=l-1;i>=0;--i){
        int curr=a[i]-'0'+b[i]-'0'+carry;
        c[i+1]=curr%10+'0';
        carry=curr/10;
       // printf("out=%c",c[i+1]);
    }
   // printf("\n");
   c[l+1]='\0';
    if(carry!=0){
        c[0]=carry+'0';
         // printf("out=%c\n",c[0]);
    }
    else{
        for(int i=1;i<=l+1;++i){
            c[i-1]=c[i];
            // printf("out=%c",c[i-1]);
        }
      //   printf("\n");
    }
}
void duplicate(char in[],char out[]){
    int l=strlen(in);
    for(int i=0;i<l;++i){
        out[i]=in[i];
    }
    out[l]='\0';
}
int main(){
    char in[110],r[110];
    int k,counts=0,flag=0;
    scanf("%s %d",in,&k);
    duplicate(in,out);
    for(int i=0;i<k;++i){
        if(isp(out)==true){
                flag=1;
            printf("%s\n",out);
            printf("%d",counts);
            break;
        }
        else{
            counts++;
            revers(in,r);
           // printf("in %s\n",in);
           // printf("r %s\n",r);
            add(in,r,out);
            duplicate(out,in);
            //printf("bhjhjj\n");
            // printf("%s %s",r,out);
           // printf("%d \n",counts);
        }
    }
    if(flag==0){
        printf("%s\n",out);
        printf("%d",k);
    }
    return 0;
}
