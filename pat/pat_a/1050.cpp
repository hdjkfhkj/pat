/*Output Specification:

For each test case, print S1 - S2 in one line.

Sample Input:
They are students.
aeiou
Sample Output:
Thy r stdnts.*/
#include <iostream>
#include <string>
using namespace std;
int md[128]={0};
int main(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    for(int i=0;i<s2.size();++i){
        if(md[s2[i]]==0){
            md[s2[i]]=1;
        }
    }
    for(int i=0;i<s1.size();++i){
        if(md[s1[i]]==0){
            cout<<s1[i];
        }
    }
    return 0;
}
