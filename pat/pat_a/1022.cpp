/*Sample Input:


3
1111111
The Testing Book
Yue Chen
test code debug sort keywords
ZUCS Print
2011
3333333
Another Testing Book
Yue Chen
test code sort keywords
ZUCS Print2
2012
2222222
The Testing Book
CYLL
keywords debug book
ZUCS Print2
2011
6
1: The Testing Book
2: Yue Chen
3: keywords
4: ZUCS Print
5: 2011
3: blablabla
Sample Output:
1: The Testing Book
1111111
2222*/
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
//#include <boost/regex.hpp>
using namespace std;
struct book{
    int id;
    string name;
    string author;
    char key[5][15];
    string pub;
    int year;
    int keyl;
};
book b[10010];
string str;
bool cmp(book a,book b){
    return a.id<b.id;
}
int mystoi(string s){
    int ans=0;
    for(int i=0;i<s.size();++i){
           // cout<<"ans"<<ans<<endl;
           // cout<<s[i]<<" "<<endl;
        ans=ans*10+s[i]-'0';
    //cout<<"ans"<<ans<<endl;
    }
    return ans;
}
int main(){
    int n;
    scanf("%d",&n);
   // printf("n=%d",n);
    getchar();
    for(int i=0;i<n;++i){
        //scanf("%d",&b[i].id);

            getline(cin,str);//接着n读一行，getchar（）之后接着读下一行
           // cout<<str<<endl;
            b[i].id=mystoi(str);
        getline(cin,b[i].name);
       // cout<<b[i].name<<endl;
        getline(cin,b[i].author);
        //cin>>str;
        int l=0,s=0;/*
        getline(cin,str);
        //cout<<"key= "<<str<<endl;
        //string str("dfa||fda||dfdf");
    for(int j=0;j<str.size();++j){
        if(str[j]!=' '){
            b[i].key[l][s++]=str[j];
        }
        else{
                b[i].key[l][s++]='\0';
//cout<<b[i].key[l]<<endl;
            l++;
            s=0;
            //b[i].key[l][s++]=str[j];
        }
    }*/

//cout<<b[i].key[l]<<" "<<l<<endl;
for(l=0;;++l){
    scanf("%s",b[i].key[l]);
    char c=getchar();
    if(c=='\n'){
        break;
    }
}

        //b[i].key=str.
        b[i].keyl=l;
        getline(cin,b[i].pub);
        //scanf("%d",&b[i].year);
        getline(cin,str);
        b[i].year=mystoi(str);
       // cout<<str<<" "<<b[i].year<<endl;
       // cout<<stoi("2011")<<endl;
    }
    sort(b,b+n,cmp);
    int m;
    scanf("%d",&m);
    //printf("m=%d ",m);
    int d,countb;
    string attr;
    for(int i=0;i<m;++i){
          //  getchar();
        scanf("%d: ",&d);
        printf("%d: ",d);
        getline(cin,attr);
        cout<<attr<<endl;
        countb=0;
        if(d==1){
            for(int j=0;j<n;++j){
               // if(strcmp(attr,b[j].name)==0){
                        if(attr==b[j].name){
                    printf("%d\n",b[j].id);
                    countb++;
                        }
               // }
            }
        }
        else if(d==2){
            for(int j=0;j<n;++j){
               // if(strcmp(attr,b[j].author)==0){
               if(attr==b[j].author){
                    printf("%d\n",b[j].id);
                    countb++;
                    }
               // }
            }
        }
        else if(d==3){
            for(int j=0;j<n;++j){
                    for(int k=0;k<=b[j].keyl;++k)
               // if(strcmp(attr,b[j].key[k])==0){
               if(attr==b[j].key[k]){
                    printf("%d\n",b[j].id);
                    countb++;
                    }
              // }
            }
        }
        else if(d==4){
            for(int j=0;j<n;++j){
              //  if(strcmp(attr,b[j].pub)==0){
              if(attr==b[j].pub){
                    printf("%d\n",b[j].id);
                    countb++;}
              //  }
            }
        }
        else if(d==5){
            for(int j=0;j<n;++j){
                    int y=mystoi(attr);
                if(y==b[j].year){
                    printf("%d\n",b[j].id);
                    countb++;
                }
            }
        }
       // scanf("%d: ",&d);
     //   getline(cin,attr);
     if(countb==0){
        printf("Not Found\n");

     }
    }
    return 0;
}
