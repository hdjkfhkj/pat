#include <stdio.h>
#include <string.h>
#include <stack>
#include <vector>
#include <algorithm>
#define maxn 100010
using namespace std;
stack<int> s;
int table[maxn]={0};
int block[400]={0};
int pm(int k){
    int sum=0,c=0;
    while(sum<k){
        sum+=block[c++];
    }
    c--;
    sum-=block[c];
int countm=sum;
int i;
for(i=c*400;i<c*400+400;++i){
    countm+=table[i];
    if(countm>=k){
        break;
    }
}
return i;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
          //  printf("%d\n",i);
        char in[20];
        int key;
        scanf("%s",in);
        if(strcmp(in,"Pop")==0){
            if(s.empty()==true){
                printf("Invalid\n");
            }
            else{
                int data=s.top();
                s.pop();
                table[data]--;
                block[data/400]--;
                printf("%d\n",data);
            }
        }
        else if(strcmp(in,"PeekMedian")==0){
            if(s.empty()){
                printf("Invalid\n");
            }
            else{
                    int k=(s.size()+1)/2;
                int data=pm(k);
                printf("%d\n",data);
            }
        }
        else{
            scanf("%d",&key);
            s.push(key);
            table[key]++;
                block[key/400]++;
        }
    }
    return 0;
}
