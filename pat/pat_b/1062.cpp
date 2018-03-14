/*输入样例：
7/18 13/20 12
输出样例：
5/12 7/12*/
#include <stdio.h>
int compare(int a,int b,int c,int d){
    if(a*d-b*c>0){
        return 1;
    }
    else if(a*d-b*c==0){
        return 0;
    }
    else{
        return -1;
    }
}
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    else
    return a>b?gcd(b,a%b):gcd(b,a);
}
int main(){
    int n1,m1,n2,m2,k;
    scanf("%d/%d %d/%d %d",&n1,&m1,&n2,&m2,&k);
    if(compare(n1,m1,n2,m2)==1){
        int t1,t2;
        t1=n1,t2=m1;;
        n1=n2,m1=m2;
        n2=t1,m2=t2;
    }
    int flag=0;
    for(int i=1;i<k;++i){
        if(gcd(k,i)==1){
            if(compare(n1,m1,i,k)==-1&&compare(i,k,n2,m2)==-1){
                    if(flag==0){
                printf("%d/%d",i,k);
                flag=1;
                    }

            else{
                printf(" %d/%d",i,k);
            }
        }
    }
    }
    return 0;
}
