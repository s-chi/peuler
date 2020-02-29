#include <stdio.h> 
#include <math.h>
#include <string.h>
#define PLIM 10000

int * ptable(){
    
    static int array[PLIM];
    int i, j, sroot = sqrt(PLIM);
    
    array[2] = 1;
    for(i=3;i<PLIM;i+=2) array[i] = 1;
    
    for(i=3;i<sroot;i+=2){
        
        while(!array[i]) i+=2;
        
        if(array[i])
            for (j=i; j*i < PLIM; j+=2) 
                array[j*i] = 0;   
    }
    
    return array;
    
}


int * fun(int *digs, int *isprime){
    
    static int res[12];
    int numdigs[4], nextdigs[4], primes[24], primedigs[24][4], num, next, tnum, topprime = 0, flag;
    int i[4], j, k, l;
    
    memset(res, 0, sizeof(res));
    
    for(i[0]=0;i[0]<4;i[0]++){
        
        numdigs[0] = *(digs+i[0]);
        
        for(i[1]=0;i[1]<4;i[1]++){
            
            if(i[1]==i[0]) continue;
            
            numdigs[1] = *(digs+i[1]);
            
            for(i[2]=0;i[2]<4;i[2]++){
                
                if(i[2]==i[0]||i[2]==i[1]) continue;
                
                numdigs[2] = *(digs+i[2]);
                
                i[3] = 6 - i[0] - i[1] - i[2];
                
                numdigs[3] = *(digs+i[3]);
                
                num = 0;
                
                for(j=0;j<4;j++)
                    num = 10*num + numdigs[j];
                
                if(!*(isprime+num)) continue;
                
                if(topprime == 0){
                    
                    for(j=0;j<4;j++)
                        primedigs[0][j] = numdigs[j];
                    
                    primes[0] = num;
                    
                    topprime = 1;
                    continue;
                    
                } else {
                    
                    flag = 0;
                    
                    for(j=0;j<topprime;j++)
                        if(num == primes[j]){
                            flag = 1;
                            break;                            
                        }
                    
                    if(flag) continue;
                        
                    for(j=0;j<4;j++)
                        primedigs[topprime][j] = numdigs[j];
                    
                    primes[topprime] = num;
                    
                    topprime++;
                    
                    for(j=0;j<topprime-1;j++){
                        
                        next = 2*num - primes[j];
                        
                        if(next>=PLIM || !*(isprime+next)) continue;
                        
                        tnum = next;
                        
                        for(k=3;k>=0;k--){
                            
                            nextdigs[k] = tnum%10;
                            
                            flag = 0;
                            
                            for(l=0;l<4;l++)
                                if(nextdigs[k] == numdigs[l])
                                    flag = 1;
                                
                                if(!flag) break;
                                
                                tnum /= 10;
                            
                        }
                        
                        if(!flag) continue;
                        
                        for(k=0;k<4;k++){
                            res[k] = primedigs[j][k];
                            res[k+4] = numdigs[k];
                            res[k+8] = nextdigs[k];
                        }                  
                        
                    }
                    
                }
                
            }
            
        }
        
    }

    return res;
    
}

int main(){
    
    int *res, *isprime, digs[4], i[4], j;
    
    isprime = ptable();
    
    for(i[0]=1;i[0]<10;i[0]++){
        
        digs[0] = i[0];
        
        for(i[1]=i[0];i[1]<10;i[1]++){
            
            digs[1] = i[1];
            
            for(i[2]=i[1];i[2]<10;i[2]++){
                
                digs[2] = i[2];
                
                for(i[3]=i[2];i[3]<10;i[3]++){
                    
                    digs[3] = i[3];
                    
                    res = fun(digs, isprime);
                    
                    if(*(res+11)){
                        
                        for(j=0;j<12;j++)
                            printf("%d",res[j]);
                        printf("\n");
                        
                    }
                    
                    
                }
                
            }
            
        }
        
    }
    
    
    return 0;
    
}
