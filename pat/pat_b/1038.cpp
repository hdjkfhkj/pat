/*�����ʽ��

�����ڵ�1�и���������105��������N����ѧ�������������1�и���N��ѧ���İٷ��������ɼ����м��Կո�ָ������1�и���Ҫ��ѯ�ķ�������K��������N�����������������K���������м��Կո�ָ���

�����ʽ��

��һ���а���ѯ˳������÷ֵ���ָ��������ѧ���������м��Կո�ָ�������ĩ�����ж���ո�

����������
10
60 75 90 55 75 99 82 90 75 50
3 75 90 88
���������
3 2 0*/
#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n],grade[110]={0};
    for(int i=0;i<n;++i){
            int score;
        scanf("%d",&score);
    grade[score]++;
    }
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;++i){
        int score;
        scanf("%d",&score);
        if(i<k-1){
            printf("%d ",grade[score]);
        }
        else
             printf("%d",grade[score]);
    }
    return 0;
}
