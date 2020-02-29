#include <stdio.h>
#define LIM 28124
#define ABNUM 7000

int divsum(int num){
    
    int hlf, i, sum=1;
    
    hlf = num/2;
    
    for (i=2;i<=hlf;i++)
        if(num%i==0) sum+=i;
    
    return sum;
}

int main(){
    int i, abuns[ABNUM] = {0}, j=0, k, nums[LIM], sum;
    
    for(i=1;i<LIM;i++){
        nums[i] = i;
        if (divsum(i) > i) {
            abuns[j] = i;
//             printf("%d\n",i);
            j++;
        }
        
    }
    
    for(i=0;i<j;i++)
        for(k=i;k<j;k++){
            sum = abuns[i] + abuns[k];
            if(sum < LIM) nums[sum] = 0;            
        }
        
    sum = 0;
    for(i=0;i<LIM;i++) sum+= nums[i];     
    
    printf("%d\n",sum);
    return 0;
    
}
