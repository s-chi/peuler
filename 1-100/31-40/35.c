#include <stdio.h>
#include <math.h>
#define PLIM 1000000

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
    
    int* isprime;
    int i, j, numdigs, lastdig, rest, num, circ, count=0;
    
    isprime = ptable();
    
    for(i=11;i<PLIM;i+=2){
        
        if(*(isprime+i)){            
            circ = 1;
            numdigs=2;
            while(i/((int) pow(10,numdigs)) > 0) numdigs++;
            
            num = i;
            
            for(j=0;j<numdigs-1;j++){
            
                lastdig = num % 10;
                rest = num/10;
                num = rest + lastdig * pow(10,numdigs-1);
                
                if(!(*(isprime+num))){
                    circ = 0;                
                    break;
                }
                
            }
            
            if(circ){
                printf("%d\n", i);
                count++;                
            }
            
        }
        
    }
    
    printf("\n%d\n", count+4);//add single digit primes
    
    
    return 0;
    
}
