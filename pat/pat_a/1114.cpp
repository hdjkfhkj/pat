/*Sample Input:
10
6666 5551 5552 1 7777 1 100
1234 5678 9012 1 0002 2 300
8888 -1 -1 0 1 1000
2468 0001 0004 1 2222 1 500
7777 6666 -1 0 2 300
3721 -1 -1 1 2333 2 150
9012 -1 -1 3 1236 1235 1234 1 100
1235 5678 9012 0 1 50
2222 1236 2468 2 6661 6662 1 300
2333 -1 3721 3 6661 6662 6663 1 100
Sample Output:
3
8888 1 1.000 1000.000
0001 15 0.600 100.000
5551 4 0.750 100.000*/
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    int id,sets,area;
    vector<int> adj;
};
struct family{
    int sid,member;
    double avgs,avga;
};
family fa[1010];
node v[10010];
int visited[10010];
int ts=0,ta=0,tm=0;
bool cmp(family a,family b){
    if(a.avga!=b.avga){
        return a.avga>b.avga;
    }
    else{
        return a.sid<b.sid;
    }
}
void init(){
    for(int i=0;i<10010;++i){
        v[i].id=-1;
        visited[i]=0;
        v[i].sets=0;
        v[i].area=0;
    }
}
void dfs(int i){
   // visited[i]=1;
    if(v[i].id!=-1){//valid node
        visited[i]=1;
        tm++;
        ts+=v[i].sets;
        ta+=v[i].area;
    }
    for(int j=0;j<v[i].adj.size();++j){

            if(visited[ v[i].adj[j] ]==0)
        dfs(v[i].adj[j]);
    }

}
int main(){
    int n;
    scanf("%d",&n);
    init();
    for(int i=0;i<n;++i){
        int id,f,m,k,sets,area;
        scanf("%d %d %d %d",&id,&f,&m,&k);
        v[id].id=id;
        if(f!=-1){
             v[id].adj.push_back(f);
              v[f].adj.push_back(id);
              v[f].id=f;
        }
        if(m!=-1){
            v[id].adj.push_back(m);
       // v[f].adj.push_back(id);
        v[m].adj.push_back(id);
        v[m].id=m;
        }
       // v[id].adj.push_back(f);
      //  v[id].adj.push_back(m);
       // v[f].adj.push_back(id);
      //  v[m].adj.push_back(id);
        for(int i=0;i<k;++i){
                int child;
            scanf("%d",&child);
        v[id].adj.push_back(child);
        v[child].adj.push_back(id);
        v[child].id=child;
        }
        scanf("%d %d",&v[id].sets,&v[id].area);
    }
    int block=0;
    for(int i=0;i<10000;++i){
        if(visited[i]==0&&v[i].id!=-1){
                ts=0,ta=0,tm=0;
            dfs(i);
            fa[block].sid=i;
            fa[block].member=tm;
            fa[block].avgs=ts*1.000/tm;
            fa[block].avga=ta*1.000/tm;
            block++;
        }
    }
    sort(fa,fa+block,cmp);
    printf("%d\n",block);
    for(int i=0;i<block;++i){
        printf("%04d %d %.3f %.3f\n",fa[i].sid,fa[i].member,fa[i].avgs,fa[i].avga);
    }
    return 0;
}
