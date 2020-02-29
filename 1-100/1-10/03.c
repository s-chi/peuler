#include <stdio.h>

int main(){
    
    long num = 600851475143L, maxfac = 1, fac = 1;
    
    while(maxfac < num){
        
        fac++;
//         printf("%ld,%ld\n", fac, num);
        while (num % fac == 0){
            
            maxfac = fac;
            num = num/fac;
//             printf("%ld\n", fac);
            
        }
        
    }
    
    printf("%ld\n", maxfac);
    return 0;    
    
}
