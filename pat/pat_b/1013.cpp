/*��Pi��ʾ��i�����������θ�����������M <= N <= 10e4�������PM��PN������������

�����ʽ��

������һ���и���M��N������Կո�ָ���

�����ʽ��

�����PM��PN������������ÿ10������ռ1�У�����Կո�ָ�������ĩ�����ж���ո�

����������
5 27
���������
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103*/
#include <stdio.h>
#include <math.h>
int p[10000];
bool isPrime(int n){
    for(int i=2;i<=sqrt(n);++i){
        if(n%i==0)
            return false;
    }
    return true;
}
void prime(){
   // int p[10010];
    p[1]=2;
    for(int i=3,j=2;j<=10000;i+=2){
        if(isPrime(i)){
            p[j++]=i;
        }

    }
}
int main(){
    int m,n,prime,count=0;
   // prime();//Ϊʲô���ܵ��ã�
    p[1]=2;
    for(int i=3,j=2;j<=10000;i+=2){
        if(isPrime(i)){
            p[j++]=i;
        }

    }
    scanf("%d %d",&m,&n);
    for(int i=m;i<=n;++i){
        if(count%10==0)
         printf("%d",p[i]);
        else if(count%10==9){
            printf(" %d\n",p[i]);
        }
        else{
            printf(" %d",p[i]);
        }
        count++;
    }
    return 0;
}

