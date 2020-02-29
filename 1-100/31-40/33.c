#include <stdio.h>

int main(){
    
    int fracs[4][2], i, j, digs[4], target[2], check[2], latest=0, prod[2] = {1,1};
    
    for(i=10;i<100;i++){
        
        for(j=i+1;j<100;j++){
            
            digs[0] = i/10;
            digs[1] = i%10;
            digs[2] = j/10;
            digs[3] = j%10;
            
            if(digs[0]*digs[1]*digs[2]*digs[3]==0) continue;
            
            if(digs[0] == digs[2]){
                target[0] = digs[1];
                target[1] = digs[3];
            } else if(digs[0] == digs[3]){
                target[0] = digs[1];
                target[1] = digs[2];
            } else if(digs[1] == digs[2]){
                target[0] = digs[0];
                target[1] = digs[3];
            } else if(digs[1] == digs[3]){
                target[0] = digs[0];
                target[1] = digs[2];
            } else continue;
            
            check[0] = i*target[1];
            check[1] = j*target[0];
            
            if(check[0]/check[1]==1 && check[0]%check[1]==0){
                
                fracs[latest][0] = i;
                fracs[latest][1] = j;
                prod[0] *= target[0];
                prod[1] *= target[1];
                printf("%d/%d = %d/%d\n",i,j,target[0],target[1]);
                latest++;
                
            }    
            
            
        }
        
    }
    
    printf("prod = %d/%d",prod[0],prod[1]);
    
    for(i=1;i<=prod[0];i++)
        if(prod[0]%i==0 && prod[1]%i==0){
            prod[0]/=i;
            prod[1]/=i;
        }
        
    printf(" = %d/%d\n",prod[0],prod[1]);
    
    return 0;
    
}
