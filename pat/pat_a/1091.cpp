/*Sample Input:
3 4 5 2
1 1 1 1
1 1 1 1
1 1 1 1
0 0 1 1
0 0 1 1
0 0 1 1
1 0 1 1
0 1 0 0
0 0 0 0
1 0 1 1
0 0 0 0
0 0 0 0
0 0 0 1
0 0 0 1
1 0 0 0
Sample Output:
26*/
#include <stdio.h>
#include <queue>
using namespace std;
struct node{
    int x,y,z;
};
int s[1300][130][80]={0};
int x[6]={1,-1,0,0,0,0};
int y[6]={0,0,1,-1,0,0};
int z[6]={0,0,0,0,1,-1};
bool visited[1300][130][80]={0};
int m,n,l,t;
bool judge(node a){
    if(visited[a.x][a.y][a.z]==1||s[a.x][a.y][a.z]==0){
        return false;
    }
    if(a.x<0||a.x>=m||a.y>=n||a.z>=l||a.y<0||a.z<0){
        return false;
    }
    return true;
}
int bfs(int cx,int cy,int cz){
    queue<node> md;
    node c;
    c.x=cx;
    c.y=cy;
    c.z=cz;
    md.push(c);
    int tsize=0;
    visited[cx][cy][cz]=1;
    while(!md.empty()){
        node f=md.front();
        md.pop();
            tsize++;
            //visited[f.x][f.y][f.z]=1;有什么区别吗？
            for(int i=0;i<6;++i){
                    node a;
                a.x=f.x+x[i];
                a.y=f.y+y[i];
                a.z=f.z+z[i];
                if(judge(a)==true){
            md.push(a);
            visited[a.x][a.y][a.z]=1;
                }
            }
    }
   // printf("%d\n",tsize);
    if(tsize>=t){
        return tsize;
    }
    else{
        return 0;
    }
}
int main(){
    scanf("%d%d%d%d",&m,&n,&l,&t);
    for(int i=0;i<l;++i){
        for(int j=0;j<m;++j){
            for(int k=0;k<n;++k){
                scanf("%d",&s[j][k][i]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<l;++i){
        for(int j=0;j<m;++j){
            for(int k=0;k<n;++k){
                if(visited[j][k][i]==0&&s[j][k][i]==1){
                    ans+=bfs(j,k,i);
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}
