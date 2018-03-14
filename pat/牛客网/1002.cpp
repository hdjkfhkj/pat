/*
6 7 HZH
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
HZH PRS 1

Êä³öÀý×Ó:
3 3 195 97
HZH->PRS->ROM*/
#include <map>
#include <string>
#include <iostream>
#include <stack>
#define maxn 210
#define inf 1000000000
using namespace std;
map<string,int> sti;
map<int,string> its;
int l=1,h[maxn],g[maxn][maxn],path[maxn],num[maxn],countm[maxn],dis[maxn],n,seted[maxn],ha[maxn];
int change1(string s){
    if(sti[s]==0){
        sti[s]=l;
        its[l]=s;
        return l++;
    }
    else{
        return sti[s];
    }
}
string change2(int i){
    return its[i];
}
void init(){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            g[i][j]=inf;
        }
        path[i]=-1;
        seted[i]=0;
        num[i]=0;
        dis[i]=inf;
    }
}
void dijkstra(){
    dis[0]=0;
    ha[0]=0;
    h[0]=0;
    for(int i=0;i<n;++i){
        int mini=inf,k;
        for(int j=0;j<n;++j){
              //  printf("%d %d\n",j,dis[j]);
            if(seted[j]==0&&dis[j]<mini){
                mini=dis[j];
                k=j;
            }
        }
        int u=k;
     //   printf("%d \n",u);
        seted[u]=1;
        countm[0]=1;
    //    cout<<u<<"fgbhnhn"<<endl;
        for(int j=0;j<n;++j){
            if(seted[j]==0&&g[u][j]<inf){
                  //  cout<<ha[j]<<" ddfffgdf "<<j<<endl;
                 //   printf("sdffvfgbg%d %d\n",j,g[u][j]);
                if(dis[u]+g[u][j]<dis[j]){
                        countm[j]=countm[u];
                    dis[j]=dis[u]+g[u][j];
                    ha[j]=ha[u]+h[j];
                    num[j]=num[u]+1;
                    path[j]=u;
                  //  cout<<"dffgg"<<u<<" "<<j<<endl;
                }
                else if(dis[u]+g[u][j]==dis[j]){
                    countm[j]=countm[j]+countm[u];
                   //printf("%d %d\n",countm[u],u);
               //     cout<<countm[u]<<" "<<u<<endl;
                    if(ha[u]+h[j]>ha[j]){
                        path[j]=u;
                        ha[j]=ha[u]+h[j];
                        num[j]=num[u]+1;
                    }
                    if(ha[u]==ha[path[j]]){
                        if(num[u]<num[path[j]]){
                            num[j]=num[u]+1;
                            path[j]=u;
                        }
                    }
                }
         //   cout<<ha[j]<<" ddfffgdf "<<j<<endl;
            }
        }
    }
}
int main(){
    int r,happiness;
    string s;
    cin>>n>>r>>s;
    sti[s]=0;
    its[0]=s;
    init();
    for(int i=1;i<=n-1;++i){
        cin>>s>>happiness;
    sti[s]=i;
    its[i]=s;
        h[i]=happiness;
    }
    for(int i=0;i<r;++i){
        string s1,s2;
        int c;
        cin>>s1>>s2>>c;
        int id1=sti[s1];
        int id2=sti[s2];
        g[id1][id2]=c;
        g[id2][id1]=c;
    }
    dijkstra();
    int d=sti["ROM"];
    //printf("%d %d %d %d\n",countm,dis[d],h[d],h[d]/countm);
    cout<<countm[d]<<" "<<dis[d]<<" "<<ha[d]<<" "<<ha[d]/num[d]<<endl;
    stack<int> st;
    for(int p=d;p!=0;p=path[p]){
        st.push(p);
    }
    cout<<its[0];
    while(!st.empty()){
        int cur=st.top();
        cout<<"->"<<its[cur];
        st.pop();
    }
return 0;
}
