/*Sample Input:
6
5 2 3 1 5 6
12 2 2 4 1 5 5 6 3 1 1 5 6
Sample Output:
7*/
#include <stdio.h>
int stripe[10010];
int order[210];
int strip[10010];
void init(){
    for(int i=0;i<210;++i){
        order[i]=-1;
    }
}
int main(){
    init();
    int n,m,l;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;++i){
            int md;
        scanf("%d",&md);
        order[md]=i;
    }
    scanf("%d",&l);
    int num=0;
    for(int i=0;i<l;++i){
        scanf("%d",&stripe[i]);
        if(order[stripe[i]]>=0)
        strip[num++]=stripe[i];
    }
  //  printf("bbvvbvb");
    int maxl=0,j,mark=0,sad=1,maxm=0;
    for(int i=0;sad!=0;++i){//最长不减子序列
      //  printf("aaaaaaaaaaa%d %d %d\n",i,sad,mark);
       // mark=sad;
        sad=0;
        j=0;
        maxl=0;
        for(int t=0;t<mark;++t){
            if(order[strip[j]]<=order[strip[t]]&&order[strip[t]]!=-1&&order[strip[t]]<=order[strip[mark]]){
                   //  printf("sssssssssss%d %d %d %d %d\n",j,mark,t,sad,i);
                    j=t;
                maxl++;
            }
            if(order[strip[j]]>order[strip[t]]&&order[strip[t]]!=-1){
                    sad=t;
               //printf("aaaaaaaaaaaaaa %d %d %d %d %d\n",j,mark,t,sad,i);
              //sad=t;
           // mark=t;
        }
           // printf("sdddddd%d \n",t);
        }

        for(int t=mark;t<num;++t){

        if(order[strip[j]]<=order[strip[t]]&&order[strip[t]]!=-1){
           // j=t;
          //  printf("wwwwwwwwwwww%d %d %d %d %d\n",j,mark,t,sad,i);
             j=t;
            maxl++;
        }
        if(order[strip[j]]>order[strip[t]]&&order[strip[t]]!=-1){
           //   printf("gdfdffgdgqqqq %d %d %d %d %d\n",j,mark,t,sad,i);
             // sad=1;
              if(t>sad)
            mark=t;
            else{
                mark=sad;
            }
            sad=t;
        }

       // printf("qqqqqqqqqqq%d \n",t);
        }
        if(maxl>maxm){
            maxm=maxl;
        }
        mark=sad;
    }
    printf("%d",maxm);
    return 0;
}

