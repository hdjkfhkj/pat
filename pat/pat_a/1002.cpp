/*This time, you are supposed to find A+B where A and B are two polynomials.

Input

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10£¬0 <= NK < ... < N2 < N1 <=1000.

Output

For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 2 1.5 1 2.9 0 3.2*/
#include <stdio.h>
struct poly{
    int ex;
    double co;
};
int main(){
    int k1,k2;
    scanf("%d",&k1);
    poly p1[k1],ans[20];
    for(int i=0;i<k1;++i){
        scanf("%d %lf",&p1[i].ex,&p1[i].co);
    }
    scanf("%d",&k2);
    poly p2[k2];
    for(int i=0;i<k2;++i){
        scanf("%d %lf",&p2[i].ex,&p2[i].co);
    }
    int k=0;
    for(int i=0,j=0;i<k1||j<k2;++k){
            if(j==k2){
                ans[k]=p1[i];
                ++i;
            }
            else if(i==k1){
                ans[k]=p2[j];
                ++j;
            }
            else{
        if(p1[i].ex>p2[j].ex){
            ans[k]=p1[i];
            i++;
        }
        else if(p1[i].ex==p2[j].ex){
            ans[k].ex=p1[i].ex;
            ans[k].co=p1[i].co+p2[j].co;
            ++i;
            ++j;
        }
        else{
            ans[k]=p2[j];
            ++j;
        }
            }
    }
    int count=0;
    for(int i=0;i<k;++i){
            if(ans[i].co!=0)
        count++;
    }
    printf("%d",count);
    for(int i=0;i<k;++i){
            if(ans[i].co!=0)
        printf(" %d %.1f",ans[i].ex,ans[i].co);
    }
    return 0;
}
