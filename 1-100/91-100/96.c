#include <stdio.h>
#define BUFL 10
#define GSIZE 9

int solve(int grid[GSIZE][GSIZE]){
    
    int row,col,i,j,k,flag;
    
    for(row=0;row<GSIZE;row++){ //find first empty cell
        flag = 0;
        for(col=0;col<GSIZE;col++){
            if(!grid[row][col]){
                flag = 1;
                break;
            }
        }
        if(flag)
            break;
    }
    
    if(row==GSIZE) //if there are no empty cells the sudoku is solved
        return 1;
    
    for(i=1;i<=GSIZE;i++){// try all possible numbers in the current empty cell
        
        flag = 0;
        
        for(j=0;j<GSIZE;j++) //if the number is already present in the same col, change number
            if(grid[j][col] == i){
                flag = 1;
                break;
            }
        if(flag)
            continue;
        
        for(j=0;j<GSIZE;j++) //if the number is already present in the same row, change number
            if(grid[row][j] == i){
                flag = 1;
                break;
            }
        if(flag)
            continue;
        
        for(j=(row/3)*3;j<(row/3+1)*3;j++){ //if the number is already present in the same square, change number
            for(k=(col/3)*3;k<(col/3+1)*3;k++){
                if(grid[j][k] == i){
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(flag)
            continue;
       
        grid[row][col] = i;
        
        if(solve(grid))
            return 1;
        
    }
    
    grid[row][col] = 0; //if a solution wasn't found reset the current cell
    return 0;
}


int main(){
    
    FILE *fp;
    char buf[BUFL];
    int grid[GSIZE][GSIZE],i,j, sum=0;
    
    fp = fopen("96_sudoku.txt","r");
    
    
    while(fgets(buf,BUFL,fp)){
        
        for(i=0;i<GSIZE;i++)
            for(j=0;j<GSIZE;j++)
                fscanf(fp,"%1d",&grid[i][j]);
            
        fgetc(fp);//"eat" a \n character so that it is not read by fgets
        
        solve(grid);
        sum += grid[0][0] * 100 + grid[0][1] * 10 + grid[0][2];
        
    }
    
    fclose(fp);
    
    printf("%d\n",sum);
    
    return 0;
    
}
