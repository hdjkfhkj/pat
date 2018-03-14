/*A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.
Input

Each input file contains one test case. Each case starts with a line containing 0 < N < 100, the number of nodes in a tree, and M (< N), the number of non-leaf nodes. Then M lines follow, each in the format:

ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 01.
Output

For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.

The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. Then we should output "0 1" in a line.

Sample Input
2 1
01 1 02
Sample Output
0 1*/
#include <stdio.h>
#include <queue>
using namespace std;
struct tnode{
    int id;
    int l;
};
int edge[100][100]={0};
int root=01;
queue<int> tree;
int level=0,layer=1;
tnode node[100];
int main(){
    int n,m,id,k;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;++i){//create tree;
        int child;
        scanf("%d %d",&id,&k);
        //printf("%d %d ",id,k);
        for(int j=0;j<k;++j){
            scanf("%d",&child);
            edge[id][child]=1;
            // printf("%d %d ",id,child);
        }
    }
    //bfs();
    tree.push(root);
    while(!tree.empty()){
    int curr=tree.front();//visit
    tree.pop();
    //printf("%d ",curr);
    int flag=0;
    if(curr==root){
        node[curr].l=1;
    }
    for(int i=1;i<=n;++i){
        if(edge[curr][i]==1){
            tree.push(i);
           //printf("%d        %d ",curr,i);
            node[i].l=node[curr].l+1;
            flag=1;
        }
    }
    //printf("%d ",flag);
        if(node[curr].l!=layer){
                    printf("%d ",level);
                layer++;
                level=0;
            }
            if(flag==0){//no child
            if(node[curr].l==layer){
                level++;
            }
        }
        }
        printf("%d",level);
    return 0;
}
