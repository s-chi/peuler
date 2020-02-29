#include <stdio.h>
#define NUM 100

unsigned sumnum(unsigned num,unsigned max){
    
    unsigned tot = 0,i;
    
    if(num<=1)
        return 1;
    
    if(max>num)
        max = num;
    
    for(i=max;i>0;i--){
        
        tot += sumnum(num-i,i);
        
    }
    
    return tot;
    
}


int main(){
    
    printf("%d\n", sumnum(NUM,NUM-1));
    return 0;
    
    
}
