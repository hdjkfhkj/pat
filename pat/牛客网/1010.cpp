/*Sample Input:
9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42
Sample Output:
58 25 82 11 38 67 45 73 42*/
#include <stdio.h>
#include <algorithm>
#include <queue>
#define maxn 110
using namespace std;
struct node{
    int lchild,rchild,data,id;
};
node t[maxn];
int n;
int ino[maxn],num=0,d[maxn];
void in(int root){
    if(root==-1){
        return;
    }
    in(t[root].lchild);
    ino[num++]=t[root].id;
    in(t[root].rchild);
}
void bfs(int root){
    queue<int> q;
    q.push(root);
    int number=0;
    while(!q.empty()){
        int f=q.front();
        q.pop();
        number++;
        if(number<n){
            printf("%d ",t[f].data);
        }
        else
        printf("%d",t[f].data);
        if(t[f].lchild!=-1){
            q.push(t[f].lchild);
        }
        if(t[f].rchild!=-1){
            q.push(t[f].rchild);
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d %d",&t[i].lchild,&t[i].rchild);
        t[i].id=i;
    }
    for(int i=0;i<n;++i){
        scanf("%d",&d[i]);
    }
    int root=0;
    in(root);
    sort(d,d+n);
    for(int i=0;i<n;++i){
            t[ino[i]].data=d[i];
    }
    bfs(root);
    return 0;
}

