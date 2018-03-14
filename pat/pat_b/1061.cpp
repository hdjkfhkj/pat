/*输入样例：
3 6
2 1 3 3 4 5
0 0 1 0 1 1
0 1 1 0 0 1
1 0 1 0 1 0
1 1 0 0 1 1
输出样例：
13
11
12*/
#include <stdio.h>
#define maxn 110
int score[maxn],ans[maxn],grade[maxn];
int main(){
    int m,n;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d",&score[i]);
    }
    for(int i=0;i<m;++i){
        scanf("%d",&ans[i]);
    }
    for(int i=0;i<n;++i){
        grade[i]=0;
        for(int j=0;j<m;++j){
                int answer;
            scanf("%d",&answer);
        if(answer==ans[j]){
            grade[i]+=score[j];
        }
        }
        printf("%d\n",grade[i]);
    }
    return 0;
}
