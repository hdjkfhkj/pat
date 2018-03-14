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
int in[1300][130][80],visited[1300][130][80]={0};
int m,n,l,t;
int sum=0;
int fo[6][3]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
struct node{
    int x,y,z;
};
bool judge(int i,int j,int k){
    if(i>=0&&i<m&&j>=0&&j<n&&k>=0&&k<l){
        return true;
    }
    else{
        return false;
    }
}
int bfs(int i,int j,int k){
    int countm=0;
   // printf("aaaaaaaaaa%d %d %d %d %d %d %d\n",countm,visited[i][j][k],judge(i,j,k),judge(1,1,1),m,n,l);
    if(judge(i,j,k)==true&&visited[i][j][k]==0){
          //   printf("aaaaaaaaaa%d %d\n",countm,in[i][j][k]);
        if(in[i][j][k]==1){
            queue<node> q;
            node a;
            a.x=i;
            a.y=j;
            a.z=k;
            q.push(a);
            while(!q.empty()){
                    node f=q.front();
            q.pop();
            if(judge(f.x,f.y,f.z)==true&&visited[f.x][f.y][f.z]==0&&in[f.x][f.y][f.z]==1){
            countm++;
           // printf("tttttttttttttttaaaaaaaaaa%d\n",countm);
            visited[f.x][f.y][f.z]=1;

                for(int o=0;o<6;++o){
                        node child;
                        child.x=f.x+fo[o][0];
                        child.y=f.y+fo[o][1];
                        child.z=f.z+fo[o][2];
                        if(judge(child.x,child.y,child.z)==true&&visited[child.x][child.y][child.z]==0&&in[child.x][child.y][child.z]==1){
                                q.push(child);
                }
            }
        }
    }
}
}
if(countm>=t){
    return countm;
}
else{
    return 0;
}
}
int main(){
    scanf("%d %d %d %d",&m,&n,&l,&t);
   // printf("cccccccccccccccc%d %d %d\n",m,n,l);
    for(int i=0;i<l;++i){
        for(int j=0;j<m;++j){
            for(int k=0;k<n;++k){
                scanf("%d",&in[j][k][i]);
               // printf("fggghjhjh\n");
            }
        }
    }
    for(int i=0;i<l;++i){
        for(int j=0;j<m;++j){
            for(int k=0;k<n;++k){
                if(visited[j][k][i]==0&&in[j][k][i]==1){
                       // printf("cccccccccccccccc%d %d %d\n",m,n,l);
                    sum+=bfs(j,k,i);
                }
            }
        }
    }
    printf("%d",sum);
    return 0;
}
