/*
�����ʽ��

ÿ���������1������������ÿ������������1�и�������������N��<=10000������������K��<=10���������������N�У�ÿ�и���һ���˵����֣��������ո񡢳��Ȳ�����8��Ӣ����ĸ������ߣ�[30, 300]�����ڵ���������

�����ʽ��

������յĶ��Ρ���K������������Կո�ָ�����ĩ�����ж���ո�ע�⣺��������������ߣ����ŵ���������Ϸ���ǰ��������·���

����������
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
���������
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
