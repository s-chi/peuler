#include <stdio.h>
#define PRIMES {2,3,5,7,11,13,17}

long fun(int digs[], int ind){
    
    int i = 0, j, flag, tnum, prime[7] = PRIMES;
    long num;
    static long sum;
    
    if (ind == 10){
        
        num = 0;
        
        for(j=0;j<10;j++){
            printf("%d",digs[j]);
            num = num * 10 + digs[j];            
        }
        
        printf("\n");
        sum += num;
        
        return sum;
        
    }
    
    if(!ind) i=1;
    
    for(;i<10;i++){
        
        flag = 0;
        
        for(j=0;j<ind;j++)
            if (i==digs[j]){
                flag = 1;
                break;                
            }
        
        if (flag) continue;
        
        digs[ind] = i;
        
        if (ind>2){
            
            tnum = 0;
            for(j=ind-2;j<=ind;j++)
                tnum = tnum * 10 + digs[j];
            
            if(tnum % prime[ind-3] != 0)
                continue;            
        }
        
        fun(digs, ind+1);
        
    }
    
    return sum;
    
}



int main(){
    
    int digs[10];
    
    printf("%ld\n", fun(digs,0));
    
    return 0;
    
}
