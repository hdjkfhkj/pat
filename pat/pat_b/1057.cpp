/*����һ�����Ȳ�����105���ַ���������Ҫ���㽫��������Ӣ����ĸ����ţ���ĸa-z��Ӧ���1-26�����ִ�Сд����ӣ��õ�����N��Ȼ���ٷ���һ��N�Ķ����Ʊ�ʾ���ж���0������1����������ַ�����PAT (Basic)��������ĸ���֮��Ϊ��16+1+20+2+1+19+9+3=71����71�Ķ�������1000111������3��0��4��1��

�����ʽ��

������һ���и������Ȳ�����105���Իس��������ַ�����

�����ʽ��

��һ�����Ⱥ����0�ĸ�����1�ĸ���������Կո�ָ���

����������
PAT (Basic)
���������
3 4*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
    char c;
    int n=0;
    char a[40];
    for(int i=0;;++i){
        scanf("%c",&c);
        if(c=='\n'){
            break;
        }
        if(c>='a'&&c<='z'||c>='A'&&c<='Z'){

        c=tolower(c);
        n+=(c-'a'+1);
        }
        else{
            continue;
        }
    }
    int i;
   for(i=0;n!=0;++i){
    a[i]=n%2;
    n/=2;
   }
   int count0=0,count1=0;
   //printf("%d",n);
   for(int j=0;j<i;++j){
      //  printf("%c ",a[i]);
    if(a[j]==0)
        count0++;
    else
        count1++;
   }
   //printf("\n");
   printf("%d %d",count0,count1);
   return 0;
}
