/*Sample Input:
12
Pop
Push 3
Push 2
Push 1
Pop
Pop
Push 5
Push 4
Pop
Pop
Pop
Pop
Sample Output:
Invalid
Invalid
3
2
2
1
2
4
4
5
3
Invalid*/
#include <cstdio>
#include <stack>
#include <math.h>
#define sqrn 316;
using namespace std;
stack<int> s;
int block[320]={0};
int table[100010]={0};
void push(int x){
    int index=x/sqrn;
    block[index]++;
    table[x]++;
}
void pop(int x){
    int index=x/sqrn;
    block[index]--;
    table[x]--;
}
void PeekMedian(int k) {
    int sum=0,index=0;
    while(sum+block[index]<k){
        sum+=block[index++];
    }
    int num=index*sqrn;
    while(sum+table[num]<k){
        sum+=table[num++];
    }
    printf("%d\n",num);
}
int main() {
    int n, temp;
    scanf("%d", &n);
    char str[15];
    for(int i = 0; i < n; i++) {
        scanf("%s", str);
        if(str[1] == 'u') {
            scanf("%d", &temp);
            s.push(temp);
            push(temp);
        } else if(str[1] == 'o') {
            if(!s.empty()) {
               // update(s.top(), -1);
                printf("%d\n", s.top());
                pop(s.top());
                s.pop();
            } else {
                printf("Invalid\n");
            }
        } else {
            if(!s.empty()){
                    int k=ceil(s.size()/2.0);

                PeekMedian(k);
            }
            else
                printf("Invalid\n");
        }
    }
    return 0;
}
