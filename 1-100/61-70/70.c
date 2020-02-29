#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define LIM 10000000
#define FACN 8         //max number of prime factors for n<LIM
#define NDIGS 8
#define SOLNUM 87109
#define RATIOMIN 1.1001389239706996716 //we know there is a solution with this n/phi(n), so the minimal ratio must be less than this


int * ptable(int *pnum){
    
    int *rarray, *array;
    int i, j, sroot = sqrt(LIM);
    
    array = (int *) malloc(LIM*sizeof(int));
    memset(array,0,LIM*sizeof(int));
    
    array[2] = 1;

    for(i=3;i<LIM;i+=2) array[i] = 1;
    
    for(i=3;i<=sroot;i+=2){
        
        while(!array[i]) i+=2;
        
        if(array[i])
            for (j=i; j*i < LIM; j+=2) 
                array[j*i] = 0;   
    }    
    
    *pnum=1;
    for(i=3;i<LIM;i+=2)
        if(array[i])
            (*pnum)++;
        
    rarray = (int *) malloc((*pnum)*sizeof(int));
    
    *pnum = 1;
    *rarray = 2;
    
    for(i=3;i<LIM;i+=2)
        if(array[i]){
            *(rarray+(*pnum)) = i;
            (*pnum)++;            
        }
    
    (*pnum)--;
    
    free(array);
            
    return rarray;
    
}

int isperm(int num, int nume, int deno){
    int phi,i,j,digfound;
    int ndigs[NDIGS] = {0}, pdigs[NDIGS] = {0};
    
    phi = ((unsigned long)num * deno)/nume;
    
    ndigs[0] = 1;
    while(num>0){
        ndigs[ndigs[0]] = num % 10;
        ndigs[0]++;
        num /= 10;   
    }
    
    ndigs[0]--;
    
    pdigs[0] = 1;
    while(phi>0){
        pdigs[pdigs[0]] = phi % 10;
        pdigs[0]++;
        phi /= 10;   
    }
    
    pdigs[0]--;
    
   if(ndigs[0]!=pdigs[0])
       return 0;
   
   for(i=1;i<=ndigs[0];i++){
        
        digfound = 0;
        
        for(j=1;j<=ndigs[0];j++)
            if(ndigs[i] == pdigs[j]){                
                pdigs[j] = -1;
                digfound = 1;
                break;
            }
            
        if(!digfound)
            break;        
            
    }
    
    if(!digfound)
        return 0;
    
    return 1;
    
    
}


int numperm(int faclist[FACN], int nume, int deno, int facind, int num){    
    
    int res;
    unsigned long tnum;
    
    if(facind==FACN){
        
        if(isperm(num,nume,deno))
            return num;
        
        return 0;
        
    }
    
    if(faclist[facind]==1){
        
        res = numperm(faclist,nume,deno,FACN,num);
        
        if(res)
            return res;
        
        return 0;
        
    }
    
    for(tnum = num*faclist[facind]; tnum < LIM; tnum*=faclist[facind]){
        
        res = numperm(faclist,nume,deno,facind+1,tnum);
        
        if(res)
            return res;
        
    }
    
    return 0;
    
}

int findmaxprime(int primes[], int cmp, int beg, int end){//find first prime > cmp, looking between primes[beg] and primes[end]. If primes[end] <= cmp returns end
    
    int mid;
    
    if(primes[beg] > cmp)
        return beg;
    
    if(primes[end] <= cmp)
        return end;
    
    if(end-beg < 2){
        
        if(primes[beg] <= cmp)
            return end;
        
        return beg;        
    }
    
    mid = (beg + end)/2;
    
    if(primes[mid] >= cmp)
        return findmaxprime(primes,cmp,beg,mid);
    
    return findmaxprime(primes,cmp,mid,end);
    
}


int fun(int *num, int facind, int faclist[FACN], double *ratiomin, int maxprime, int primes[], int cmp){
    
    int tnum, ind, newind, res;
    double ratio, nume, deno;
    
    if (facind == -1){
        
        nume = 1;
        deno = 1;
        
        for(ind=0;ind<FACN;ind++)
            if(faclist[ind]>1){
                
                nume *= faclist[ind];
                deno *= faclist[ind] - 1;
                
            }
            
        ratio = nume/deno;
        
        if(ratio>*ratiomin)
            return 0;
        
        tnum = numperm(faclist,nume,deno,0,1);
        
        if(tnum){
            
            *ratiomin = ratio;
            *num = tnum;
            printf("phi(%d) = %d, %d/phi(%d) = %f\n", *num, (int)(*num/ *ratiomin + 0.5), *num, *num, *ratiomin);
            
        }
        
        return 1;
        
    }
    
    maxprime = findmaxprime(primes, cmp, 0, maxprime);
    
    for(ind=maxprime; ind>=facind; ind--){
        
        faclist[facind] = primes[ind];
        
        res = fun(num,facind-1,faclist,ratiomin,ind-1,primes,cmp/primes[ind]);
        
        if(!res)
            break;
        
    }
    
    return 1;
    
}


int main(){
    
    int *primes;
    int faclist[FACN];
    int maxprime, numfacs, i, num;
    double ratiomin;
    
    primes = ptable(&maxprime);
    
    ratiomin = RATIOMIN;
    num = SOLNUM;
    
    for(numfacs=0;numfacs<FACN;numfacs++){
        
        printf("numbers with %d factors\n",numfacs+1);
        
        for(i=0;i<FACN;i++)
            faclist[i] = 1;
        
        fun(&num, numfacs, faclist, &ratiomin, maxprime, primes, LIM);   
        
    }
    
    free(primes);
    
    printf("phi(%d) = %d, %d/phi(%d) = %f\n", num, (int)(num/ratiomin + 0.5), num, num, ratiomin);
    
    return 0;
    
}
