/*
�δ�ʷѧ��˾����ڡ�����ͨ��������һ�������ġ��²��ۡ������ǹʲŵ�ȫ��ν֮ʥ�ˣ��ŵ¼���ν֮���ˣ���ʤ��ν֮���ӣ���ʤ��ν֮С�ˡ���ȡ��֮����������ʥ�ˣ����Ӷ���֮�������С�ˣ����������ˡ���

�ָ���һ�������ĵ²ŷ����������˾�������۸���¼ȡ������

�����ʽ��

�����1�и���3�����������ֱ�Ϊ��N��<=105����������������L��>=60����Ϊ¼ȡ��ͷ����ߣ����·ֺͲŷ־�������L�Ŀ��������ʸ񱻿���¼ȡ��H��<100����Ϊ����¼ȡ�ߡ����·ֺͲŷ־������ڴ��ߵı�����Ϊ���ŵ�ȫ���������࿼�����²��ִܷӸߵ������򣻲ŷֲ������·ֵ��ߵ�һ�࿼�����ڡ���ʤ�š���Ҳ���ܷ����򣬵����ڵ�һ�࿼��֮�󣻵²ŷ־�����H�����ǵ·ֲ����ڲŷֵĿ������ڡ��ŵ¼����������С���ʤ�š��ߣ����ܷ����򣬵����ڵڶ��࿼��֮�������ﵽ�����L�Ŀ���Ҳ���ܷ����򣬵����ڵ����࿼��֮��

���N�У�ÿ�и���һλ��������Ϣ��������׼��֤�š��·֡��ŷ֣�����׼��֤��Ϊ8λ�������²ŷ�Ϊ����[0, 100]�ڵ����������ּ��Կո�ָ���

�����ʽ��

�����1�����ȸ����ﵽ��ͷ����ߵĿ�������M�����M�У�ÿ�а��������ʽ���һλ��������Ϣ��������������˵���Ĺ���Ӹߵ������򡣵�ĳ�࿼�����ж����ܷ���ͬʱ������·ֽ������У����·�Ҳ���У���׼��֤�ŵ����������

����������
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
���������
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
