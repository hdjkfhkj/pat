/*Sample Input 1:
6 110 1 10
Sample Output 1:
2
Sample Input 2:
1 ab 1 2
Sample Output 2:
Impossible*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
long long inf= (1ll<<63)-1;
long long findr(char b[]){
    long long r=1;
        for(int i=0;b[i]!='\0';++i){//max+1 ½øÖÆ
            if(b[i]-'0'>r){
                r=b[i]-'0';
            }
            else if(b[i]-'a'+10>r){
                r=b[i]-'a'+10;
            }
        }
        //printf("r+1=%d ",r+1);
        return (r+1);
}
long long ten(char a[],long long radix,long long t){
    long long l1=strlen(a);
    long long n1=0;
    for(int i=0;a[i]!='\0';++i){
            if(a[i]>='0'&&a[i]<='9')
                n1+=(a[i]-'0')*pow(radix,l1-i-1);
            else{
                n1+=(a[i]-'a'+10)*pow(radix,l1-i-1);
            }
            if(n1<0||n1>t)
                return -1;
             //printf(" a[i]=%d n1=%d\n",a[i],n1);
        }
        return n1;
}
long long binary(long long n1,char b[],long long low,long long high){
    if(low<=high){
    long long mid=(low+high)/2;
    long long n2=ten(b,mid,inf);
    //printf(" low=%ld high=%ld n1=%ld mid=%ld n2=%ld\n",low,high,n1,mid,n2);
    if(n2<n1){
        binary(n1,b,mid+1,high);
    }
    else if(n1<n2){
        binary(n1,b,low,mid-1);
    }
    else if(n1==n2){
        return mid;
    }
    }
    else{
        return -1;
    }
}
int main(){
    long long high,radix,l1=0,l2=0;
    int tag;
    char a[11],b[11],temp[11];
    long long n1=0,n2=0;
    scanf("%s %s %d %ld",a,b,&tag,&radix);
   // printf("%d ",tag);
    //printf("%s %s\n",a,b);
if(tag==2){//long long 类型比较大小也与int 类型不同？
        //swap(a,b);
        strcpy(temp,a);
        strcpy(a,b);
        strcpy(b,temp);
}
   // printf("%s %s\n",a,b);
    n1=ten(a,radix,inf);
   // printf(" n1=%ld ",n1);
   long long low=findr(b);
   //printf(" low=%ld  ",low);
   if(low>n1){
    high=low+1;
   }
   else{
    high=n1+1;
   }
   // printf(" high=%ld  ",high);
   long long r=binary(n1,b,low,high);
   if(r==-1){
    printf("Impossible");
   }
   else{
    printf("%ld",r);
   }
    return 0;
}
