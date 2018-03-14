/*输入例子:
11 3
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3

输出例子:
5 5 5 2 5 5 5 3 1 3 5*/
#include <stdio.h>
#include <queue>
#define maxn 1000000000
using namespace std;
struct mice{
    int r;
    int weight;
};
queue<int> q;
int np;
int main(){
    int ng,g;
    scanf("%d %d",&np,&ng);
    mice m[np];
    for(int i=0;i<np;++i){
        scanf("%d",&m[i].weight);
    }
    for(int i=0;i<np;++i){
        int order;
        scanf("%d",&order);
        q.push(order);
    }
    int pc=0,t;
    while(!q.empty()){
            pc++;
            if(pc>20)
                break;
          //  printf("ghhhjhjh %d %d\n",q.size(),g);
            t=q.size();
            if(q.size()%ng==0){
        g=q.size()/ng;
    }
    else{
        g=q.size()/ng+1;
    }
    for(int i=0;i<g;++i){
            int maxm=-1,mark;

        for(int j=0;j<ng&&i*ng+j<t;++j){//attention to the cycle
            int f=q.front();
            q.pop();
          //  printf("%d %d\n",m[f].weight,q.size());
            m[f].r=g+1;
            if(m[f].weight>maxm){
                maxm=m[f].weight;
                mark=f;
            }
        }
        m[mark].r=g;
        q.push(mark);
       // printf("%d\n",m[mark].weight);
    }
    if(q.size()==1){
            break;
        }
    }
    for(int i=0;i<np;++i){
        if(i<np-1){
            printf("%d ",m[i].r);
        }
        else{
            printf("%d",m[i].r);
        }
    }
    return 0;
}
