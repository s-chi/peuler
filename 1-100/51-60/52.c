#include <stdio.h>
#include <math.h>
#include <string.h>
#define DLIM 10
#define MAXFAC 6

void dincrease(int digs[DLIM]){
    
    int i;
    
    digs[0]++;
    
    for(i=0;i<DLIM-1;i++)
        if(digs[i] >= 10){
            
            digs[i+1] += digs[i]/10;
            digs[i] %= 10;
            
        }
        
    return;        
    
}

void dmult(int numdigs[DLIM], int fac, int multdigs[DLIM]){
    
    int i;
    
    memset(multdigs, 0, DLIM * sizeof(int));
    
    for(i=0;i<DLIM;i++)
        multdigs[i] = fac * numdigs[i];
    
    for(i=0;i<DLIM-1;i++)
        if(multdigs[i]>=10){
            
            multdigs[i+1] += multdigs[i] / 10;
            multdigs[i] %= 10;
            
        }
        
    return;    
    
}

int dcompare(int digs1[DLIM], int digs2[DLIM]){
    
    int i,j, found;
    
    for(i=0;i<DLIM;i++){
        
        found = 0;
        
        for(j=0;j<DLIM;j++)
            if(digs1[i] == digs2[j]){
                
                found = 1;
                break;
                
            }
            
        if(!found) return 0;        
            
    }
        
    return 1;   
    
}


int main(){
    
    int num, dignum=0, numdigs[DLIM] = {0}, multdigs[DLIM] = {0}, topd = 0, i, flag, power;
    int j;
    
    while(1){
        
        dignum++;
        
        memset(numdigs, 0, sizeof(numdigs));
        numdigs[dignum-1] = 1;
        power = pow(10,dignum-1);
        
        for(num = power; num < 2*power; num++, dincrease(numdigs)){//if 6*num must have the same number of digits as num, say n (so n>=10^(n-1)), then num < 5/3 * 10^(n-1) < 2 * 10^(n-1)
            
            flag = 0;
            
            for(i=2;i<=MAXFAC;i++){
                
                dmult(numdigs, i, multdigs);
                
                if(!dcompare(numdigs,multdigs)){
                    
                    flag = 1;
                    break;
                    
                }
                
            }
            
            if(flag) continue;
            
            printf("%d\n",num);
            return 0;   
            
            
        }
        
    }   
       
}
