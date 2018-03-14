/*Sample Input:

11 3
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3
Sample Output:
5 5 5 2 5 5 5 3 1 3 5*/
#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct mice{
    int r;
    int w;
};
vector<mice> md;
queue<int> match;
int main(){
    int ng,np;
    //double np;
    scanf("%d %d",&np,&ng);
    int mgbz=np;
   // printf("%d %d\n",np,ng);
    for(int i=0;i<np;++i){
            mice mouse;
        scanf("%d",&mouse.w);
    md.push_back(mouse);
      //  printf("%d ",md[i].w);
    }
    int order;
    for(int i=0;i<np;++i){
       scanf("%d",&order);
    //   printf("%d ",order);
      match.push(order);
    }
    int mark;
    for(int i=0;np!=1;++i){
        int group=ceil(np/(ng*1.0));
   //     printf("aaaaaaa%d ",group);
        for(int j=0;j<group;++j){
                int weight=-1;
            for(int s=0;s<ng;++s){
                    if(j*ng+s==np){
                        break;
                    }
                int c=match.front();
                match.pop();
                md[c].r=group+1;
                if(md[c].w>weight){
                    weight=md[c].w;
                    mark=c;
                }
            }
           // printf("oooooo%d\n",mark);
            match.push(mark);
        }
        np=group;
    }
  //  printf("%d",mark);
    md[mark].r=1;
    for(int i=0;i<mgbz;++i){
        if(i<mgbz-1){
            printf("%d ",md[i].r);
        }
        else{
             printf("%d",md[i].r);
        }
    }
    return 0;
}
