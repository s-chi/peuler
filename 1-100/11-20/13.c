#include <stdio.h>


int main(){
    
    int i,j;
    long nums[100][5], rem = 0, sum;
    char str[21];
    
    for(i=0;i<100;i++)
        for(j=0;j<5;j++){
            
            scanf("%10ld",&nums[i][j]);
            
        }
        
    for(j=4;j>=0;j--){
        
        sum = 0;
        
        for(i=0;i<100;i++) sum += nums[i][j];
        
        sum += rem;
        rem = sum/1E10;
        
    }
    
    sprintf(str,"%ld",sum);
    
    printf("%.10s\n", str);
    return 0;
        
    
    
}
