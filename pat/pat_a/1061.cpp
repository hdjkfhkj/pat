/*Sample Input:
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm
Sample Output:
THU 14:04*/
#include <stdio.h>
char s1[70],s2[70],s3[70],s4[70],day[10][10]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main(){
    scanf("%s %s %s %s",s1,s2,s3,s4);
    int i;
    for(i=0;s1[i]!='\0'&&s2[i]!='\0';++i){
        if(s1[i]==s2[i]&&s1[i]>='A'&&s1[i]<='G'){
            printf("%s ",day[s1[i]-'A']);
            break;
        }
    }
    for(i=i+1;s1[i]!='\0'&&s2[i]!='\0';++i){
        if(s1[i]==s2[i]){
                if(s1[i]<='N'&&s1[i]>='A'){
            printf("%02d:",s1[i]-'A'+10);
            break;//不跳出，会被覆盖
                }
        else if(s1[i]>='0'&&s1[i]<='9'){
             printf("%02d:",s1[i]-'0');
             break;
        }
        }
    }
    for(i=0;s3[i]!='\0'&&s4[i]!='\0';++i){
        if(s3[i]==s4[i]&&((s3[i]<='z'&&s3[i]>='a')||(s3[i]<='Z'&&s3[i]>='A'))){
            printf("%02d",i);
            break;
        }
    }
    return 0;
}
