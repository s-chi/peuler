#include <stdio.h>

int main(){
    
    int digs[160] = {0}, top = 0, sum = 0, i, j;
    
    digs[0] = 1;
        
    for(j=2; j<101; j++){
        
        for(i=0; i<=top; i++) digs[i] *= j;
        
        for(i=0; i<=top; i++){
            
            if (digs[i] > 9){
                
                digs[i+1] += digs[i]/10;
                digs[i] %= 10;               
                
            }
            
        }
        
        while(digs[top+1]){
            
            top++;
            if (digs[top] > 9){
             
                digs[top+1] += digs[top]/10;
                digs[top] %= 10;               
             
            }
            
        }
        
    }
    
    for(i=0;i<=top;i++) sum += digs[i];
    
    printf("%d\n", sum);
    return 0;
    
    
}

