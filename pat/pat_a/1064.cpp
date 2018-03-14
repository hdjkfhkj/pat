/*Sample Input:
10
1 2 3 4 5 6 7 8 9 0
Sample Output:
6 3 8 1 5 7 9 0 2 4*/
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
struct node{
    int layer;
    int data;
};
int in[1010],countx=0;
node bst[1010];
bool cmp(node a,node b){
    if(a.layer!=b.layer){
        return a.layer<b.layer;
    }
    else{
        return a.data<b.data;
    }
}
void create(int in[],int l,int h,int layer){
    if(l<=h){
    int left,right;
    node root;
    int n=h-l+1;
    int level=ceil(log(n+1)/log(2));
    int md=pow(2,level-2);
    int lt=n-(pow(2,level-1)-1);
    if(lt>md){
        left=pow(2,level-1)-1;
        right=n-left-1;
    }
    else{
        right=pow(2,level-2)-1;
        left=n-right-1;
    }
    root.layer=layer;
    root.data=in[l+left];
    bst[countx++]=root;
    create(in,l,l+left-1,layer+1);
    create(in,l+left+1,h,layer+1);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&in[i]);
    }
    sort(in,in+n);
    create(in,0,n-1,1);
    sort(bst,bst+n,cmp);
    for(int i=0;i<n;++i){
        if(i<n-1){
            printf("%d ",bst[i].data);
        }
        else{
            printf("%d",bst[i].data);
        }
    }
    return 0;
}
