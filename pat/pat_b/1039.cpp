/*�����ʽ��

ÿ���������1������������ÿ�����������ֱ���2�����Ⱥ����̯�����鴮��С���������鴮��������������1000�����ӡ�

�����ʽ��

�������������һ���������Yes���Լ��ж��ٶ�������ӣ����������������һ���������No���Լ�ȱ�˶������ӡ������1���ո�ָ���

��������1��
ppRYYGrrYBR2258
YrR8RrY
�������1��
Yes 8
��������2��
ppRYYGrrYB225
YrR8RrY
�������2��
No 2
*/
#include <stdio.h>
int main(){
    char s1[1010],s2[1010];
    int count[128]={0},c=0;
    scanf("%s %s",s1,s2);
    for(int i=0;s1[i]!='\0';++i){
        count[s1[i]]++;
        c++;
    }
    for(int i=0;s2[i]!='\0';++i){
        count[s2[i]]--;
        c--;
    }
    int que=0;
    for(int i=0;i<128;++i){
        if(count[i]<0){
            que+=count[i];
        }
    }
    if(que==0){
        printf("Yes %d",c);
    }
    else{
        printf("No %d",-que);
    }
    return 0;
}
