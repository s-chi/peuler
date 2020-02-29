#include <stdio.h>
#define LIM 1000

int main(){
    
    int f1[LIM]={0}, f2[LIM]={0};
    int n=2, temp, maxdig = 1, i;
    f1[0] = 1;
    f2[0] = 1;
    
    while(maxdig<LIM){
        
        for(i=0;i<maxdig;i++) f1[i] += f2[i];
        for(i=0;i<maxdig;i++)
            if(f1[i]>9){    
                
                f1[i+1]++;
                f1[i] %= 10;                
                
            }
        if(f1[maxdig]) maxdig++;
        for(i=0;i<maxdig;i++){
            
            temp = f1[i];
            f1[i] = f2[i];
            f2[i] = temp;
            
        }
        n++;        
    }
    
    printf("%d\n",n);
    return 0;
    
    
}
