/*����һ�����Ȳ�����10000�ġ�����Ӣ����ĸ���ɵ��ַ������뽫�ַ����µ���˳�򣬰���PATestPATest....��������˳������������������ַ�����Ȼ�������ַ��ĸ�����һ����һ����ģ���ĳ���ַ��Ѿ�����꣬�����µ��ַ��԰�PATest��˳���ӡ��ֱ�������ַ����������

�����ʽ��

������һ���и���һ�����Ȳ�����10000�ġ�����Ӣ����ĸ���ɵķǿ��ַ�����

�����ʽ��

��һ���а���ĿҪ������������ַ�������Ŀ��֤����ǿա�

����������
redlesPayBestPATTopTeePHPereatitAPPT
���������
PATestPATestPTetPTePePee
*/
#include <stdio.h>
int main(){
    char s[10010];
    scanf("%s",s);
    int count[6]={0};
    for(int i=0;s[i]!='\0';++i){
        if(s[i]=='P'){
            count[0]++;
        }
        else if(s[i]=='A'){
            count[1]++;
        }
        else if(s[i]=='T'){
            count[2]++;
        }
        else if(s[i]=='e'){
            count[3]++;
        }
        else if(s[i]=='s'){
            count[4]++;
        }
        else if(s[i]=='t'){
            count[5]++;
        }
    }
    for(int i=0;count[0]+count[1]+count[2]+count[3]+count[4]+count[5]!=0;++i){
        if(count[0]>0){
            printf("P");
            count[0]--;
        }
        if(count[1]>0){
            printf("A");
            count[1]--;
        }
        if(count[2]>0){
            printf("T");
            count[2]--;
        }
        if(count[3]>0){
            printf("e");
            count[3]--;
        }
        if(count[4]>0){
            printf("s");
            count[4]--;
        }
        if(count[5]>0){
            printf("t");
            count[5]--;
        }
    }
    return 0;
}
