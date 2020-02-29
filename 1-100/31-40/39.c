#include <stdio.h>
#define LIM 1000

int main(){
    
    int p, a, b, nsol, maxsol = 0, maxp;
    
    for(p=1;p<=LIM;p++){
        
        nsol = 0;
        for(a=1;a<p/3;a++){
            
            if((p*(2*a - p))%(2*(a-p)) == 0){
                
                b = (p*(2*a - p))/(2*(a-p));
                if (b >= a){
                    
                    printf("p = %d, (%d, %d, %d)\n",p,a,b,p-a-b);
                    nsol++;
                    
                }
                
            }
            
        }
        
        if(nsol>maxsol){
            
            maxsol = nsol;
            maxp = p;
        }
        
        
    }
    
    printf("Max number of solutions: %d, for p = %d\n", maxsol, maxp);
    
    return 0;
    
}
