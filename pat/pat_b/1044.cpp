/*����������13���Ƽ����ģ�

�����˵�0�������˳�Ϊtret��
����������1��12�Ļ����ķֱ�Ϊ��jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec��
�����˽���λ�Ժ��12����λ���ֱַ��Ϊ��tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou��
��������˵����֡�29������ɻ����ľ��ǡ�hel mar�����������ġ�elo nov����Ӧ�������֡�115����Ϊ�˷��㽻���������д����ʵ�ֵ���ͻ�������֮��Ļ��롣

�����ʽ��

�����һ�и���һ��������N��<100�������N�У�ÿ�и���һ��[0, 169)�����ڵ����� ���� �����ǵ����ģ������ǻ����ġ�

�����ʽ��

��Ӧ�����ÿһ�У���һ���������������һ�����Ե����֡�

����������
4
29
5
elo nov
tam
���������
hel mar
may
115
13*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
char ge[13][5]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
char shi[13][5]={"fd","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
int main(){
    int n;
    scanf("%d",&n);
    char in1[10],in2[10],inn;

    for(int i=0;i<n;++i){
        //scanf("%s",in1)
         scanf("%s%c",in1,&inn);
        if(in1[0]>='0'&&in1[0]<='9'){
            int value=atoi(in1);
            if(value/13){
                printf("%s %s\n",shi[value/13],ge[value%13]);
            }
            else{
                printf("%s\n",ge[value%13]);
            }
        }
        else{
                int flag=0;
                    for(int k=0;k<13;++k){
                        if(strcmp(in1,ge[k])==0){//shi
                            printf("%d\n",k);
                            flag=1;
                          break;
                    }
                    }
                //scanf("%s",in1);
                if(flag==0){
                int count=0;
            for(int j=1;j<13;++j){

                if(strcmp(in1,shi[j])==0){//shi
                    count=j*13;
               // scanf("%s",in2);
               break;
                }
            }
            if(count!=0){
               if(inn==' '){
                    scanf("%s",in2);
                    for(int k=0;k<13;++k){
                        if(strcmp(in2,ge[k])==0){
                                count+=k;
                                break;
                        }
                    }
               }
                    printf("%d\n",count);
            }
        }
        }
    }
    return 0;
}
