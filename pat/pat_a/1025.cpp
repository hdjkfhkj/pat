/*Sample Input:
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
Sample Output:
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 48*/
#include <stdio.h>
#include <algorithm>
using namespace std;
struct stu{
    long long id;
    int score;
    int fr;
    int lo;
    int lr;
};
stu s[30010];
bool cmp(stu a,stu b){
    if(a.score!=b.score){
        return a.score>b.score;
    }
    else{
        return a.id<b.id;
    }
}
int main(){
    int n,k,counts=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&k);
        int start=counts;
        for(int j=0;j<k;++j){
            scanf("%lld %d",&s[counts].id,&s[counts].score);
           // printf("%lld %d \n",s[counts].id,s[counts].score);
            s[counts].lo=i;
            counts++;

        }
        sort(s+start,s+start+k,cmp);
        s[start].lr=1;
        for(int j=start+1;j<start+k;++j){
            if(s[j].score==s[j-1].score){
                s[j].lr=s[j-1].lr;
            }
            else{
                s[j].lr=j-start+1;
            }
        }
    }
    sort(s,s+counts,cmp);
     s[0].fr=1;
     printf("%d\n",counts);
     printf("%lld %d %d %d\n",s[0].id,s[0].fr,s[0].lo,s[0].lr);
     for(int i=1;i<counts;++i){
        if(s[i].score==s[i-1].score){
            s[i].fr=s[i-1].fr;
        }
        else{
            s[i].fr=i+1;
        }
 printf("%lld %d %d %d\n",s[i].id,s[i].fr,s[i].lo,s[i].lr);
     }
     return 0;
}
