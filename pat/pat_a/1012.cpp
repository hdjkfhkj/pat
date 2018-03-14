/*Sample Input

5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999
Sample Output
1 C
1 M
1 E
1 A
3 A
N/A*/
#include <stdio.h>
#include <algorithm>
using namespace std;
struct stu{
    int id;
    int c,cr;
    int m,mr;
    int e,er;
    int ar;
    double a;
};
 stu s[1000000],s1[1000000];//大数组只能在这里初始化？
bool cmp1(stu s1,stu s2){
    if(s1.a!=s2.a)
    return s1.a>s2.a;
}
bool cmp2(stu s1,stu s2){
    return s1.c>s2.c;
}

bool cmp3(stu s1,stu s2){
    return s1.m>s2.m;
}
bool cmp4(stu s1,stu s2){
    return s1.e>s2.e;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    //stu s[1000000],s1[1000000];
    char course[10]={"ACME"};
    for(int i=0;i<n;++i){
        s[i].a=0;
        s[i].c=0;
        s[i].m=0;
        s[i].e=0;
    }
    for(int i=0;i<n;++i){
            int no;
    scanf("%d",&s[i].id);
        scanf(" %d %d %d",&s[i].c,&s[i].m,&s[i].e);
        s[i].a=(s[i].c+s[i].m+s[i].e)/3.0;
    }
    sort(s,s+n,cmp1);
    s[0].ar=1;
    for(int i=1;i<n;++i){
            if(s[i].a==s[i-1].a)
        s[i].ar=s[i-1].ar;
        else{
            s[i].ar=i+1;
        }
    }
    sort(s,s+n,cmp2);
    s[0].cr=1;
    for(int i=1;i<n;++i){
            if(s[i].c==s[i-1].c)
        s[i].cr=s[i-1].cr;
        else{
            s[i].cr=i+1;
        }
    }
    sort(s,s+n,cmp3);
    s[0].mr=1;
    for(int i=1;i<n;++i){
            if(s[i].m==s[i-1].m)
        s[i].mr=s[i-1].mr;
        else{
            s[i].mr=i+1;
        }
    }
    sort(s,s+n,cmp4);
    s[0].er=1;
    for(int i=1;i<n;++i){
            if(s[i].e==s[i-1].e)
        s[i].er=s[i-1].er;//额，原来考点在排名应为1 1 3 3 5 这种形式
        else{
            s[i].er=i+1;
        }
    }
    for(int i=0;i<1000000;++i){
        s1[i].ar=0;
    }
    for(int i=0;i<n;++i){
        s1[s[i].id]=s[i];
    }
    for(int i=0;i<m;++i){
            int no;
            char c='A';
        scanf("%d",&no);
        if(s1[no].ar!=0){
        int rank=s1[no].ar;
    if(s1[no].cr<rank){
        rank=s1[no].cr;
        c='C';
    }
    if(s1[no].mr<rank){
        rank=s1[no].mr;
        c='M';
    }
    if(s1[no].er<rank){
        rank=s1[no].er;
        c='E';
    }
    printf("%d %c\n",rank,c);
        }
        else{
            printf("N/A\n");
        }
    }
    return 0;
}
