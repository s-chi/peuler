#include <stdio.h>
#define SIZE 1001 //odd number

int main(){
    
    int spiral[SIZE][SIZE], row, col, dir = 0, len = 1, rlen = 1, num = 1, sum=0;
    
    row = col = SIZE/2;
    
    spiral[row][col] = 1;
    
    for(num = 2; num <= SIZE*SIZE; num++){
        
        switch(dir){
            
            case 0:
                col++;
                break;
            case 1:
                row++;
                break;
            case 2:
                col--;
                break;
            case 3:
                row--;
                break;            
            
        }
        
        spiral[row][col] = num;
        
        rlen--;
        if(rlen==0){
            
            dir = (dir + 1) % 4;
            if (dir % 2 == 0) len++;
            rlen = len;
            
        }
        
    }

    for(row=0;row<SIZE;row++){        
        sum += spiral[row][row];
        sum += spiral[row][SIZE-1-row];
    }
    
    sum--;
    
    printf("%d\n", sum);
    
    return 0;
    
    
}
