/*Sample Input:
4 4
10 6 4 15
Sample Output:
0 1 4 -*/
#include <stdio.h>
#include <math.h>
int e[10010]={0};
bool prime(int n){
    if(n<=1){
        return false;
    }
    else{
        for(int i=2;i<=sqrt(n);++i){
            if(n%i==0){
                return false;
            }
        }
    }
    return true;
}
int fun(int n){
    while(prime(n)!=true){
        n++;
    }
    return n;
}
int main(){
    int msize,n;
    scanf("%d %d",&msize,&n);
    msize=fun(msize);
  //  printf("%d\n",msize);
    for(int i=0;i<n;++i){
            int temp;
            scanf("%d",&temp);
            int po=temp%msize,position=-1;
           //  printf("aaaaaaaaa%d\n",po);
            if(e[po]==0){
                position=po;
                e[po]=1;
                // printf("mmmmm%d",position);
            }
            else
            for(int step=1;step<msize;++step){
                po=(temp+step*step)%msize;
                if(e[po]==0){
                        position=po;
                e[po]=1;
                    break;
                }
            }
            if(position==-1){
                printf("-");
            }
            else{
                printf("%d",position);
            }
            if(i<n-1){
                printf(" ");
            }
    }
    return 0;
}
