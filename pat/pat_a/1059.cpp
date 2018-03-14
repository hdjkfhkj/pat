/*Sample Input:
97532468
Sample Output:
97532468=2^2*11*17*101*1291*/
#include <stdio.h>
#include <math.h>
struct factor{
    int p;
    int k;
};
factor book[100];
bool prime(int x){
    if(x<=1){
        return false;
    }
    else{
        for(int i=2;i<=(sqrt(x));++i){
            if(x%i==0){
                return false;
            }
        }
    }
    return true;
}
int main(){
    long long int n,m;
    scanf("%lld",&n);
    m=n;
    int j=0;
    for(int i=2;i<=(sqrt(n));++i){
        if(prime(i)==true){
                if(n%i==0){
                    book[j].p=i;
                    book[j].k=0;
            while(n%i==0){
                book[j].k++;
                n/=i;
            }
            ++j;
        }
    }
    if(n==1){
        break;
    }
    }
    if(n!=1&&n!=0){
        book[j].k=1;
        book[j].p=n;
    }
    printf("%lld=",m);
    if(m!=1){
    for(int i=0;i<=j;++i){
            if(book[i].p!=0)
        printf("%d",book[i].p);
        if(book[i].k>1){
            printf("^%d",book[i].k);
        }
        if(i<j&&book[i+1].p!=0)
        printf("*");
    }
    }
    else{
        printf("1");
    }
    return 0;
}
