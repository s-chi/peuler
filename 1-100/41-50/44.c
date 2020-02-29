#include <stdio.h>
#include <math.h>

int ispenta(long num){
    
    long num2;
    
    num2 = (1+sqrt(1+24*num))/6;
    
    if((num2*(3*num2-1))/2 == num) return 1;
    return 0;
    
}


int main(){
    
    long a=1,numa=1, newa, newnuma, sum, diff, b, numb;
    
    while(1){
        
        newa = a+1;
        newnuma = numa + 3*a + 1;
        
        for(numb = numa, b = a; b > 0; numb += 2 - 3 * b--){
            
            sum = newnuma + numb;
            
            if(ispenta(sum)){
                
                printf("%ld + %ld = %ld\n", newnuma, numb, sum);
                
                diff = newnuma - numb;
                if(ispenta(diff)){//found a solution, but is the difference minimal? (apparently yes, but I don't know how to prove it.) Could there be better solutions with larger a?
                                //since the distance between adjacent pentagonal numbers P_n-P_{n-1} = 3n-2 increases with n, one could check up to the value of a such that 3a-2=diff
                                //however this requires to check up to huge numbers
                    
                    printf("%ld - %ld = %ld\n", newnuma, numb, diff);
                    return 0;
                    
                }
                
            }
            
        }
            
            
        numa = newnuma;        
        a = newa;
        
    }
    
    
}
