#include <stdio.h>
#include <math.h>
//it can be shown that the product must have exactly 4 digits
//since in total there are 9 digits, reordering the factors one can have 1d x 4d = 4d or 2d x 3d = 4d

int check(int facdigs[5]){
    
    static int products[10], topprod;
    int rvalue = 0, i, j, digs[4], digs3[3], flag, prod;
    
    for(i=0;i<4;i++) digs[i] = facdigs[1+i];
    
    for(i=3;i>=0;i--) digs[i] *= facdigs[0];
    
    for(i=3;i>0;i--) 
        if(digs[i] > 9){
            digs[i-1] += digs[i]/10;
            digs[i] %= 10;
        }
        
    if (digs[0]<10){
        
        flag = 0;
        
        for(i=0;i<4;i++){
            
            if (digs[i]==0){
                flag = 1;
                break;                
            }
            
            for(j=0;j<i;j++)
                if(digs[i]==digs[j]){
                    flag=1;
                    break;                    
                }
            if (flag) break;
            
            for(j=0;j<5;j++)                
                if(digs[i] == facdigs[j]){                    
                    flag = 1;
                    break;                    
                }
                
            
            if (flag) break;
            
        }
        
        if (!flag) {
            
            flag = 0;
            prod = digs[0]*1000 + digs[1]*100 + digs[2]*10 + digs[3];
            printf("%d * %d%d%d%d = %d\n", facdigs[0],facdigs[1],facdigs[2],facdigs[3],facdigs[4],prod);
            for(i=0;i<topprod;i++)
                if (prod==products[i]){
                    flag = 1;
                    break;
                }
            if(!flag){
                
                products[topprod] = prod;
                topprod++;
                rvalue += prod;                
            }
        }
        
    }
    
    digs[3] = 0;
    
    for(i=0;i<3;i++){        
        digs[i] = facdigs[2+i];
        digs3[i] = facdigs[2+i];        
    } 
    
    for(i=2;i>=0;i--){
        digs[i] *= facdigs[0];
        digs3[i] *= facdigs[1];        
    } 
    
    for(i=2;i>0;i--){ 
        if(digs[i] > 9){
            digs[i-1] += digs[i]/10;
            digs[i] %= 10;
        }
        if(digs3[i] > 9){
            digs3[i-1] += digs3[i]/10;
            digs3[i] %= 10;
        }
    }
    
    for(i=3;i>0;i--){
        digs[i] += digs3[i-1];
        if(digs[i]>9){
            digs[i-1] += digs[i]/10;
            digs[i] %= 10;            
        }
    }       
        
    if (digs[0]<10){
        
        flag = 0;
        
        for(i=0;i<4;i++){
            
            if (digs[i]==0){
                flag = 1;
                break;                
            }
            
            for(j=0;j<i;j++)
                if(digs[i]==digs[j]){
                    flag=1;
                    break;                    
                }
            if (flag) break;
            
            for(j=0;j<5;j++)                
                if(digs[i] == facdigs[j]){                    
                    flag = 1;
                    break;                    
                }                
            
            if (flag) break;
            
        }
        
        if (!flag){
            
            flag = 0;
            prod = digs[0]*1000 + digs[1]*100 + digs[2]*10 + digs[3];
            printf("%d%d * %d%d%d = %d\n", facdigs[0],facdigs[1],facdigs[2],facdigs[3],facdigs[4],prod);
            for(i=0;i<topprod;i++)
                if (prod==products[i]){
                    flag = 1;
                    break;
                }
                if(!flag){
                    
                    products[topprod] = prod;
                    topprod++;
                    rvalue += prod;                
                }
        } 
        
    }
    
    
    return rvalue;
    
}

void fun(int facdigs[5], int ind, int * prodsum){
    
    int i,j, flag;
    
    if (ind==5){        
        *prodsum += check(facdigs);//returns 0 or product
        return;        
    }
        
    for(i=1;i<10;i++){
        flag = 0;
        for (j=0;j<ind;j++){            
            if (*(facdigs+j) == i){
                
                flag = 1;
                break;
                
            }
        }
        
        if (flag) continue;
        *(facdigs+ind) = i;
        fun(facdigs,ind+1, prodsum);        
        
    }
    
    
}


int main(){
    
    int facdigs[5], prodsum=0;
    
    fun(facdigs, 0, &prodsum);
    
    printf("\n%d\n", prodsum);
    
    return 0;
    
}
