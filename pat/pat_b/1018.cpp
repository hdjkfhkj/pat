/*现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：

输入第1行给出正整数N（<=105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。

输出格式：

输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯一，则输出按字母序最小的解。

输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
输出样例：
5 3 2
2 3 5
B B*/
#include <stdio.h>
int main(){
    int n,w=0,e=0,l=0,max1,max2;
    int w1[3]={0},w2[3]={0};
    //char ch1,ch2;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        getchar();//有换行符，要吸收空格
        char ch1,ch2;
        scanf("%c %c",&ch1,&ch2);
        //printf("%d\n",cmp(ch1,ch2));
        if(ch1!=ch2){
            if(ch1=='B'){
                if(ch2=='C'){
                    w++;
                    w1[0]++;
                }
                else if(ch2=='J'){
                    l++;
                    w2[2]++;
                }
            }
            else if(ch1=='C'){
                if(ch2=='B'){
                    l++;
                    w2[0]++;
                }
                else if(ch2=='J'){
                    w++;
                    w1[1]++;
                }
            }
            else{
               if(ch2=='B'){
                    w++;
                    w1[2]++;
                }
                else if(ch2=='C'){
                    l++;
                    w2[1]++;
                }
            }
        }
        else if(ch1==ch2){
            e++;
        }
    }
    printf("%d %d %d\n",w,e,l);
    printf("%d %d %d\n",l,e,w);
    max1=w1[0];
    if(max1<w1[1]){
        max1=w1[1];
    }
    if(max1<w1[2]){
        max1=w1[2];
    }
    if(max1==w1[0]){
        printf("B ");
    }
    else if(max1==w1[1]){
        printf("C ");
    }
    else{
        printf("J ");
    }
    max2=w2[0];
    if(max2<w2[1]){
        max2=w2[1];
    }
    if(max2<w2[2]){
        max2=w2[2];
    }
    if(max2==w2[0]){
        printf("B");
    }
    else if(max2==w2[1]){
        printf("C");
    }
    else{
        printf("J");
    }

    return 0;
}
