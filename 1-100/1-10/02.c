#include <stdio.h>


int main(){
    
    int sum = 0, f1 = 1, f2 = 2, f3 = 3;
    
    while(f2 < 4000000){
        
        sum += f2;
        f1 = f2 + f3;
        f2 = f3 + f1;
        f3 = f1 + f2;        
        
    }
    
    printf("%d\n",sum);
    return 0;
    
}
