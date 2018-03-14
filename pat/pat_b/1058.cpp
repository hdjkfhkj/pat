/*批改多选题是比较麻烦的事情，本题就请你写个程序帮助老师批改多选题，并且指出哪道题错的人最多。

输入格式：

输入在第一行给出两个正整数N（<=1000）和M（<=100），分别是学生人数和多选题的个数。随后M行，每行顺次给出一道题的满分值（不超过5的正整数）、选项个数（不少于2且不超过5的正整数）、正确选项个数（不超过选项个数的正整数）、所有正确选项。注意每题的选项从小写英文字母a开始顺次排列。各项间以1个空格分隔。最后N行，每行给出一个学生的答题情况，其每题答案格式为“(选中的选项个数 选项1 ……)”，按题目顺序给出。注意：题目保证学生的答题情况是合法的，即不存在选中的选项数超过实际选项数的情况。

输出格式：

按照输入的顺序给出每个学生的得分，每个分数占一行。注意判题时只有选择全部正确才能得到该题的分数。最后一行输出错得最多的题目的错误次数和编号（题目按照输入的顺序从1开始编号）。如果有并列，则按编号递增顺序输出。数字间用空格分隔，行首尾不得有多余空格。如果所有题目都没有人错，则在最后一行输出“Too simple”。

输入样例：
3 4
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (2 b d) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (2 b c) (4 a b c d)
输出样例：
3
6
5
2 2 3 4
*/
#include <stdio.h>
#include <iostream>
using namespace std;
struct timu{
    int fen;
    int d;
    int c;//cuo
    char ans[10];
};
int main(){
    int m,n;
    scanf("%d %d",&n,&m);
    timu t[m];
    int de[1000]={0};
    for(int i=0;i<m;++i){
            int xuanxiang;
        scanf("%d %d %d",&t[i].fen,&xuanxiang,&t[i].d);
        //printf("分值=%d 答案个数=%d ",t[i].fen,t[i].d);
        for(int j=0;j<t[i].d;++j){
            scanf(" %c",&t[i].ans[j]);
            //printf("答案%c",t[i].ans[j]);
        }
        t[i].c=0;
    }
    //printf("\n");
    getchar();
    //getchar();//我不就输出了一个换行吗？为什么要用两个getcha()?
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            int k,s;
            char useless;
            scanf(" (%d%c",&k,&useless);
                    int flag=0;
            for(s=0;s<k;++s){
                    char answer;
                    scanf("%c%c",&answer,&useless);

                    //printf("答案%c ",answer);

                    if(k==t[j].d){
                if(answer!=t[j].ans[s]){//wrong
            flag=1;
                }
            }
            }
            if(flag||k!=t[j].d){
                //de[i]+=t[j].fen;
                t[j].c++;
            }
            else{
                de[i]+=t[j].fen;
            }
            }
        }
    for(int i=0;i<n;++i){
        printf("%d\n",de[i]);
    }
    int max=0;
    int cuo[100]={0};
    for(int i=0,j=0;i<m;++i){
        if(t[i].c>max){
            max=t[i].c;
            cuo[100]={0};//clear
            cuo[0]=i+1;
            j=0;
        }
        else if(t[i].c==max){
            cuo[j]=i+1;
        }
        ++j;
    }
    //printf("%d",max);
    if(max==0){
        printf("Too simple");
    }
    else{
            printf("%d",max);
    for(int i=0;;++i){
        if(cuo[i]==0){
            break;
        }
        else{
            printf(" %d",cuo[i]);
        }
    }
    }
    return 0;
}
