/*���Ķ�ѡ���ǱȽ��鷳�����飬���������д�����������ʦ���Ķ�ѡ�⣬����ָ���ĵ���������ࡣ

�����ʽ��

�����ڵ�һ�и�������������N��<=1000����M��<=100�����ֱ���ѧ�������Ͷ�ѡ��ĸ��������M�У�ÿ��˳�θ���һ���������ֵ��������5������������ѡ�������������2�Ҳ�����5��������������ȷѡ�������������ѡ�����������������������ȷѡ�ע��ÿ���ѡ���СдӢ����ĸa��ʼ˳�����С��������1���ո�ָ������N�У�ÿ�и���һ��ѧ���Ĵ����������ÿ��𰸸�ʽΪ��(ѡ�е�ѡ����� ѡ��1 ����)��������Ŀ˳�������ע�⣺��Ŀ��֤ѧ���Ĵ�������ǺϷ��ģ���������ѡ�е�ѡ��������ʵ��ѡ�����������

�����ʽ��

���������˳�����ÿ��ѧ���ĵ÷֣�ÿ������ռһ�С�ע������ʱֻ��ѡ��ȫ����ȷ���ܵõ�����ķ��������һ��������������Ŀ�Ĵ�������ͱ�ţ���Ŀ���������˳���1��ʼ��ţ�������в��У��򰴱�ŵ���˳����������ּ��ÿո�ָ�������β�����ж���ո����������Ŀ��û���˴��������һ�������Too simple����

����������
3 4
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (2 b d) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (2 b c) (4 a b c d)
���������
3
6
5
2 2 3 4
*/
#include <stdio.h>
#include <iostream>
using namespace std;
struct timu{
    int fen;
    int d;
    int c;//cuo
    char ans[10];
};
int main(){
    int m,n;
    scanf("%d %d",&n,&m);
    timu t[m];
    int de[1000]={0};
    for(int i=0;i<m;++i){
            int xuanxiang;
        scanf("%d %d %d",&t[i].fen,&xuanxiang,&t[i].d);
        //printf("��ֵ=%d �𰸸���=%d ",t[i].fen,t[i].d);
        for(int j=0;j<t[i].d;++j){
            scanf(" %c",&t[i].ans[j]);
            //printf("��%c",t[i].ans[j]);
        }
        t[i].c=0;
    }
    //printf("\n");
    getchar();
    //getchar();//�Ҳ��������һ��������ΪʲôҪ������getcha()?
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            int k,s;
            char useless;
            scanf(" (%d%c",&k,&useless);
                    int flag=0;
            for(s=0;s<k;++s){
                    char answer;
                    scanf("%c%c",&answer,&useless);

                    //printf("��%c ",answer);

                    if(k==t[j].d){
                if(answer!=t[j].ans[s]){//wrong
            flag=1;
                }
            }
            }
            if(flag||k!=t[j].d){
                //de[i]+=t[j].fen;
                t[j].c++;
            }
            else{
                de[i]+=t[j].fen;
            }
            }
        }
    for(int i=0;i<n;++i){
        printf("%d\n",de[i]);
    }
    int max=0;
    int cuo[100]={0};
    for(int i=0,j=0;i<m;++i){
        if(t[i].c>max){
            max=t[i].c;
            cuo[100]={0};//clear
            cuo[0]=i+1;
            j=0;
        }
        else if(t[i].c==max){
            cuo[j]=i+1;
        }
        ++j;
    }
    //printf("%d",max);
    if(max==0){
        printf("Too simple");
    }
    else{
            printf("%d",max);
    for(int i=0;;++i){
        if(cuo[i]==0){
            break;
        }
        else{
            printf(" %d",cuo[i]);
        }
    }
    }
    return 0;
}
