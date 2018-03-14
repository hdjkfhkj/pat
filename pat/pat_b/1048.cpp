/*本题要求实现一种数字加密方法。首先固定一个加密用正整数A，对任一正整数B，将其每1位数字与A的对应位置上的数字进行以下运算：对奇数位，对应位的数字相加后对13取余——这里用J代表10、Q代表11、K代表12；对偶数位，用B的数字减去A的数字，若结果为负数，则再加10。这里令个位为第1位。

输入格式：

输入在一行中依次给出A和B，均为不超过100位的正整数，其间以空格分隔。

输出格式：

在一行中输出加密后的结果。

输入样例：
1234567 368782971
输出样例：
3695Q8118*/
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(){
    string a,b,s;
    cin>>a>>b;
    int al=a.length();
    int bl=b.length();
    int count=1;
    for(int i=al-1,j=bl-1;i>=0||j>=0;--i,--j){
            char m,n;
            if(i>=0&&j>=0){
        m=a[i];
        n=b[j];
            }
            else{
            if(i<0){
                m='0';
                n=b[j];
            }
            else if(j<0){
                n='0';
                m=a[i];
            }
            }
        if(count%2==1){
            int guodu=(m-'0'+n-'0')%13;
            if(guodu==10){
                s[count-1]='J';
            }
            else if(guodu==11){
                s[count-1]='Q';
            }
            else if(guodu==12){
                s[count-1]='K';
            }
            else{
                s[count-1]=guodu+'0';
            }
        }
        else{
            if((n-'0'-(m-'0'))<0){
                s[count-1]=n-'0'-(m-'0')+10+'0';
            }
            else{
                s[count-1]=n-'0'-(m-'0')+'0';
            }
        }
        ++count;
    }
    for(int i=count-2;i>=0;--i){//要注意哦，数据存储的范围
        printf("%c",s[i]);
    }
    return 0;
}
