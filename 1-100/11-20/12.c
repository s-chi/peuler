#include <stdio.h>
#include <math.h>
#define LIM 500
//expect max triang number <~ 2E9, product of 2 numbers of same order of mag, 
//-> max prime < sqrt(2E9)~45000, odd numbers are half
#define PLIM 25000 

// int main(){
//     
//     int i=2, div=0, num, j;
//     
//     while(div<=LIM){
//         
//         div = 2;
//         num = (i*(i+1))/2;
//         
//         for(j=2;j<=num/2;j++)
//             if (num % j == 0) div++;
//             
// //         printf("%d, %d\n", div, num);
//             
//         i++;
//         
//     }
//     
//     printf("%d, %d\n", div, num);
//     
//     return 0;
//     
//     
//     
// }

int main(){
    
    int i=2, div=0, num=1, j, k, tnum;
    int nums[PLIM] = {0}, dcount, sqnum, nind, prime;
    int sroot = sqrt(PLIM*2);
    
    for(j=0;j<PLIM;j++) nums[j] = 3+2*j;
    
    j=0;
    
    while (j < PLIM){
        
        while(!nums[j]) j++;
        if(j > PLIM - 1) break;
        
        if(nums[j]<sroot)
            for (k=nums[j]; k*nums[j] < PLIM*2; k+=2) nums[(k*nums[j]-3)/2] = 0;
            
        j++;
        
    }
    
    
    while(div<=LIM){
        
        div = 1;
        num += i;
        tnum = num;
        sqnum = sqrt(num);
        
        dcount = 0;
        
        prime = 2;
        
        while(tnum % prime == 0){
            
            tnum /= prime;
            dcount++;
            
        }
        
        div *= (dcount + 1);
        
        nind = 0;
        
        while(prime <= sqnum){
            
            while(!nums[nind]) nind++;
            
            prime = nums[nind];
            dcount = 0;
            
            while(tnum % prime == 0){
                
                tnum /= prime;
                dcount++;
                
            }
            
            div *= (dcount + 1);
            nind++;
            
        } 
            
        i++;
        
    }
    
    printf("%d, %d\n", div, num);
    
    return 0;
    
    
    
}
