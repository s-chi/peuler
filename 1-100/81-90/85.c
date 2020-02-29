#include <stdio.h>
#define LIM 2000000

int rects(int sidea, int sideb){
    
    int i,j,numa,numb, tot = 0;
    
    for(i=1;i<=sidea;i++){
        
        numa = sidea - i + 1;
        
        for(j=1;j<=sideb;j++){
            
            numb = sideb - j + 1;
            
            tot += numa * numb;
            
        }
        
    }
    
    return tot;
    
}



int main(){
    
    int inf, sup, areainf, areasup, value = 0, a,b;
    
    inf = 0;
    sup = 10*LIM;
    
    for(a=1;;a++){
        
        value = rects(a,1);
        if(value>LIM){
            if (value < sup){
                sup = value;
                areasup = a;
            }
            break;            
        }
        
        for(b=2;b<a;b++){
            
            value = rects(a,b);
            if(value>LIM){
                if(value<sup){
                    sup = value;
                    areasup = a*b;
                }
                break;
            }
            if(value<LIM && value>inf){
                inf = value;
                areainf = a*b;
            }                
        }
    }
    
    if(sup-LIM > LIM-inf)
        printf("%d\n",areainf);
    else
        printf("%d\n",areasup);
    
    return 0;
    
}
