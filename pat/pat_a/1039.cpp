/*Sample Input:
11 5
4 7
BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
1 4
ANN0 BOB5 JAY9 LOR6
2 7
ANN0 BOB5 FRA8 JAY9 JOE4 KAT3 LOR6
3 1
BOB5
5 9
AMY7 ANN0 BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
ZOE1 ANN0 BOB5 JOE4 JAY9 FRA8 DON2 AMY7 KAT3 LOR6 NON9
Sample Output:
ZOE1 2 4 5
ANN0 3 1 2 5
BOB5 5 1 2 3 4 5
JOE4 1 2
JAY9 4 1 2 4 5
FRA8 3 2 4 5
DON2 2 4 5
AMY7 1 5
KAT3 3 2 4 5
LOR6 4 1 2 4 5
NON9 0*/
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <iterator>
using namespace std;
map<string,set<int> > mp;//26*26*26+10
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<k;++i){
        int course,m;
        cin>>course>>m;
        for(int j=0;j<m;++j){
            string name;
            cin>>name;
            mp[name].insert(course);
        }
    }
    for(int i=0;i<n;++i){
        string name;
        cin>>name;
        cout<<name<<" "<<mp[name].size();
        set<int>::iterator it=mp[name].begin();
        for(;it!=mp[name].end();++it){
            cout<<" "<<*it;
        }
        cout<<endl;
    }
    return 0;
}
