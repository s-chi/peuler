#include <stdio.h>
#include <string.h>
#define LIM 10000
#define ITELIM 50
#define DIGLIM 50

void dincrease(int digs[], int *dign){
    
    int i;
    
    digs[0]++;
    
    for(i=0;i<*dign;i++)
        if(digs[i] >= 10){
            
            digs[i+1] += digs[i]/10;
            digs[i] %= 10;
            
        }
    
    if(digs[*dign])
        (*dign)++;
        
    return;        
    
}

void addreverse(int digs[DIGLIM], int *dign){
    
    int i;
    
    for(i=0;i<*dign-i-1;i++){
        
        digs[i] += digs[*dign-i-1];
        digs[*dign-i-1] = digs[i];
        
    }
    
    if(i==*dign-i-1)
        digs[i] *= 2;
    
    for(i=0;i<*dign;i++)
        if(digs[i] >= 10){
            
            digs[i+1] += digs[i]/10;
            digs[i] %= 10;
            
        }
        
    if(digs[*dign])
        (*dign)++;
    
    return;
    
}

int ispali(int digs[DIGLIM], int dign){
    
    int i;
    
    for(i=0;i<dign-i-1;i++){
        
        if(digs[i] != digs[dign-i-1])
            return 0;
        
    }
    
    return 1;
    
}

int main(){
    
    int num, numdigs[5] = {0}, tdigs[DIGLIM], ndign = 1, i, tdign, lych, counter = 0;
    
    for(num=1;num<LIM;num++){
        
        dincrease(numdigs, &ndign);
        
        memset(tdigs, 0, sizeof(tdigs));
        
        for(i=0;i<ndign;i++)
            tdigs[i] = numdigs[i];
        tdign = ndign;
        
        lych = 1;
        
        for(i=0;i<ITELIM;i++){
            
            addreverse(tdigs, &tdign);
            
            if(ispali(tdigs, tdign)){
                lych = 0;
                break;                
            }            

        }
        
        if(lych){
            
            counter++;
//             printf("%d\n",num);
            
        }
        
    }
    
    printf("\n%d\n", counter);
    
    
    return 0;
    
}
