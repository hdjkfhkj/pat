/*����Ļ���Ҫ��ǳ��򵥣�����N��ʵ�����������ǵ�ƽ��ֵ�������ӵ�����Щ�������ݿ����ǷǷ��ġ�һ�����Ϸ�����������[-1000��1000]�����ڵ�ʵ����������ྫȷ��С�����2λ���������ƽ��ֵ��ʱ�򣬲��ܰ���Щ�Ƿ������������ڡ�

�����ʽ��

�����һ�и���������N��<=100�������һ�и���N�������������ּ���һ���ո�ָ���

�����ʽ��

��ÿ���Ƿ����룬��һ���������ERROR: X is not a legal number��������X�����롣�����һ��������������The average of K numbers is Y��������K�ǺϷ�����ĸ�����Y�����ǵ�ƽ��ֵ����ȷ��С�����2λ�����ƽ��ֵ�޷����㣬���á�Undefined���滻Y�����KΪ1���������The average of 1 number is Y����

��������1��
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35
�������1��
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38
��������2��
2
aaa -9999*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;
int main(){
    int n,count=0;
    char in[10];
    double ans=0.0;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        cin>>in;
        int pos=-1,j;
        for(j=0;in[j]!='\0';++j){
            if(in[j]!='-'&&in[j]!='.'&&!(in[j]>='0'&&in[j]<='9')){
               // printf("ERROR:%s is not a legal number\n",in);
                cout<<"ERROR: "<<in<<" is not a legal number"<<endl;
                break;
            }
            if(in[j]=='-'){
                if(j!=0){
                     cout<<"ERROR: "<<in<<" is not a legal number"<<endl;
                break;
                }
            }
            if(in[j]=='.'&&pos==-1&&j!=0){
                if(in[j-1]>='0'&&in[j-1]<='9'){
                    pos=j;
                }
            }
            else if(in[j]=='.'&&pos!=-1){
                 cout<<"ERROR: "<<in<<" is not a legal number"<<endl;
                break;
        }
        if(pos!=-1&&j-pos>=3){
 cout<<"ERROR: "<<in<<" is not a legal number"<<endl;
                break;
        }
    }
    if(in[j]=='\0'){
        double shu;
        shu=atof(in);
        if(shu>=-1000&&shu<=1000){
            count++;
            ans+=shu;
        }
        else{
            cout<<"ERROR: "<<in<<" is not a legal number"<<endl;
        }
    }
}
if(count==0)
  printf("The average of 0 numbers is undefined");
  else if(count==1){
    printf("The average of 1 number is %.2f",ans);
  }
  else{
    printf("The average of %d numbers is %.2f",count,ans/count);
  }
  return 0;
}
