#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define LIM 1000000
#define PLIM 2000000
#define TARGET 0.42857142857142857143 //3/7
#define SNUM 2 //starting fraction
#define SDEN 5
//we look for the largest proper fraction < 3/7 with denominator <= LIM

int * ptable(int *pnum){
    
    int *rarray, *array;
    int i, j, sroot = sqrt(PLIM);
    
    array = (int *) malloc(PLIM*sizeof(int));
    memset(array,0,PLIM*sizeof(int));
    
    array[2] = 1;

    for(i=3;i<PLIM;i+=2) array[i] = 1;
    
    for(i=3;i<=sroot;i+=2){
        
        while(!array[i]) i+=2;
        
        if(array[i])
            for (j=i; j*i < PLIM; j+=2) 
                array[j*i] = 0;   
    }    
    
    *pnum=1;
    for(i=3;i<PLIM;i+=2)
        if(array[i])
            (*pnum)++;
        
    rarray = (int *) malloc((*pnum)*sizeof(int));
    
    *pnum = 1;
    *rarray = 2;
    
    for(i=3;i<PLIM;i+=2)
        if(array[i]){
            *(rarray+(*pnum)) = i;
            (*pnum)++;            
        }
    
    (*pnum)--;
    
    free(array);
            
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
    
    int num,den,prevnum,prevden;
    int *primes,maxprime;
    double frac, prevfrac;
    
    primes = ptable(&maxprime);
    
    num = SNUM; 
    den = SDEN;
    frac = ((double)num/den);
    prevnum = 0;
    prevden = 1;
    prevfrac = 0.;
    
    while(den <= LIM){
        
        while(den <= LIM){
            
            if(frac < TARGET){
                prevnum = num;
                prevden = den;
                prevfrac = frac;
            }
            
            num++;
            
            while(frac >= TARGET && frac > prevfrac){ //max den -> den + 3
                den++;
                frac = ((double)num/den);            
            }
            
            if (frac <= prevfrac){
                den--;
                frac = ((double)num/den);
            }
            
        }
        
        simplify(&num,&den,primes);//if after simplification den>LIM, either the fraction was already simplified or den was at least 2*LIM -->  impossible for LIM>3-->no need to increase num further
        
    }
    
    free(primes);
    
    printf("\n%d/%d\n",prevnum,prevden);
    return 0;    
    
}
