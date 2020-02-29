#include <stdio.h>
#include <math.h>
#define EXPO 5
#define DIGS 6
#define MAXN 1000000 // 10^DIGS

// \Sum_{i=0}^n a_i (a_i^4-10^i) = 0, with 0 <= a_i <= 9, a_n != 0
// It can be verified that if n>=6 the above expression is always negative
// ==> n_max = 5 ==> DIGS = n_max + 1 = 6

int main(){
    
    int digs[DIGS] = {0};
    int i, n, sum = 0, expsum;
    
    digs[0] = 2;
    
    for (n=2;n<MAXN;n++) {
        
        expsum = 0;
        
        for (i=0;i<DIGS;i++){
            
            expsum += pow(digs[i], EXPO);

        }
        
        if (expsum == n) {
            
            printf("%d\n", n);
            sum += n;
            
        }
        
        digs[0]++;
        for (i=0;i<DIGS-1;i++){
            
            if (digs[i]>=10){
                
                digs[i+1] += digs[i]/10;
                digs[i] %= 10;
                
            }
            
        }
        
        
    }
    
    printf("\n%d\n", sum);
    return 0;
    
}
