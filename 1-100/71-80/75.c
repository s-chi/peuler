#include <stdio.h>
#include <math.h>
#define LIM  1500000
#define SQLIM 1224
#define PLIM  750000 //LIM/2
#define FACN 7 //product of first FACN primes <= LIM

//pythagorean triples: k(a,b,c), a=m*n, b=(m^2-n^2)/2, c=(m^2+n^2)/2, with m,n odd, m>n, gcd(m,n) = 1
// L = k(a+b+c) = k*m*(m+n)
//for a given L, different possible choices of (k,m,n) correspond to different pythagorean triples
//if there are N distinct choices (k_i,m_i,n_i), i=1..N for a given L, there will be at least n choices for a*L: (a * k_i,m_i,n_i)

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

unsigned int gcd(unsigned int a, unsigned int b){//assume a>b
    
    unsigned int r;
    
    if(b==0)
        return a;
    
    r = a % b;
    
    if(b>r)
        return gcd(b,r);
    
    return gcd(r,b);
    
}

int numtriples(int L, int facs[FACN], int facpows[FACN], int mfacs[FACN], int ind){
    
    int i,j,counter = 0, m,n,prod;
    
    if(!facs[ind]){
        
        m=1;
        
        for(i=ind-1;i>0;i--)
            m *= mfacs[i];
        
        if(m>SQLIM)
            return counter;       
        
        for(n=1;n<m;n+=2){
            
            prod = m*(n+m);
            if(prod>L)
                break;
            
            if(gcd(m,n)==1 && L % prod == 0)
                counter++;
            
            if (counter>1)
                break;
            
        }
        
        return counter;
        
    }
    
    for(j=0;j<=facpows[ind];j++){
        
        mfacs[ind] = pow(facs[ind],j);
        counter += numtriples(L,facs,facpows,mfacs,ind+1);
        if(counter>1)
            break;
        
    }
    
    return counter;
    
}

void factorize(unsigned int num, int facs[], int facpows[], int primes[]){
    
    int i=0,j=0;
    
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

int hasOneTriple(int L, int primes[]){//assume L is even without checking
    
    int facs[FACN] = {0}, facpows[FACN] = {0}, mfacs[FACN] = {0};
    int counter;
    
    factorize(L,facs,facpows,primes);
    
    counter = numtriples(L,facs,facpows,mfacs,1);
    
    if (counter==0)
        return 0;
    
    if (counter==1)
        return 1;
    
    return 2;
    
}


int main(){
    
    int *primes, counter = 0, i, j, res;
    short excluded[LIM+1] = {0};
    
    primes = ptable();
    
    for(i=12;i<=LIM;i+=2){
        
        if(excluded[i])
            continue;
        
        res = hasOneTriple(i,primes);
        
        if(res == 1)
            counter++;
        else if (res > 1)
            for(j=2;j*i <= LIM;j++)
                excluded[j*i] = 1;
            
    }
    
    printf("%d\n",counter);
    
    return 0;
    
}
