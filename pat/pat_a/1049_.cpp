#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int left=n,right=0,now,ans=0,weight=1;
    for(int i=0;;++i){
        now=left%10;
        left=left/10;
        if(now==0){
            ans+=left*weight;
        }
        else if(now==1){
            ans+=left*weight+right+1;
        }
        else{
            ans+=(left+1)*weight;
        }
       // weight*=10;
        right=now*weight+right;
        weight*=10;
    if(left==0){
        break;
    }
    }
    printf("%d",ans);
    return 0;
}
