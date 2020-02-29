#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIM 1000000
#define SIZE 100000

//using Euler's pentagonal recurrence relation for the partition function

unsigned long part(int num, unsigned long *values){
    
    unsigned long tot = 0;
    int i, delta;
    
    if(*(values+num))
        return *(values+num);
    
    for(i=1;;i+=2){
        
        delta = (i*(3*i-1))/2;
        
        if(delta <= num){
            
            tot += part(num - delta, values);
            
            delta += i;
            if (delta <= num){
                tot += part(num - delta, values);
                
                delta += 1 + 2*i;
                if(delta <= num){
                    tot = (tot + LIM - part(num - delta, values)) % LIM; //add LIM to avoid going negative
                    
                    delta += 1 + i;
                    if(delta <= num)
                        tot = (tot + LIM - part(num - delta, values)) % LIM;
                }
            }
        } else 
            break;
        
        
    }
    
    tot %= LIM; //since the numbers get very large fast, only keep track of the remainder
    *(values+num) = tot;
    return tot;
    
}


int main(){
    
    int i;
    unsigned long *values;
    
    values = (unsigned long *)malloc(SIZE*sizeof(unsigned long));
    memset(values,0,SIZE*sizeof(unsigned long));
    
    *values = 1;
    
    for(i=1;1;i++){
        
//         printf("%d\n",i);
        
        *(values+i) = part(i,values);
        
        if(*(values+i) == 0)
            break;      
        
    }
    
    printf("%d\n", i);
    return 0;
    
    
}
