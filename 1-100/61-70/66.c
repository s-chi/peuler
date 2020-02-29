#include <stdio.h>
#include <math.h>
#include <string.h>
#define ITELIM 10000
#define LIMD 1000 //max D
#define MAXN 32//(MAXN-1)^2 < LIMD
#define DLIM 100

// Theorem (pell's equation): x^2 - D y^2 = 1 ==> x/y is a convergent (continued fractions) of sqrt(D)

void dprint(int digs[]){
    
    int i;
    
    for(i = digs[0]; i>0; i--)
                printf("%d", digs[i]);
    
    return;
}

void dmult(int digs[], int fac){
    
    int i;
    for(i=1;i<=digs[0];i++)
        digs[i] *= fac;
        
    for(i=1;i<=digs[0];i++)
        if(digs[i]>=10){
            
            digs[i+1] += digs[i]/10;
            digs[i] %= 10;
            
            if(i == digs[0])
                digs[0]++;            
        }
    
    return;
    
}

void dassign(int d1[], int d2[]){
    
    int i;
    
    for(i=0;i<=d2[0];i++)
        d1[i] = d2[i];
    
    return;
    
}

void dsum(int d1[], int d2[]){
    
    int i,maxd;
    
    if(d1[0]>d2[0]){
        maxd = d1[0];
        for(i=d2[0]+1;i<=d1[0];i++)
            d2[i]=0;
        
    } else {
        maxd = d2[0];
        for(i=d1[0]+1;i<=d2[0];i++)
            d1[i]=0;
    }
        
    
    for(i=1;i<=maxd;i++){
        d1[i] += d2[i];
        
        if(d1[i]>=10){
            
            d1[i+1] += d1[i]/10;
            d1[i] %= 10;
            if(i==d1[0])
                d1[0]++;
        }
        
    }
    
    return;
    
}


int *dsquare(int digs[]){//returns the square of digs in static digs array
    
    static int num[DLIM];
    int i,j;
    
    memset(num, 0, sizeof(num));
    
    num[0] = 2*digs[0] - 1;
    
    for(j=0;j<digs[0];j++)
        for(i=1;i<=digs[0];i++)
            num[i+j] += digs[1+j]*digs[i];
        
    for(i=1;i<=num[0];i++){
        
        if(num[i]>=10){
            
            num[i+1] += num[i]/10;
            num[i] %= 10;
            
            if(i == num[0]) 
                num[0]++;
        
        }
        
    }

    return num;   
    
}

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

int dequal(int d1[], int d2[]){
    
    int i;
    
    for(i=0;i<=d1[0];i++)
        if(d1[i] != d2[i])
            return 0;
        
    return 1;
    
}

int dgreater(int d1[], int d2[]){
    
    int i;
    
    if (d1[0] > d2[0])
        return 1;
    if (d1[0] < d2[0])
        return 0;
    
    for(i=d1[0];i>0;i--){
        
        if (d1[i] > d2[i])
            return 1;
        if (d1[i] < d2[i])
            return 0;        
        
    }
    
    return 0;
    
}

int main(){
    
    int n,d,dlim,itetop,i,maxxd;
    int a[ITELIM] = {0}, b[ITELIM] = {0}, c[ITELIM] = {0};
    int num[DLIM], den[DLIM], numsq[DLIM] = {0}, densq[DLIM] = {0}, maxx[DLIM] = {0}, maxxy[DLIM] = {0}, temp[DLIM] = {0};
    double root;
    
    for(n=1;n<MAXN;n++){
        
        dlim = (n+1)*(n+1);
        
        for(d=n*n+1;d<dlim && d<=LIMD;d++){//avoid perfect squares
            
            root = sqrt(d);
            
            a[0] = (int) root;
            b[0] = a[0];
            c[0] = d - pow(b[0],2);
            
            itetop = 0;
            
            while(1){
                
                memset(num,0,sizeof(num));
                memset(den,0,sizeof(den));
                memset(numsq,0,sizeof(numsq));
                memset(densq,0,sizeof(densq));
                
                num[0] = den[0] = 1;
                num[1] = den[1] = 1;
                
                dmult(num,a[itetop]);
                
                for(i = itetop - 1; i>=0; i--){
                    
                    dassign(temp, den);
                    dassign(den, num);
                    dmult(num,a[i]);
                    dsum(num,temp);
                    
                }
                
                dassign(numsq,dsquare(num)); //num*num
                dassign(densq,dsquare(den)); //den*den
                dmult(densq,d);              //d*den*den
                dincrease(densq);            //d*den*den + 1
                
                if(dequal(numsq,densq)){
                    
//                     dprint(num);
//                     printf("^2 - %d * ",d);
//                     dprint(den);
//                     printf("^2 = 1\n");
                    
                    if(dgreater(num,maxx)){
                        
                        dassign(maxx,num);
                        dassign(maxxy,den);
                        maxxd = d;
                        
                    }
                    
                    break;
                    
                }
                
                itetop++;
                if(itetop>=ITELIM){
                    printf("increase ITELIM\n");
                    return 0;
                    
                }
                
                a[itetop] = (int) (root + b[itetop-1])/c[itetop-1];
                b[itetop] = a[itetop] * c[itetop-1] - b[itetop-1];
                c[itetop] = (d - pow(b[itetop],2))/(c[itetop-1]);  
                
            }
            
        }
        
    }
    
    dprint(maxx);
    printf("^2 - %d * ",maxxd);
    dprint(maxxy);
    printf("^2 = 1\n");
    
    return 0;    
    
}
