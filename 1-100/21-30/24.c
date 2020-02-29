#include <stdio.h>
#define IND 1000000

int fact(unsigned int num){
    
    if(num>1) return num * fact(num-1);
    return 1;    
}

int main(){
    
    int tot, perm[10], i, j, used[10] = {0}, decr;
    
    tot = fact(10);
    
    for(i=0;i<10;i++){
        
        j=9;
        while(used[j]) j--;
        perm[i] = j;
        used[j] = 1;
        
        decr = fact(9-i);
        
        while(tot>=IND){
            
            tot -= decr;
            used[j] = 0;
            j--;
            while(used[j]) j--;
            perm[i] = j;
            used[j] = 1;
            
        }
        
        tot += decr;
        used[j] = 0;
        j++;
        while(used[j]) j++;
        perm[i] = j;
        used[j] = 1;
        
    }
    
    
    for(i=0;i<10;i++) printf("%d",perm[i]);
    printf("\n");
    
    return 0;
}
