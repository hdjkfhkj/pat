/*Sample Input:
73 10
23 2
23 10
-2
Sample Output:
Yes
Yes
No*/
#include <stdio.h>
#include <math.h>
bool prime(int n){
    if(n<=1){
        return false;
    }
    for(int i=2;i<sqrt(n);++i){
        if(n%i==0)
            return false;
    }
    return true;
}
int itoa(int n,int d,int s[]){
    int l=0;
    for(int i=0;n!=0;++i){
        s[i]=n%d;
        n/=d;
        l++;
      //  printf("%d ",s[i]);
    }
    return l;
}
int rever(int s[],int d,int l){
    int re=0;
    for(int i=0;i<l;++i){
        re=re*d+s[i];
    }
   // printf("%d ",re);
    return re;
}
int main(){
    int n,d,l=0;
    int s[40];
    for(int i=0;;++i){
        scanf("%d",&n);
        if(n<0)
            break;
        scanf("%d",&d);
        if(prime(n)){
        l=itoa(n,d,s);
        int re=rever(s,d,l);
        if(prime(re)){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}
