/*输入例子:
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6

输出例子:
4
5*/
#include <stdio.h>
#include <vector>
#include <queue>
#define maxn 1010
using namespace std;
struct userq{
    int id;
    vector<int> child;
    int layer;
    int v;
};
userq user[maxn];
int n,l;
int visited[maxn];
int countm;
void init(){
    for(int i=1;i<=n;++i){
        user[i].v=0;
        user[i].layer=0;
    }
}
void dfs(int root){
    if(user[root].v==0&&user[root].layer<=l){
            user[root].v=1;
        countm++;
   // printf("aaaaaaaaaa%d %d\n",countm,root);
        for(int i=0;i<user[root].child.size();++i){
            int kid=user[root].child[i];
            user[kid].layer=user[root].layer+1;
            dfs(kid);
        }
    }
}
void bfs(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int f=q.front();
        q.pop();
        if(user[f].v==0&&user[f].layer<=l){
            user[f].v=1;
            countm++;
            //printf("aaaaaaaaaa%d %d %d\n",countm,f,user[f].layer);
            for(int i=0;i<user[f].child.size();++i){
                    if(user[user[f].child[i]].layer==0)
                   user[user[f].child[i]].layer=user[f].layer+1;
          //  printf("aaaaaaaaaa%d %d %d %d\n",countm,user[f].child[i],user[f].layer,user[user[f].child[i]].layer);
                q.push(user[f].child[i]);

            }
        }
    }
}
int main(){
    scanf("%d %d",&n,&l);
    for(int i=1;i<=n;++i){
        int num;
        scanf("%d",&num);
        for(int j=0;j<num;++j){
            int father;
            scanf("%d",&father);
            user[father].child.push_back(i);
        }
    }
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;++i){
            countm=0;
            init();
        int query;
        scanf("%d",&query);
        bfs(query);
        user[i].layer=0;
        printf("%d\n",countm-1);
    }
    return 0;
}
