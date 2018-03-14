/*Sample Input 1:
11111 22222 9
67890 i 00002
00010 a 12345
00003 g -1
12345 D 67890
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 67890
00001 o 00010
Sample Output 1:
67890
Sample Input 2:
00001 00002 4
00001 a 10001
10001 s -1
00002 a 10002
10002 t -1
Sample Output 2:
-1*/
#include <stdio.h>
struct node{
    int address;
    char data;
    int next;
    int visited;
};
node n[100001];
int main(){
    int start1,start2,m,j,k;
    scanf("%d %d %d",&start1,&start2,&m);
    for(int i=0;i<m;++i){
            int mdzz;
   scanf("%d ",&mdzz);//Í´¿ÞÁ÷Ìé£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡
        scanf("%c %d",&n[mdzz].data,&n[mdzz].next);
      //  printf("sdff %d %d %d\n",mdzz,n[mdzz].next,i);
        n[mdzz].address=mdzz;
        n[mdzz].visited=0;
    }
    int next=start1;
    for(int i=0;i<m;++i){
         //   printf("qqqqqqqqqqqq%d \n",next);
        if(n[next].next!=-1){
                n[next].visited=1;
            next=n[next].next;
        }
        else{
                n[next].visited=1;
            break;
        }
    }
    next=start2;
    int common;
    for(int i=0;i<m;++i){
          //  printf("wwwwwwwwwwwww%d \n",next);
            if(n[next].next!=-1){
        if(n[next].visited==0){
               // n[next].visited=1;

            next=n[next].next;
        }
        else{
            common=n[next].address;
            break;
        }
            }
            else{
                if(n[next].visited==0){
               // n[next].visited=1;
            common=-1;
        }
        else{
            common=n[next].address;

        }
        break;
            }
    }
    if(common!=-1)
    printf("%05d",common);
    else{
        printf("%d",common);
    }
    return 0;
}
