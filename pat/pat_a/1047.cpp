/*Sample Input:
10 5
ZOE1 2 4 5
ANN0 3 5 2 1
BOB5 5 3 4 2 1 5
JOE4 1 2
JAY9 4 1 2 5 4
FRA8 3 4 2 5
DON2 2 4 5
AMY7 1 5
KAT3 3 5 4 2
LOR6 4 2 4 1 5
Sample Output:
1 4
ANN0
BOB5
JAY9
LOR6
*/

#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
char name[40010][5];
vector<int> s[2510];
bool cmp(int a,int b){
    return strcmp(name[a],name[b])<0;
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;++i){
       // char stu[5];
        int m;
       scanf("%s %d",name[i],&m);
      // cin>>stu>>m;

       for(int j=0;j<m;++j){
        int c;
        scanf("%d",&c);
      //  s[c].push_back(stu);
      s[c].push_back(i);
       }
    }
    for(int i=1;i<=k;++i){
            sort(s[i].begin(),s[i].end(),cmp);
        //cout<<i<<" "<<s[i].size()<<endl;
        printf("%d %d\n",i,s[i].size());
        for(int j=0;j<s[i].size();++j){
        //    cout<<name[s[i][j]]<<endl;
            printf("%s\n",name[s[i][j]]);
        }
    }
    return 0;
}
