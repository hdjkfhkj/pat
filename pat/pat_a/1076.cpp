/*Sample Input:
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6
Sample Output:
4
5*/
#include <stdio.h>
#include <vector>
#include <queue>
#define maxn 1010
using namespace std;
vector<int> user[maxn];
int visited[maxn];
int l,n,sum=-1,layer[maxn];
void init(){
    for(int i=1;i<=n;++i){
        visited[i]=0;
        layer[i]=0;
    }
}
void bfs(int v){
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int f=q.front();
        q.pop();
        if(layer[f]<=l){
            sum++;
            visited[f]=1;
         //   printf("%d \n",f);
        }
        else{
            return;
        }
        for(int i=0;i<user[f].size();++i){
            int c=user[f][i];
            if(visited[c]==0&&layer[c]==0){
                    layer[c]=layer[f]+1;
                q.push(c);
              //   printf("%d fans=%d layer=%d %d\n",f,c,layer[c],user[f].size());
            }
        }
    }
}
int main(){
    scanf("%d %d",&n,&l);
    for(int i=1;i<=n;++i){
        int m;
        scanf("%d",&m);
        for(int j=0;j<m;++j){
                int fo;
        scanf("%d",&fo);
            user[fo].push_back(i);
          //  printf("%d %d\n",fo,i);
        }
    }
    int query;
    scanf("%d",&query);
    for(int i=0;i<query;++i){
        int id;
        scanf("%d",&id);
        init();
        layer[id]=0,sum=-1;
        bfs(id);
        printf("%d\n",sum);
    }
    return 0;
}
