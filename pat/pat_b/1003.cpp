/*1. �ַ����б������P, A, T�������ַ��������԰��������ַ���
2. �������� xPATx ���ַ��������Ի�á�����ȷ�������� x �����ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
3. ��� aPbTc ����ȷ�ģ���ô aPbATca Ҳ����ȷ�ģ����� a, b, c �������ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����

���ھ�����ΪPATдһ���Զ����г����ж���Щ�ַ����ǿ��Ի�á�����ȷ���ġ�
�����ʽ�� ÿ�������������1��������������1�и���һ����Ȼ��n (<10)������Ҫ�����ַ���������������ÿ���ַ���ռһ�У��ַ������Ȳ�����100���Ҳ������ո�

�����ʽ��ÿ���ַ����ļ����ռһ�У�������ַ������Ի�á�����ȷ���������YES���������NO��

����������
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA*/
#include <stdio.h>
using namespace std;
bool judge(char s[100]){
    int i=0,p1=-1,p2=-1,len=0;
    while(s[i]!='\0'){
        if(s[i]=='A')
            i++;
        else if(s[i]=='P'&&p1==-1)
            p1=i++;
        else if(s[i]='T'&&p2==-1)
            p2=i++;
        else
            return false;
    }
    len=(i-1);
    if((p2-p1)==2){
        if(p1==(len-p2))
            return true;
        else
            return false;
    }
    else if((p2-p1)>2){
        int m=(p2-p1-2);
        while(m--){
            p2--;
            len-=p1;
        }
        if(p1==(len-p2))
            return true;
        else
            return false;
    }
    else
        return false;
}

int main()
{
    int n;
    char s[100];
    scanf("%d",&n);
    while(n--){
        //gets(s);
        scanf("%s",s);
        if(judge(s)){
            printf("����ȷ\n");
        }
        else
            printf("�𰸴���\n");
    }
    return 0;
}
