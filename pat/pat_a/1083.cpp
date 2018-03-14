/*Sample Input 1:
4
Tom CS000001 59
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
60 100
Sample Output 1:
Mike CS991301
Mary EE990830
Joe Math990112
Sample Input 2:
2
Jean AA980920 60
Ann CS01 80
90 95
Sample Output 2:
NONE*/
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct stu{
    char name[20];
    char id[20];
    int grade;
    bool out;
};
vector<stu> s;
bool cmp(stu a,stu b){
    if(a.out!=b.out){
        return a.out>b.out;
    }
    else{
        return a.grade>b.grade;
    }
}
int main(){
    int n,num=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
            stu c;
            c.out=false;
        scanf("%s %s %d",c.name,c.id,&c.grade);
    s.push_back(c);
    }
    int low,high;
    scanf("%d %d",&low,&high);
    for(int i=0;i<s.size();++i){
        if(s[i].grade>=low&&s[i].grade<=high){
                num++;
            s[i].out=true;
        }
    }
    sort(s.begin(),s.end(),cmp);
    if(num==0){
        printf("NONE");
    }
    else{
        for(int i=0;i<num;++i){
            printf("%s %s\n",s[i].name,s[i].id);
        }
    }
    return 0;
}

