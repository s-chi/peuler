//There is a better method: just take the product of the first n primes
//This is a reasonably fast brute force method
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define LIM 1000000
#define FACN 8//max number of distinct prime factors for a number<=LIM (the product of the first FACN prime numbers > LIM) 

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


int mults(int n, int mult, int * pos){
    
    int rvalue, j;
    
    rvalue = n/mult - 1;           
    
    for(j=1; *(pos+j); j++)
        rvalue -= mults(n, mult*(*(pos+j)), pos+j);
    
    return rvalue;
    
}

int phi(int n, int *factors){
    
    int rvalue,j;    
    
    rvalue = n-1;//max possible number of relative primes (all numbers < n)
        
    for(j=0;*(factors + n*FACN + j); j++)                               //for each multiple of each prime factor of n, less than n, subtract 1 from rvalue
        rvalue -= mults(n,*(factors + n*FACN + j),factors + n*FACN + j);//if k_max is the max k such that k*Factor<n, k_max = n/Factor - 1, and there are k_max multiples of Factor less than n
                                                                        //the function mults takes care of multiples overcounting (e.g.: mult(a)+mult(b)+mult(c)-mult(ab)-mult(ac)-mult(bc)+mult(abc) etc)
        
    return rvalue;
    
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

int main(){
    
    int n, phiv, maxn, maxphi;
    int *primes, *factors;//factors[LIM+1][FACN] = {0};
    double ratio, maxratio = 0.;
    int j;
    
    primes = ptable();
    
    factors = (int *) malloc((LIM+1)*FACN*sizeof(int));
    memset(factors,0,(LIM+1)*FACN*sizeof(int));
    
    for(n=4; n<=LIM; n++)
        genfac(n,primes,factors);        
    
    for(n=2;n<=LIM;n++){
        
        phiv = phi(n,factors);
        
        ratio = ((double) n)/phiv;
        
        if (ratio>maxratio){
            
            printf("%d\n",n);
            
            maxratio = ratio;
            maxn = n;
            maxphi = phiv;
            
        }
        
    }
    
    printf("%d/%d = %f\n",maxn,maxphi,maxratio);
    
    
    return 0;
    
}
