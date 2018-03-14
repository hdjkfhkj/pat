/*大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，因为前面两字符串中第1对相同的大写英文字母（大小写有区分）是第4个字母'D'，代表星期四；第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

输入格式：

输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。

输出格式：

在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。

输入样例：
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm
输出样例：
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
