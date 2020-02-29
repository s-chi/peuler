#include <stdio.h>
#include <math.h>
#define MAXSIZE 50001 //odd number
#define PLIM 1000000000

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


int main(){
    
    int row, col, dir = 0, len = 1, rlen = 1, num = 1, sum=0, size, center, numprimes = 0;
    int * isprime;
    
    isprime = ptable();
    
    center = MAXSIZE/2;
    
    row = col = center;
    
    for(size = 3; size <= MAXSIZE; size += 2){
        
        for(num = (size-2)*(size-2)+1; num <= size*size; num++) {
        
            switch(dir){
                
                case 0:
                    col++;
                    break;
                case 1:
                    row--;
                    break;
                case 2:
                    col--;
                    break;
                case 3:
                    row++;
                    break;            
                    
            }
            
            rlen--;
            if(rlen==0){
                
                dir = (dir + 1) % 4;
                if (dir % 2 == 0) len++;
                rlen = len;
                
            }
        
        }
            
        if(*(isprime + num - size)) //lower right corner can never be prime, since it's size^2
            numprimes++;
        if(*(isprime + num - 2*size + 1))
            numprimes++;
        if(*(isprime + num - 3*size + 2))
            numprimes++;            
        
        if((numprimes*10)/(2*size - 1) < 1)
            break;        
    }
    
    printf("%d\n", size);    
    
    
    return 0;
    
}
