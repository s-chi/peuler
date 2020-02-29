#include <stdio.h>
#define NTH 10001

int main(){
    
    int lastprime=3, counter=2, num=3, primes[NTH], i, isprime;
    primes[0]=2;
    primes[1]=3;
    
    while(counter<NTH){
        
        num += 2;
        isprime = 1;
        
        for (i=0;i<counter;i++){
            
            if (num % primes[i] == 0){
                
                isprime = 0;
                break;
                
            }
            
        }
        
        if (isprime){
            
            primes[counter] = num;
            counter++;
            
        }
        
    }
    
    printf("%d\n", primes[NTH-1]);
    return 0;
    
    
}
