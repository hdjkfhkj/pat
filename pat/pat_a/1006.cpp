/*Sample Input:
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40
Sample Output:
SC3021234 CS301133*/
#include <stdio.h>
struct node{
    char id[20];
    int in;
    int out;
};
int main(){
    int m,h1,m1,s1,h2,m2,s2;
    node first,last;
    first.in=1000000000;
    last.out=0;
    scanf("%d",&m);
    for(int i=0;i<m;++i){
            node p;
        scanf("%s %d:%d:%d %d:%d:%d",p.id,&h1,&m1,&s1,&h2,&m2,&s2);
        p.in=h1*3600+m1*60+s1;
        p.out=h2*3600+m2*60+s2;
        if(p.in<first.in){
            first=p;
        }
        if(p.out>last.out){
            last=p;
        }
    }
    printf("%s %s",first.id,last.id);
    return 0;
}
