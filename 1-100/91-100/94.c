#include <stdio.h>
#include <math.h>
#define SIDELIM 333333334
#define EPS 0.000000001

int main(){
    
    unsigned long side, sum = 0, temp, temp2, root;
    
    for(side=2;side<SIDELIM;side++){//side>1 --> no degenerate triangles
        
        temp = 3 * powl(side,2) - 1;
        
        temp2 = temp + 2*side;
        
        root = sqrtl(temp2);
        
        if(root*root == temp2)
            sum += 3*side-1;
        
        temp2 = temp - 2*side;
        
        root = sqrtl(temp2);
        
        if(root*root == temp2)
            sum += 3*side+1;
        
    }
    
    printf("\n%lu\n",sum);
    return 0;
    
    
}
