#include <stdio.h>

int main(){
    
    int nums[120], i, j, rowstart;
    
    for(i=0;i<120;i++) scanf("%d",&nums[i]);
    
    for(j=15;j>1;j--){
        
        rowstart = (j*(j-1))/2;
        
        for(i=1;i<j;i++){
            
            if (nums[rowstart+i] > nums[rowstart+i-1]) 
                
                nums[rowstart-j+i] += nums[rowstart+i];
            
            else nums[rowstart-j+i] += nums[rowstart+i-1];
            
        }
        
    }
    
    printf("%d\n", nums[0]);
    return 0;    
    
}
