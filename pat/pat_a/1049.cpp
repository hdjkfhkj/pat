/*Sample Input:
12
Sample Output:
5*/
#include <stdio.h>
#include <math.h>
int ans;
int md2(int n){
    int ans;
    if(n<1){
        ans=0;
    }
    else if(n<10){
        ans=1;
    }
    else{
    if(n/10==1){
            if(n<11){
                ans=2;
            }
            else{
                ans=1+n%10+1+1;
            }
        }
        else{
            ans=ceil(n/10.0)+10;
        }
        return ans;
    }
}
int md3(int n){
    int ans;
    if(n<10){
            if(n>0)
        ans=1;
    else{
        ans=0;
    }
    }
    else if(n<100){
        ans=md2(n);
    }
    else{
            if(n/100==1){
                ans=20+n%100+1+md2(n%100);
            }
            else{
                ans=n/100*20+100+md2(n%100);
            }
            return ans;
}
}
int md4(int n){
int ans;
if(n<10){
    if(n>0)
        ans=1;
    else{
        ans=0;
    }
}
else if(n<100){
    ans=md2(n);
}
else if(n<1000){
    ans=md3(n);
}
else{
if(n/1000==1){
            ans=300+n%1000+1+md3(n%1000);
        }
        else{
            ans=n/1000*300+1000+md3(n%1000);
        }
        return ans;
}
}
int md5(int n){
int ans;
if(n<10){
    if(n>0)
        ans=1;
    else{
        ans=0;
    }
}
else if(n<100){
    ans=md2(n);
}
else if(n<1000){
    ans=md3(n);
}
else if(n<10000){
    ans=md4(n);
}
else{
if(n/10000==1){
            ans=4000+n%10000+1+md4(n%10000);
        }
        else{
            ans=n/10000*4000+10000+md4(n%10000);
        }
        return ans;
}
}
int md6(int n){
int ans;
if(n<10){
    if(n>0)
        ans=1;
    else{
        ans=0;
    }
}
else if(n<100){
    ans=md2(n);
}
else if(n<1000){
    ans=md3(n);
}
else if(n<10000){
    ans=md4(n);
}
else if(n<100000){
    ans=md5(n);
}
else{
if(n/100000==1){
            ans=50000+n%100000+1+md5(n%100000);
        }
        else{
            ans=n/100000*50000+100000+md5(n%100000);
        }
        return ans;
}
}
int md7(int n){
int ans;
if(n<10){
    if(n>0)
        ans=1;
    else{
        ans=0;
    }
}
else if(n<100){
    ans=md2(n);
}
else if(n<1000){
    ans=md3(n);
}
else if(n<10000){
    ans=md4(n);
}
else if(n<100000){
    ans=md5(n);
}
else if(n<1000000){
    ans=md6(n);
}
else{
if(n/1000000==1){
            ans=600000+n%1000000+1+md6(n%1000000);
        }
        else{
            ans=n/1000000*600000+1000000+md6(n%1000000);
        }
        return ans;
}
}
int md8(int n){
int ans;
if(n<10){
    if(n>0)
        ans=1;
    else{
        ans=0;
    }
}
else if(n<100){
    ans=md2(n);
}
else if(n<1000){
    ans=md3(n);
}
else if(n<10000){
    ans=md4(n);
}
else if(n<100000){
    ans=md5(n);
}
else if(n<1000000){
    ans=md6(n);
}
else if(n<10000000){
    ans=md7(n);
}
else{
if(n/10000000==1){
            ans=7000000+n%10000000+1+md7(n%10000000);
        }
        else{
            ans=n/10000000*7000000+10000000+md7(n%10000000);
        }
        return ans;
}
}
int md9(int n){
int ans;
if(n<10){
    if(n>0)
        ans=1;
    else{
        ans=0;
    }
}
else if(n<100){
    ans=md2(n);
}
else if(n<1000){
    ans=md3(n);
}
else if(n<10000){
    ans=md4(n);
}
else if(n<100000){
    ans=md5(n);
}
else if(n<1000000){
    ans=md6(n);
}
else if(n<10000000){
    ans=md7(n);
}
else if(n<100000000){
    ans=md8(n);
}
else{
if(n/100000000==1){
            ans=80000000+n%100000000+1+md8(n%100000000);
        }
        else{
            ans=n/100000000*80000000+100000000+md8(n%100000000);
        }
        return ans;
}
}
int main(){
    int n,ans;
    scanf("%d",&n);
    if(n<10){
        ans=1;
    }
    else if(n<100){
        if(n/10==1){
            if(n<11){
                ans=2;
            }
            else{
                ans=1+n%10+1+1;
            }
        }
        else{
            ans=ceil(n/10.0)+10;
        }
    }
    else if(n<1000){
            if(n/100==1){
                ans=20+n%100+1+md2(n%100);
            }
            else{
                ans=n/100*20+100+md2(n%100);
            }
            }
    else if(n<10000){
        if(n/1000==1){
            ans=300+n%1000+1+md3(n%1000);
        }
        else{
            ans=n/1000*300+1000+md3(n%1000);
        }
    }
    else if(n<100000){
        if(n/10000==1){
            ans=4000+n%10000+1+md4(n%10000);
        }
        else{
            ans=n/10000*4000+10000+md4(n%10000);
        }
    }
    else if(n<1000000){
        if(n/100000==1){
            ans=50000+n%100000+1+md5(n%100000);
        }
        else{
            ans=n/100000*50000+100000+md5(n%100000);
        }
    }
    else if(n<10000000){
        if(n/1000000==1){
            ans=600000+n%1000000+1+md6(n%1000000);
        }
        else{
            ans=n/1000000*600000+1000000+md6(n%1000000);
        }
    }
   else if(n<100000000){
        if(n/10000000==1){
            ans=7000000+n%10000000+1+md7(n%10000000);
        }
        else{
            ans=n/10000000*7000000+10000000+md7(n%10000000);
        }
    }
    else if(n<1000000000){
        if(n/100000000==1){
            ans=80000000+n%100000000+1+md8(n%100000000);
        }
        else{
            ans=n/100000000*80000000+100000000+md8(n%100000000);
        }
    }
    else {
        ans=900000000+n%1000000000+1+md9(n%1000000000);
    }
    printf("%d",ans);
}
