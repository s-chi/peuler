#include <stdio.h>
#define LIM 10000

int main(){
    
    int i, j, k, l, fdigs[4] = {0}, tempdigs[5], totdigs[20], maxnum = 0, num, ftop=1, ndigs, ttop, flag;
    
    for(i=1;i<LIM;i++){
        
        fdigs[0]++;//increment the digits of i
        for(k=0;k<3;k++)
            if(fdigs[k]>9){
                fdigs[k+1]++;
                fdigs[k] = 0;
            }
        if(ftop<4 && fdigs[ftop]) ftop++;// ftop is the number of digits of i
            
        tempdigs[4] = 0;//the other components are always assigned explicitely
        num = 0; 
        
        for(k=ftop-1;k>=0;k--){//i*1
            totdigs[k] = fdigs[k];
            num = num*10 + fdigs[k];
        }  
        ndigs = ftop;
        
        
        
        for(j=2;ndigs<9;j++){//j never exceeds 9, since 1*(1,2,3,4,5,6,7,8,9) = 123456789 has 9 digits
            
            ttop = ftop;
            for(k=0;k<4;k++) tempdigs[k] = fdigs[k] * j;
            for(k=0;k<4;k++)
                if(tempdigs[k]>9){
                    tempdigs[k+1] += tempdigs[k]/10;
                    tempdigs[k] %= 10;
                }
            if(tempdigs[ttop]) ttop++; //ttop is the number of digits of i*j
            
            for(k=ttop-1,l=ndigs; k>=0; k--,l++){
                
                num = num*10 + tempdigs[k];// num: concatenated product
                totdigs[l] = tempdigs[k]; //totdigs: digits of concatenated product
                ndigs++;                
            }
            
        }
        
        flag = 0;
        
        if(ndigs==9){
            
            for(l=0;l<9;l++){
                
                if (totdigs[l] == 0){
                    flag = 1;
                    break;                    
                }
                
                for(k=l+1;k<9;k++)
                    if(totdigs[l] == totdigs[k]){
                        flag = 1;
                        break;
                    }
                if(flag) break;
            }
            
            if(!flag){
                
                printf("%d * (",i);
                for(l=1;l<j;l++) printf("%d, ",l);
                printf("\b\b) = %d\n",num);
                if (num>maxnum) maxnum = num;
                
            }
            
        }     
        
        
        
    }
    
    printf("%d\n",maxnum);
    return 0;
}
