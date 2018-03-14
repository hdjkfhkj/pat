/*输入例子:
16 7
JH007BD 18:00:01 in
ZD00001 11:30:08 out
DB8888A 13:00:00 out
ZA3Q625 23:59:50 out
ZA133CH 10:23:00 in
ZD00001 04:09:59 in
JH007BD 05:09:59 in
ZA3Q625 11:42:01 out
JH007BD 05:10:33 in
ZA3Q625 06:30:50 in
JH007BD 12:23:42 out
ZA3Q625 23:55:00 in
JH007BD 12:24:23 out
ZA133CH 17:11:22 out
JH007BD 18:07:01 out
DB8888A 06:30:50 in
05:10:00
06:30:50
11:00:00
12:23:42
14:00:00
18:00:00
23:59:00

输出例子:
1
4
5
2
1
0
1
JH007BD ZD00001 07:20:09
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <vector>
#define maxn 10010
#define maxq 80010
using namespace std;
struct record{
    string id;
    int t;
    bool status;
  //  bool useful;
};
struct query{
    int t;
    int num;
};
struct car{
    int t;
    string id;
};
record r[maxn];
query q[maxq];
car c[maxn];
vector<string> maxc;
int maxm=0;
bool cmp1(record a,record b){
    if(a.id!=b.id){
        return a.id<b.id;
    }
    else{
        return a.t<b.t;
    }
}
int main(){
    int re,qu;
    scanf("%d %d",&re,&qu);
    for(int i=0;i<re;++i){
            string id;
    int h,m,s;
    string status;
        cin>>id;
        scanf("%d:%d:%d",&h,&m,&s);
        cin>>status;
        r[i].id=id;
        r[i].t=h*60*60+m*60+s;
        if(status=="in"){
            r[i].status=0;
        }
        else if(status=="out"){
            r[i].status=1;
        }
      //  r[i].useful=1;
        c[i].t=0;
    }
    for(int i=0;i<qu;++i){
        int h,m,s;
        scanf("%d:%d:%d",&h,&m,&s);
        q[i].t=h*60*60+m*60+s;
        q[i].num=0;
      //  printf("%d\n",q[i].t);
    }
    sort(r,r+re,cmp1);//delete useless record
    int number=0;
    c[number].id=r[0].id;
    for(int i=0;i<re-1;){//被自己蠢哭了。。。。。
            if(c[number].id!=r[i].id){
                number++;
            }
        if(r[i].id==r[i+1].id){
            if(r[i].status==0&&r[i+1].status==1){
                    c[number].id=r[i].id;
            c[number].t+=r[i+1].t-r[i].t;
            for(int j=0;j<qu;++j){
                if(q[j].t<r[i+1].t&&q[j].t>=r[i].t){
                q[j].num++;
            }
            }
            if(c[number].t>maxm){
                maxm=c[number].t;
                maxc.clear();
                maxc.push_back(c[number].id);
            }
            else if(c[number].t==maxm){
                maxc.push_back(c[number].id);
            }
                i=i+2;
            }
            else{
              //  r[i].useful=0;
            i++;
            }
        }
        else{

            i++;
        }
    }
   // sort(r,r+re,cmp2);
    for(int i=0;i<qu;++i){
        printf("%d\n",q[i].num);
    }
    for(int i=0;i<maxc.size();++i){
        cout<<maxc[i]<<" ";
    }
    printf("%02d:%02d:%02d",maxm/3600,maxm/60%60,maxm%60);
    return 0;
}
