/*Sample Input:
Is PAT&TAP symmetric?
Sample Output:
11*/
#include <iostream>
#include <string>
using namespace std;
bool sym(string a){
    for(int i=0;i<a.size();++i){
        if(a[i]!=a[a.size()-1-i]){
            return false;
        }
    }
    return true;
}
int main(){
    string s;
    getline(cin,s);
    int l=s.size();
    int maxl=1;
    for(int i=0;i<l;++i){
        for(int j=l-1;j>=i;--j){
            if(s[j]==s[i]){
                if(sym(s.substr(i,j-i+1))==true){//快三重循环了。。。。。动态规划确实快很多。。。。。。。。。。。。。。。。
                    if(j-i+1>maxl){
                        maxl=j-i+1;
                    }
                   // cout<<s.substr(i,j-i+1)<<" "<<j-i+1<<" "<<i<<" "<<j<<endl;
                    break;
                }
            }
        }
    }
    cout<<maxl;
    return 0;
}
