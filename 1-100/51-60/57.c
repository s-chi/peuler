#include <stdio.h>
#include <string.h>
#define ITELIM 1000
#define DLIM 400

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
            if(i==d1[0])
                d1[0]++;
        }
        
    }
    
    return;
    
}

void dmult(int digs[], int fac){
    
    int i;
    for(i=1;i<=digs[0];i++)
        digs[i] *= fac;
        
    for(i=1;i<=digs[0];i++)
        if(digs[i]>=10){
            
            digs[i+1] += digs[i]/10;
            digs[i] %= 10;
            
            if(i == digs[0])
                digs[0]++;            
        }
    
    return;
    
}

void dassign(int d1[], int d2[]){
    
    int i;
    
    for(i=0;i<=d2[0];i++)
        d1[i] = d2[i];
    
    return;
    
}

int main(){
    
    int i, counter = 0;
    int num[DLIM] = {0}, den[DLIM] = {0}, temp[DLIM] = {0};
    
    num[0] = 1;
    num[1] = 1;
    den[0] = 1;
    den[1] = 2;
    
    
    for(i=1;i<ITELIM;i++){
        
        memset(temp,0,sizeof(temp));
        dassign(temp,num);//temp = num, save old num
        memset(num,0,sizeof(num));
        dassign(num,den);//num = den, new num = old den
        
        dmult(den,2);//den *= 2
        
        dsum(den,temp);//den += temp, new den = 2*old den + old num
        memset(temp,0,sizeof(temp));
        dassign(temp,num);// temp = num
        
        dsum(temp, den);// temp += den
        
        if(temp[0]>den[0])
            counter++;

    }
    
    printf("%d\n", counter);
    
    return 0;
    
}
