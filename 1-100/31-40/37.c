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
    
    int sum = 0, counter = 0, num = 10, tnum, tdigs, nope;
    int * isprime;
    
    isprime = ptable();
    
    while(counter<11){
        
        num++;
        while(!*(isprime+num)) num++;
        
        nope = 0;
        tdigs = 1;
        tnum = num;
        
        while(tnum>10){
            
            tdigs++;
            tnum /= 10; //truncate one digit from the right
            
            if(!*(isprime+tnum)){                
                nope = 1;
                break;                
            }            
        }
        
        if(nope) continue;
        
        tnum = num;
        
        while(tnum>10){
            
            tdigs--;
            tnum %= (int) pow(10,tdigs);
            if(!*(isprime+tnum)){                
                nope = 1;
                break;                
            }                 
            
        }
        
        if(nope) continue;
        
        printf("%d\n", num);
        sum += num;
        counter++;
        
    }
    
    printf("\n%d\n",sum);
    return 0;
    
}
