#include <stdio.h>
#include <math.h>
#define LIM 2000000

// int main(){
//     
//     int primes[LIM/10] = {0}, i, num, isprime;
//     long sum=0;
//     
//     primes[0] = 2;
//     primes[1] = 3;
//     
//     num = 3;
//     
//     while(num < LIM){
//         
//         isprime = 1;
//         i=0;
//         while(primes[i]!=0){
//             
//             if (num % primes[i] == 0){
//                 
//                 isprime = 0;
//                 break;
//                 
//             }
//             
//             i++;
//             
//         }
//         
//         if (isprime) {
//             
//             primes[i] = num;
// //             printf("primes[%d] = %d\n", i, num);
//             
//         }
//         
//         num +=2;
//         
//     }
//     
//     i=0;
//     while(primes[i]!=0){
//         
//         sum += primes[i];
//         i++;
//         
//     }
//     
//     printf("%ld\n", sum);
//     return 0;
//     
// }

int main(){
    
    int numbers[(LIM+1)/2-1], i, j, sroot = sqrt(LIM);
    long sum=2;
    
    for(i=0;i<(LIM+1)/2-1;i++) numbers[i] = 3+2*i;
    
    i=0;
    
//     printf("array size %d\n", (LIM+1)/2-1);
    
    while (i < (LIM+1)/2-1){
        
        while(!numbers[i]) i++;
        if(i > (LIM+1)/2-2) break;
        
        sum += numbers[i];
        
        if(numbers[i]<sroot)
            for (j=numbers[i]; j*numbers[i] < LIM; j+=2) numbers[(j*numbers[i]-3)/2] = 0;
            
        i++;
        
    }
    
    printf("%ld\n", sum);
    return 0;
    
    
}
