/*����һ�����������У���������p������������е����ֵ��M����Сֵ��m�����M <= m * p���������������������С�

���ڸ�������p��һЩ���������������ѡ�񾡿��ܶ��������һ���������С�

�����ʽ��

�����һ�и�������������N��p������N��<= 105����������������ĸ�����p��<= 109���Ǹ����Ĳ������ڶ��и���N����������ÿ����������109��

�����ʽ��

��һ�������������ѡ����ٸ����������������һ���������С�

����������
10 8
2 3 20 4 5 1 6 7 8 9
���������
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
                if(a[j]-agent>=10e-6){//����֣�Ϊʲô���ʾ�����ݲ���Ӱ����
                    break;
                }
            }
       //   j=upper_bound(a,a+i+1,agent)-a;//�ѵ���ֱ�Ӱ�float������int�ٲ��ҵģ�
            b=i-(j-1);
            if(b>max){
                max=b;
            }
    }
printf("%d",max);
return 0;
}
