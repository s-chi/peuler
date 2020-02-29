#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define LIM 1000000
#define FACN 8//max number of distinct prime factors for a number<=LIM (the product of the first FACN prime numbers > LIM) 
//for every denominator d there is a number of proper fractions equal to phi(d), where phi is the totient function
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

void join(int newprime, int *oldfacs, int *newfacs){
    
    int i=0,j;
    
    *(newfacs) = newprime;
    
    if (*oldfacs == newprime)
        i=1;
    
    for(j=1;j+i<FACN;j++)
        *(newfacs+j) = *(oldfacs+j+i-1);    
    
    return;
    
}

void genfac(int num, int primes[], int *factors){//fills factors[num] with the distinct prime factors of num (excluding num)
    
    int i = 0, rem, half;
    
    half = num/2;
    
    while(primes[i] <= half && num % primes[i]) i++;//primes[i] is the smallest prime factor of num
    
    if(primes[i] > half)//primes[i] not found --> num is prime --> leave factors[num] empty
        return;
    
    rem = num/primes[i];
    
    if(*(factors + rem*FACN) == 0){//if num is a product of two primes fill factors[num] with them
        
        *(factors + num*FACN) = primes[i];
        
        if(rem != primes[i])//if the two factors are equal take it only once
            *(factors + num*FACN + 1) = rem;
        
        return;
        
    }
    
    join(primes[i],factors+rem*FACN,factors+num*FACN);//otherwise factors[num] is given by the factors of num/primes[i] and primes[i], if not already present
    
    return;
    
}

int phi(int n, int *factors){
    
    unsigned long num, den;
    int *factor;
    
    factor = factors+n*FACN;
    
    if(!*factor) //n is prime
        return n-1;
    
    num = n;
    den = 1;
    
    while(*factor){        
        num *= *factor - 1;
        den *= *factor;
        factor++;
    }
    
    return num/den;
    
}

int main(){
    
    unsigned long sum = 0;
    int n;
    int *primes, *factors;
    
    primes = ptable();
    
    factors = (int *) malloc((LIM+1)*FACN*sizeof(int));
    memset(factors,0,(LIM+1)*FACN*sizeof(int));
    
    for(n=4; n<=LIM; n++)
        genfac(n,primes,factors);
    
    for(n=2; n<=LIM; n++)
        sum += phi(n,factors);
    
    printf("%lu\n",sum);
    return 0;
    
}
