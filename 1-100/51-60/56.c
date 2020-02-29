#include <stdio.h>
#include <string.h>
#define LIM 100
#define LEN 201 //number of digits of LIM^LIM


int main(){
    
    int a,b,j;
    int num[LEN], topdig, maxa, maxb;
    long sum, maxsum = 0;
    
    for(a=1;a<LIM;a++){
        
        memset(num, 0, sizeof(num));
        topdig = 1;
        num[0] = 1;
        
        for(b=1;b<LIM;b++){
            
            for(j=0;j<topdig;j++) 
                num[j] *= a;
            
            for(j=0;j<topdig;j++){
                if (num[j] >= 10){
                    
                    num[j+1] += num[j]/10;
                    num[j] %= 10;
                    if((j+1)==topdig) topdig++;
                    
                }
            }
            
            sum = 0;
            
            for(j=0;j<topdig;j++)
                sum += num[j];
            
            if(sum>maxsum){
                
                maxsum = sum;
                maxa = a;
                maxb = b;
                
            }            
            
        }
    }
    
    printf("%d^%d --> %ld\n",maxa,maxb,maxsum);
    
    return 0;    
}
