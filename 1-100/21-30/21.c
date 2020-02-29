#include <stdio.h>
#define LIM 10000

int divsum(int num){
    
    int hlf, i, sum=1;
    
    hlf = num/2;
    
    for (i=2;i<=hlf;i++)
        if(num%i==0) sum+=i;
    
    return sum;
}

int main(){
    
    int sum = 0, i, t1, t2;
    
    for(i=1;i<LIM;i++){
        
        t1 = divsum(i);
        
        if(t1 > i && t1 < LIM){
            
            t2 = divsum(t1);
            if (t2==i) {
                sum += i+t1;
                printf("(%d,%d)\n",i,t1);
            }
            
        }
        
    }
    
    printf("%d\n", sum);
    return 0;
    
}

