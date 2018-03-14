/*����ά���ٿƵĶ��壺

���������ǵ����㷨����һ����������ݣ��𲽲��������������С�ÿ�������У��㷨������������ȡ��һԪ�أ���֮����������������ȷ��λ�á���˵���ֱ��ȫ��Ԫ������

�鲢����������µ������������Ƚ�ԭʼ���п���N��ֻ����1��Ԫ�ص����������У�Ȼ��ÿ�ε����鲢�������ڵ����������У�ֱ�����ֻʣ��1����������С�

�ָ���ԭʼ���к���ĳ�����㷨�������м����У������жϸ��㷨���������������㷨��

�����ʽ��

�����ڵ�һ�и���������N (<=100)�����һ�и���ԭʼ���е�N�����������һ�и�����ĳ�����㷨�������м����С�������������Ŀ���������������ּ��Կո�ָ���

�����ʽ��

�����ڵ�1���������Insertion Sort����ʾ�������򡢻�Merge Sort����ʾ�鲢����Ȼ���ڵ�2��������ø������㷨�ٵ���һ�ֵĽ�����С���Ŀ��֤ÿ����ԵĽ����Ψһ�ġ����ּ��Կո�ָ�������ĩ�����ж���ո�
��������1��
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
�������1��
Insertion Sort
1 2 3 5 7 8 9 4 6 0
��������2��
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
�������2��
Merge Sort
1 2 3 8 4 5 7 9 0 6
*/
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int a[n],b[n],flag=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    int k=n;
    for(int i=0;i<n-1;++i){
        if(b[i]>b[i+1]){
                k=i+1;
            break;
        }
    }
    if(k==n){
        printf("Insertion Sort\n");
        printf("%d",b[0]);
        for(int s=1;s<n;++s){
            printf(" %d",b[s]);
        }
        return 0;
    }
    for(int j=k;j<n;++j){
        if(a[j]!=b[j]){
            flag=1;//not insertion,merge
            break;
        }
    }
    if(flag==0){
        int t=upper_bound(b,b+k,b[k])-b;
        int temp=b[k];
        for(int s=k;s>t;--s){
            b[s]=b[s-1];
        }
        b[t]=temp;
        printf("Insertion Sort\n");
        printf("%d",b[0]);
        for(int s=1;s<n;++s){
            printf(" %d",b[s]);
        }
    }
    else{//��ʵ�����i+1,�ȼ�һ������
            int mi=log(k)/log(2);//
            int youxu=pow(2,mi);
            k=youxu;//��������ֻ����1 2 4 8 16
            for(int j=0;j<n/(2*k);++j){
                sort(b+j*2*k,b+(j+1)*2*k);
            }
            sort(b+n/(2*k)*2*k,b+n);
            printf("Merge Sort\n");
        printf("%d",b[0]);
        for(int s=1;s<n;++s){
            printf(" %d",b[s]);
        }
        }

    return 0;
}
/*else {
        cout << "Merge Sort" << endl;
        int k = 1;
        int flag = 1;
        while(flag) {
            flag = 0;
            for (i = 0; i < n; i++) {
                if (a[i] != b[i])
                    flag = 1;
            }
            k = k * 2;
            for (i = 0; i < n / k; i++)
                sort(a + i * k, a + (i + 1) * k, cmp);
            sort(a + n / k * k, a + n, cmp);
        }
    }*/
