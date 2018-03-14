/*著名的快速排序算法里有一个经典的划分过程：我们通常采用某种方法取一个元素作为主元，通过交换，把比主元小的元素放到它的左边，比主元大的元素放到它的右边。 给定划分后的N个互不相同的正整数的排列，请问有多少个元素可能是划分前选取的主元？

例如给定N = 5, 排列是1、3、2、4、5。则：

1的左边没有元素，右边的元素都比它大，所以它可能是主元；
尽管3的左边元素都比它小，但是它右边的2它小，所以它不能是主元；
尽管2的右边元素都比它大，但其左边的3比它大，所以它不能是主元；
类似原因，4和5都可能是主元。
因此，有3个元素可能是主元。

输入格式：

输入在第1行中给出一个正整数N（<= 105）； 第2行是空格分隔的N个不同的正整数，每个数不超过109。

输出格式：

在第1行中输出有可能是主元的元素个数；在第2行中按递增顺序输出这些元素，其间以1个空格分隔，行末不得有多余空格。

输入样例：
5
1 3 2 4 5
输出样例：
3
1 4 5*/
//聪明的人实在是太聪明了、、、、左边都是小于他的（左边的最大值小于他），他又在最终位置，右边自然就都是大于它的
#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int a[n],b[n];
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    int count=0,k=0;
    for(int i=0;i<n;++i){
            int flag=1;//yes
        for(int j=0;j<i;++j){
            if(a[j]>a[i]){//bushizhuyuan
                flag=0;//no
                break;
            }
        }
        if(flag==1){
            for(int j=i+1;j<n;++j){
            if(a[j]<a[i]){//bushizhuyuan
                flag=0;
                break;
            }
        }
        }
    if(flag){
        b[k++]=a[i];//不要轻易改变数组！！！！！！！！！！！！！！！！！！
        ++count;
    }
    }
    printf("%d\n",count);
    sort(b,b+count);
    for(int i=0;i<k;++i){
        if(count>1){
            printf("%d ",b[i]);
            count--;
        }
        else if(count==1){
            printf("%d",b[i]);
        }
    }
    printf("\n");
    return 0;
}
