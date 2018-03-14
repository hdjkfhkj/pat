/*Sample Input:
5 32 321 3214 0229 87
Sample Output:
22932132143287*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string in[10010];
bool cmp(string a,string b){/*
    int la=a.size();
    int lb=b.size();
    for(int i=0;i<la&&i<lb;++i){
        if(a[i]!=b[i]){
            return a[i]<b[i];
        }
    }
    if(la==lb){
        return true;
    }
    else{
    a=a+b;
    b=b+a;
    return cmp(a,b);
    }*/
    return a+b<b+a;//集合的互异性
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>in[i];
    }
    sort(in,in+n,cmp);
    string ans;//string初始时就是空串
    for(int i=0;i<n;++i){
        ans+=in[i];
    }
    int l=ans.size();
    int i;

    while(ans.size()>0&&ans[0]=='0')
        ans.erase(ans.begin());
    if(ans.size()==0){
        cout<<0;
    }
    else{
        cout<<ans;
    }
    return 0;
}
