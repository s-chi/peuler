#include <stdio.h>
#include <math.h>
#define LIM     1000000000000L
#define MINROOT 1414213562373L

//blue/tot * (blue-1)/(tot-1) = 1/2 ---> solution: blue = (1+sqrt(1-2*tot+2*tot^2))/2
//MINROOT: sqrt(1-2*LIM+2*LIM^2) (approx) +1 (root must be odd)

int main(){
    
    unsigned __int128 rad, root, root2, tot;
    int i;
    
    tot = LIM;
    rad = 1+2*tot*(tot-1);
    root = MINROOT;
    root2 = root*root;
    
    
    while(1){
        
        while(rad < root2){
            rad += 4 * tot;
            tot++;
        }
        
        while(root2 < rad){
            root += 2;
            root2 = root*root;
        }
        
        if(rad==root2){
            
            printf("%lu\n",(unsigned long)((1+root)/2));
            return 0;
            
        }
        
        
    }
    
    
}
