#include <stdio.h>

int main(){
    
    int grid[20][20], i, j, k, prod=0, tprod, type=1, start[2];
    
    for (i=0;i<20;i++)
        for (j=0;j<20;j++) scanf("%d",&grid[i][j]);
        
    //horizontal, type 1
        
    for(i=0;i<20;i++)
        for(j=0;j<17;j++){
            
            tprod=1;
            for(k=0;k<4;k++) tprod *= grid[i][j+k];
            
            if (tprod>prod) {
                
                start[0]=i;
                start[1]=j;
                prod=tprod;
                
            }
            
        }
        
    //vertical, type 2
    
    for(i=0;i<17;i++)
        for(j=0;j<20;j++){
            
            tprod=1;
            for(k=0;k<4;k++) tprod *= grid[i+k][j];
            
            if (tprod>prod) {
                
                type=2;
                start[0]=i;
                start[1]=j;
                prod=tprod;
                
            }
            
        }
        
    //dxdiag, type 3
        
    for(i=0;i<17;i++)
        for(j=0;j<17;j++){
            
            tprod=1;
            for(k=0;k<4;k++) tprod *= grid[i+k][j+k];
            
            if (tprod>prod) {
                
                type=3;
                start[0]=i;
                start[1]=j;
                prod=tprod;
                
            }
            
        }
        
    //sxdiag, type 4
        
    for(i=0;i<17;i++)
        for(j=3;j<20;j++){
            
            tprod=1;
            for(k=0;k<4;k++) tprod *= grid[i+k][j-k];
            
            if (tprod>prod) {
                
                type=4;
                start[0]=i;
                start[1]=j;
                prod=tprod;
                
            }
            
        }
        
    printf("start at (%d,%d), type %d\n", start[0], start[1], type);
    printf("%d\n", prod);
    return 0;
    
}
