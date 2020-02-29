#include <stdio.h>
#define LIM 100
#define DLIM 100

void dprint(int digs[]){
    
    int i;
    
    for(i = digs[0]; i>0; i--)
                printf("%d", digs[i]);
    
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


int a(int n){
    
    if(n==0)
        return 2;
    
    if(n%3 == 2)
        return 2 * (n+1)/3;
    
    return 1; 
    
}

int main(){
    
    int n, sum = 0;
    int num[DLIM] = {0}, den[DLIM] = {0}, temp[DLIM] = {0};
    const int a0 = 2;
    
    num[0] = den[0] = 1;
    num[1] = den[1] = 1;
    
    dmult(num,a(LIM-1));    
    
    printf("a_%d = %d, ",LIM-1,a(LIM-1));dprint(num);printf("/");dprint(den);printf("\n");
    
    for(n=LIM-2;n>=0;n--){
        
        dassign(temp, den);
        dassign(den, num);
        dmult(num,a(n));
        dsum(num,temp);
        
        printf("a_%d = %d, ",n,a(n));dprint(num);printf("/");dprint(den);printf("\n");
        
        
    }
    
    for(n=1;n<=num[0];n++)
        sum += num[n];
    
    printf("%d\n",sum);
    
    return 0;
    
}
