#include <stdio.h>
#define CHLEN 60
#define LIM 1000000
#define DLIM 20

unsigned int fac(unsigned int n){
    
    if (n<2)
        return 1;
    
    return n*fac(n-1);
    
}

void numtodigs(int num, int digs[]){
    
    int i;
    
    for(i=1;num>0;i++){
        digs[i] = num % 10;
        num /= 10;        
    }
    
    digs[0] = i-1;
    
    return;
    
    
}

int chnext(int prev,int facts[10]){
    
    int digs[DLIM], sum = 0, i;
    
    numtodigs(prev,digs);
    
    for(i=1;i<=digs[0];i++){
        
        sum += facts[digs[i]];
        
    }
    
    return sum; 
    
}


int main(){
    
    int startnum, facts[10], tot = 0, chain[CHLEN];
    int i, j, stop;
    
    for(i=9;i>=0;i--){
        facts[i] = fac(i);
    }
    
    for(startnum = LIM-1; startnum > 0; startnum--){
        
        chain[CHLEN-1] = startnum;
        stop = 0;
        
        for(i=CHLEN-2;i>=0;i--){
            
            chain[i] = chnext(chain[i+1],facts);
            
            for(j=CHLEN-1;j>i;j--){
                if(chain[i]==chain[j]){
                    stop = 1;
                    break;                    
                }
            }
            
            if(stop)
                break;
            
        }
        
        if(i<0)
            tot++;
        
    }
    
    printf("%d\n",tot);
    return 0;
    
}
