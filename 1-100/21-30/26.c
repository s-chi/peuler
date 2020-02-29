#include <stdio.h>
#define LIM 1000
#define DECMAX 1000

int main(){
    
    int den, max=0, nums[DECMAX], i, j, temp, maxden, flag;
    
    for(den=2;den<LIM;den++){
        
        nums[0] = 1;
        i=1;
        
        while(1){
            
            nums[i] = nums[i-1]*10;
            while(nums[i]<den) nums[i] *= 10;
            nums[i] %= den;
            
            if (nums[i]==0) break;
            
            flag = 0;
            
            for (j=0;j<i;j++){
                
                if (nums[i]==nums[j]){
                    
                    temp = i-j;
                    
                    if (temp>max){
                        
                        max = temp;
                        maxden = den;                        
                        
                    }
                    
                    flag = 1;
                    break;
                    
                }
                
            }
            
            if (flag) break;
            
            i++;
            if(i>= DECMAX){
                printf("Error! Increase DECMAX!\n");
                return 0;
            }
            
        }
        
        
    }
    
    printf("%d, %d\n", maxden, max);
    return 0;

    
    
}
