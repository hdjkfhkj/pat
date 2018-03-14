#include <iostream>
#include <string>
using namespace std;
int main(){
 string maxname,maxno,minname,minno,name,no;
 int max=-1,min=101,score;
 int n;
 cin>>n;
 while(n--){
    cin>>name;
    cin>>no;
    cin>>score;
    if(max<score){
        maxname=name;
        maxno=no;
        max=score;
    }
    if(min>score){
        minname=name;
        minno=no;
        min=score;
    }
 }
 cout<<maxname<<" "<<maxno<<endl;
 cout<<minname<<" "<<minno;
 return 0;
}
