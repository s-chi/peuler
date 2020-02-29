#include <stdio.h>
#define LIM 1000000

int main(){
    
    int i, j, digs[6] = {0}, bins[20] = {0}, topdig = 1, topbin = 1, sum = 0, bad;
    
    digs[0] = -1;
    bins[0] = 1;
    bins[1] = -1;
    
    for(i=1;i<LIM;i+=2){//check only odd numbers to avoid trailing zeroes both in decimal and binary
        
        digs[0]+=2;//add 2 in decimal
        for(j=0;digs[j]>9;j++){           
            digs[j+1]++;
            digs[j] %= 10;      
        }
        if(topdig<6 && digs[topdig]) topdig++;
        
        bins[1]++; //add 2 in binary
        for(j=1;bins[j]>1;j++){
            bins[j+1]++;
            bins[j] %= 2;
        }
        if(topbin<20 && bins[topbin]) topbin++;
        
        bad = 0;
        
        for(j=0;2*j<topdig-1;j++){
            
            if(digs[j]!=digs[topdig-j-1]){
                
                bad = 1;
                break;
                
            }
            
        }
        
        if(bad) continue;
        
        for(j=0;2*j<topbin-1;j++){
            
            if(bins[j]!=bins[topbin-j-1]){
                
                bad = 1;
                break;
                
            }
            
        }
        
        if(bad) continue;
        
        printf("%d, ",i);
        for(j=topdig-1;j>=0;j--) printf("%d",digs[j]);
        printf(", ");
        for(j=topbin-1;j>=0;j--) printf("%d",bins[j]);
        printf("\n");
        sum += i;
        
    }
    
    printf("%d\n",sum);
    
    return 0;
    
}
