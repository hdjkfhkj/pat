/*输出描述:
For each test case, print in one line the kuchiguse of the character, i.e., the longest common suffix of all N lines. If there is no such suffix, write "nai".

输入例子:
3
Itai nyan~
Ninjin wa iyadanyan~
uhhh nyan~

输出例子:
nyan~*/
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
string common(string s1,string s2){
    int l1=s1.size(),l2=s2.size();
    string s;
    int i,j;
    for(i=l1-1,j=l2-1;i>=0&&j>=0;--i,--j){
        if(s1[i]!=s2[j]){
            break;
        }
    }
    s1.erase(0,i+1);
    s=s1;
    return s;
}
int main(){
    int n;
    cin>>n;
    string s1,s2;
    getchar();
    getline(cin,s1);
    for(int i=0;i<n-1;++i){
        getline(cin,s2);
        s1=common(s1,s2);
       // cout<<s1<<endl;
    }
    if(s1==""){
        cout<<"nai";
    }
    else{
        cout<<s1;
    }
    return 0;
}
