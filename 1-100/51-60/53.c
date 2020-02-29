#include <stdio.h>
#define MAX 100
#define LIM 1000000

int main(){
    
    int r, n, bin, counter = 0;
    
    for(r=1;r<=MAX;r++){
        
        bin = 1;
        
        for(n=r+1;n<=MAX;n++){
            
            bin = (bin * n)/(n - r);
            
            if(bin > LIM){
                
                counter += MAX - n + 1;//for a given r, bin grows with n, no need to compute bin for higher n
                break;
                
            }
            
            
        }
        
        
    }
    
    printf("%d\n", counter);
    
    
    return 0;
    
}
