/*����n��ѧ����������ѧ�š��ɼ����ֱ�����ɼ���ߺͳɼ����ѧ����������ѧ�š�

�����ʽ��ÿ�������������1��������������ʽΪ

  ��1�У�������n
  ��2�У���1��ѧ�������� ѧ�� �ɼ�
  ��3�У���2��ѧ�������� ѧ�� �ɼ�
  ... ... ...
  ��n+1�У���n��ѧ�������� ѧ�� �ɼ�
����������ѧ�ž�Ϊ������10���ַ����ַ������ɼ�Ϊ0��100֮���һ�����������ﱣ֤��һ�����������û������ѧ���ĳɼ�����ͬ�ġ�
�����ʽ����ÿ�������������2�У���1���ǳɼ����ѧ����������ѧ�ţ���2���ǳɼ����ѧ����������ѧ�ţ��ַ�������1�ո�

����������
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
���������
Mike CS991301
Joe Math990112*/
#include <stdio.h>
#include <string.h>
using namespace std;
int main(){
    int n;
    char hname[15],lname[15],hsno[15],lsno[15],name[15],sno[15],grade;
    int hgrade=-1,lgrade=101;
    scanf("%d",&n);
    while(n--){
        scanf("%s %s %d",name,sno,&grade);
        //scanf("%s %s ",name,sno);
        //scanf("%d",&grade);
        if(grade<lgrade){
            strcpy(lname,name);
            strcpy(lsno,sno);
            lgrade=grade;
        }
        if(grade>hgrade){
            strcpy(hname,name);
            strcpy(hsno,sno);
            hgrade=grade;
        }
    }
    printf("%s %s\n",hname,hsno);
    printf("%s %s\n",lname,lsno);
    return 0;
}
