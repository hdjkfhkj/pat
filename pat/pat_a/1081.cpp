/*Sample Input 1:
5
2/5 4/15 1/30 -2/60 8/3
Sample Output 1:
3 1/3
Sample Input 2:
2
4/3 2/3
Sample Output 2:
2
Sample Input 3:
3
1/3 -1/6 1/8
Sample Output 3:
7/24*/
#include <stdio.h>
#include <stdlib.h>
long long int gcd(long long int a,long long int b){
    a=abs(a),b=abs(b);
        if(b==0){
            return a;
        }
        else
        return gcd(b,a%b);
}
int main(){
    int n;
    long long int fz1,fz2,fm1,fm2;
    scanf("%d",&n);
    fz1=0,fm1=1;
    for(int i=0;i<n;++i){
        scanf("%lld/%lld",&fz2,&fm2);
        long long int fm=gcd(fm1,fm2),c1,c2;
       // fz1=fz1*fm2+fz2*fm1;
        c1=fm2/fm,c2=fm1/fm;
        fm1=fm1/fm;
        fm1=fm1*fm2;
        fz1=fz1*c1+fz2*c2;
       //  printf("%ld %ld\n",fz1,fm1);
         long long int c=gcd(fz1,fm1);
        fz1/=c;
        fm1/=c;
     //  printf("%ld %ld %ld\n",c,fz1,fm1);
    }
    if(fz1%fm1==0)
    printf("%lld\n",fz1/fm1);
    else{
        if(fz1>fm1){
            printf("%lld %lld/%lld\n",fz1/fm1,(fz1%fm1),fm1);
        }
        else{
            printf("%lld/%lld\n",fz1,fm1);
        }
    }
    return 0;
}
