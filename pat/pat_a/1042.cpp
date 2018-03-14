/*Sample Input:

2
36 52 37 38 3 39 40 53 54 41 11 12 13 42 43 44 2 4 23 24 25 26 27 6 7 8 48 49 50 51 9 10 14 15 16 5 17 18 19 1 20 21 22 28 29 30 31 32 33 34 35 45 46 47
Sample Output:
S7 C11 C10 C12 S1 H7 H8 H9 D8 D9 S11 S12 S13 D10 D11 D12 S3 S4 S6 S10 H1 H2 C13 D2 D3 D4 H6 H3
 D13 J1 J2 C1 C2 C3 C4 D1 S5 H5 H11 H12 C6 C7 C8 C9 S2 S8 S9 H10 D5 D6 D7 H4 H13 C5
*/
#include <stdio.h>
int ans[55],in[55],out[55];
char mp[10]={'S','H','C','D','J'};
int main(){
    int k;
    scanf("%d",&k);
    for(int i=1;i<=54;++i){
        scanf("%d",&in[i]);
        ans[in[i]]=i;
        out[in[i]]=i;
    }
    for(int i=0;i<k-1;++i){
        for(int j=1;j<=54;++j){
            ans[in[j]]=out[j];
        }
        for(int j=1;j<=54;++j){
            out[j]=ans[j];
        }
    }
    for(int i=1;i<=54;++i){
            if(i<54)
        printf("%c%d ",mp[(ans[i]-1)/13],(ans[i]%13==0)?13:ans[i]%13);
    else{
        printf("%c%d",mp[(ans[i]-1)/13],(ans[i]%13==0)?13:ans[i]%13);
    }
    }
    return 0;
}
