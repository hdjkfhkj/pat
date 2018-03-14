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
#include <stdio.h>
#include <set>
using namespace std;
int n;
set<int> v[51];
int main(){
    int m;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&m);
       // init();
        for(int j=0;j<m;++j){
            int temp;
            scanf("%d",&temp);
            v[i].insert(temp);
            }
        }
       // init();

   // init();
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;++i){
        int s,t;
        scanf("%d %d",&s,&t);
        int same=0,total=v[s].size();
        for(set<int>::iterator it=v[t].begin();it!=v[t].end();++it){
            if(v[s].find(*it)!=v[s].end()){
                same++;
            }
            else{
                total++;
            }
        }
        printf("%.1f%%\n",same*100.00/total);
    }
return 0;
}
