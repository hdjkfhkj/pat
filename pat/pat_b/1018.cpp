/*�ָ������˵Ľ����¼����ͳ��˫����ʤ��ƽ�������������Ҹ���˫���ֱ��ʲô���Ƶ�ʤ�����

�����ʽ��

�����1�и���������N��<=105������˫������Ĵ��������N�У�ÿ�и���һ�ν������Ϣ�����ס���˫��ͬʱ�����ĵ����ơ�C�������ӡ���J������������B������������1����ĸ����׷�����2�������ҷ����м���1���ո�

�����ʽ��

�����1��2�зֱ�����ס��ҵ�ʤ��ƽ�������������ּ���1���ո�ָ�����3�и���������ĸ���ֱ����ס��һ�ʤ�����������ƣ��м���1���ո�����ⲻΨһ�����������ĸ����С�Ľ⡣

����������
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
���������
5 3 2
2 3 5
B B*/
#include <stdio.h>
int main(){
    int n,w=0,e=0,l=0,max1,max2;
    int w1[3]={0},w2[3]={0};
    //char ch1,ch2;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        getchar();//�л��з���Ҫ���տո�
        char ch1,ch2;
        scanf("%c %c",&ch1,&ch2);
        //printf("%d\n",cmp(ch1,ch2));
        if(ch1!=ch2){
            if(ch1=='B'){
                if(ch2=='C'){
                    w++;
                    w1[0]++;
                }
                else if(ch2=='J'){
                    l++;
                    w2[2]++;
                }
            }
            else if(ch1=='C'){
                if(ch2=='B'){
                    l++;
                    w2[0]++;
                }
                else if(ch2=='J'){
                    w++;
                    w1[1]++;
                }
            }
            else{
               if(ch2=='B'){
                    w++;
                    w1[2]++;
                }
                else if(ch2=='C'){
                    l++;
                    w2[1]++;
                }
            }
        }
        else if(ch1==ch2){
            e++;
        }
    }
    printf("%d %d %d\n",w,e,l);
    printf("%d %d %d\n",l,e,w);
    max1=w1[0];
    if(max1<w1[1]){
        max1=w1[1];
    }
    if(max1<w1[2]){
        max1=w1[2];
    }
    if(max1==w1[0]){
        printf("B ");
    }
    else if(max1==w1[1]){
        printf("C ");
    }
    else{
        printf("J ");
    }
    max2=w2[0];
    if(max2<w2[1]){
        max2=w2[1];
    }
    if(max2<w2[2]){
        max2=w2[2];
    }
    if(max2==w2[0]){
        printf("B");
    }
    else if(max2==w2[1]){
        printf("C");
    }
    else{
        printf("J");
    }

    return 0;
}
