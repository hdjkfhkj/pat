/*输出描述:
For each test case you should output the admission results for all the graduate schools.  The results of each school must occupy a line, which contains the applicants' numbers that school admits.  The numbers must be in increasing order and be separated by a space.  There must be no extra space at the end of each line.  If no applicant is admitted by a school, you must output an empty line correspondingly.

输入例子:
11 6 3
2 1 2 2 2 3
100 100 0 1 2
60 60 2 3 5
100 90 0 3 4
90 100 1 2 0
90 90 5 1 3
80 90 1 0 2
80 80 0 1 2
80 80 0 1 2
80 70 1 3 2
70 80 1 2 3
100 100 0 2 4

输出例子:
0 10
3
5 6 7
2 8

1 4*/
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct student{
    int ge,gi,t;
    vector<int> sch;
    int r;
    int id;
};
struct school{
    int quota;
    vector<int> stu;
    int lr;
};
school sc[110];
student st[40010];
bool cmp(student a,student b){
    if(a.t!=b.t){
        return a.t>b.t;
    }
    else{
        return a.ge>b.ge;
    }
}
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<m;++i){
        scanf("%d",&sc[i].quota);
    }
    for(int i=0;i<n;++i){
        scanf("%d %d",&st[i].ge,&st[i].gi);
        st[i].t=st[i].ge+st[i].gi;
        st[i].id=i;
        for(int j=0;j<k;++j){
                int choice;
            scanf("%d",&choice);
            st[i].sch.push_back(choice);
        }
    }
    sort(st,st+n,cmp);
    st[0].r=1;
    for(int i=0;i<n-1;++i){
        if(st[i].t==st[i+1].t&&st[i].ge==st[i+1].ge){
            st[i+1].r=st[i].r;
        }
        else{
            st[i+1].r=i+2;
        }
       // printf("%d %d %d %d\n",st[i].id,st[i].ge,st[i].gi,st[i].r);
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<st[i].sch.size();++j){
            int goal=st[i].sch[j];
            if(sc[goal].quota>0){
                sc[goal].stu.push_back(st[i].id);
                sc[goal].lr=st[i].r;
                sc[goal].quota--;
                break;
            }
            else{
                if(sc[goal].lr==st[i].r){
                     sc[goal].stu.push_back(st[i].id);
                     break;
                }
            }
        }
    }
    for(int i=0;i<m;++i){
        sort(sc[i].stu.begin(),sc[i].stu.end());
        for(int j=0;j<sc[i].stu.size();++j){
            if(j<sc[i].stu.size()-1){
                printf("%d ",sc[i].stu[j]);
            }
            else{
                 printf("%d",sc[i].stu[j]);
            }
        }
        printf("\n");
    }
    return 0;
}
