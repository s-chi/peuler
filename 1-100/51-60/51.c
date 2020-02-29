#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
#define PLIM 1000000
#define NUM 8

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

void dincrease(int * digs, int incr, int top, int *longer){
    
    int i;
    
    *digs += incr;
    
    for(i=0;i<top;i++)
        if(*(digs+i) >= 10){
            
            *(digs+i+1) += *(digs+i)/10;
            *(digs+i) %= 10;
            
        }
    
    if(*(digs+top))
        *longer = 1;
        
    return;        
    
}

int * findmasks(int topdig, int * nmask){
    
    int * ret;
    int i, j, temp;
    
    *nmask = pow(2,topdig)-2;
    
    ret = (int *) malloc((*nmask)*topdig*sizeof(int));
    
    for(i=1;i<=*nmask;i++){
        
        temp = i;
        
        for(j=0;j<topdig;j++){
            
            *(ret + topdig*(i-1) + j) = temp % 2;
//             printf("%d, %d\n", temp, temp%2);
            temp /= 2;
            
        }
        
        
    }
    
    return ret;
    
}

int main(){
    
    int *isprime, *masks;
    int prime = 13, pdigs[7] = {0}, topdig = 2, i, j, k, nmask, longer, num, counter, flag;
    
    isprime = ptable();
    pdigs[0] = 3;
    pdigs[1] = 1;
    
    masks = findmasks(2, &nmask);
    
    while(1){
        
        for(i=0;i<nmask;i++){
            
            counter = 0;
            
//             j=0;
//             
//             while(!*(masks+topdig*i+j)) j++;
//             
//             checkd = pdigs[j];
//             
//             if(prime==120383) printf("%d\n",checkd);
//             
//             for(j++;j<topdig;j++)
//                 if(*(masks+topdig*i+j) && pdigs[j]!=checkd) continue;
            
            flag = 0;
            
            for(j=0;j<10;j++){
                
                num = 0;
                
                for(k=topdig-1;k>=0;k--){
                    
                    num = num*10 + j*(*(masks+topdig*i+k)) + pdigs[k]*(1-*(masks+topdig*i+k));
                    
                    if(num == prime)
                        flag = 1;
                    
                }
                
                if (*(isprime+num) && num > pow(10,topdig-1)) counter++;                
                
            }
            
            if(counter >= NUM && flag){
                
                printf("prime: %d\n", prime);
                for(k=topdig-1;k>=0;k--)
                    printf("%d", *(masks+topdig*i+k));
                printf("\n");
                return 0;
                
            }    
            
        }
        
        do {
            
            prime +=2;
            longer = 0;
            dincrease(pdigs,2,topdig,&longer);
            if(longer){
                topdig++;
                free(masks);
                masks = findmasks(topdig, &nmask);                
            }
            
        } while(!*(isprime+prime));
        
    }
    
    return 0;
    
}
