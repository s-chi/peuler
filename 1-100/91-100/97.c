#include <stdio.h>
#define FACT 28433
#define EXPO 7830457

int main(){
    
    int digs[10] = {0},i,j;
    
    digs[0] = 1;
    
    for(i=0;i<EXPO;i++){
        
        for(j=0;j<10;j++)
            digs[j] *= 2;
        
        for(j=0;j<9;j++){
            digs[j+1] += digs[j]/10;
            digs[j] %= 10;
        }
            
        digs[9] %= 10;
        
    }
    
    for(j=0;j<10;j++)
        digs[j] *= FACT;
    
    for(j=0;j<9;j++){
        digs[j+1] += digs[j]/10;
        digs[j] %= 10;       
    }
    
    digs[9] %= 10;
    
    digs[0]++;
    
    for(j=0;j<9;j++){
        digs[j+1] += digs[j]/10;
        digs[j] %= 10;       
    }
    
    digs[9] %= 10;
    
    for(j=9;j>=0;j--)
        printf("%d",digs[j]);
    printf("\n");
    
    return 0;
    
}
