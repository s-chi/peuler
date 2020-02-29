#include <stdio.h>
#define SIZE 80

int pathlen(int mat[SIZE][SIZE], int row, int col){
    
    if(row==SIZE-1 && col==SIZE-1)
        return mat[row][col];
    
    if(row==SIZE-1)
        return mat[row][col] + mat[row][col+1];
    
    if(col==SIZE-1)
        return mat[row][col] + mat[row+1][col];
    
    if(mat[row+1][col] > mat[row][col+1])
        return mat[row][col] + mat[row][col+1];
    
    return mat[row][col] + mat[row+1][col];
    
}

int main(){
    
    int i,j, mat[SIZE][SIZE];
    FILE * fp;
    
    fp = fopen("81_matrix.txt","r");
    
    for(i=0;i<SIZE;i++)
        for(j=0;j<SIZE;j++)
            fscanf(fp,"%d ,",&mat[i][j]);  
    
    fclose(fp);
    
    for(i=SIZE-1;i>=0;i--)
        for(j=SIZE-1;j>=0;j--)
            mat[i][j] = pathlen(mat,i,j);
        
    printf("%d\n",mat[0][0]);
    
    return 0;
    
}
