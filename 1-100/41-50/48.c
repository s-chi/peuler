#include <stdio.h>
#define DIGS 10
#define LIM 1000

int * addpow(int a){
    
    static int sum[DIGS];
    int i, j, num[DIGS] = {0};
    
    num[0] = 1;
    
    for(i=1;i<=a;i++){
        for(j=0;j<DIGS;j++) num[j] *= a;
        for(j=0;j<DIGS-1;j++){
            if (num[j] >= 10){
                
                num[j+1] += num[j]/10;
                num[j] %= 10;
                
            }
        }
        
        if(num[DIGS-1]>=10)
            num[DIGS-1] %= 10;
    }
    
    for(i=0;i<DIGS-1;i++){
        
        sum[i] += num[i];
        if(sum[i] >= 10){
            
            sum[i+1] += sum[i]/10;
            sum[i] %= 10;
            
        }
    }
    
    sum[DIGS-1] = (sum[DIGS-1] + num[DIGS-1]) % 10;

    return sum;   
    
}


int main(){
    
    int i, *sum;
    
    for(i=1;i<LIM;i++)
        addpow(i);    
    
    sum = addpow(LIM);
    
    for(i=DIGS-1;i>=0;i--)
        printf("%d",*(sum+i));
    
    printf("\n");
    
    
    return 0;
    
}
