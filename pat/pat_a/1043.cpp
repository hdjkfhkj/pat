/*Sample Input 1:
6
8 6 5 7 10 11
Sample Output 1:
YES
5 7 6 8 11 10 8
Sample Input 2:
7
8 10 11 8 6 7 5
Sample Output 2:
YES
11 8 10 7 5 6 8
Sample Input 3:
7
8 6 8 5 10 9 11
Sample Output 3:
NO*/
#include <stdio.h>
int in[1010];
bool preb(int in[],int l1,int l2){
    if(l1<l2){
        int pivot=l2+1;
        int i;
        for(i=l1+1;i<=l2;++i){
            if(in[i]>=in[l1]){
                pivot=i;
                break;
            }
        }
        for(i=pivot;i<=l2;++i){
            if(in[i]<in[l1]){
                return false;
            }
        }
        return preb(in,l1+1,pivot-1)&&preb(in,pivot,l2);
    }
    if(l1==l2){
        return true;
    }
}
bool prem(int in[],int l1,int l2){
    if(l1<l2){
        int pivot=l2+1;
        int i;
        for(i=l1+1;i<=l2;++i){
            if(in[i]<in[l1]){
                pivot=i;
                break;
            }
        }
        for(i=pivot;i<=l2;++i){
            if(in[i]>=in[l1]){
                return false;
            }
        }
        return prem(in,l1+1,pivot-1)&&prem(in,pivot,l2);
    }
    if(l1==l2){
        return true;
    }
}
void postb(int in[],int l1,int l2){
    if(l1<=l2){
        int pivot=in[l1];
        int i;
        for(i=l1+1;i<=l2;++i){
            if(in[i]>=pivot){
                break;
            }
        }
        postb(in,l1+1,i-1);
        postb(in,i,l2);
        if(l1!=0)
        printf("%d ",in[l1]);
        else{
            printf("%d",in[l1]);
        }
    }
}
void postm(int in[],int l1,int l2){
    if(l1<=l2){
        int pivot=in[l1];
        int i;
        for(i=l1+1;i<=l2;++i){
            if(in[i]<pivot){
                break;
            }
        }
        postm(in,l1+1,i-1);
        postm(in,i,l2);
        if(l1==0)
        printf("%d",in[l1]);
        else{
             printf("%d ",in[l1]);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&in[i]);
    }
    if(preb(in,0,n-1)==true){
        printf("YES\n");
        postb(in,0,n-1);
    }
    else if(prem(in,0,n-1)==true){
printf("YES\n");
        postm(in,0,n-1);
    }
    else{
        printf("NO");
    }
    return 0;
}
