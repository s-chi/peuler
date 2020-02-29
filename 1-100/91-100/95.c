#include <stdio.h>
#include <math.h>
#define LIM 1000000
#define CHLEN 1000
#define FACN 7
#define PLIM 1000000

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

void factorize(unsigned int num, int facs[FACN], int facpows[FACN]){
    
    
    static int *primes=NULL;
    int i=0,j=0;
    
    if(primes==NULL){
        primes = ptable();
    }
    
    while(num>1){
        
        while(num % primes[i]) i++;
        
        facs[j] = primes[i];
        facpows[j] = 1;
        num /= primes[i];
        
        while(!(num % primes[i])){
            
            facpows[j]++;
            num/= primes[i];
        }
        
        i++;
        j++;
        
    }
    
    return;
    
    
}

void addivisors(int facs[], int facpows[], int ind, int prod, int *sum){
    
    int i;
    
    if(ind==FACN){
        
        *sum += prod;
        return;
        
    }
    
    for(i=0;i<=facpows[ind];i++)
        addivisors(facs,facpows,ind+1,prod*pow(facs[ind],i),sum);
    
    return;
    
}


int sumdivisor(int num){
    
    int rvalue = 0;
    int facs[FACN] = {0}, facpows[FACN] = {0};
    
    factorize(num,facs,facpows);
    
    addivisors(facs,facpows,0,1,&rvalue);
        
    return rvalue - num;
    
}

int main(){
    
    int i, j, k, maxlen = 0, longestmin, num, flag, visited[LIM+1] = {0}, chain[CHLEN], chlen;
    
    for(i=2;i<=LIM;i++){
        
        if(visited[i]) //if already visited, a) not amicable chain, b) amicable chain not starting from min member
            continue;
        
        chain[0] = i;
        
        chlen = 1;
        
        num = sumdivisor(i);
        
        while(1){
            
            if(num==i){ //back to first member --> amicable chain, first time this chain is met --> starts from min member
                
                for(j=0;j<chlen;j++)
                        
                    visited[chain[j]] = 1;
                
                if(chlen > maxlen){
                    
                    maxlen = chlen;
                    longestmin = i;
                    
                }
                    
                break;
            }
            
            if(num > LIM || num==1 || visited[num]){// chain ends in 1, or contains a number too large, or ends in a number already visited --> not amicable chain or amicable chain with too large members
                
                for(j=0;j<chlen;j++)
                    
                    visited[chain[j]] = 1;
                
                break;                
                
            }
            
            flag = 0;
                
            for(k=1;k<chlen;k++) //if a number (not the first) repeats, chain contains amicable chain but is not amicable itself
                if(num==chain[k]){
                    flag = 1;
                    break;
                }
                
            if(flag){
                
                for(j=0;j<k;j++)
                    
                    visited[chain[j]] = 1;
                
                break;    
                
            }
                
            //if none of the previous conditions is met, the chain continues
        
            chain[chlen] = num;
            chlen++;
            
            num = sumdivisor(num);
            
        }
        
    }
    
    printf("longest chain: length %d, min element %d\n",maxlen,longestmin);
    
    return 0;
    
}
