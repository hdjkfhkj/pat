/*6 7 HZH
ROM 100
PKN 40
GDN 55
PRS 95
BLN 80
ROM GDN 1
BLN ROM 1
HZH PKN 1
PRS ROM 2
BLN HZH 2
PKN GDN 1
HZH PRS 1*/
#include <map>
#include <iostream>
#include <string>
#include <stack>
#define inf 1000000000
#define maxn 210
using namespace std;
map<string,int> city;
map<int,string> cityno;
int g[maxn][maxn];
int w[maxn];
int lowcost[maxn],vset[maxn];
int path[maxn],sum[maxn],num[maxn],md[maxn],n,l=1;
int change(string c){
    if(city[c]==0){
        city[c]=l;
        cityno[l]=c;
    //    cout<<cityno[l]<<endl;
        l++;
    }
    return city[c];
}
void dijkstra(int s){
    lowcost[s]=0;
   // cout<<s<<endl;
   num[s]=1;//从起点开始并入，所以只用初始化num【s】
    for(int i=1;i<=n;++i){
            int mini=inf,k;
        for(int j=1;j<=n;++j){
            if(vset[j]==0&&lowcost[j]<mini){
                mini=lowcost[j];
                k=j;
            }
        }
        vset[k]=1;
       // cout<<k<<endl;
        for(int j=1;j<=n;++j){
              //  int cost=lowcost[k]+g[k][j];
            if(vset[j]==0&&g[k][j]!=inf){
                int cost=lowcost[k]+g[k][j];
                 //  cout<<g[k][j]<<" "<<k<<" "<<j<<endl;
                if(cost<lowcost[j]){
                    lowcost[j]=cost;
                    path[j]=k;
                   // cout<<"vhbhjhnj"<<endl;
                    sum[j]=sum[k]+w[j];
                    num[j]=num[k];//k所拥有的路径
                    md[j]=md[k]+1;
                }
                else if(cost==lowcost[j]){
                   // cout<<"hgghghh"<<lowcost[j]<<" "<<cost<<endl;
                        num[j]+=num[k];//k所拥有的路径，j可以全部拥有
                    if(sum[k]+w[j]>sum[j]){
                        path[j]=k;
                        sum[j]=sum[k]+w[j];
                        md[j]=md[k]+1;
                    }
                    else{
                        if(md[j]>md[k]+1){
                            md[j]=md[k]+1;
                            path[j]=k;
                        }
                    }
                }
            }
        }
    }
}
int main(){
    int k;
    string start;
    cin>>n>>k>>start;
    for(int i=1;i<=n;++i){//attention!!!!!!!!!!!
          //  cout<<"hgghghhh"<<endl;
        for(int j=1;j<=n;++j){
            g[i][j]=inf;//???9
           // cout<<g[i][j]<<endl;
        }
        lowcost[i]=inf;
        vset[i]=0;
        path[i]=-1;
        sum[i]=0;
        md[i]=0;
        num[i]=0;
        g[i][i]=0;
    }
    int s=change(start);
    for(int i=0;i<n-1;++i){
        cin>>start;
        int id=change(start);
        cin>>w[id];
      //  cout<<start<<" "<<id<<endl;
    }
    for(int i=0;i<k;++i){
            string city1,city2;
    cin>>city1>>city2;
    int id1=change(city1);
    int id2=change(city2);
        cin>>g[id1][id2];
        g[id2][id1]=g[id1][id2];
    }
    dijkstra(s);
    int e=change("ROM"),avg;
    avg=sum[e]/md[e];
   // cout<<e<<" "<<cityno[s]<<" "<<path[e]<<endl;
    cout<<num[e]<<" "<<lowcost[e]<<" "<<sum[e]<<" "<<avg<<endl;
    stack<int> p;
    for(int c=e;path[c]!=-1;c=path[c]){
           // cout<<c<<endl;
        p.push(c);
    }
    cout<<cityno[s];
    while(!p.empty()){
            string c=cityno[p.top()];
    p.pop();
        cout<<"->"<<c;
    }
    return 0;
}
