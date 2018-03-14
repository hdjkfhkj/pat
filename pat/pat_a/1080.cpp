/*Sample Input:
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
Sample Output:
0 10
3
5 6 7
2 8

1 4*/
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct stu{
    int ge,gi,total,r,id;
    vector<int> school;
};
struct uni{
    int quota;
    int last,a;
    vector<int> student;
};
vector<stu> s;
vector<uni> u;
bool cmp(stu a,stu b){
    if(a.total!=b.total){
        return a.total>b.total;
    }
    else{
        return a.ge>b.ge;
    }
}
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<m;++i){
        uni in;
        scanf("%d",&in.quota);
        in.last=-1;
        in.a=0;
        u.push_back(in);
    }
    for(int i=0;i<n;++i){
            stu in;
            scanf("%d %d",&in.ge,&in.gi);
            in.total=in.ge+in.gi;
            in.id=i;
        for(int j=0;j<k;++j){
            int prefer;
            scanf("%d",&prefer);
            in.school.push_back(prefer);
        }
        s.push_back(in);
    }
    sort(s.begin(),s.end(),cmp);
    s[0].r=1;
    for(int i=1;i<n;++i){
        if(s[i].total==s[i-1].total&&s[i].ge==s[i-1].ge){
            s[i].r=s[i-1].r;
        }
        else{
            s[i].r=i+1;
        }
    //   printf("%d %d %d\n",s[i].id,s[i].total,s[i].r);
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<k;++j){
                int c=s[i].school[j];
            if(u[c].quota>u[c].a){
                u[c].student.push_back(s[i].id);
                u[c].last=s[i].id;
                u[c].a++;
                break;
            }
            else{
                    int md=u[c].last;
                if(md!=-1){
                    if(s[md].r==s[i].r){
                        u[c].student.push_back(s[i].id);
                        u[c].last=s[i].id;
                        u[c].a++;
                        break;
                    }
                }
            }
        }
    }
    for(int i=0;i<m;++i){
            if(u[i].student.size()>0){
        sort(u[i].student.begin(),u[i].student.end());
         printf("%d",u[i].student[0]);
        for(int j=1;j<u[i].student.size();++j){
            printf(" %d",u[i].student[j]);
        }
            }
         //   if(i<m-1)
        printf("\n");
    }
    return 0;
}
