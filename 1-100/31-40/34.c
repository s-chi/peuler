#include <stdio.h>
#define LIM 10000000
//it can be shown that if the number has more than 7 digits the sum of
// factorials is always smaller than the number

int fac(unsigned n){    
    if(n < 2) return 1;
    return n*fac(n-1);    
}

int main(){
    
    int digits[8] = {0}, i, j, psum, tsum = 0, dignum = 2;
    
    digits[0] = 1;
    digits[1] = 1;
    
    for(i=11;i<LIM;i++){
        
        psum = 0;
        for(j=0;j<dignum;j++) 
            psum += fac(digits[j]);
        
        if(psum==i){
            tsum += i;
            printf("%d\n",i);            
        }
        
        digits[0]++;
        
        for(j=0;j<dignum;j++){
            if(digits[j]>9){
                digits[j+1] += digits[j]/10;
                digits[j] %= 10;                
            }
        }
        
        if(digits[dignum]) dignum++;
        
    }
    
    printf("\nsum = %d\n", tsum);
    
    return 0;
    
}
