/*����̽����Ħ˹�ӵ�һ����ֵ�������������Լ��ɣ� 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm��������̽�ܿ�������ˣ���������ֵ�����ʵ���Ͼ���Լ���ʱ�䡰������ 14:04������Ϊǰ�����ַ����е�1����ͬ�Ĵ�дӢ����ĸ����Сд�����֣��ǵ�4����ĸ'D'�����������ģ���2����ͬ���ַ���'E'�����ǵ�5��Ӣ����ĸ������һ����ĵ�14����ͷ������һ���0�㵽23��������0��9���Լ���д��ĸA��N��ʾ�����������ַ�����1����ͬ��Ӣ����ĸ's'�����ڵ�4��λ�ã���0��ʼ�������ϣ������4���ӡ��ָ��������ַ��������������Ħ˹����õ�Լ���ʱ�䡣

�����ʽ��

������4���зֱ����4���ǿա��������ո��ҳ��Ȳ�����60���ַ�����

�����ʽ��

��һ�������Լ���ʱ�䣬��ʽΪ��DAY HH:MM�������С�DAY����ĳ���ڵ�3�ַ���д����MON��ʾ����һ��TUE��ʾ���ڶ���WED��ʾ��������THU��ʾ�����ģ�FRI��ʾ�����壬SAT��ʾ��������SUN��ʾ�����ա���Ŀ���뱣֤ÿ�����Դ���Ψһ�⡣

����������
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm
���������
THU 14:04*/
#include <stdio.h>
#include <string.h>
int main(){
    char s1[61],s2[61],s3[61],s4[61];
    int i=0;
    scanf("%s",s1);
    scanf("%s",s2);
    scanf("%s",s3);
    scanf("%s",s4);
    while((s1[i]!='\0')&&(s2[i]!='\0')){
        if((s1[i]==s2[i])&&(s1[i]>='A'&&s1[i]<='G')){
            switch(s1[i]){
            case 'A':
                printf("MON ");
                break;
            case 'B':
                printf("TUE ");
                break;
            case 'C':
                printf("WED ");
                break;
            case 'D':
                printf("THU ");
                break;
            case 'E':
                printf("FRI ");
                break;
            case 'F':
                printf("SAT ");
                break;
            case 'G':
                printf("SUN ");
                break;
            }
            break;
        }
        ++i;
    }
    ++i;
     while((s1[i]!='\0')&&(s2[i]!='\0')){
        if((s1[i]==s2[i])&&((s1[i]>='A'&&s1[i]<='N')||(s1[i]>='0'&&s1[i]<='9'))){
            switch(s1[i]){
            case '0':
                printf("00:");
                break;
            case '1':
                printf("01:");
                break;
            case '2':
                printf("02:");
                break;
            case '3':
                printf("03:");
                break;
            case '4':
                printf("04:");
                break;
            case '5':
                printf("05:");
                break;
            case '6':
                printf("06:");
                break;
            case '7':
                printf("07:");
                break;
            case '8':
                printf("08:");
                break;
            case '9':
                printf("09:");
                break;
            case 'A':
                printf("10:");
                break;
            case 'B':
                printf("11:");
                break;
            case 'C':
                printf("12:");
                break;
            case 'D':
                printf("13:");
                break;
            case 'E':
                printf("14:");
                break;
            case 'F':
                printf("15:");
                break;
            case 'G':
                printf("16:");
                break;
            case 'H':
                printf("17:");
                break;
            case 'I':
                printf("18:");
                break;
            case 'J':
                printf("19:");
                break;
            case 'K':
                printf("20:");
                break;
            case 'L':
                printf("21:");
                break;
            case 'M':
                printf("22:");
                break;
            case 'N':
                printf("23:");
                break;
            }
            break;
        }
        ++i;
     }
     int j=0;
     while((s3[j]!='\0')&&(s4[j]!='\0')){
        if(s3[j]==s4[j]&&((s3[j]>='a'&&s3[j]<='z')||(s3[j]>='A'&&s3[j]<='Z'))){
           printf("%02d",j);
        }
        ++j;
     }
     return 0;
}
