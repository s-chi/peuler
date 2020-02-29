#include <stdio.h>
#include <math.h>
#include <string.h>
#define LIM 10000
#define EPS 0.000000001

double apply(int op, double a, double b){
    
    switch(op){
        
        case 0:
            return a+b;
            break;
        case 1:
            return a*b;
            break;
        case 2:
            return a-b;
            break;
        case 3:
            return b-a;
            break;
        case 4:
            if(b==0)
                return a*INFINITY;
            return a/b;
            break;
        case 5:
            if(a==0)
                return b*INFINITY;
            return b/a;
            break;
        default:
            printf("Unknown operator %d\n",op);
            return INFINITY;
            break;
    }
}

int main(){
    
    int a[4],   digset[126][4], digind = 0; //Binomial(9,4)=126 sets of 4 digits
    int op[3],  opset[216][3],  opind = 0;  //6^3 = 216 (6 operations, since - and / are not symmetric)
    int ord[4], ordset[24][4],  ordind = 0; //4! = 24 permutations of 4 digits
    int itemp,i, max, maxind, found[LIM];
    double dtemp;
    int j;
    
    
    for(a[0]=1;a[0]<7;a[0]++)
        for(a[1]=a[0]+1;a[1]<8;a[1]++)
            for(a[2]=a[1]+1;a[2]<9;a[2]++)
                for(a[3]=a[2]+1;a[3]<10;a[3]++){//generate all sets of 4 distinct digits 1-9
                    
                    for(i=0;i<4;i++)
                        digset[digind][i] = a[i];
                    
                    digind++;
                }
                    
    for(op[0]=0;op[0]<6;op[0]++)
        for(op[1]=0;op[1]<6;op[1]++)
            for(op[2]=0;op[2]<6;op[2]++){//generate all sets of 3 operations (not distinct, order counts)
                
                for(i=0;i<3;i++)
                    opset[opind][i] = op[i];
                
                opind++;                
                
            }
            
    for(ord[0]=0;ord[0]<4;ord[0]++)
        for(ord[1]=0;ord[1]<4;ord[1]++){//generate all permutations of 4 digits
            
            if(ord[1]==ord[0])
                continue;
            
            for(ord[2]=0;ord[2]<4;ord[2]++){
                
                if(ord[2]==ord[1]||ord[2]==ord[0])
                    continue;
                
                ord[3] = 6 - ord[0] - ord[1] - ord[2];
                
                 for(i=0;i<4;i++)
                     ordset[ordind][i] = ord[i];
                 
                 ordind++;                
                
            }
            
        }
            
    max = 0;
        
    for(digind=0;digind<126;digind++){
        
        memset(found,0,sizeof(found));
        
        for(opind=0;opind<216;opind++)
            for(ordind=0;ordind<24;ordind++){
                
                dtemp = apply(opset[opind][0], digset[digind][ordset[ordind][0]], digset[digind][ordset[ordind][1]]);
                dtemp = apply(opset[opind][1], dtemp, digset[digind][ordset[ordind][2]]);
                dtemp = apply(opset[opind][2], dtemp, digset[digind][ordset[ordind][3]]);
                
                if(dtemp<=0 || dtemp==INFINITY || dtemp==-INFINITY)
                    continue;
                
                itemp = dtemp + 0.5;
                
                if(itemp==0)
                    continue;
                
                if(fabs(dtemp-itemp) < EPS){
                    found[itemp-1] = 1;
                }                
                
            }
        
        i=0;
        
        while(i<LIM && found[i]) i++;
        
        if(i>=LIM) printf("increase LIM\n");
        
        if(i>max){            
            max = i;
            maxind = digind;
        }
        
    }
                    
    for(i=0;i<4;i++)
        printf("%d",digset[maxind][i]);
    printf(": %d\n",max);    
    
    return 0;
    
}
