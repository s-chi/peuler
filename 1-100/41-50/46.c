#include <stdio.h>
#include <math.h>
#define PLIM 10000

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
    
    int *isprime, num = 7, i, check, flag;
    
    isprime = ptable();
    
    while(1){
        
        num += 2;
        
        if(*(isprime+num)) continue;
        
        i=0;
        flag = 0;
        
        while(i<num){
            
            while(*(isprime+i) == 0) i++;
            
            check = sqrt((num - i)/2);
            
            if(i+2*check*check == num){
                
                flag = 1;
                break;
                
            }
            
            i++;            
            
        }
        
        if (flag) continue;
        
        printf("%d\n",num);
        return 0;
        
    }
    
    
    return 0;
    
}
