/*Sample Input:
9
25 30 42 16 20 20 35 -5 28

10 2 2 345 67 21 76 67 67 34 567
Sample Output:
2 + 4 = 6*/


#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
struct node{
    int data;
    struct node *lchild,*rchild;
    int layer;
};
node *root=NULL;
int n1=0,n2=0,layer=1,ml=0;
void insertb(node *&root,int data,int &layer){//´«Öµ
    if(root==NULL){
            root=(node*)malloc(sizeof(node));
            root->layer=layer;
        root->data=data;
        root->lchild=NULL;
        root->rchild=NULL;
    if(root->layer>ml){
        ml=root->layer;
    }
    }
    else{
            layer=root->layer+1;
            if(layer>ml){
                ml=layer;
            }
        if(data<=root->data){
            //   printf("laddddddddddddaaaaa%d  %d \n",data,layer);

            insertb(root->lchild,data,layer);
        }
        else{
          //     printf("raddddddddddddaaaaa%d  %d \n",data,layer);
            insertb(root->rchild,data,layer);
        }
    }
  //  printf("aaaaa%d  %d\n",root->data,root->layer);
}
void pre(node *root){
    if(root==NULL){
        return;
    }
    if(root!=NULL){
        //      printf("jkhggjhraddddddddddddaaaaa%d  %d  %d\n",root->data,ml,root->layer);
        if(root->layer==ml){
            n1++;
        }
        else if(root->layer==ml-1){
            n2++;
        }



    pre(root->lchild);
    pre(root->rchild);
    }
}
int main(){
    int n;
    scanf("%d",&n);
  //  node *root=NULL;
    for(int i=0;i<n;++i){
        int temp;
        scanf("%d",&temp);
        insertb(root,temp,layer);
    }
   // int n1=0,n2=0;
    pre(root);
    printf("%d + %d = %d",n1,n2,n1+n2);
    return 0;
}
