#include <stdio.h>
#include <math.h>
#include <string.h>
#define PLIM 1000000000
#define LIM 100000 
#define DLIM 7
#define MAXSUM 1000000000

int * ptable(){
    
    static int array[PLIM];
    int i, j, sroot = sqrt(PLIM);
    
    array[2] = 1;
    for(i=3;i<PLIM;i+=2) array[i] = 1;
    
    for(i=3;i<=sroot;i+=2){
        
        while(!array[i]) i+=2;
        
        if(array[i])
            for (j=i; j*i < PLIM; j+=2) 
                array[j*i] = 0;   
    }
    
    return array;
    
}

long concat(int d1[], int d2[]){
    
    int dres[2*DLIM] = {0}, i;
    long res;
    
    dres[0] = d1[0] + d2[0];
    
    for(i=1;i<=d1[0];i++)
        dres[i] = d1[i];
    for(i=1;i<=d2[0];i++)
        dres[i + d1[0]] = d2[i];
    
    res = 0;
    
    for(i=dres[0];i>0;i--)
        res = res*10 + dres[i];
    
    return res;
    
}

void dincrease(int digs[]){
    
    int i;
    
    digs[1]+=2;
    
    for(i=1;i<=digs[0];i++)
        if(digs[i] >= 10){
            
            digs[i+1] += digs[i]/10;
            digs[i] %= 10;
            
        }
    
    if(digs[digs[0]+1])
        digs[0]++;
        
    return;        
    
}

void dassign(int d1[], int d2[]){
    
    int i;
    
    memset(d1,0,DLIM*sizeof(int));
    
    for(i=0;i<=d2[0];i++)
        d1[i] = d2[i];
    
    return;
    
}

int main(){
    
    int *isprime;
    int prime[5], dprime[5][DLIM] = {0}, i, sum, flag, minsum = MAXSUM, lim = LIM;
    long temp;
    
    isprime = ptable();
    
    for(prime[0]=3, dprime[0][0] = 1, dprime[0][1] = 3; prime[0] < lim; prime[0] += 2, dincrease(dprime[0])){
        
        while(!*(isprime + prime[0])){
            
            prime[0] += 2;
            dincrease(dprime[0]);
            
        }
        
        if(prime[0] >= lim)
            continue;
        
        for(prime[1]=prime[0]+2, dassign(dprime[1], dprime[0]), dincrease(dprime[1]); prime[1] < lim; prime[1] += 2, dincrease(dprime[1])){
            
            while(!*(isprime + prime[1])){
                
                prime[1] += 2;
                dincrease(dprime[1]);
                
            }
            
            if(prime[1] >= lim)
                continue;
            
            temp = concat(dprime[0],dprime[1]);
            if(temp >= PLIM || !*(isprime + temp))
                continue;
            temp = concat(dprime[1],dprime[0]);
            if(temp >= PLIM || !*(isprime + temp))
                continue;
            
            for(prime[2]=prime[1]+2, dassign(dprime[2], dprime[1]), dincrease(dprime[2]); prime[2] < lim; prime[2] += 2, dincrease(dprime[2])){
                
                while(!*(isprime + prime[2])){
                    
                    prime[2] += 2;
                    dincrease(dprime[2]);
                    
                }
                
                if(prime[2] >= lim)
                    continue;
                
                flag = 0;
                
                for(i=0;i<2;i++){                    
                    temp = concat(dprime[i],dprime[2]);
                    if(temp >= PLIM || !*(isprime + temp)){
                        flag = 1;
                        break;
                    }
                    temp = concat(dprime[2],dprime[i]);
                    if(temp >= PLIM || !*(isprime + temp)){
                        flag = 1;
                        break;
                    }                    
                }
                if(flag) continue;
                
                for(prime[3]=prime[2]+2, dassign(dprime[3], dprime[2]), dincrease(dprime[3]); prime[3] < lim; prime[3] += 2, dincrease(dprime[3])){
                    
                    while(!*(isprime + prime[3])){
                        
                        prime[3] += 2;
                        dincrease(dprime[3]);
                        
                    }
                    
                    if(prime[3] >= lim)
                        continue;
                    
                    flag = 0;
                    
                    for(i=0;i<3;i++){                    
                        temp = concat(dprime[i],dprime[3]);
                        if(temp >= PLIM || !*(isprime + temp)){
                            flag = 1;
                            break;
                        }
                        temp = concat(dprime[3],dprime[i]);
                        if(temp >= PLIM || !*(isprime + temp)){
                            flag = 1;
                            break;
                        }                    
                    }
                    if(flag) continue;
                    
                    for(prime[4]=prime[3]+2, dassign(dprime[4], dprime[3]), dincrease(dprime[4]); prime[4] < lim; prime[4] += 2, dincrease(dprime[4])){
                        
                        while(!*(isprime + prime[4])){
                            
                            prime[4] += 2;
                            dincrease(dprime[4]);
                            
                        }
                        
                        if(prime[4] >= lim)
                            continue;
                        
                        flag = 0;
                        
                        for(i=0;i<4;i++){                    
                            temp = concat(dprime[i],dprime[4]);
                            if(temp >= PLIM || !*(isprime + temp)){
                                flag = 1;
                                break;
                            }
                            temp = concat(dprime[4],dprime[i]);
                            if(temp >= PLIM || !*(isprime + temp)){
                                flag = 1;
                                break;
                            }                    
                        }
                        if(flag) continue;
                        
                        sum = 0;
                            
                        for(i=0;i<5;i++){
                            
                            printf("%d ", prime[i]);
                            sum += prime[i];
                            
                        }
                        
                        printf("\n%d\n\n",sum);
                        
                        if(sum < minsum){
                            
                            minsum = sum;
                            if (minsum < lim)
                                lim = minsum;
                            
                        }                        
                    }
                }
            }
        }
    }
    
    printf("%d\n", minsum);
    
    return 0;
    
}
