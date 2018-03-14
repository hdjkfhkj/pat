/*Sample Input 1:
7 5 31 5 88 67 88 17
Sample Output 1:
31
Sample Input 2:
5 888 666 666 888 888
Sample Output 2:
None*/
#include <stdio.h>
#include <algorithm>
using namespace std;
struct md{
    int times;
    int order;
    int data;
};
md in[10010];
int n;
bool cmp(md a,md b){
    return a.order<b.order;
}
void init(){
    for(int i=0;i<10010;++i){
        in[i].order=0;
        in[i].times=0;
    }
}
int main(){//汗。。。。。。。。。。。。。直接用两个数组就好了。。。。。。。。。。。。
    int flag=0;
    scanf("%d",&n);
    init();
    for(int i=0;i<n;++i){
        int a;
        scanf("%d",&a);
      //  printf(" %d",a);
        in[a].times++;
        in[a].order=i+1;
        in[a].data=a;

    }
  //  printf("sdfg    %d         ",in[31].times);
    sort(in,in+10010,cmp);
    for(int i=0;i<10010;++i){
        if(in[i].times==1){
              //  printf("dgfhg");
                flag=1;
            printf("%d",in[i].data);
            break;
        }
    }
    if(flag==0){
        printf("None");
    }
    return 0;
}
