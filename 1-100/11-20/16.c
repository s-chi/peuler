#include <stdio.h>
#define EXPO 1000



int main(){
    
    int digs[350] = {0}, top = 0, sum = 0, counter, i;
    
    digs[0] = 1;
        
    for(counter=0; counter < EXPO; counter++){
        
        for(i=0; i<=top; i++) digs[i] *= 2;
        
        for(i=0; i<=top; i++){
            
            if (digs[i] > 9){
                
                digs[i+1]++;
                digs[i] %= 10;               
                
            }
            
        }
        
        if(digs[top+1]) top++;
        
    }
    
    for(i=0;i<=top;i++) sum += digs[i];
    
    printf("%d\n", sum);
    return 0;
    
    
}
