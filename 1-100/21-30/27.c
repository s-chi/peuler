#include <stdio.h>
#include <math.h>
#define LIM 1000
#define PLIM ((2*LIM*LIM + LIM)/2)

int * ptable(){
    
    int array[PLIM];
    static int rarray[PLIM];
    int i, j, sroot = sqrt(PLIM*2);
    
    for(i=0;i<PLIM;i++) array[i] = 3+2*i;
    
    for(i=0;i<PLIM;i++){
        
        while(!array[i] && i < PLIM - 1) i++;
        if(i > PLIM - 1) break;
        if(array[i]<sroot && array[i]!=0)
            for (j=array[i]; j*array[i] < PLIM*2; j+=2) array[(j*array[i]-3)/2] = 0;
        
    }
    
    rarray[0] = 2;
    j = 1;
    
    
    
    for(i=0;i<PLIM;i++){        
        if(array[i]!=0){
            
            rarray[j] = array[i];
            j++;
            
        }        
    }
    
    return rarray;
    
}

int isprime(unsigned num, int ptable[PLIM]){
    
    int ind, sqnum;
    
    sqnum = sqrt(num);
    
    ind = 0;
    
    while(ptable[ind] <= sqnum){
        
        if (num % ptable[ind] == 0) return 0;
        
        ind++;
        
    }
    
    return 1;
    
    
} 


int main(){
    
    int n, a, b, num, maxa, maxb, max = 0;
    int *primes, *bpoint;
    
    primes = ptable();
    
    for(a = 1-LIM; a < LIM; a++){
        
        for(bpoint = primes; *bpoint <= LIM; bpoint++){//b must be prime
            
            n = 0;
            
            while(1){
                
                num = (n + a) * n + *bpoint;
                
                if(num < 2) break;
                
                if(!isprime(num, primes)) break;
                
                n++;
                
            }
            
            
            if (n > max){
                
                max = n;
                maxa = a;
                maxb = *bpoint;
                
            }
            
        }
        
    }
    
    
    printf("(n + %d) * n + %d generates %d consecutive primes\n", maxa, maxb, max);
    printf("a * b = %d\n", maxa*maxb);
    
    return 0;
    
}
