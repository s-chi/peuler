#include <stdio.h>
#define SUM 1000

int main(){
    
    int a,b,c/*,found=0*/;
    
    for(a=1;a<SUM/3;a++){
        for(b=a+1;b<(SUM-a)/2;b++){
            
            c = SUM - a - b;
            
            if (a*a+b*b-c*c == 0){
                
//                 found = 1;
//                 break;
                printf("%d * %d * %d = %d\n", a,b,c,a*b*c);
                return 0;
                
                
            }
            
        }
        
//         if (found) break;
        
    }
    
//     printf("%d * %d * %d = %d\n", a,b,c,a*b*c);
    return 0;
            
    
    
}
