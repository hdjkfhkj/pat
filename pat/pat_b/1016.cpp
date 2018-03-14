/*正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。

现给定A、DA、B、DB，请编写程序计算PA + PB。

输入格式：

输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。

输出格式：

在一行中输出PA + PB的值。

输入样例1：
3862767 6 13530293 3
输出样例1：
399
输入样例2：
3862767 1 13530293 8
输出样例2：
0*/
//string 和char有很大不同
//他妈的到底哪错了啊
//先放这算了。。。
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main(){
    char a[11],b[11];
    int da,db,i=0,counta=0,countb=0;
    long long pa=0,pb=0;
    //cin>>a>>da>>b>>da;
    //cin>>a;
    scanf("%s %d %s %d",a,&da,b,&db);
    //cin>>b;
    //scanf("%d",&da);
    while(a[i]!='\0'){//定义为string，就不能这样用
        if((a[i]-'0')==da)
            ++counta;
        i++;
    }
    i=0;
    while(b[i]!='\0'){
        if((b[i]-'0')==db)
            ++countb;
        i++;
    }
    //cout<<counta<<countb<<endl;
    while(counta--){
        pa=(pa*10+da);
    }
    while(countb--){
        pb=(pb*10+db);
    }
    //cout<<(pa+pb);
    printf("%ld\n",(pa+pb));
    return 0;
}
