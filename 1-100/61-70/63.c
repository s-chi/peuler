#include <stdio.h>
#include <math.h>
// #include <string.h>
#define MAXN 21 //P = Q^n, P has n digits --> 10^(n-1)<=P<10^n --> 10^(1-1/n)<=Q<=9, but for n>21  10^(1-1/n)>9

// void dprint(int digs[]){
//     
//     int i;
//     
//     for(i = digs[0]; i>0; i--)
//                 printf("%d", digs[i]);
//     printf("\n");
//     
//     return;
// }
// 
// int * mpow(int a, int b){
//     
//     static int num[MAXN+2];
//     int i,j;
//     
//     memset(num, 0, sizeof(num));
//     
//     num[0] = 1;
//     num[1] = 1;
//     
//     for(i=1;i<=b;i++){
//         for(j=1;j<=num[0];j++) num[j] *= a;
//         for(j=1;j<=num[0];j++){
//             if (num[j] >= 10){
//                 
//                 num[j+1] += num[j]/10;
//                 num[j] %= 10;
//                 if(j==num[0]) num[0]++;
//                 
//             }
//         } 
//         
//     }
// 
//     return num;   
//     
// }

int main(){
    
    int n, q, counter = 1;
    
//     printf("1^1 = 1\n");
    
    for(n=1;n<=MAXN;n++){
        
        for(q = pow(10,1-1./n) + 1; q < 10; q++){
            
            counter++;
//             printf("%d^%d = ",q,n);
//             dprint(mpow(q,n));
            
        }
        
        
    }
    
    printf("%d\n",counter);
    return 0;
    
    
}
