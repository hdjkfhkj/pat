/*Sample Input:
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
Sample Output:
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
1*/
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
struct node{
    int id;
    int de,cai;
    int total;
};
vector<node> v1,v2,v3,v4;
bool cmp(node a,node b){
    if(a.total!=b.total){
        return a.total>b.total;
    }
    else{
        if(a.de!=b.de){
            return a.de>b.de;
        }
        else{
            return a.id<b.id;
        }
    }
}
int main(){
    int n,l,h;
    scanf("%d %d %d",&n,&l,&h);
    node p;
    int m=0;
    for(int i=0;i<n;++i){
        scanf("%d %d %d",&p.id,&p.de,&p.cai);
        p.total=p.de+p.cai;
        if(p.de>=l&&p.cai>=l){
                ++m;
        if(p.de>=h&&p.cai>=h){
            v1.push_back(p);
        }
        else if(p.de>=h&&p.cai<h){
            v2.push_back(p);
        }
        else if(p.de<h&&p.cai<h&&p.de>=p.cai){
            v3.push_back(p);
        }
        else{
            v4.push_back(p);
        }
        }
    }
    sort(v1.begin(),v1.end(),cmp);
    sort(v2.begin(),v2.end(),cmp);
    sort(v3.begin(),v3.end(),cmp);
    sort(v4.begin(),v4.end(),cmp);
    printf("%d\n",m);
    for(int i=0;i<v1.size();++i){
        printf("%d %d %d\n",v1[i].id,v1[i].de,v1[i].cai);
    }
    for(int i=0;i<v2.size();++i){
        printf("%d %d %d\n",v2[i].id,v2[i].de,v2[i].cai);
    }
    for(int i=0;i<v3.size();++i){
        printf("%d %d %d\n",v3[i].id,v3[i].de,v3[i].cai);
    }
    for(int i=0;i<v4.size();++i){
        printf("%d %d %d\n",v4[i].id,v4[i].de,v4[i].cai);
    }
    return 0;
}
