#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define LIM 5000
#define PLIM 1000

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

int lastprimeunder(int num,int primes[], int start, int end){//find last prime number <= num
    
    int mid;
    
    if(primes[end]<=num)
        return end;
    
    if(primes[start]>num)
        return -1;
    
    if(end-start<2)
        return start;
    
    mid = (start+end)/2;
    
    if(primes[mid]>num)
        return lastprimeunder(num,primes,start,mid);
    
    return lastprimeunder(num,primes,mid,end);
    
}

unsigned sumnum(unsigned num,unsigned maxprime, int lastprime, int primes[]){
    
    unsigned tot = 0;
    int i;
    
    if(num==0)
        return 1;
    
    if(num<=1)
        return 0;
    
    if(primes[maxprime]>num)
        maxprime = lastprimeunder(num,primes,0,lastprime);
    
    for(i=maxprime;i>=0;i--)
        tot += sumnum(num-primes[i],i,lastprime,primes);
    
    return tot;
    
}


int main(){
    
    int i,lastprime, value;
    int *primes;
    
    primes = ptable(&lastprime);
    
    
    for(i=10;1;i++){
        
        value = sumnum(i,lastprimeunder(i-1,primes,0,lastprime),lastprime,primes);
        
        if(value>LIM){
            
            printf("%d\n",i);
            break;
            
        }
        
    }
    
    free(primes);
    return 0;
    
    
}
