/*����Ҫ�󽫸�����N�����������ǵ�����˳�����롰�������󡱡���ν���������󡱣���ָ�����Ͻǵ�1�����ӿ�ʼ����˳ʱ������������䡣Ҫ�����Ĺ�ģΪm��n�У�����������m*n����N��m>=n����m-nȡ���п���ֵ�е���Сֵ��

�����ʽ��

�����ڵ�1���и���һ��������N����2�и���N�����������������������ֲ�����104�����������Կո�ָ���

�����ʽ��

�����������ÿ��n�����֣���m�С�����������1���ո�ָ�����ĩ�����ж���ո�

����������
12
37 76 20 98 76 42 53 95 60 81 58 93
���������
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
        for(j;j<n-k;++j){//����ÿ�θ�ֵ�����ٸ�����֮�����ϵ���������
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
