#include <stdio.h>
#define LIM 1000000

int main(){
    
    int prod = 1, digit = 0, digs[7] = {0}, topdig = 1, i, dcheck = 1;
    
    
    for(digs[0] = 1; digit<LIM; digs[0]++){
        
        for(i=0;digs[i]==10;i++){
            digs[i+1]++;
            digs[i] = 0;
        }
        if(digs[topdig]) topdig++;
        
        digit += topdig;
        
        if(digit >= dcheck){
            prod *= digs[digit - dcheck];
            printf("dcheck = %d, num = ",dcheck);
            for(i=topdig-1;i>=0;i--) printf("%d",digs[i]);
            printf(", digit = %d\n",digit);
            dcheck *= 10;      
        }        
        
    }
    
    
    printf("\n\n%d\n", prod);
    
    return 0;
    
}
