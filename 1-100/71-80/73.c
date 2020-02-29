#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define LIM 12000
#define LNUM 1
#define LDEN 3
#define RNUM 1
#define RDEN 2

int * ptable(){
    
    static int rarray[LIM];
    int array[LIM] = {0};
    int i, j, sroot = sqrt(LIM);
    
    array[2] = 1;
    for(i=3;i<LIM;i+=2) array[i] = 1;
    
    for(i=3;i<=sroot;i+=2){
        
        while(!array[i]) i+=2;
        
        if(array[i])
            for (j=i; j*i < LIM; j+=2) 
                array[j*i] = 0;   
    }    
    
    rarray[0] = 2;
    j=1;
    for(i=3;i<LIM;i+=2)
        if(array[i]){
            rarray[j] = i;
            j++;
        }
            
    return rarray;
    
}

void simplify(int *num, int *den, int primes[]){
    
    int i=0;
    
    while(primes[i]<=*num){
        
        while(*num % primes[i] == 0 && *den % primes[i] == 0){
            
            *num /= primes[i];
            *den /= primes[i];            
            
        }
        
        i++;        
    } 
    
    return;
    
}

int main(){
    
    int num, nummax, tnum, den, tden, fractot=0;
    int *primes;
    
    primes = ptable();
    
    for(den=2; den<=LIM; den++){
        
        nummax = (den*RNUM - 1)/RDEN;
        
        for(num = (den*LNUM)/LDEN + 1; num<=nummax; num++){
            
            tnum = num;
            tden = den;
            simplify(&tnum,&tden,primes);
            
            if(tnum==num)
                fractot++;            
            
        }
        
        
    }
    
    printf("%d\n",fractot);
    
    
    return 0;
    
}
