/*
�����Ƕ��� dn Ϊ��dn = pn+1 - pn������ pi �ǵ�i����������Ȼ�� d1=1 �Ҷ���n>1�� dn ��ż�����������Բ��롱��Ϊ�����������������Ҳ�Ϊ2����������

�ָ�������������N (< 105)������㲻����N���������������Եĸ�����

�����ʽ��ÿ�������������1����������������������N��

�����ʽ��ÿ���������������ռһ�У�������N���������������Եĸ�����

����������
20
���������
4*/
#include <iostream>
#include <math.h>
using namespace std;
bool prime(int n){
    for(int i=2;i<=sqrt(n);++i){
        if(n%i==0)
            return false;
    }
    return true;
}
int main(){
    int n,count=0;
    cin>>n;
    for(int i=3;(i+2)<=n;i=i+2){//be careful
        if(prime(i)&&prime(i+2))
            ++count;
    }
    cout<<count;
    return 0;
}
