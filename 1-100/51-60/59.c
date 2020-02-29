#include <stdio.h>
#define MSGLEN 2000

int main(){
    
    FILE *fp;
    int i, j, value, badkey, cind, sum;
    char key[3], ch;
    char string[MSGLEN];
    
    fp = fopen("59_cipher.txt","r");
    
    for(key[0]='a';key[0]<='z';key[0]++)        
        for(key[1]='a';key[1]<='z';key[1]++)
            for(key[2]='a';key[2]<='z';key[2]++){
                
                badkey = 0;
                i=0;
                cind = 0;
                sum = 0;
                
                while(!feof(fp)){
                    
                    fscanf(fp,"%d,", &value);
                    
                    ch = value ^ key[i];
                    
                    if ((ch >= ' ' && ch <= 'z') && ch != '@' && ch != '`'){
                        
                        string[cind++] = ch;
                        sum += (int) ch;
                        
                    } else {
                        
                        badkey = 1;
                        break;
                    }     
                    
                    i = (i+1) % 3;
                    
                }
//                 printf("\n\n");
                
                rewind(fp);
                
                if(badkey)
                    continue;
                
                string[cind] = '\0';
                printf("%s\n\n", string);
                printf("%d\n", sum);
                fclose(fp);
                return 0;
                
            }
            
    fclose(fp);    
    
    return 0;
    
}
