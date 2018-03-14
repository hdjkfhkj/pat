/*输入样例：
8
123 899 51 998 27 33 36 12
输出样例：
4
3 6 9 26*/
#include <stdio.h>
#include <set>
using namespace std;
int main(){
    int n,countn=0;
    scanf("%d",&n);
    set<int> id;
    for(int i=0;i<n;++i){
        char c[10];
        scanf("%s",c);
        int sum=0;
        for(int j=0;c[j]!='\0';++j){
            sum+=c[j]-'0';
        }
        id.insert(sum);
    }
    printf("%d\n",id.size());
    set<int>::iterator it;
    for(it=id.begin();it!=id.end();++it){
        if(it==id.begin()){
            printf("%d",*it);
        }
        else{
            printf(" %d",*it);
        }
    }
    return 0;
}
