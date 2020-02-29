#include <stdio.h>
#define SIZE 80
#define UPLIM 1000000000
//Dijkstra

int expand(int row, int col, int mat[SIZE][SIZE], int explored[SIZE][SIZE], int queued[SIZE][SIZE]){
    
    int temp;
    
    if(row==SIZE-1 && col==SIZE-1)
        return queued[row][col];
    
    if(row>0 && !explored[row-1][col]){//up
        
        temp = mat[row-1][col] + queued[row][col];
        
        if(!queued[row-1][col] || temp < queued[row-1][col])
            
            queued[row-1][col] = temp;
        
    }
    
    if(row<SIZE-1 && !explored[row+1][col]){//down
        
        temp = mat[row+1][col] + queued[row][col];
        
        if(!queued[row+1][col] || temp < queued[row+1][col])
            
            queued[row+1][col] = temp;
        
    }
    
    if(col<SIZE-1 && !explored[row][col+1]){//right
        
        temp = mat[row][col+1] + queued[row][col];
        
        if(!queued[row][col+1] || temp < queued[row][col+1])
            
            queued[row][col+1] = temp;
        
    }
    
    if(col>0 && !explored[row][col-1]){//left
        
        temp = mat[row][col-1] + queued[row][col];
        
        if(!queued[row][col-1] || temp < queued[row][col-1])
            
            queued[row][col-1] = temp;
        
    }
    
    queued[row][col] = 0;
    explored[row][col] = 1;
    
    return 0;
    
}

void findnext(int next[2], int queued[SIZE][SIZE]){
    
    int i, j, min = UPLIM;
    
    for(i=0;i<SIZE;i++)
        for(j=0;j<SIZE;j++){
            
            while(j<SIZE-1 && !queued[i][j]) j++;
            
            if(queued[i][j] && queued[i][j] < min){
                
                min = queued[i][j];
                next[0] = i;
                next[1] = j;
                
            }
            
        }
    
    return;    
    
}

int main(){
    
    int i,j, len, mat[SIZE][SIZE], explored[SIZE][SIZE] = {{0}}, queued[SIZE][SIZE] = {{0}}, next[2];
    FILE * fp;
    
    fp = fopen("83_matrix.txt","r");
    
    for(i=0;i<SIZE;i++)
        for(j=0;j<SIZE;j++)
            fscanf(fp,"%d ,",&mat[i][j]);  
    
    fclose(fp);
    
    queued[0][0] = mat[0][0];
    len = expand(0,0,mat,explored,queued);
    
    while(!len){
        
        findnext(next,queued);
        len = expand(next[0],next[1],mat,explored,queued);        
        
    }
    
        
    printf("%d\n",len);
    
    return 0;
    
}
