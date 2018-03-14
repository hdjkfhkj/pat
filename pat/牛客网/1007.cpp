/*输入例子:
630

输出例子:
3
5*6*7*/
#include <stdio.h>
#include <vector>
#include <math.h>
#define maxn pow(2,31)-1
using namespace std;
vector<int> factor;
int countm=0,maxm=0;
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
    int n,l=0,start;
    long long int ans=1;
    scanf("%d",&n);
    for(int i=2;i<=sqrt(n)+1;++i){
           for(int j=i;j<=sqrt(n)+1;++j){
            ans*=j;
            if(n%ans==0){
                l++;
                if(l>maxm){
                    maxm=l;
                    start=i;
                }
            }
            else{
                ans=1;
                    l=0;
                break;
            }
           }
    }
    if(maxm==0){
        printf("1\n");
        printf("%d",n);
    }
    else{
    printf("%d\n%d",maxm,start);
    for(int i=1;i<maxm;++i){
        printf("*%d",start+i);
    }
    }
    return 0;
}
