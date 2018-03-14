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
#include <math.h>
struct Node{
    int data;
    int next;
   // int address;
};
Node node[100010];
int l[100010];
int main(){
    int start,n,k;
    scanf("%d %d %d",&start,&n,&k);
    for(int i=0;i<n;++i){
        int address,data,next;
        scanf("%d %d %d",&address,&data,&next);
        node[address].data=data;
        node[address].next=next;
       // node[address].address=address;
    }
    int countn=0;
    for(int p=start;p!=-1;p=node[p].next){
        l[countn++]=p;
     //   printf("%d %d\n",l[countn-1],countn);
    }
  //  int p=start;
    int g=ceil(n*1.0/k);
    for(int i=0;i<g;++i){
        for(int j=0;j<k;++j){
                int index=l[i*k+j];
                if(i*k+j==n){
                    break;
                }
            if(i<g-1){
                  //   printf("%d %d\n",index,l[i*k+j-1]);
                    if(i<g-2||i==g-2&&n%k==0){
                if(j==0){
                    node[index].next=l[i*j+2*k-1];
                  //  printf("aa%d %d %d\n",node[index].data,node[index].next,node[node[index].next].data);
                }
                else{
                    node[index].next=l[i*k+j-1];
                  //  printf("ss%d %d %d\n",node[index].data,node[index].next,node[node[index].next].data);
               }
                    }
                    else{
                         if(j==0){
                    node[index].next=l[i*j+k];
                }
                else{
                    node[index].next=l[i*k+j-1];
                   // printf("%d %d\n",index,l[i*k+j-1]);
               }
              // printf("cc%d %d %d\n",node[index].data,node[index].next,node[node[index].next].data);
                    }
                    // printf("%d %d %d\n",node[index].data,node[index].next,node[node[index].next].data);
            }
            else if(i==g-1){
                if(n%k==0){
                if(j==0){
                    node[index].next=-1;
                }
                else{
                    node[index].next=l[i*k+j-1];
               }
 //printf("%d %d\n",node[index].data,node[index].next);
 //printf("dd%d %d %d\n",node[index].data,node[index].next,node[node[index].next].data);
            }
            else{
                    // printf("%d %d\n",node[index].data,node[l[i*k+j-1]].data);
                if(i*k+j==n-1){
                    node[index].next=-1;
                }
                else{
                    node[index].next=l[i*k+j+1];
                }
          //printf("%d %d\n",node[index].data,node[index].next);
       //   printf("ee%d %d %d %d\n",node[index].data,node[index].next,node[node[index].next].data,i);
            }
        }
    }
    }
    int b=l[k-1];
    for(int i=0;b!=-1;++i){
            if(i<n-1)
        printf("%05d %d %05d\n",b,node[b].data,node[b].next);
    else{
         printf("%05d %d -1\n",b,node[b].data);
    }
        b=node[b].next;
    }
    return 0;
}
