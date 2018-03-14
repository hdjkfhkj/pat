/*Sample Input:
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
Sample Output:
YES
NO
NO
YES
NO*/
#include <stdio.h>
int s[1010]={0};
int in[1010],n;
void init(){
    for(int i=0;i<=n;++i){
        in[i]=0;
    }
}
int main(){
    int m,n,k;
    scanf("%d %d %d",&m,&n,&k);
    for(int i=0;i<k;++i){
            int md,zz=0;
            for(int j=0;j<=n;++j){
        in[j]=0;
    }
        for(int j=0;j<n;++j){

            scanf("%d",&md);
           // in[md]=1;//mark the output
            if(md>m){
                if(md-j>m){
             //   printf("aaaaaaaaaNO\n");
                   s[i]=1;
                }
            }
            if(zz>md){
                    int l;
                    for(l=zz-1;in[l]==1;--l){
                      //  printf("ssssssss%d %d\n",l,in[l]);
                    }//l mark the biggest unoutputed number
                if(md!=l){
                 //  printf("xxxxxxNO %d %d\n",md,l);
                   s[i]=1;
                }
            }
            in[md]=1;
            zz=md;
        }
        if(s[i]==1){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
    return 0;
}
