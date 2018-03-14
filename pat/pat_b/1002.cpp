/*读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10100。

输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789
输出样例：
yi san wu*/
#include <string>
#include <iostream>
using namespace std;
string pin[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

int main(){
    string s;
    int i=0,m=0;
    cin>>s;
    while(s[i]!='\0'){
        m+=s[i]-'0';
        i++;
    }
    if(m>=100)
     cout<<pin[m/100]<<" "<<pin[(m/10)%10]<<" "<<pin[m%10];
    //printf("%s %s %s",pin[m/100],pin[(m/10)%10],pin[m%10]);
    else if(m>=10)
     cout<<pin[m/10]<<" "<<pin[m%10];
    else
     cout<<pin[m];
    return 0;
}

