/*Sample Input 1:

3
Joe M Math990112 89
Mike M CS991301 100
Mary F EE990830 95
Sample Output 1:
Mary EE990830
Joe Math990112
6
Sample Input 2:
1
Jean M AA980920 60
Sample Output 2:
Absent
Jean AA980920
NA*/
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
struct stu{
    string name;
    char gender;
    string id;
    int grade;
};
int main(){
    int n;
    stu in,hf,lm;
    hf.grade=-1;
    lm.grade=101;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        cin>>in.name>>in.gender>>in.id>>in.grade;
        if(in.gender=='M'){
            if(in.grade<lm.grade){
                lm=in;
            }
        }
        else{
            if(in.grade>hf.grade){
                hf=in;
            }
        }
    }
    int flag=0;
    if(hf.grade==-1){
        printf("Absent\n");
        flag=1;
    }
    else{
        cout<<hf.name<<" "<<hf.id<<endl;
    }
    if(lm.grade==101){
        printf("Absent\n");
        flag=1;
    }
    else{
        cout<<lm.name<<" "<<lm.id<<endl;
    }
    if(flag==1){
        printf("NA");
    }
    else{
        cout<<hf.grade-lm.grade;
    }
    return 0;
}
