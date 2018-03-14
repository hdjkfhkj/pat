/*Sample Input:
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
Sample Output:
50.0%
33.3%*/
#include <set>
#include <stdio.h>
#include <iterator>
#include <iostream>
#define maxn 60
using namespace std;
set<int> s[maxn];
void compare(int a,int b){
    int t=s[a].size(),same=0;
    for(set<int>::iterator it=s[b].begin();it!=s[b].end();++it){
        if(s[a].find(*it)!=s[a].end()){
            same++;
        }
        else{
            t++;
        }
    }
    printf("%.1f%c\n",same*100.00/t,37);
   // printf("%\n");
}
int main(){
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&m);
        for(int j=0;j<m;++j){
                int data;
        scanf("%d",&data);
            s[i].insert(data);
        }
    }
    int query;
    scanf("%d",&query);
    for(int i=0;i<query;++i){
        int q1,q2;
        scanf("%d %d",&q1,&q2);
        compare(q1,q2);
    }
    return 0;
}
