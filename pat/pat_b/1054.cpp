/*本题的基本要求非常简单：给定N个实数，计算它们的平均值。但复杂的是有些输入数据可能是非法的。一个“合法”的输入是[-1000，1000]区间内的实数，并且最多精确到小数点后2位。当你计算平均值的时候，不能把那些非法的数据算在内。

输入格式：

输入第一行给出正整数N（<=100）。随后一行给出N个正整数，数字间以一个空格分隔。

输出格式：

对每个非法输入，在一行中输出“ERROR: X is not a legal number”，其中X是输入。最后在一行中输出结果：“The average of K numbers is Y”，其中K是合法输入的个数，Y是它们的平均值，精确到小数点后2位。如果平均值无法计算，则用“Undefined”替换Y。如果K为1，则输出“The average of 1 number is Y”。

输入样例1：
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35
输出样例1：
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38
输入样例2：
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
