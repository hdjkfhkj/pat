/*������A�ġ�DA��Ϊ1λ���������֡�����Ϊ��A������DA��ɵ�������PA�����磺����A = 3862767��DA = 6����A�ġ�6���֡�PA��66����ΪA����2��6��

�ָ���A��DA��B��DB�����д�������PA + PB��

�����ʽ��

������һ�������θ���A��DA��B��DB���м��Կո�ָ�������0 < A, B < 1010��

�����ʽ��

��һ�������PA + PB��ֵ��

��������1��
3862767 6 13530293 3
�������1��
399
��������2��
3862767 1 13530293 8
�������2��
0*/
//string ��char�кܴ�ͬ
//����ĵ����Ĵ��˰�
//�ȷ������ˡ�����
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main(){
    char a[11],b[11];
    int da,db,i=0,counta=0,countb=0;
    long long pa=0,pb=0;
    //cin>>a>>da>>b>>da;
    //cin>>a;
    scanf("%s %d %s %d",a,&da,b,&db);
    //cin>>b;
    //scanf("%d",&da);
    while(a[i]!='\0'){//����Ϊstring���Ͳ���������
        if((a[i]-'0')==da)
            ++counta;
        i++;
    }
    i=0;
    while(b[i]!='\0'){
        if((b[i]-'0')==db)
            ++countb;
        i++;
    }
    //cout<<counta<<countb<<endl;
    while(counta--){
        pa=(pa*10+da);
    }
    while(countb--){
        pb=(pb*10+db);
    }
    //cout<<(pa+pb);
    printf("%ld\n",(pa+pb));
    return 0;
}
