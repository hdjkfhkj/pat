/*����һ������K�Լ�һ��������L�����д����L��ÿK����㷴ת�����磺����LΪ1��2��3��4��5��6��KΪ3�������Ӧ��Ϊ3��2��1��6��5��4�����KΪ4�������Ӧ��Ϊ4��3��2��1��5��6������󲻵�K��Ԫ�ز���ת��

�����ʽ��

ÿ���������1������������ÿ������������1�и�����1�����ĵ�ַ������ܸ���������N(<= 105)���Լ�������K(<=N)����Ҫ��ת���������ĸ��������ĵ�ַ��5λ�Ǹ�������NULL��ַ��-1��ʾ��

��������N�У�ÿ�и�ʽΪ��

Address Data Next

����Address�ǽ���ַ��Data�Ǹý�㱣����������ݣ�Next����һ���ĵ�ַ��

�����ʽ��

��ÿ������������˳�������ת�����������ÿ�����ռһ�У���ʽ��������ͬ��

����������
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
���������
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn=100010;
struct node{
    int address;
    int data;
    int next;
    int order;
};
node no[maxn];
node temp;
bool cmp(node a,node b){
    if(a.order!=b.order){
        return a.order<b.order;
    }
}
int main(){
    int start,n,k,address;
    scanf("%d %d %d",&start,&n,&k);
    for(int i=0;i<maxn;++i){
        no[i].order=maxn;
    }
    for(int i=0;i<n;++i){
        scanf("%d",&address);
        scanf("%d %d",&no[address].data,&no[address].next);//���������ɻ����Ϲ���𣿣�����������������������������������������
        no[address].address=address;
    }
    int p=start,order=0;
    while(p!=-1){
        no[p].order=order++;
        p=no[p].next;
    }
    sort(no,no+maxn,cmp);
    n=order;
    for(int i=0;i<n/k;++i){
           for(int j=k-1;j>=1;--j){
                printf("%05d %d %05d\n",no[i*k+j].address,no[i*k+j].data,no[i*k+j-1].address);
           }
           if(i!=(n/k-1)){
             printf("%05d %d %05d\n",no[i*k].address,no[i*k].data,no[(i+1)*k+k-1].address);
        }
    }
    if(n%k!=0){
        //no[((n/k)-1)*k].next=no[(n/k)*k].address;
         printf("%05d %d %05d\n",no[(n/k-1)*k].address,no[(n/k-1)*k].data,no[(n/k)*k].address);
        for(int i=0;i<(n%k-1);++i){
            printf("%05d %d %05d\n",no[(n/k)*k+i].address,no[(n/k)*k+i].data,no[(n/k)*k+i+1].address);
        }
        printf("%05d %d -1\n",no[n-1].address,no[n-1].data);
    }
    else{
         printf("%05d %d -1\n",no[(n/k-1)*k].address,no[(n/k)-1].data);
    }
    return 0;
}
