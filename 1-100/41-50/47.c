#include <stdio.h>
#include <math.h>
#define PLIM 1000000
#define NFAC 4


int * ptable(){
    
    static int array[PLIM];
    int i, j, sroot = sqrt(PLIM);
    
    array[2] = 1;
    for(i=3;i<PLIM;i+=2) array[i] = 1;
    
    for(i=3;i<sroot;i+=2){
        
        while(!array[i]) i+=2;
        
        if(array[i])
            for (j=i; j*i < PLIM; j+=2) 
                array[j*i] = 0;   
    }
    
    return array;
    
}

int main(){
    
    int factors[NFAC][NFAC], num=1, tnum, cons = 0, prime, factop;
    int *isprime;
    
    isprime = ptable();
    
    while(1){
        
        num++;
        factop = 0;
        tnum = num;
        prime=0;
        
        while(tnum > 1){
            
            while(*(isprime+prime) == 0) prime++;
            
            while(tnum % prime == 0){
                
                tnum /= prime;
                if(factop == 0 || factors[cons][factop - 1] != prime){
                    
                    factors[cons][factop] = prime;
                    factop++;
                    
                }
                
            }
            
            if(factop == NFAC) break;
            
            prime++;
            
        }
        
        if(factop == NFAC){
            
            cons++;
            if (cons == NFAC){
                
                printf("%d\n", num + 1 - NFAC);
                return 0;
                
            }
            
        } else cons = 0;
        
    }
    
    
    return 0;
}
