#include <stdio.h>


int combs(unsigned value, unsigned index){
    
    int coins[8] = {200,100,50,20,10,5,2,1};
    int i, combnum = 0;
    
    if (value == 0) return 1;    
    
    for(i=index;i<8;i++){
        
        if (coins[i] <= value) {
            combnum += combs(value - coins[i], i);}
        
    }
    
    return combnum;
    
    
}



int main(){
    
    printf("%d\n", combs(200,0));
    return 0;
      
}
