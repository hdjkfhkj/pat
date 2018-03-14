/*输入样例：
 输入样例：
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333
输出样例：
5
10000 23333 44444 55555 88888
输出样例：
5
10000 23333 44444 55555 88888*/
#include <stdio.h>
#include <algorithm>
using namespace std;
#define maxn 100010
int cp[maxn]={-1},party[maxn]={-1},present[maxn]={0},dog[maxn];
int main(){
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        int a,b;
        scanf("%d %d",&a,&b);
        cp[a]=b;
        cp[b]=a;
    }
    scanf("%d",&m);
    for(int i=0;i<m;++i){
        int a;
        scanf("%d",&a);
        party[i]=a;
        present[a]=1;
    }
    int countn=0;
    for(int i=0;i<m;++i){
        int a=party[i];
        if(cp[a]==-1){
            dog[countn++]=a;
        }
        else if(present[cp[a]]==0){
             dog[countn++]=a;
        }
    }
    printf("%d\n",countn);
    sort(dog,dog+countn);
    for(int i=0;i<countn;++i){
        if(i==0){
            printf("%05d",dog[i]);
        }
        else{
            printf(" %05d",dog[i]);
        }
    }
    return 0;
}
