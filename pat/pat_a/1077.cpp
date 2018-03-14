/*Sample Input 1:
3
Itai nyan~
Ninjin wa iyadanyan~
uhhh nyan~
Sample Output 1:
nyan~
Sample Input 2:
3
Itai!
Ninjinnwaiyada T_T
T_T
Sample Output 2:
nai*/
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int main(){
    string in,common;
    int n;
    cin>>n;
    //getchar();//用getline为什么不行呢？反正会覆盖掉啊。。。。
    getline(cin,common);
    getline(cin,common);
  //  cout<<common<<endl;
    for(int i=0;i<n-1;++i){
        getline(cin,in);
       // cout<<in<<endl;
        int l1=common.size(),l2=in.size(),l,j1,j2;
        l=(l1>l2)?l2:l1;
        for(j1=l1-1,j2=l2-1;j1>=l1-l&&j2>=l2-l;--j1,--j2){
            if(common[j1]!=in[j2]){
                break;
            }
        }
        common=common.substr(j1+1,l1-j1-1);

    }
    if(common==""){
        cout<<"nai";
    }
    else{
        cout<<common;
    }
    return 0;
}
