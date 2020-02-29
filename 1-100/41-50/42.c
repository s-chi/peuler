#include <stdio.h>
#include <math.h>
// assume no word is longer than 30 chars

int main(){
    
    int index=1, value = 0, j, counter = 0;
    char word[30];
    FILE *fp;
    
    fp = fopen("42_words.txt","r");
    
    fscanf(fp,"\"%[^\"]s", word);
    
    for(j=0;word[j];j++)
        value += word[j] - 64;
    
    if(fmod(sqrt(8*value+1)-1, 2) == 0){
        
        printf("word: %s, value: %d\n", word, value);
        counter++;
        
    }
    
    while(!feof(fp)){
        
        fscanf(fp,"\",\"%[^\"]s", word);
        value = 0;
        for(j=0;word[j];j++)
            value += word[j] - 64;
        
        if(fmod(sqrt(8*value+1)-1, 2) == 0){
            
            printf("word: %s, value: %d\n", word, value);
            counter++;
            
        } 
        
    }   
    
    fclose(fp);
    
    printf("\n%d\n",counter);
    
    return 0;
    
}
