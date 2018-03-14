/*Sample Input:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
Sample Output:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1*/
#include <stdio.h>
#define maxn 100010
int data[maxn],next[maxn],link[maxn],result[maxn];
int main(){
    int start,n,k;
    scanf("%d %d %d",&start,&n,&k);
    for(int i=0;i<n;++i){
        int address;
        scanf("%d",&address);
        scanf("%d %d",&data[address],&next[address]);
    }
    int sum=0;
    for(int p=start;p!=-1;p=next[p]){
        link[sum++]=p;
    }
    for(int i=0;i<sum-sum%k;++i){
        result[i]=link[i/k*k+k-1-i%k];
    }
    for(int i=sum-sum%k;i<sum;++i){
        result[i]=link[i];
    }
    for(int i=0;i<sum-1;++i){
        printf("%05d %d %05d\n",result[i],data[result[i]],result[i+1]);
    }
    printf("%05d %d %d\n",result[sum-1],data[result[sum-1]],-1);
    return 0;
}
