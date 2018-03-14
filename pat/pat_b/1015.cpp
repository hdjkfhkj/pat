/*
宋代史学家司马光在《资治通鉴》中有一段著名的“德才论”：“是故才德全尽谓之圣人，才德兼亡谓之愚人，德胜才谓之君子，才胜德谓之小人。凡取人之术，苟不得圣人，君子而与之，与其得小人，不若得愚人。”

现给出一批考生的德才分数，请根据司马光的理论给出录取排名。

输入格式：

输入第1行给出3个正整数，分别为：N（<=105），即考生总数；L（>=60），为录取最低分数线，即德分和才分均不低于L的考生才有资格被考虑录取；H（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；德才分均低于H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；其他达到最低线L的考生也按总分排序，但排在第三类考生之后。

随后N行，每行给出一位考生的信息，包括：准考证号、德分、才分，其中准考证号为8位整数，德才分为区间[0, 100]内的整数。数字间以空格分隔。

输出格式：

输出第1行首先给出达到最低分数线的考生人数M，随后M行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。

输入样例：
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
输出样例：
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90*/
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct stu{
    int no;
    int de;
    int cai;
    int sum;
};
vector<stu> l1,l2,l3,l4;
bool cmp(stu a,stu b){
    if(a.sum!=b.sum)
        return a.sum>b.sum;
    else if(a.sum==b.sum){
        if(a.de!=b.de){
            return a.de>b.de;
        }
        else if(a.de==b.de){
            if(a.no!=b.no)
                return a.no<b.no;
        }
    }
}
int main(){
    int n,l,h,count=0;
    stu sample;
    scanf("%d %d %d",&n,&l,&h);
    for(int i=0;i<n;++i){
        scanf("%d %d %d",&sample.no,&sample.de,&sample.cai);
        sample.sum=sample.de+sample.cai;
        if(sample.de>=l&&sample.cai>=l){
                count++;
        if(sample.de>=h&&sample.cai>=h){
            l1.push_back(sample);
            /*l1[j].no=no;
            l1[j].de=de;
            l1[j].cai=cai;
            l1[j].sum=sum;
            j++;*/
        }
        else if(sample.de>=h){
            l2.push_back(sample);
        }
        else if((sample.de<h)&&sample.de>=sample.cai){
            l3.push_back(sample);
        }
        else{
            l4.push_back(sample);
        }
      }
    }
    sort(l1.begin(),l1.end(),cmp);
    sort(l2.begin(),l2.end(),cmp);
    sort(l3.begin(),l3.end(),cmp);
    sort(l4.begin(),l4.end(),cmp);

    printf("%d\n",count);

    for(int i=0;i<l1.size();++i){
        printf("%d %d %d\n",l1[i].no,l1[i].de,l1[i].cai);
    }
     for(int i=0;i<l2.size();++i){
        printf("%d %d %d\n",l2[i].no,l2[i].de,l2[i].cai);
    }
     for(int i=0;i<l3.size();++i){
        printf("%d %d %d\n",l3[i].no,l3[i].de,l3[i].cai);
    }
     for(int i=0;i<l4.size();++i){
        printf("%d %d %d\n",l4[i].no,l4[i].de,l4[i].cai);
    }
    return 0;
}
