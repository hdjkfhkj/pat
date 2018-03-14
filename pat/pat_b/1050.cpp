/*本题要求将给定的N个正整数按非递增的顺序，填入“螺旋矩阵”。所谓“螺旋矩阵”，是指从左上角第1个格子开始，按顺时针螺旋方向填充。要求矩阵的规模为m行n列，满足条件：m*n等于N；m>=n；且m-n取所有可能值中的最小值。

输入格式：

输入在第1行中给出一个正整数N，第2行给出N个待填充的正整数。所有数字不超过104，相邻数字以空格分隔。

输出格式：

输出螺旋矩阵。每行n个数字，共m行。相邻数字以1个空格分隔，行末不得有多余空格。

输入样例：
12
37 76 20 98 76 42 53 95 60 81 58 93
输出样例：
98 95 93
42 37 81
53 20 76
58 60 76*/
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;
bool cmp(int a,int b){
    if(a!=b){
        return a>b;
    }
}
int main(){
    int s,m,n;
    scanf("%d",&s);
    int a[s];
    for(int i=0;i<s;++i){
        scanf("%d",&a[i]);
    }
    sort(a,a+s,cmp);
    int k=sqrt(s);
    for(int i=k;i>=1;--i){
        if(s%i==0){
            n=i;
            m=s/n;
            break;
        }
    }
    int b[m][n];
    //for(int i=0;i<m;++i){
    int i=0,j=0,count=0;
    for(int k=0;count<s;++k){
        for(j;j<n-k;++j){//尽量每次赋值，减少各个块之间的联系，方便调试
            b[i][j]=a[count++];
            // printf("%d %d %d\n",b[i][j],i,j);
            if(count==s)
                break;
        }
        if(count==s)
                break;
        ++i,--j;
        for(;i<m-k;++i){
            b[i][j]=a[count++];
            // printf("%d %d %d\n",b[i][j],i,j);
            if(count==s)
                break;
        }
        if(count==s)
                break;
        --j,--i;
        for(;j>=k;--j){
            b[i][j]=a[count++];
//printf("%d %d %d\n",b[i][j],i,j);
            if(count==s)
                break;
        }
        if(count==s)
                break;
        --i,++j;
        for(;i>=k+1;--i){
            b[i][j]=a[count++];
          //  printf("%d %d %d\n",b[i][j],i,j);
            if(count==s)
                break;
        }
        ++i,++j;
    }
   // printf("\n");
    //int t[2][2]={4,3,1,2};
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(j<n-1){
                printf("%d ",b[i][j]);
            }
            else{
                printf("%d\n",b[i][j]);
            }
        }
        //printf("\n");
    }
    return 0;
}
