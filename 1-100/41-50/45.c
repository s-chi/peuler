#include <stdio.h>
#include <math.h>

long penta(long num){
    
    long num2;
    
    num2 = (1+sqrt(1+24*num))/6;
    
    if((num2*(3*num2-1))/2 == num) return num2;
    return 0;
    
}

long hexa(long num){
    
    long num2;
    
    num2 = (1+sqrt(1+8*num))/4;
    
    if(num2*(2*num2-1) == num) return num2;
    return 0;
    
}

int main(){
    
    long tri = 40755, n = 285, p, h;
    
    while(1){
        
        n++;
        tri += n;
        
        h = hexa(tri);
        
        if(h){
            
            p = penta(tri);
            
            
            if(p){
                
                printf("T(%ld) = P(%ld) = H(%ld) = %ld\n", n, p, h, tri);
                return 0;
                
            }
            
        }
        
        
    }
    
    return 0;
    
}
