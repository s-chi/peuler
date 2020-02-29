#include <stdio.h>
#include <math.h>
#define MAXN 20

// int main(){
//     
//     int primes[9][2] = {{0}}, i, j, k, temp, prod=1;
//     
//     primes[0][0] = 2;
//     primes[0][1] = 1;
//     
//     for(i=3;i<21;i++){
//         
//         j=0;
//         temp = i;
//         while(primes[j][0]!=0){
//             k=0;
//             while(temp % primes[j][0] == 0){
//                 
//                 k++;
//                 temp /= primes[j][0];               
//                 
//             }
//             
//             if (k > primes[j][1]) primes[j][1] = k;
//             j++;
//             
//         }
//         
//         if (temp > 1) {
//             
//             primes[j][0] = temp;
//             primes[j][1] = 1;
//             
//         }
//         
//     }
//     
//     j=0;
//     while(primes[j][0]!=0){
//         
//         prod *= pow(primes[j][0], primes[j][1]);
// //         printf("%d, %d\n",primes[j][0], primes[j][1]);
//         
//         j++;
//     }
//     
//     printf("%d\n", prod);
//     return 0;
//     
//     
// }

int main(){
    
    int primes[9] = {0}, i, j, prod=1, isprime;
    
    primes[0] = 2;
    
    for(i=3;i<MAXN+1;i++){
        
        j=0;
        isprime = 1;
        while(primes[j]!=0){
            
            if(i % primes[j] == 0) {
                
                isprime = 0;
                break;
                
            }
            j++;
        }
            
        if (isprime) primes[j] = i;
        
    }
    
    
    
    j=0;
    while(primes[j]!=0){
        i=1;
        while(pow(primes[j],i)<MAXN+1) i++;
        i--;
        prod *= pow(primes[j], i);
        j++;
        
    }
    
    printf("%d\n", prod);
    return 0;
    
}
