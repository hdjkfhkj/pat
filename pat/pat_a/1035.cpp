/*Sample Input 1:

3
Team000002 Rlsp0dfa
Team000003 perfectpwd
Team000001 R1spOdfa
Sample Output 1:
2
Team000002 RLsp%dfa
Team000001 R@spodfa
Sample Input 2:
1
team110 abcdefg332
Sample Output 2:
There is 1 account and no account is modified
Sample Input 3:
2
team110 abcdefg222
team220 abcdefg333
Sample Output 3:
There are 2 accounts and no account is modified*/
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
struct account{
    string username;
    string password;
    int modified;
};
account a[1010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        cin>>a[i].username>>a[i].password;
        a[i].modified=0;
    }
    int m=0;
    for(int i=0;i<n;++i){
            int flag=0;
        int l=a[i].password.size();
        for(int j=0;j<l;++j){
            if(a[i].password[j]=='1'){
                a[i].password[j]='@';
    flag=1;
            }
            else if(a[i].password[j]=='l'){
                a[i].password[j]='L';
                flag=1;
            }
            else if(a[i].password[j]=='0'){
                a[i].password[j]='%';
                flag=1;
            }
            else if(a[i].password[j]=='O'){
                a[i].password[j]='o';
                flag=1;
            }
        }
        if(flag==1){
                a[i].modified=1;
            m++;
        }
    }
    if(m==0){
        if(n==1){
            printf("There is 1 account and no account is modified");
        }
        else{
            printf("There are %d accounts and no account is modified",n);
        }
    }
    else{
        printf("%d\n",m);
        for(int i=0;i<n;++i){
            if(a[i].modified==1){
                cout<<a[i].username<<" "<<a[i].password<<endl;
            }
        }
    }
    return 0;
}
