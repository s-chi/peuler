#include <stdio.h>
#define CONFN 210 //Binomial(10,6)

void genconf(int dconf[CONFN][10], int tconf[10], int *ind, int pos, int min){
    
    int i;
    
    
    if(pos==6){
        
        for(i=0;i<10;i++)
            dconf[*ind][i] = tconf[i];
        
        (*ind)++;
        return;
        
    }   
    
    for(i=min;i<5+pos;i++){
        
        tconf[i] = 1;
        genconf(dconf,tconf,ind,pos+1,i+1);
        tconf[i] = 0;
        
    }
    
    return;
    
}

int includes(int dconf[CONFN][10], int d1, int num){
    
    if(num==6)
        return (dconf[d1][6] || dconf[d1][9]);
    
    return dconf[d1][num];    
    
}


int main(){
    
    int dconf[CONFN][10] = {0}, ind = 0, tconf[10] = {0};
    int couples[8][2] = {{0,1},{0,4},{0,6},{1,6},{1,8},{2,5},{3,6},{4,6}};
    int d1,d2,flag,counter=0;
    
    genconf(dconf,tconf,&ind,0,0);
    
    for(d1=0;d1<CONFN-1;d1++)
        for(d2=d1+1;d2<CONFN;d2++){
            
            flag = 0;
            
            for(ind=0;ind<8;ind++){
                
                if(!(includes(dconf,d1,couples[ind][0])&&includes(dconf,d2,couples[ind][1])) &&
                   !(includes(dconf,d1,couples[ind][1])&&includes(dconf,d2,couples[ind][0]))){
                       
                    flag = 1;
                    break;
                    
                }
                
            }
            
            if(!flag)
                counter++;
            
            
        }
    
    
    printf("%d\n",counter);
    
    return 0;
    
}
