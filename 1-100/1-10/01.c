#include <stdio.h>
#define TOP 1000

int main(){
    
    int sum = 0, i;
    
    for(i=1;i<(TOP+2)/3;i++) sum += 3*i;
    for(i=1;i<(TOP+4)/5;i++) sum += 5*i;
    for(i=1;i<(TOP+14)/15;i++)  sum -= 15*i;
    
//     for(i=1;i<TOP;i++)
//         if(i%3==0||i%5==0) sum+=i;
    
    printf("%d\n",sum);
    
    return 0;
    
} 
