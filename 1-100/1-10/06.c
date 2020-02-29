#include <stdio.h>
#define NUM 100

// int main(){
//     
//     int i, sumsq=0, sum=0, sqsum;
//     
//     for(i=1;i<101;i++){
//         
//         sumsq += i*i;
//         sum += i;
//         
//     }
//     
//     sqsum = sum*sum;
//     
//     printf("%d\n", sqsum-sumsq);
//     
//     return 0;   
//     
//     
// }

int main(){
    
    int sumsq, sum;
    
    sum = (NUM * (NUM + 1))/2;
    sumsq = (sum * (1 + 2 * NUM))/3;
    
    printf("%d\n", sum*sum-sumsq);
    
    return 0;   
    
    
}
