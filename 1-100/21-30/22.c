#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    char names[5500][20];
    int nameindex = 1, i, j, score, totscore = 0;
    FILE * fp;
    
    fp = fopen("22.txt","r");
    
    fscanf(fp,"\"%[^\"]s", names[0]);
    
    while(!feof(fp)){
        
        fscanf(fp,"\",\"%[^\"]s", names[nameindex]);
        nameindex++;      
        
    }   
    
    nameindex--;

    qsort(names, nameindex, 20, strcmp);
    
    for(i=0;i<nameindex;i++) {
        
        score = 0;
        j=0;
        
        while(names[i][j]){
            
            score += names[i][j] - 64;
            j++;
            
        }
        
        totscore += (i+1)*score;
        
    }
    
    printf("%d\n", totscore);

    return 0;
    
}
