/*给定一个正整数数列，和正整数p，设这个数列中的最大值是M，最小值是m，如果M <= m * p，则称这个数列是完美数列。

现在给定参数p和一些正整数，请你从中选择尽可能多的数构成一个完美数列。

输入格式：

输入第一行给出两个正整数N和p，其中N（<= 105）是输入的正整数的个数，p（<= 109）是给定的参数。第二行给出N个正整数，每个数不超过109。

输出格式：

在一行中输出最多可以选择多少个数可以用它们组成一个完美数列。

输入样例：
10 8
2 3 20 4 5 1 6 7 8 9
输出样例：
8*/
#include <stdio.h>
#include <algorithm>
#include<math.h>
using namespace std;/*
int binary(int a[],int low,int high,float b){
    int mid=(low+high)/2;
    if(b<=a[mid]&&b>a[mid-1]){
        return mid;
    }
    else if(b>a[mid]){
        return binary(a,mid+1,high,b);
    }
    else
        return binary(a,low,mid-1,b);
}*/
int main(){
    int n,p;
    scanf("%d %d",&n,&p);
    int a[n],b;
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int max=1;
    for(int i=n-1;i>=0;--i){
            float agent=a[i]/p;
            int j;
            for(j=0;j<n;++j){
                if(a[j]-agent>=10e-6){//好奇怪，为什么会对示例数据产生影响呢
                    break;
                }
            }
       //   j=upper_bound(a,a+i+1,agent)-a;//难道是直接把float换成了int再查找的？
            b=i-(j-1);
            if(b>max){
                max=b;
            }
    }
printf("%d",max);
return 0;
}
