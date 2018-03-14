/*输入例子:
97532468

输出例子:
97532468=2^2*11*17*101*1291*/
#include <stdio.h>
#include <math.h>
long long int n;
struct factor{
    long long int v,c;
};
factor f[50000];
bool prime(long long int n){
if(n<2){
    return false;
}
else{
    for(long long int i=2;i<=sqrt(n);++i){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

}
int main(){
    scanf("%lld",&n);
    long long int m=n;
    long long int number=0;
    for(long long int i=2;i<=sqrt(m);++i){
        if(prime(i)==true){
                if(n%i==0){
                     //   printf("%d %d\n",i,number);
                      f[number].v=i;
                    //  printf("%d %d\n",i,number);
            while(n%i==0){
                f[number].c++;
                n/=i;
            }
            number++;
        }
        }
    }
    if(n!=1){
        f[number].v=n;
        f[number++].c=1;
    }
    printf("%lld=",m);
 //  printf("fhgjhhhhh%d\n",number);
 if(m==1){
    printf("%lld",m);
 }
 else
    for(long long int i=0;i<number;++i){
                    if(i<number-1){
        if(f[i].c>1){
            printf("%lld^%lld*",f[i].v,f[i].c);
        }
        else{
            printf("%lld*",f[i].v);
        }
                    }
                    else{

                         if(f[i].c>1){
            printf("%lld^%lld",f[i].v,f[i].c);
        }
        else{
            printf("%lld",f[i].v);
        }
                    }

            }
    return 0;
}
