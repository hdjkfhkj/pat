/*���������Ǹ�10��������A��B(<=230-1)�����A+B��D (1 < D <= 10)��������

�����ʽ��

������һ�������θ���3������A��B��D��

�����ʽ��

���A+B��D��������

����������
123 456 8
���������
1103*/
#include <stdio.h>
using namespace std;
int main(){
    int a,b,c,d,r[100],i;
    scanf("%d %d %d",&a,&b,&d);
    //cin>>a>>b>>d;
    c=a+b;
    if(c==0){
        printf("0");
        //return 0;
    }
    for(i=0;c!=0;++i){
        r[i]=c%d;
        c/=d;
    //printf("%d",r[i]);
    }
     //printf("%d",i);
     //int j;
    for(int j=i-1;j>=0;j--){
         printf("%d",r[j]);
    }
    return 0;
}
