/*Sample Input:
Can1: "Can a can can a can?  It can!"
Sample Output:
can 5*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <map>
#include <algorithm>
using namespace std;
map<string,int> c;
void toup(char &str){
    str=toupper(str);
}
int main(){
    string in,s;
    string temp;
    vector<string> v;
    getline(cin,in);
  //  transform(in.begin(),in.end(),tolower);
    int l=in.size();
    s=in;
    for(int i=0;i<l;++i){
        if(s[i]>='0'&&s[i]<='9'||s[i]>='A'&&s[i]<='Z'||s[i]>='a'&&s[i]<='z'){
                if(s[i]>='A'&&s[i]<='Z'){
                    s[i]+=32;
                }
            temp+=s[i];
        }
        else{
            if(temp!=""){
                v.push_back(temp);
                temp="";
            }
        }
    }
    if(temp!=""){//ghh hj
        v.push_back(temp);
    }
    for(int i=0;i<v.size();++i){
        c[v[i]]++;
     //   printf("%d \n",c[v[i]]);
    }
    int maxw=0;//eeeeeeeeeeeeee
    string out;
    for(map<string,int>::iterator i=c.begin();i!=c.end();++i){
        if(i->second>maxw){
            maxw=i->second;
            out=i->first;
        }
    }
    cout<<out<<" "<<maxw;
    return 0;
}
