/*�±����й���������ѽ�ʱ�Ե�һ�ִ�ͳʳƷ����ͬ��������಻ͬ��ζ���±����ָ������������±��Ŀ���������ۼۡ��Լ��г�����������������������Ի�õ���������Ƕ��١�

ע�⣺����ʱ����ȡ��һ���ֿ�档���������������������ģ�����������3���±����������ֱ�Ϊ18��15��10��֣����ۼ۷ֱ�Ϊ75��72��45��Ԫ������г������������ֻ��20��֣���ô��������������Ӧ��������ȫ��15��ֵ�2���±����Լ�5��ֵ�3���±������ 72 + 45/2 = 94.5����Ԫ����

�����ʽ��

ÿ���������1������������ÿ�����������ȸ���һ��������1000��������N��ʾ�±������������Լ�������500�������Ϊ��λ����������D��ʾ�г���������������һ�и���N��������ʾÿ���±��Ŀ�����������Ϊ��λ�������һ�и���N��������ʾÿ���±������ۼۣ�����ԪΪ��λ�������ּ��Կո�ָ���

�����ʽ��

��ÿ�������������һ�������������棬����ԪΪ��λ����ȷ��С�����2λ��

����������
3 20
18 15 10
75 72 45
���������
94.50*/
#include <algorithm>
#include <stdio.h>
using namespace std;
typedef struct mooncake{
    float storage;
    float sum;
    float sale;
};//����ı�������������Ҫ���ֿ�
int cmp(mooncake a,mooncake b){
        return a.sale>b.sale;
}
int main(){

    int n,need;
    scanf("%d %d",&n,&need);
    //mooncake cake[1010];
    mooncake *cake = new mooncake [n];//����ṹ���������������???????????????????>?????????????????????
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
    sort(cake,cake+n,cmp);//����Ҳ��û�����
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
