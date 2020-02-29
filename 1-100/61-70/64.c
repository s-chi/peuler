#include <stdio.h>
#include <math.h>
#define ITELIM 1000
#define LIM 10000

// Iteration: a_n = (int) D_n, where 
// D_n = (sqrt(N)+b_(n-1))/c_(n-1) and D_0 = sqrt(N)
// b_n = a_n c_(n-1) - b_(n-1) and b_0 = a_0
// c_n = (N - b_n^2)/(c_(n-1)) and c_0 = N - b_0^2



int main(){
    
    int num, a[ITELIM], b[ITELIM], c[ITELIM], repeat, i, j, counter = 0, rational;
    double root;
    
    for(num=2;num<=LIM;num++){
        
        printf("sqrt(%d) = ",num);
        
        root = sqrt(num);
        
        a[0] = (int) root;
        b[0] = a[0];
        c[0] = num - pow(b[0],2);
        
        printf("[%d;(",a[0]);
        
        if(c[0] == 0){
            
            printf("\b\b], perfect square\n");
            continue;
            
        }
        
        repeat = 0;
        rational = 0;
        i=0;
        
        while(!repeat){
            
            i++;
            
            a[i] = (int) (root + b[i-1])/c[i-1];
            b[i] = a[i] * c[i-1] - b[i-1];
            c[i] = (num - pow(b[i],2))/(c[i-1]);
            
            printf("%d,",a[i]);
            
            if(c[i] == 0){
                
                rational = 1;
                printf("\b)], rational\n");
                break;
                
            }
            
            for(j=0;j<i;j++)
                if(b[i] == b[j] && c[i] == c[j]){                    
                    repeat = 1;
                    break;                    
                }
            
        }
        
        if(!rational){
            
            printf("\b)], period = %d\n",i);
            if(i%2) counter++;
            
        }
        
    }
    
    printf("%d\n",counter);
    
    return 0;
    
}
