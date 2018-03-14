/*Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4*/
#include <stdio.h>
int main(){
    int a[10010],b[10010],max;
    int k,j=0;
    scanf("%d",&k);
    scanf("%d",&a[0]);
    b[0]=a[0];
    max=b[0];
    for(int i=1;i<k;++i){
        scanf("%d",&a[i]);
        if(b[i-1]>=0){
            b[i]=b[i-1]+a[i];
        }
        else{
            b[i]=a[i];
        }
        if(b[i]>max){
            max=b[i];
            j=i;
        }
      // printf("%d %d ",a[i],max);
    }
    int s;
    for(s=j;s>=0;--s){//oh my god!!!!!!!!!!!!!!!!不给j赋初值也要出问题。。。。
        if(b[s]<0){
            break;
        }
    }
    if(max>0)
    printf("%d %d %d",max,a[s+1],a[j]);
    else if(max<0){
        printf("0 %d %d",a[0],a[k-1]);
    }
    else{
            int i;
        for(i=0;i<k;++i){
            if(a[i]==0){
                break;
            }
        }
        printf("0 %d %d",a[i],a[i]);
    }
    return 0;
}
