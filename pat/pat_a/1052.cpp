/*Sample Input:
5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345
Sample Output:
5 12345
12345 -1 00001
00001 0 11111
11111 100 22222
22222 1000 33333
33333 100000 -1*/
#include <algorithm>
#include <stdio.h>
using namespace std;
struct node{
    int address;
    int key;
    int next;
    int flag;
};
node md[100010];
void init(){
    for(int i=0;i<100010;++i){
        md[i].key=1000000;
        md[i].flag=0;
    }
}
bool cmp(node a,node b){
    return a.key<b.key;
}
int main(){
    int n,start;
    scanf("%d %d",&n,&start);
  // printf("%d ",n);
   init();
    for(int i=0;i<n;++i){
        int address,key,next;
scanf("%d %d %d",&address,&key,&next);
md[address].address=address;
md[address].key=key;
md[address].next=next;
    }
    int num=0,address=start;
    while(address!=-1){
            md[address].flag=1;
            num++;
        address=md[address].next;
    }
    sort(md,md+100010,cmp);
    if(num==0){
        printf("0 -1\n");
    }
    else{
    printf("%d %05d\n",num,md[0].address);
    int j=0;
    for(int i=0;i<n;++i){
            if(md[i].flag==1){
            if(j<num-1){

        printf("%05d %d %05d\n",md[i].address,md[i].key,md[i+1].next);
        }
    else{
         printf("%05d %d -1\n",md[i].address,md[i].key);
    }
    ++j;
    }
    }
    }
    return 0;
}
