/*Sample Input:
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
Sample Output:
3 4 2 6 5 1*/
#include <stdio.h>
#include <stack>
#include <string.h>
#include <stdlib.h>
using namespace std;
int pre[40];//pre or level?
int ino[40];
struct node{
    int id;
    struct node* lchild;
    struct node* rchild;
};
node *root=NULL;
stack<int> in;
int countn=0;
int n,num1=0;
void create(int in[],int pre[],int l1,int h1,int l2,int h2,node *&root){//remember to &
    if(l1<=h1){
            int r=pre[l2],i;
        for(i=l1;i<=h1;++i){
            if(r==in[i]){
                   // printf("%d ",i);
                break;
            }
        }
      //  printf("DFgfbh\n");
        if(root==NULL){
               // printf("dgfgggh\n");
                root=(node*)malloc(sizeof(node));//oh my god !!!!!!!!!!!
            root->id=r;
       // printf("%d\n",root->id);
            root->rchild=NULL;
            root->lchild=NULL;
        }
      //  printf("%d \n",root->id);
        create(in,pre,l1,i-1,l2+1,l2+i-l1,root->lchild);
        create(in,pre,i+1,h1,l2+i-l1+1,h2,root->rchild);
    }
}
void post(node *root){
   // printf("fgbfgfgg\n");
    if(root!=NULL){
         //  printf("dfgfghh\n");
        post(root->lchild);
        post(root->rchild);
        countn++;
        if(countn<n)
        printf("%d ",root->id);
        else{
            printf("%d",root->id);
        }
    }
}
int main(){
    scanf("%d",&n);
    char str[10];
    int id,num=0;;
    for(int i=0;i<2*n;++i){
        scanf("%s",str);
        if(strcmp(str,"Push")==0){
            scanf("%d",&id);
            in.push(id);
            pre[num1++]=id;
        }
        else{
            ino[num++]=in.top();
            in.pop();
        }
    }
    create(ino,pre,0,n-1,0,n-1,root);
   // printf("%d\n",root->id);
    post(root);
    return 0;
}
