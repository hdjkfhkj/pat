/*ĳ��������˿��ղ飬�õ���ȫ���������ա�������д�������ҳ��������곤����������ˡ�

����ȷ��ÿ����������ڶ��ǺϷ��ģ�����һ���Ǻ���ġ���������֪����û�г���200������ˣ���������2014��9��6�գ����Գ���200������պ�δ���������ն��ǲ�����ģ�Ӧ�ñ����˵���

�����ʽ��

�����ڵ�һ�и���������N��ȡֵ��(0, 105]�����N�У�ÿ�и���1���˵��������ɲ�����5��Ӣ����ĸ��ɵ��ַ��������Լ�����yyyy/mm/dd��������/��/�գ���ʽ���������ա���Ŀ��֤���곤�����������û�в��С�

�����ʽ��

��һ����˳�������Ч���յĸ��������곤�˺��������˵�����������Կո�ָ���

����������
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
���������
3 Tom John*/
#include <stdio.h>
#include <vector>
#include <algorithm>
struct people{
    char name[10];
    int year;
    int month;
    int day;
};
bool cmp(people a,people b){
    if(a.year!=b.year){
        return a.year<b.year;
    }
    else{
        if(a.month!=b.month){
            return a.month<b.month;
        }
        else{
            return a.day<=b.day;
        }
    }
}
int main(){
        int n,c=0;
        scanf("%d",&n);
       // vector<people> v;
        people sample,low,high,oldest,youngest;
        low.year=1814;
        low.month=9;
        low.day=6;
        high.year=2014;
        high.month=9;
        high.day=6;
        oldest=high;
        youngest=low;
        for(int i=0;i<n;++i){
            scanf("%s %04d/%02d/%02d",sample.name,&sample.year,&sample.month,&sample.day);
            if(cmp(sample,high)&&cmp(low,sample)){
                                       // printf("valid\n");
                c++;
                if(cmp(sample,oldest)){
                    oldest=sample;
                }
                if(cmp(youngest,sample)){
                    youngest=sample;
                }
            }
        }
        if(c==0)
            printf("0");//�ݰݣ���һ�ֹ����̲�Ҫ�ˡ���
        else
        printf("%d %s %s",c,oldest.name,youngest.name);
        return 0;
        }
