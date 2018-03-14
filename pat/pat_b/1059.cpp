/*0. 冠军将赢得一份“神秘大奖”（比如很巨大的一本学生研究论文集……）。
1. 排名为素数的学生将赢得最好的奖品 —— 小黄人玩偶！
2. 其他人将得到巧克力。

给定比赛的最终排名以及一系列参赛者的ID，你要给出这些参赛者应该获得的奖品。

输入格式：

输入第一行给出一个正整数N（<=10000），是参赛者人数。随后N行给出最终排名，每行按排名顺序给出一位参赛者的ID（4位数字组成）。接下来给出一个正整数K以及K个需要查询的ID。

输出格式：

对每个要查询的ID，在一行中输出“ID: 奖品”，其中奖品或者是“Mystery Award”（神秘大奖）、或者是“Minion”（小黄人）、或者是“Chocolate”（巧克力）。如果所查ID根本不在排名里，打印“Are you kidding?”（耍我呢？）。如果该ID已经查过了（即奖品已经领过了），打印“ID: Checked”（不能多吃多占）。

输入样例：
6
1111
6666
8888
1234
5555
0001
6
8888
0001
1111
2222
8888
2222
输出样例：
8888: Minion
0001: Chocolate
1111: Mystery Award
2222: Are you kidding?
8888: Checked
2222: Are you kidding?*/
#include <stdio.h>
#include <math.h>
bool prime(int n){
    if(n<=1)
        return false;
    for(int i=2;i<=sqrt(n);++i){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int rank[10000];
    for(int i=0;i<10000;++i){
        rank[i]=-1;
    }
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        int m;
        scanf("%d",&m);
        rank[m]=i+1;
         // printf("%d ",rank[m]);
    }
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;++i){
        int m;
        scanf("%d",&m);
        if(rank[m]==1){
            printf("%04d: Mystery Award\n",m);
            rank[m]=-2;
        }
        else if(prime(rank[m])){
            printf("%04d: Minion\n",m);
            rank[m]=-2;
        }
        else if(rank[m]==-1){
            printf("%04d: Are you kidding?\n",m);
        }
        else if(rank[m]==-2){
            printf("%04d: Checked\n",m);
        }
        else{
             printf("%04d: Chocolate\n",m);
            rank[m]=-2;
        }
        //printf("%d ",rank[m]);
    }
    return 0;
}
