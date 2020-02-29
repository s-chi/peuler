#include <stdio.h>
#include <math.h>
#define PLIM 1000000000

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
    
    int *isprime, digs[9] = {9,8,7,6,5,4,3,2,1}, i=987654321, topdig = 9, j, k, flag;
    
    isprime = ptable();
    
    while(1){
        
        if (*(isprime+i)){
            
            flag = 1;
            for(j=8;j>= 9-topdig;j--){
                
                if(digs[j]>topdig||digs[j]==0){                    
                    flag = 0;
                    break;
                }
                for(k=j-1;k>= 9-topdig;k--)
                    if(digs[k]==digs[j]){
                        flag = 0;
                        break;
                    }
            }
            if(flag){
                printf("%d\n",i);
                break;                
            }
            
        }
        
        
        
        digs[8] -= 2;
        for(j=8; digs[j]<0; j--){
            
            digs[j] += 10;
            digs[j-1]--;
            
        }
        
        if(digs[9-topdig]==0) topdig--;
        
        i-=2;
        
    }
    
    return 0;
    
}
