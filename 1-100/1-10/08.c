#include <stdio.h>
#define LENGTH 1000
#define LIM 13

int main(){
    
    int nums[LENGTH],i,j,startind;
    long prod, maxprod=0;
    
    for(i=0;i<LENGTH;i++) scanf("%1d",&nums[i]);
    
//     printf("num[%d] = %d\n",i,nums[i]);}
    
    for(i=0;i<LENGTH-LIM+1;i++){
        
        prod = 1;
        
        for(j=i;j<i+LIM;j++){
            
            prod *= nums[j];
            
        }
        
//         printf("")
        
        if (prod>maxprod){
            
            maxprod = prod;
            startind = i;
            
        }
        
    }
    
    printf("%d",nums[startind]);
    for (i=1;i<LIM;i++) printf(" * %d",nums[startind+i]);
    printf(" = %ld\n", maxprod);
    
    
    return 0;
    
}
