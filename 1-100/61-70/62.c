#include <stdio.h>
#define DLIM 5
#define LIM 10000
#define NPERM 5

void dprint(int digs[]){
    
    int i;
    
    for(i = digs[0]; i>0; i--)
                printf("%d", digs[i]);
    printf("\n");
    
    return;
}

void mcube(int dcube[], int num){
    
    int i;
    
    dcube[0] = 1;
    
    dcube[1] = num*num;
    
    for(i=1;i<=dcube[0];i++)
        if(dcube[i]>=10){
            
            dcube[i+1] += dcube[i] / 10;
            dcube[i] %= 10;
            
            if(i==dcube[0])
                dcube[0]++;
            
        }
        
    for(i=1;i<=dcube[0];i++)
        dcube[i] *= num;
    
    for(i=1;i<=dcube[0];i++)
        if(dcube[i]>=10){
            
            dcube[i+1] += dcube[i] / 10;
            dcube[i] %= 10;
            
            if(i==dcube[0])
                dcube[0]++;
            
        }
    
    return;
    
}

int iscubeperm(int num, int num2, int cubes[LIM][3*DLIM]){
    
    int compcub[3*DLIM], i, j, digfound;
    
    if(cubes[num2][0] != cubes[num][0])
        return 0;
    
    for(i=0;i<=cubes[num2][0];i++)
        compcub[i] = cubes[num2][i];
    
    for(i=0;i<=cubes[num2][0];i++){
        
        digfound = 0;
        
        for(j=0;j<=cubes[num2][0];j++)
            if(cubes[num][i] == compcub[j]){                
                compcub[j] = -1;
                digfound = 1;
                break;
            }
            
        if(!digfound)
            break;        
            
    }
    
    if(!digfound)
        return 0;
    
    return 1;
    
}

int main(){
    
    int num, num2, counter, cubes[LIM][3*DLIM] = {0};
    int res[NPERM];
    
    for(num = 345; num < LIM; num++)
        mcube(cubes[num],num);
    
    for(num = 345; num < LIM; num++){
        
        counter = 1;
        
        for(num2 = num + 1; num2 < LIM; num2++)
            if(iscubeperm(num,num2,cubes)){
                
                res[0] = num;
                res[counter] = num2;
                counter++;
                
            }
            
        if(counter==NPERM){
            
            for(num2 = 0; num2 < NPERM; num2++){
                
                printf("%d^3 = ", res[num2]);
                dprint(cubes[res[num2]]);
                
            }
            
            return 0;
            
        }
            
        
    } 
    
    return 0;
    
}

