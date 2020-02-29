#include <stdio.h>
#define LIM 1000000

int main(){
    
    int lens[LIM] = {0}, i, len, maxlen = 0, maxnum;
    long tnum;
    
    for(i=1; i<LIM; i++){
        
        tnum = i;
        len = 1;
        
        
        
        while(tnum > 1){
            
//             if (i==837799) printf("%ld\n",tnum);
            
            if (tnum < LIM && lens[tnum]) {
                
//                 if (i==837799) {
//                     printf("reached prev tested %ld, len = %d + %d\n", tnum, len, lens[tnum]);
//                     
//                 }
                
                len += lens[tnum] - 1;
                break;
                
            }
            
            if (tnum % 2 == 0) tnum /= 2;
            else tnum = 3*tnum +1;
            
            len++;
            
        }
        
        lens[i] = len;
        
        if (len > maxlen){
            
            maxlen = len;
            maxnum = i;
            
        }
        
//         if (i==837799) printf("%d\n", len);
        
    }
    
    printf("num = %d, length = %d\n", maxnum, maxlen);
    return 0;
    
}
