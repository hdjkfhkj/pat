/*����һ����Ȼ��n���������λ����֮�ͣ��ú���ƴ��д���͵�ÿһλ���֡�

�����ʽ��ÿ�������������1��������������������Ȼ��n��ֵ�����ﱣ֤nС��10100��

�����ʽ����һ�������n�ĸ�λ����֮�͵�ÿһλ��ƴ�����ּ���1 �ո񣬵�һ�������һ��ƴ�����ֺ�û�пո�

����������
1234567890987654321123456789
���������
yi san wu*/
#include <string>
#include <iostream>
using namespace std;
string pin[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

int main(){
    string s;
    int i=0,m=0;
    cin>>s;
    while(s[i]!='\0'){
        m+=s[i]-'0';
        i++;
    }
    if(m>=100)
     cout<<pin[m/100]<<" "<<pin[(m/10)%10]<<" "<<pin[m%10];
    //printf("%s %s %s",pin[m/100],pin[(m/10)%10],pin[m%10]);
    else if(m>=10)
     cout<<pin[m/10]<<" "<<pin[m%10];
    else
     cout<<pin[m];
    return 0;
}

