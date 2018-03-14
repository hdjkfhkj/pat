/*输入例子:
4 4
10 6 4 15

输出例子:
0 1 4 -*/
#include <stdio.h>
#include <math.h>
#define maxn 10010
int d[maxn],ht[maxn]={0};
bool prime(int n){
if(n<2){
    return false;
}
else{
    for(int i=2;i<=sqrt(n);++i){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

}
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    if(prime(m)!=true){
        for(int i=m+1;;++i){
            if(prime(i)==true){
                m=i;
                break;
            }
        }
    }
    for(int i=0;i<n;++i){
        scanf("%d",&d[i]);
        int mode=d[i]%m;
        int flag=0;
        if(ht[mode]==0){
              //  po[i]=mode;
            ht[mode]=1;
            flag=1;
            if(i<n-1){
                printf("%d ",mode);
            }
            else{
                printf("%d",mode);
            }
        }
        else{
            for(int j=1;j<m;++j){
                mode=(d[i]+j*j)%m;
                if(ht[mode]==0){
               // po[i]=mode;
               flag=1;
            ht[mode]=1;
            if(i<n-1){
                printf("%d ",mode);
            }
            else{
                printf("%d",mode);
            }
            break;
        }
            }
            if(flag==0){
                if(i<n-1){
                printf("- ");
            }
            else{
                printf("-");
            }
            }
        }
    }
    return 0;
}
