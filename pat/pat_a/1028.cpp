/*Sample Input 1
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60
Sample Output 1
000001 Zoe 60
000007 James 85
000010 Amy 90
Sample Input 2*/
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct stu{
    int id;
    char name[10];
    int score;
};
stu s[100010];
bool cmp1(stu a,stu b){
    return a.id<b.id;
}
bool cmp2(stu a,stu b){
    if(strcmp(a.name,b.name)!=0){
        return strcmp(a.name,b.name)<0;
    }
    else{
        return a.id<b.id;
    }
}
bool cmp3(stu a,stu b){
    if(a.score!=b.score){
        return a.score<b.score;
    }
    else{
        return a.id<b.id;
    }
}
int main(){
    int n,c;
    scanf("%d %d",&n,&c);
    for(int i=0;i<n;++i){
        scanf("%d %s %d",&s[i].id,s[i].name,&s[i].score);
    }
    if(c==1){
        sort(s,s+n,cmp1);
    }
    else if(c==2){
        sort(s,s+n,cmp2);
    }
    else if(c==3){
        sort(s,s+n,cmp3);
    }
    for(int i=0;i<n;++i){
        printf("%06d %s %d\n",s[i].id,s[i].name,s[i].score);
    }
    return 0;
}
