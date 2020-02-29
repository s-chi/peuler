#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PLIM 10000
#define LIM 50000000

int * ptable(){
    
    static int rarray[PLIM];
    int array[PLIM] = {0};
    int i, j, sroot = sqrt(PLIM);
    
    array[2] = 1;
    for(i=3;i<PLIM;i+=2) array[i] = 1;
    
    for(i=3;i<=sroot;i+=2){
        
        while(!array[i]) i+=2;
        
        if(array[i])
            for (j=i; j*i < PLIM; j+=2) 
                array[j*i] = 0;   
    }    
    
    rarray[0] = 2;
    j=1;
    for(i=3;i<PLIM;i+=2)
        if(array[i]){
            rarray[j] = i;
            j++;
        }
            
    return rarray;
    
}

int main(){
    
    int *primes,i,j,k,pow2,pow3,pow4,tot=0;
    char *nums;
    
    primes = ptable();
    nums = (char *) calloc(LIM,sizeof(char));
    
    i  = 0;
    pow2 = pow(primes[0],2);
    
    while(pow2<LIM-24){
        
        j = 0;
        pow3 = pow2 + pow(primes[0],3);
        
        while(pow3<LIM-16){
            
            k = 0;
            pow4 = pow3 + pow(primes[0],4);
            
            while(pow4<LIM){
                
                nums[pow4] = 1;             
                
                k++;
                pow4 = pow3 + pow(primes[k],4);
                
            }
            
            j++;    
            pow3 = pow2 + pow(primes[j],3);
        
        }
        
        i++;
        pow2 = pow(primes[i],2);
        
    }
    
    for(i=0;i<LIM;i++)
        if(nums[i])
            tot++;
    
    printf("%d\n",tot);
    return 0;    
    
}
