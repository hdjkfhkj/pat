/*
输入格式：

每个输入包含1个测试用例。每个测试用例第1行给出两个正整数N（<=10000，总人数）和K（<=10，总排数）。随后N行，每行给出一个人的名字（不包含空格、长度不超过8个英文字母）和身高（[30, 300]区间内的整数）。

输出格式：

输出拍照的队形。即K排人名，其间以空格分隔，行末不得有多余空格。注意：假设你面对拍照者，后排的人输出在上方，前排输出在下方。

输入样例：
10 3
Tom 188
Mike 170
Eva 168
Tim 160
Joe 190
Ann 168
Bob 175
Nick 186
Amy 160
John 159
输出样例：
Bob Tom Joe Nick
Ann Mike Eva
Tim Amy John
*/
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct p{
    char name[10];
    int height;
};
bool cmp(p a,p b){
    if(a.height!=b.height){
        return a.height>b.height;
    }
    else{
        if(strcmp(a.name,b.name)!=0){
            return strcmp(a.name,b.name)<0;
        }
    }
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    p pz[n];
    p row[n/k+k];
    for(int i=0;i<n;++i){
        scanf("%s %d",&pz[i].name,&pz[i].height);
    }
    sort(pz,pz+n,cmp);
   // for(int i=0;i<n;)
    int count=0;
    for(int i=0;i<k;++i){
            int j=n/k;
        if(i==0&&n%k!=0){
            j=n/k+n%k;
        }
        int s=0,l=0;
      while(s<j){
        if(s==0){
            row[j/2]=pz[count++];
            // printf("%s %d %d %d",row[j/2].name,count,row[j/2].height,j/2);
            ++s;
            if(s==j){
                break;
            }
        }
      else{
            row[j/2-l]=pz[count++];
            // printf("%s %d %d %d",row[j/2-l].name,count,row[j/2-l].height,j/2-l);
            ++s;
            if(s==j){
                break;
            }
            row[j/2+l]=pz[count++];
             //printf("%s %d %d %d",row[j/2+l].name,count,row[j/2+l].height,j/2+l);
            ++s;
            if(s==j){
                break;
            }
      }
      ++l;
      }
      //printf("\n");

      for(int t=0;t<j-1;++t){
        printf("%s ",row[t].name);
      }
      printf("%s\n",row[j-1].name);
    }

    return 0;
}
