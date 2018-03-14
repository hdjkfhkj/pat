/*Sample Input 1:
5
88 70 61 96 120
Sample Output 1:
70
Sample Input 2:7
88 70 61 96 120 90 65

Sample Output 2:
88*/
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
struct node{
    int key;
    struct node *lchild,*rchild;
};
node *root=NULL;
int depth(node *root){
    if(root==NULL){
        return 0;
    }
    else{
            int h1=depth(root->lchild);
            int h2=depth(root->rchild);
        return (h1>h2)?h1+1:h2+1;
    }
}
void r(node *&root){
    node *temp=root->lchild;
    root->lchild=temp->rchild;
    temp->rchild=root;
    root=temp;
}
void l(node *&root){
    node *temp=root->rchild;
    root->rchild=temp->lchild;
    temp->lchild=root;
    root=temp;
}
void insertb(node *&root,int key){
   //  printf("%d %d %d\n",key);
    if(root==NULL){
      //  root=(node*)malloc(sizeof(node));
         root=(node*)malloc(sizeof(node));
        root->key=key;
        root->lchild=NULL;
        root->rchild=NULL;
    }
    else if(key<root->key){
        insertb(root->lchild,key);
        int h1=depth(root->lchild);
        int h2=depth(root->rchild);
        if(h1-h2==2){
            if(key<root->lchild->key){//ll
                r(root);
               // printf("ll %d\n",key);
            }
            else{//lr
                l(root->lchild);
                r(root);
               //  printf("lr %d\n",key);
            }
        }
    }
    else{
        insertb(root->rchild,key);
        int h1=depth(root->lchild);
        int h2=depth(root->rchild);
        if(h1-h2==-2){
            if(key<root->rchild->key){//rl
                r(root->rchild);
                l(root);
              //   printf("rl %d\n",key);
            }
            else{//rr
                l(root);
              //   printf("rr %d\n",key);
            }
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        int key;
        scanf("%d",&key);
        insertb(root,key);

    }
    printf("%d",root->key);
    return 0;
}
