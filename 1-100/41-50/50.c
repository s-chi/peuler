#include <stdio.h> 
#include <math.h>
#define PLIM 1000000

int * ptable(){
    
    static int array[PLIM];
    int i, j, sroot = sqrt(PLIM);
    
    array[2] = 1;
    for(i=3;i<PLIM;i+=2) array[i] = 1;
    
    for(i=3;i<=sroot;i+=2){
        
        while(!array[i]) i+=2;
        
        if(array[i])
            for (j=i; j*i < PLIM; j+=2) 
                array[j*i] = 0;   
    }
    
    return array;
    
}

int main(){
    
    int *isprime, maxcount = 1, count, sum, i, startprime = 2, maxnum, maxstart;
    
    isprime = ptable();    
    
    while(startprime < PLIM){
        
        sum = startprime;
        count = 1;
        
        i = startprime + 1;
        
        while(sum < PLIM){
            
            while(i < PLIM && !*(isprime+i)) i++;
            if(i>=PLIM) break;
            
            sum += i;
            if (sum > PLIM) break;
            
            count++;
            
            if(*(isprime+sum) && count > maxcount){
                
                maxstart = startprime;
                maxnum = sum;
                maxcount = count;
                
            }
            
            i++;        
            
        }
        
        startprime++;
        while(startprime < PLIM && !*(isprime+startprime)) startprime++;      
        
    }
    
    printf("%d can be written as the sum of %d consecutive primes, starting from %d\n", maxnum, maxcount, maxstart);
    
    
    return 0;
    
}
