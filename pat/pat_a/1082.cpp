/*Sample Input 1:
-123456789
Sample Output 1:
Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu
Sample Input 2:
100800
Sample Output 2:
yi Shi Wan ling ba Bai*/
#include <stdio.h>
#include <string.h>
char c[10][10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main(){
    char in[20];
    scanf("%s",in);
    int i=0;
    if(in[0]=='-'){
        printf("Fu ");
        i=1;
    }
    int l=strlen(in);
    int be=i;
    if(in[i]=='0'){
        printf("ling");
    }
    for(i;i<l;++i){
            if(in[i]!='0'){
                if(i==be){
                     printf("%s",c[in[i]-'0']);
                }
                else
            printf(" %s",c[in[i]-'0']);
            if(l-i==8||l-i==4){
                printf(" Qian");
            }
            if(l-i==7||l-i==3){
                printf(" Bai");
            }
            if(l-i==6||l-i==2){
                printf(" Shi");
            }
            }
            else{
                if(in[i+1]>='1'&&in[i+1]<='9'){
                    printf(" ling");
                }
            }
        if(l-i==9){
            printf(" Yi");
        }
        if(l-i==5){
            printf(" Wan");
        }
    }
}
