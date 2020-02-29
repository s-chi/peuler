#include <stdio.h>
#include <string.h>

#define STRLEN 20

int romtodec(char *rom){
    
    int dec = 0,prev,cur=0;
    char *point=rom;
    
    while(*point){
        
        prev = cur;
        
        switch(*point){
            
            case 'M':
                cur = 1000;
                break;
            case 'D':
                cur = 500;
                break;
            case 'C':
                cur = 100;
                break;
            case 'L':
                cur = 50;
                break;
            case 'X':
                cur = 10;
                break;
            case 'V':
                cur = 5;
                break;
            case 'I':
                cur = 1;
                break;
            default:
                printf("Unknown char: %c\n",*point);
                return -1;
                break;
            
        }
        
        if(cur<=prev)
            dec += prev;
        else
            cur -= prev;
        
        point++;
    }
    
    dec += cur;
    
    return dec;   
    
}

void dectorom(int num, char rom[STRLEN]){
    
    char romden[7] = {'M' ,'D','C','L','X','V','I'};
    int  romval[7] = {1000,500,100, 50, 10, 5 , 1 };
    int i,j,ind=0,rep;
    
    for(i=0;i<7;i+=2){
        
        rep = num / romval[i];
        num %= romval[i];
        
        if(i>0 && rep==4){
            
            if(rom[ind-1]==romden[i-1]){
                
                rom[ind-1] = romden[i];
                rom[ind] = romden[i-2];
                ind++;
                
            } else {
                
                rom[ind] = romden[i];
                rom[ind+1] = romden[i-1];
                ind += 2;
                
            }
            
        } else {
            
            for(j=0;j<rep;j++){
                
                rom[ind] = romden[i];
                ind++;
                
            }
                
        }
        
        if(i<6 && num/romval[i+1]){
            
            rom[ind] = romden[i+1];
            ind++;
            num -= romval[i+1];
            
        }
        
    }
    
    rom[ind] = '\0';
    
    return;
}


int main(){
    
    char rom[STRLEN] = "MMMDLXVIIII", newrom[STRLEN];
    int num, sum = 0, len, newlen;
    FILE *fp;
    
    fp = fopen("89_roman.txt","r");
    
    while(fgets(rom,STRLEN,fp)){
        
        len = strlen(rom);
        if(len > 0 && rom[len-1] == '\n'){
            rom[len-1] = '\0';
            len--;
        }
        
        num = romtodec(rom);
        dectorom(num,newrom);
        
        newlen = strlen(newrom);
        sum += len - newlen;
        
//         printf("%s = %d = %s\n",rom,num,newrom);
        
    }
    
    fclose(fp);
    
    printf("%d\n",sum);
    
    
    return 0;
    
}
