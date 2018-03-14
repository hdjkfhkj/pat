/*某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。

这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过200岁的老人，而今天是2014年9月6日，所以超过200岁的生日和未出生的生日都是不合理的，应该被过滤掉。

输入格式：

输入在第一行给出正整数N，取值在(0, 105]；随后N行，每行给出1个人的姓名（由不超过5个英文字母组成的字符串）、以及按“yyyy/mm/dd”（即年/月/日）格式给出的生日。题目保证最年长和最年轻的人没有并列。

输出格式：

在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。

输入样例：
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
输出样例：
3 Tom John*/
#include <stdio.h>
#include <vector>
#include <algorithm>
struct people{
    char name[10];
    int year;
    int month;
    int day;
};
bool cmp(people a,people b){
    if(a.year!=b.year){
        return a.year<b.year;
    }
    else{
        if(a.month!=b.month){
            return a.month<b.month;
        }
        else{
            return a.day<=b.day;
        }
    }
}
int main(){
        int n,c=0;
        scanf("%d",&n);
       // vector<people> v;
        people sample,low,high,oldest,youngest;
        low.year=1814;
        low.month=9;
        low.day=6;
        high.year=2014;
        high.month=9;
        high.day=6;
        oldest=high;
        youngest=low;
        for(int i=0;i<n;++i){
            scanf("%s %04d/%02d/%02d",sample.name,&sample.year,&sample.month,&sample.day);
            if(cmp(sample,high)&&cmp(low,sample)){
                                       // printf("valid\n");
                c++;
                if(cmp(sample,oldest)){
                    oldest=sample;
                }
                if(cmp(youngest,sample)){
                    youngest=sample;
                }
            }
        }
        if(c==0)
            printf("0");//拜拜，这一分姑奶奶不要了。。
        else
        printf("%d %s %s",c,oldest.name,youngest.name);
        return 0;
        }
