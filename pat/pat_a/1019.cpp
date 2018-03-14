/*Sample Input 1:
27 2
Sample Output 1:
Yes
1 1 0 1 1
Sample Input 2:
121 5
Sample Output 2:
No
4 4 1*/
#include <stdio.h>
int itoa(int n,int b,int a[]){
    int len=0;
    for(int i=0;n!=0;++i){
        a[i]=n%b;
        n/=b;
        len++;
       // printf(" %d \n",a[i]);
    }
    return len;
}
bool pa(int a[],int len){
    for(int i=0;i<len;++i){
        if(a[i]!=a[len-1-i]){
            return false;
        }
    }
    return true;
}
int main(){
    int n,b,a[40];
    scanf("%d %d",&n,&b);
    int len=itoa(n,b,a);
    if(pa(a,len)==true){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    for(int i=len-1;i>0;--i){
        printf("%d ",a[i]);
    }
    printf("%d",a[0]);
    return 0;
}
