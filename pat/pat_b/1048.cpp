/*����Ҫ��ʵ��һ�����ּ��ܷ��������ȹ̶�һ��������������A������һ������B������ÿ1λ������A�Ķ�Ӧλ���ϵ����ֽ����������㣺������λ����Ӧλ��������Ӻ��13ȡ�ࡪ��������J����10��Q����11��K����12����ż��λ����B�����ּ�ȥA�����֣������Ϊ���������ټ�10���������λΪ��1λ��

�����ʽ��

������һ�������θ���A��B����Ϊ������100λ��������������Կո�ָ���

�����ʽ��

��һ����������ܺ�Ľ����

����������
1234567 368782971
���������
3695Q8118*/
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(){
    string a,b,s;
    cin>>a>>b;
    int al=a.length();
    int bl=b.length();
    int count=1;
    for(int i=al-1,j=bl-1;i>=0||j>=0;--i,--j){
            char m,n;
            if(i>=0&&j>=0){
        m=a[i];
        n=b[j];
            }
            else{
            if(i<0){
                m='0';
                n=b[j];
            }
            else if(j<0){
                n='0';
                m=a[i];
            }
            }
        if(count%2==1){
            int guodu=(m-'0'+n-'0')%13;
            if(guodu==10){
                s[count-1]='J';
            }
            else if(guodu==11){
                s[count-1]='Q';
            }
            else if(guodu==12){
                s[count-1]='K';
            }
            else{
                s[count-1]=guodu+'0';
            }
        }
        else{
            if((n-'0'-(m-'0'))<0){
                s[count-1]=n-'0'-(m-'0')+10+'0';
            }
            else{
                s[count-1]=n-'0'-(m-'0')+'0';
            }
        }
        ++count;
    }
    for(int i=count-2;i>=0;--i){//Ҫע��Ŷ�����ݴ洢�ķ�Χ
        printf("%c",s[i]);
    }
    return 0;
}
