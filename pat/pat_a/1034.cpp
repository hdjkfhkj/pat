/*Sample Input 1:
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 1:
2
AAA 3
GGG 3
Sample Input 2:
8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 2:
0*/
#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
struct gang{
    int head,countn;
    int weight;
};
map<string,int> mp;
map<int,string> md;
int g[2010][2010],visited[2010],v[2010],n,countn=0;
int l=1;
gang mdgb[2010];
int head,weight;
bool cmp(gang a,gang b){
    return md[a.head]<md[b.head];
}
void init(){
    for(int i=0;i<n;++i){
        visited[i]=0;
        v[i]=0;
       // m[i].weight=0;
        for(int j=0;j<n;++j){
            g[i][j]=0;
        }
    }
}
int change(string a){
    if(mp[a]==0){
            md[l]=a;
        mp[a]=l++;
        return mp[a];
    }
    else
    return mp[a];
}
void dfs(int i){
    visited[i]=1;
    weight+=v[i];
    countn++;
    if(v[i]>v[head]){
        head=i;
    }
    for(int j=1;j<l;++j){
         if(g[i][j]!=0&&visited[j]==0){
            dfs(j);
         }
    }
}
int main(){
    int k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;++i){
       // scanf("%s %s %d",r[i].a,r[i].b,r[i].weight);
       string a,b;
       int weight;
        cin>>a>>b>>weight;
        int id1=change(a);
        int id2=change(b);
     //  printf("%d %d %d\n",id1,id2,l);
       g[id1][id2]=weight;
       g[id2][id1]=weight;
       v[id1]+=weight;
       v[id2]+=weight;
    }
    int block=0;
    for(int i=1;i<l;++i){
        if(visited[i]==0){
                head=i;
        weight=0;
        countn=0;
           dfs(i);
            if(countn>2&&weight>k*2){
                    mdgb[block].head=head;
                    mdgb[block].weight=weight/2;
                    mdgb[block].countn=countn;
                block++;
            }
        }
    }
    printf("%d\n",block);
    sort(mdgb,mdgb+block,cmp);
    for(int i=0;i<block;++i){
        cout<<md[mdgb[i].head]<<" "<<mdgb[i].countn<<endl;
    }
    return 0;
}
