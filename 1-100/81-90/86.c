#include <stdio.h>
#include <math.h>
#define LIM 1000000

//given a cuboid a x b x c, distances have the form d = sqrt(h^2+b^2) + sqrt((a-h)^2+c^2), minimized when h=ab/(b+c)
//--> 3 potential minimal distances, one for each side, of the form sqrt(a^2+(b+c)^2) 


int main(){
    
    int side[3],sqdist[3],i,counter = 0, min, intsqrt, maxside = 0;
    
    
    while(counter<LIM){
        
        maxside++;
//         printf("%d: ",maxside);
        
        side[2] = maxside;
        
        for(side[0]=1;side[0]<=maxside;side[0]++)
            for(side[1]=side[0];side[1]<=maxside;side[1]++){
                
                for(i=0;i<3;i++)
                    sqdist[i] = pow(side[i],2) + pow(side[(i+1)%3] + side[(i+2)%3],2);
                
                if(sqdist[0]<=sqdist[1] && sqdist[0]<=sqdist[2])
                    min = sqdist[0];
                else if(sqdist[1]<=sqdist[2])
                    min = sqdist[1];
                else
                    min = sqdist[2];
                
                intsqrt = sqrt(min);
                
                if(pow(intsqrt,2)==min)
                    counter++;
            }
//             printf("%d\n",counter);
    }
    
    printf("%d\n",maxside);
    return 0;
    
}
