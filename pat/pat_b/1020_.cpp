
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

struct Cake{
    double kucun;
    double shoujia;
    double danjia;
};

bool cmp(Cake a,Cake b)  //bool��int����
{
    return a.danjia > b.danjia;
}

int main()
{
    Cake cake[1010];
    int n,i=0;
    double xuqiu,shouyi=0;
    cin>>n>>xuqiu;
    for(i=0;i<n;i++)
    {
        cin>>cake[i].kucun;
    }//һ��Ҫ�ֿ�����
    for(i=0;i<n;i++)
    {
        cin>>cake[i].shoujia;
        cake[i].danjia=cake[i].shoujia/cake[i].kucun;
    }

    sort(cake,cake+n,cmp);

    int k=0;
    for(i=0;i<n;i++)
    {
        //cout<<cake[i].shoujia<<" ";
        if(cake[i].kucun <= xuqiu )
            {
                xuqiu-= cake[i].kucun;
                k++;
                shouyi+=cake[i].shoujia;
            }
            else{
                shouyi=shouyi+cake[i].danjia*xuqiu;
                break;//�����break
            }
    }
    //shouyi=shouyi+cake[k].danjia*xuqiu;  //֮ǰ����else,�����Ϊʲô����PAT�϶���ͨ��
    printf("%.2f\n",shouyi);
    //cout<<xuqiu;
    return 0;
}
