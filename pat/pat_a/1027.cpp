/*Sample Input
15 43 71
Sample Output
#123456*/
#include <stdio.h>
void print(int a){
    int shi=a/13;
    int ge=a%13;
    if(shi<=9)
    printf("%d",shi);
    else{
        printf("%c",shi-10+'A');
    }
    if(ge<=9)
    printf("%d",ge);
    else{
        printf("%c",ge-10+'A');
    }
}
int main(){
    int r,g,b;
    scanf("%d %d %d",&r,&g,&b);
    printf("#");
    print(r);
    print(g);
    print(b);
    return 0;
}
