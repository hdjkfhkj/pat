/*月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。现给定所有种类月饼的库存量、总售价、以及市场的最大需求量，请你计算可以获得的最大收益是多少。

注意：销售时允许取出一部分库存。样例给出的情形是这样的：假如我们有3种月饼，其库存量分别为18、15、10万吨，总售价分别为75、72、45亿元。如果市场的最大需求量只有20万吨，那么我们最大收益策略应该是卖出全部15万吨第2种月饼、以及5万吨第3种月饼，获得 72 + 45/2 = 94.5（亿元）。

输入格式：

每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N表示月饼的种类数、以及不超过500（以万吨为单位）的正整数D表示市场最大需求量。随后一行给出N个正数表示每种月饼的库存量（以万吨为单位）；最后一行给出N个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。

输出格式：

对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后2位。

输入样例：
3 20
18 15 10
75 72 45
输出样例：
94.50*/
#include <algorithm>
#include <stdio.h>
using namespace std;
typedef struct mooncake{
    float storage;
    float sum;
    float sale;
};//定义的变量名和类型名要区分开
int cmp(mooncake a,mooncake b){
        return a.sale>b.sale;
}
int main(){

    int n,need;
    scanf("%d %d",&n,&need);
    //mooncake cake[1010];
    mooncake *cake = new mooncake [n];//定义结构体数组必须这样吗？???????????????????>?????????????????????
    for(int i=0;i<n;++i){
            //cin>>cake[i].storage;
        scanf("%f",&cake[i].storage);
    //cake[i].storage=storage;
       // printf("%.2f\n",storage[i]);
    }
    for(int i=0;i<n;++i){
        scanf("%f",&cake[i].sum);
        cake[i].sale=cake[i].sum/cake[i].storage;
        //printf("%.2f\n",sale[i]);
    }
    sort(cake,cake+n,cmp);//排序也是没问题的
    float income=0.0;
    for(int i=0;i<n&&need>0;++i){
          // printf("%.2f\n",sale[i]);
        if(need>=cake[i].storage){
            income+=cake[i].sum;
            need-=cake[i].storage;
 // printf("%.2f\n",income);
        }
        else{
             // printf("%.2f\n",sale[i]);
            income+=need*cake[i].sale;
            need=0;
        }
    }//printf("%.2f\n",sale[i]);
    printf("%.2f",income);
    return 0;
}
