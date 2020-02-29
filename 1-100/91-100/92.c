#include <stdio.h>
#include <string.h>
#define LIM 10000000
#define DLIM 10

void dincrease(int digs[]){//increases digs by 1
    
    int i;
    
    if(digs[0]==0)
        digs[0] = 1;
    
    digs[1]++;
    
    for(i=1;i<=digs[0];i++){
        if(digs[i] >= 10){
            
            digs[i+1] += digs[i]/10;
            digs[i] %= 10;
            
            if(i == digs[0])
                digs[0]++;
            
        }
        
    }
        
    return;
    
}

void dassign(int d1[], int d2[]){ //assigns d1 = d2
    
    int i;
    
    memset(d1,0,DLIM*sizeof(int));
    
    for(i=0;i<=d2[0];i++)
        d1[i] = d2[i];
    
    return;
    
}

void dsum(int d1[], int d2[]){
    
    int i,maxd;
    
    if(d1[0]>d2[0])
        maxd = d1[0];
    else
        maxd = d2[0];
    
    for(i=1;i<=maxd;i++){
        d1[i] += d2[i];
        
        if(d1[i]>=10){
            
            d1[i+1] += d1[i]/10;
            d1[i] %= 10;
        }
        
    }
    
    d1[0]=DLIM-1;
    while(!d1[d1[0]]) d1[0]--;
    
    return;
    
}

void numtodigs(int num, int digs[]){
    
    int i;
    
    memset(digs,0,DLIM*sizeof(int));
    
    for(i=1;num>0;i++){
        digs[i] = num % 10;
        num /= 10;        
    }
    
    digs[0] = i-1;
    
    return;
    
    
}


int main(){
    
    int i, j, digs[DLIM] = {0}, ndigs[DLIM], tdigs[DLIM] = {0}, tdigs2[DLIM] = {0}, counter = 0;
    
    for(i=1;i<LIM;i++){
        
//         printf("%d: \n",i);
        
        dincrease(digs);
        
        dassign(ndigs,digs);
        
        while(1){
            
            memset(tdigs,0,sizeof(tdigs));
            
            for(j=1;j<=ndigs[0];j++){
                numtodigs(ndigs[j]*ndigs[j],tdigs2);
                dsum(tdigs,tdigs2);
            }
            
            
            if(tdigs[0]==1&&tdigs[1]==1){
                break;}
            
            if(tdigs[0]==2&&tdigs[1]==9&&tdigs[2]==8){
                
                counter++;
                break;
                
            }
            
            dassign(ndigs,tdigs);
            
        }
        
    }
    
    printf("%d\n",counter);
    
    
    return 0;
    
}

