/*0. �ھ���Ӯ��һ�ݡ����ش󽱡�������ܾ޴��һ��ѧ���о����ļ���������
1. ����Ϊ������ѧ����Ӯ����õĽ�Ʒ ���� С������ż��
2. �����˽��õ��ɿ�����

�������������������Լ�һϵ�в����ߵ�ID����Ҫ������Щ������Ӧ�û�õĽ�Ʒ��

�����ʽ��

�����һ�и���һ��������N��<=10000�����ǲ��������������N�и�������������ÿ�а�����˳�����һλ�����ߵ�ID��4λ������ɣ�������������һ��������K�Լ�K����Ҫ��ѯ��ID��

�����ʽ��

��ÿ��Ҫ��ѯ��ID����һ���������ID: ��Ʒ�������н�Ʒ�����ǡ�Mystery Award�������ش󽱣��������ǡ�Minion����С���ˣ��������ǡ�Chocolate�����ɿ��������������ID���������������ӡ��Are you kidding?����ˣ���أ����������ID�Ѿ�����ˣ�����Ʒ�Ѿ�����ˣ�����ӡ��ID: Checked�������ܶ�Զ�ռ����

����������
6
1111
6666
8888
1234
5555
0001
6
8888
0001
1111
2222
8888
2222
���������
8888: Minion
0001: Chocolate
1111: Mystery Award
2222: Are you kidding?
8888: Checked
2222: Are you kidding?*/
#include <stdio.h>
#include <math.h>
bool prime(int n){
    if(n<=1)
        return false;
    for(int i=2;i<=sqrt(n);++i){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int rank[10000];
    for(int i=0;i<10000;++i){
        rank[i]=-1;
    }
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        int m;
        scanf("%d",&m);
        rank[m]=i+1;
         // printf("%d ",rank[m]);
    }
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;++i){
        int m;
        scanf("%d",&m);
        if(rank[m]==1){
            printf("%04d: Mystery Award\n",m);
            rank[m]=-2;
        }
        else if(prime(rank[m])){
            printf("%04d: Minion\n",m);
            rank[m]=-2;
        }
        else if(rank[m]==-1){
            printf("%04d: Are you kidding?\n",m);
        }
        else if(rank[m]==-2){
            printf("%04d: Checked\n",m);
        }
        else{
             printf("%04d: Chocolate\n",m);
            rank[m]=-2;
        }
        //printf("%d ",rank[m]);
    }
    return 0;
}
