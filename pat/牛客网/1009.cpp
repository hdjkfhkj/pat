/*输入例子:
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0

输出例子:
Insertion Sort
1 2 3 5 7 8 9 4 6 0*/
/*Sample Input 1:
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
Sample Output 1:
Insertion Sort
1 2 3 5 7 8 9 4 6 0
Sample Input 2:
10
3 1 2 8 7 5 9 4 6 0
6 4 5 1 0 3 2 7 8 9
Sample Output 2:
Heap Sort
5 4 3 1 0 2 6 7 8 9*/
#include <stdio.h>
#include <algorithm>
#define maxn 110
using namespace std;
int s[maxn],in[maxn];
int flag=0;
void sift(int a[],int low,int high){
    if(low<high){
            int i=low,j=2*i+1;
        while(j<=high){
            if(j+1<=high){
                if(a[j+1]>a[j]){
                    j=j+1;
                }
            }
            if(a[j]>a[i]){
            int temp=a[j];
            a[j]=a[i];
            a[i]=temp;
           // printf("%d %d\n",a[i],a[j]);
            i=j;
            if(2*i+1<=high){
                j=2*i+1;
            }
            else{
                break;
            }
           // printf("%d %d\n",i,j);
        }
        else{
            break;
        }
    }
}
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&s[i]);
    }
    for(int i=0;i<n;++i){
        scanf("%d",&in[i]);
    }
    int k;
    for(int i=0;i<n-1;++i){
        if(in[i]>in[i+1]){
                k=i+1;
            break;
        }
    }
    for(int i=k;i<n;++i){
        if(in[i]!=s[i]){
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("Insertion Sort\n");
        sort(in,in+k+1);
    }
    else{
        printf("Heap Sort\n");
        int k;
        for(int i=n-1;i>0;--i){
            if(in[i]<in[0]){
                k=i;
                break;
            }
        }
        int temp=in[0];
        in[0]=in[k];
        in[k]=temp;
        sift(in,0,k-1);
    }
    for(int i=0;i<n;++i){
        if(i<n-1){
            printf("%d ",in[i]);
        }
        else{
            printf("%d",in[i]);
        }
    }
    return 0;
}
