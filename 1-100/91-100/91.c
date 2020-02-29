#include <stdio.h>
#define LIM 50


int main(){
    
    int x1,x2,y1,y2,counter=0;
    
    for(x1=0;x1<=LIM;x1++)
        for(x2=0;x2<=LIM;x2++)
            for(y1=0;y1<=LIM;y1++)
                for(y2=0;y2<=LIM;y2++){
                    
                    if((x1==0&&y1==0)||(x2==0&&y2==0)||(x1==x2&&y1==y2))//avoid degenerate cases
                        continue;
                    
                    if(x1*x2+y1*y2==0||x1*x1+y1*y1-x1*x2-y1*y2==0||x2*x2+y2*y2-x1*x2-y1*y2==0) //||vec1||^2 +- ||vec2||^2 = ||vec1-vec2||^2
                        counter++;
                    
                }
                    
    counter /= 2; //avoid double counting vec1 <-> vec2
    
    printf("%d\n",counter);
    
    return 0;
    
}
