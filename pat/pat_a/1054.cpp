/*Sample Input:
5 3
0 0 255 16777215 24
24 24 0 0 24
24 0 24 24 24
Sample Output:
24*/
#include <stdio.h>
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int countm=0,past,current;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
           // int current,past;
            scanf("%d",&current);
            if(countm==0){
                countm=1;
                past=current;
            }
            else{
                if(current!=past){
                    countm--;
                }
                else{
                    countm++;
                }
            }
        }
    }
    printf("%d",current);
    return 0;
}
