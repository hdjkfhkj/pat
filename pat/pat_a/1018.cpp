/*Sample Input:
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1

10 4 4 5
4 8 9 0
0 1 1
1 2 1
1 3 2
2 3 1
3 4 1

Sample Output:
3 0->2->3 0*/
#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;
#define inf 100000000
struct road{
    int a,b,w;
};
int n,bike=0,path[510];
int lowcost[510];
    int vset[510];
    int g[510][510];
    int flag;
    int s[510];
    vector<int> v;
void init(){
    for(int i=0;i<n+1;++i){
        for(int j=0;j<n+1;++j){
            g[i][j]=inf;
            //printf("%d \n",g[i][j]);
        }
    }
               // printf("g[4][0]=%d \n",g[0][4]);
    for(int i=0;i<n+1;++i){
        lowcost[i]=inf;
        vset[i]=0;
        path[i]=-1;
       // printf("low=%d i=%d\n",lowcost[i],i);
    }
    lowcost[0]=0;
    //printf("fgbfh");
}
void dijstra(){
    int u=0;
    //printf("hello");
    for(int i=0;i<n+1;++i){
            int mini=inf,k;
           // printf("hello");
        for(int j=0;j<n+1;++j){
                 //printf("gggggggggg%d %d %d %d\n",u,j,g[u][j],lowcost[j]);
            if(vset[j]==0&&lowcost[j]<mini){
                mini=lowcost[j];
               // printf("j=%d low=%d\n",j,lowcost[j]);
                k=j;
            }
        }
        u=k;
        //printf("hello");
       //printf("u=%d mini=%d i=%d low=%d\n",u,mini,i,lowcost[u]);
        vset[u]=1;
        for(int j=0;j<n+1;++j){
               //printf("%d %d %d %d\n",u,j,g[u][j],lowcost[j]);
            if(vset[j]==0&&g[u][j]+lowcost[u]<=lowcost[j]){
                if(g[u][j]+lowcost[u]<lowcost[j]){
                    lowcost[j]=g[u][j]+lowcost[u];
                   // printf("%d %d %d %d\n",u,j,g[u][j],lowcost[j]);
                    path[j]=u;
                }
                else{
                    if(s[u]>s[path[j]]&&flag==0){
                        path[j]=u;
                    }
                    if(s[u]<s[path[j]]&&flag==1){
                        path[j]=u;
                    }
                }
            }
        }
        //printf("u=%d low=%d path=%d",u,lowcost[u],path[u]);
    }

}
int main(){
    int cmax,sp,m;
    stack<int> p;
    scanf("%d %d %d %d",&cmax,&n,&sp,&m);
    int goal=sp;;
    init();
    s[0]=0;
    for(int i=1;i<=n;++i){
        scanf("%d",&s[i]);
       // printf("%d \n",s[i]);
        if(s[goal]==0){
            flag=0;
        }
        if(s[goal]==cmax){
            flag=1;
        }
    }
    for(int i=0;i<m;++i){
            int a,b,w;
        scanf("%d %d %d",&a,&b,&w);
        //printf("%d \n",a,b,w);
    g[a][b]=w;
    g[b][a]=w;
    }
   // printf("g[4][0]=%d",g[0][4]);
    dijstra();
    int bike=0,bike1=0;/*
    if(flag==0){
        bike=0;
    }
    else{
        bike=10;
    }*/
    for(int i=0;path[goal]!=-1;++i){
        p.push(goal);
            goal=path[goal];
    }
    vector<int> mdzz;
    while(!p.empty()){
        mdzz.push_back(p.top());
        p.pop();
    }
    for(int i=0;i<mdzz.size();++i){
        bike+=s[mdzz[i]]-cmax/2;
        if(bike<0){
            v.push_back(bike);
        }
    }
    if(flag==1){
            if(bike<0)
        printf("%d ",-(bike));
        else{
            printf("0 ");
        }
    }
    else{
        int minimum=0;
            for(int i=0;i<v.size();++i){
                if(v[i]<minimum){
                    minimum=v[i];
                }
            }
    bike1=minimum;
            printf("%d ",-minimum);
    }
    printf("0");
    for(int i=0;i<mdzz.size();++i){
        printf("->%d",mdzz[i]);
    }
        if(bike>=0)
        printf(" %d",bike-bike1);
    else
        printf(" 0");
    return 0;
}
