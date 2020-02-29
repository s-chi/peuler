#include <stdio.h>
#define NUM 50

void dincrease(int digs[]){//increases digs by 1
    
    int i;
    
    digs[1]++;
    
    for(i=1;i<=digs[0];i++){
        if(digs[i] >= 10){
            
            digs[i+1] += digs[i]/10;
            digs[i] %= 10;
            
            if(i == digs[0])
                digs[0]++;
            
        }
        
    }
        
    return;
    
}

void dprint(int digs[]){
    
    int i;
    
    for(i = digs[0]; i>0; i--)
                printf("%d", digs[i]);
    
    return;
}

int check(int code[], int nums[3]){
    
    int i = 1, j;
    
    for(j=2;j>=0;j--){
        
        while(i<=code[0]-j && code[i] != nums[j]) i++;
        
        if(i > code[0]-j)
            return 0;
        
        i++;
        
    }
    
    return 1;    
    
}

int main(){
    
    FILE *fp;
    int i,digs[NUM][3],code[3*NUM] = {0};
    
    fp = fopen("79_keylog.txt","r");
    
    for(i=0;i<NUM;i++)        
        fscanf(fp,"%1d%1d%1d",&digs[i][0],&digs[i][1],&digs[i][2]);
    
    fclose(fp);
    
    code[0] = 3;
    code[3] = 1;
    
    while(1){
        
        dincrease(code);
        
        for(i=0;i<NUM;i++)
            if(!check(code,digs[i]))
                break;
            
        if(i==NUM)
            break;
        
        
    }
    
    
    dprint(code);
    printf("\n");
    
    return 0;
    
}
