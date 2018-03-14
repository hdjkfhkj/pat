#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;
struct person{
    char name[9];
    short int age;
    int worth;
};
vector<person> p[1002];
int book[210]={0};
bool cmp(person a,person b){
    if(a.worth!=b.worth){
        return a.worth>b.worth;
    }
    else{
        if(a.age!=b.age){
            return a.age<b.age;
        }
        else{
            return strcmp(a.name,b.name)<0;
        }
    }
}
int main(){
    int n,k;
    //cin>>n>>k;
    scanf("%d %d",&n,&k);
    person somebody;
    for(int i=0;i<n;++i){
      //  cin>>somebody.name>>somebody.age>>somebody.worth;
        scanf("%s %d %d",somebody.name,&somebody.age,&somebody.worth);
        p[0].push_back(somebody);

    }
    sort(p[0].begin(),p[0].end(),cmp);
    for(int i=0;i<p[0].size();++i){
    book[p[0][i].age]++;
    if(book[p[0][i].age]<=100){
        p[1001].push_back(p[0][i]);
    }
    }
    for(int i=1;i<=k;++i){
        short m,amin,amax;
      //  cin>>m>>amin>>amax;
        scanf("%d %d %d",&m,&amin,&amax);
        for(int j=0,md=0;j<p[1001].size();++j){
            if(p[1001][j].age>=amin&&p[1001][j].age<=amax){
                p[i].push_back(p[1001][j]);
                md++;
                if(md==100){
                    break;
                }
            }
        }
        //cout<<"Case"<<"  #"<<i<<":"<<endl;
        printf("Case #%d:\n",i);
        if(p[i].size()==0){
           // cout<<"None"<<endl;
            printf("None\n");
        }
       int md;
       //=m<p[i].size():m?p[i].size();
        if(m>p[i].size()){
            md=p[i].size();
        }
        else{
            md=m;
        }
        for(int j=0;j<md;++j){
          //  cout<<p[i][j].name<<" "<<p[i][j].age<<" "<<p[i][j].worth<<endl;
            printf("%s %d %d\n",p[i][j].name,p[i][j].age,p[i][j].worth);
        }
    }
    return 0;
}
