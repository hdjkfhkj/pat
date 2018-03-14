/*Sample Input:
1234567899
Sample Output:
Yes
2469135798*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int out[30]={0},in[30],dup[30]={15};
char md[30];
void init(int l){
    for(int i=0;i<=l;++i){
        out[i]=0;
        dup[i]=15;
        //printf("%d %d\n",out[i],dup[i]);
    }
}
int main(){
    int l=0;
   //for(;~scanf("%d",&in[l]);++l)/*
   scanf("%s",md);
for(;md[l]!='\0';++l){
    in[l]=md[l]-'0';
   // printf("%dhgdfjhjhjh\n",in[l]);
}
/*
for(;l<=9;++l){
    in[l]=l+1;
}
in[9]=9;*/
init(l);
    //int l=strlen(in);
    for(int i=l-1;i>=0;--i){
       //   printf("hdhh%d \n",in[i]);
            int ans=in[i]*2;
            ans+=out[i+1];
            out[i+1]=ans%10;
            out[i]=ans/10;
            dup[i+1]=out[i+1];
            // printf("hdhh%d ",dup[i+1]);
    }
sort(in,in+l);
sort(dup,dup+l+1);
int flag=0;
for(int i=0;i<l;++i){
    if(in[i]!=dup[i]){
        flag=1;
    }
}
if(flag==0){
    printf("Yes\n");
}
else{
    printf("No\n");
}
if(out[0]!=0){
    printf("%d",out[0]);
}
for(int i=1;i<=l;++i){
    printf("%d",out[i]);
}
return 0;
}
