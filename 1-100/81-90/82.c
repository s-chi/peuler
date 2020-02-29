#include <stdio.h>
#define SIZE 80

void collen(int j, int mat[SIZE][SIZE]){//find path lengths for elements in column j, if the lengths for cols >j are known
    
    int i,k,min,temp;
    
    for(k=0;k<SIZE;k++){
        if(k>0 && mat[k][j+1] > mat[k-1][j])
            min = mat[k-1][j];
        else
            min = mat[k][j+1];
        
        temp = 0;
        
        for(i=k+1;i<SIZE;i++){
            
            temp += mat[i][j];
            if(temp >= min)
                break;
            if(temp+mat[i][j+1]<min)
                min = temp+mat[i][j+1];
        }
        
        mat[k][j] += min;        
        
    }
        
    return;
    
}

int main(){
    
    int i,j, min, mat[SIZE][SIZE];
    FILE * fp;
    
    fp = fopen("82_matrix.txt","r");
    
    for(i=0;i<SIZE;i++)
        for(j=0;j<SIZE;j++)
            fscanf(fp,"%d ,",&mat[i][j]);  
    
    fclose(fp);
    
    for(i=SIZE-2;i>=0;i--)
        collen(i,mat);
   
    min = mat[0][0];
    for(i=1;i<SIZE;i++)
        if(mat[i][0]<min)
            min = mat[i][0];
        
    printf("%d\n",min);
    
    return 0;
    
}
