/*keep the rest of the cities connected.
Input

Each input file contains one test case. Each case starts with a line containing 3 numbers N (<1000), M and K, which are the total number of cities, the number of remaining highways, and the number of cities to be checked, respectively. Then M lines follow, each describes a highway by 2 integers, which are the numbers of the cities the highway connects. The cities are numbered from 1 to N.
Sample Input
3 2 3
1 2
1 3
1 2 3
Sample Output
1
0
0*/
#include <stdio.h>
#include <vector>
using namespace std;
int f[1010];
bool v[1010];
int n;
vector<int> g[1010];//two dimension vector
void init(){
    for(int i=1;i<=n;++i){
        f[i]=i;
        v[i]=false;
        printf("fi=%d\n",f[i]);
    }
}
int findf(int x){
    int a=x;
    while(x!=f[x]){
        x=f[x];
    }
    while(a!=f[a]){
        int z=a;
        a=f[z];
        f[z]=x;
    }
    return x;
}
void Union(int a,int b){
    int fa=findf(a);
    int fb=findf(b);
    if(fa!=fb){
        f[fa]=fb;//attention!!!!!
    }
}
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<m;i++){
        int a, b;
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int q=0;q<k;++q){
        int city;
        scanf("%d",&city);
        //init();调用init()为什么没用呢？
       //  printf("fi=%d\n",fi);
       for(int i=1;i<=n;++i){
        f[i]=i;
        v[i]=false;
        //printf("fi=%d\n",f[i]);
    }
        for(int i=1;i<=n;++i){
               //  printf("fi=%d\n",f[i]);
            for(int j=0;j<g[i].size();++j){
                int u=i,v=g[i][j];
                if(u==city||v==city){
                    continue;
                }
                Union(u,v);
            }
        }
        int block=0;
        for(int i=1;i<=n;++i){
                if(i==city)
                continue;
                int fi=findf(i);
                  //printf("fi=%d\n",fi);
            if(v[fi]==false){
                block++;
        // printf("block=%d\n",block);
                v[fi]=true;
            }
        }
        printf("%d\n",block-1);
    }
    return 0;
}
