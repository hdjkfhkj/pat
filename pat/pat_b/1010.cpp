/*��ƺ�����һԪ����ʽ�ĵ�������ע��xn��nΪ��������һ�׵���Ϊn*xn-1����

�����ʽ����ָ���ݽ���ʽ�������ʽ������ϵ����ָ��������ֵ��Ϊ������1000�������������ּ��Կո�ָ���

�����ʽ������������ͬ�ĸ�ʽ�����������ʽ�������ϵ����ָ�������ּ��Կո�ָ�������β�����ж���ո�ע�⡰�����ʽ����ָ����ϵ������0�����Ǳ�ʾΪ��0 0����

����������
3 4 -5 2 6 1 -2 0
���������
12 3 -10 1 6 0*/
#include <iostream>
#include <stdio.h>
using namespace std;
typedef struct{
    int coe;
    int exp;
}a[1001];
int main(){
    int n,m,i=0;
    while((~scanf("%d %d",&a,&b)){
        a[i].coe=n;
        a[i].exp=m;
        ++i;
    }
    for(int j=i-1;j>=0;--j){
        if(a[j].exp==0){
            a[j].coe=0;//ϵ��Ϊ��Ͳ��������
        }
        else{
            a[j].coe*=a[j].exp;
            a[j].exp--;
        }
    }
    for(int j=0;j<i;++j){
        if(a[j].coe!=0){
            printf("%d %d",a[j].coe,a[j].exp);
        }
    }
    return 0;

}
