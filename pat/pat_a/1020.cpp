/*Sample Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
Sample Output:
4 1 6 3 5 7 2*/
#include <stdio.h>
#include <queue>
using namespace std;
struct node{
    int data;
    int layer;
};
int in[40],post[40];
int countn=0,n;
queue<node> mdzz[30];
void create(int post[],int in[],int l1,int h1,int l2,int h2,int level){
    if(l1<=h1){
            node root;
    root.data=post[h1];
    int j;
    root.layer=level;
    mdzz[level].push(root);
    for(int i=l2;i<=h2;++i){
        if(in[i]==root.data){
                j=i;
            break;
        }
    }
    create(post,in,l1,l1+j-1-l2,l2,j-1,level+1);
    create(post,in,l1+j-1-l2+1,h1-1,j+1,h2,level+1);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&post[i]);
        //printf("post %d ",post[i]);
    }
    for(int i=0;i<n;++i){
        scanf("%d",&in[i]);
       // printf("in %d ",in[i]);
    }
    create(post,in,0,n-1,0,n-1,0);
    //printf("l=%d ",l);
    int countn=0;
    for(int i=0;i<n;++i){
        for(int j=0;!mdzz[i].empty();++j){
            countn++;
            if(countn<n){
                printf("%d ",mdzz[i].front());
                mdzz[i].pop();
            }
            else if(countn==n){
                printf("%d",mdzz[i].front());
                mdzz[i].pop();
                break;
            }
        }
    }
    return 0;
}
