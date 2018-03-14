/*输入例子:
00100 6
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854
66770 7 55667

输出例子:
00100 21 23854
23854 -15 99999
99999 -7 -1
00000 -15 87654
87654 15 -1*/
#include <algorithm>
#include <stdio.h>
#define maxn 100010
using namespace std;
struct node{
    int address;
    int key;
    int next;
    int order;
    int useful;
};
node lnode[maxn];
int hkey[10010]={0};
bool cmp(node a,node b){
    return a.order<b.order;
}
bool cmp1(node a,node b){
    return a.useful>b.useful;
}
int main(){
    int start,n;
    scanf("%d %d",&start,&n);
    for(int i=0;i<n;++i){
        int address;
        scanf("%d",&address);
        scanf("%d %d",&lnode[address].key,&lnode[address].next);
        lnode[address].address=address;
    }
    for(int i=0;i<maxn;++i){
        lnode[i].order=maxn;
        lnode[i].useful=1;
    }
    int order=0,p=start;
    while(p!=-1){
        lnode[p].order=order++;
        p=lnode[p].next;
    }
    sort(lnode,lnode+maxn,cmp);
    int num=0,md=0;
    for(int i=0;i<order;++i){
            int v=abs(lnode[i].key);
        if(hkey[v]==0){
            hkey[v]=1;
        }
        else{
            lnode[i].useful=0;
            num++;
        }
    }
    sort(lnode,lnode+order,cmp1);
    int i;
    for(i=0;i<order-num-1;++i){
        printf("%05d %d %05d\n",lnode[i].address,lnode[i].key,lnode[i+1].address);
    }
    if(order>0)
    printf("%05d %d -1\n",lnode[i].address,lnode[i].key);
    ++i;
    for(;i<order-1;++i){
        printf("%05d %d %05d\n",lnode[i].address,lnode[i].key,lnode[i+1].address);
    }
    if(num>0)
    printf("%05d %d -1\n",lnode[i].address,lnode[i].key);
    return 0;
}
