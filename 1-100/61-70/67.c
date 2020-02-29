#include <stdio.h>
#define ROWS 100
#define MAX 5050 //ROWS*(ROWS+1)/2


int main(){
    
    int nums[MAX], i, j, rowstart;
    FILE *fp;
    
    fp = fopen("67_triangle.txt","r");
    
    for(i=0;i<MAX;i++) fscanf(fp,"%d",&nums[i]);
    
    fclose(fp);
    
    for(j=ROWS;j>1;j--){
        
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
