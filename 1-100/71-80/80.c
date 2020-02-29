#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define DIGS 500
#define LIM 100
#define NLIM 100
#define COEFFN 300

// Use continued fraction expansion of square roots: for each number
// 1) find period and coefficients as in problem 64 (-->all coefficients of expansion known)
// 2) consider successive convergents as approximations of square roots
// 3) from each convergent we are only interested in extracting one digit and comparing with previous convergents: once the first digit has stabilized, look at the second and so on 

// NB: digs arrays should always contain zeroes above last digit

void dprint(int digs[]){
    
    int i;
    
    for(i = digs[0]; i>0; i--)
                printf("%d", digs[i]);
    
    return;
}

void dassign(int d1[], int d2[]){ //assigns d1 = d2
    
    int i;
    
    memset(d1,0,DIGS*sizeof(int));
    
    for(i=0;i<=d2[0];i++)
        d1[i] = d2[i];
    
    return;
    
}

void dmult(int digs[], int fac){
    
    int i;
    
    if(fac==0){
        for(i=digs[0];i>=0;i--)
            digs[i] = 0;
        return;        
    }
    
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

void dsum(int d1[], int d2[]){
    
    int i,maxd;
    
    if(d1[0]>d2[0])
        maxd = d1[0];
    else 
        maxd = d2[0];
    
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

void dsub(int d1[], int d2[]){//return d1-d2, assuming d1>d2
    
    int i;
    
    if(dgreater(d2,d1)){
        printf("wrong!!!!\n");
        exit(0);        
    }
    
    for(i=1;i<=d1[0];i++){
        d1[i] -= d2[i];
        
        while(d1[i]<0){
            
            d1[i+1]--;
            d1[i]+=10;
        }
        
    }
    
    while(!d1[d1[0]])
        d1[0]--;
    
    return;
    
}

void numtodigs(int num, int digs[]){
    
    int i;
    
    for(i=1;num>0;i++){
        digs[i] = num % 10;
        num /= 10;        
    }
    
    digs[0] = i-1;
    
    return;
    
    
}

void sqrtexpansion(int n, int coeff[COEFFN], int *period){//computes period and coefficient of the continued fraction expansion of sqrt(n)
    
    double root;
    int b[COEFFN] = {0}, c[COEFFN] = {0}, repeat, i, j;
    
    memset(coeff,0,COEFFN*sizeof(int));
    
    root = sqrt(n);
    coeff[0] = (int) root;
    b[0] = coeff[0];
    c[0] = n - pow(b[0],2);
    
    if(c[0] == 0){//perfect square
        *period = 0;
        return;        
    }
    
    repeat = 0;
    i=0;
    
    while(!repeat){
        
        i++;
        
        coeff[i] = (int) (root + b[i-1])/c[i-1];
        b[i] = coeff[i] * c[i-1] - b[i-1];
        c[i] = (n - pow(b[i],2))/(c[i-1]);
        
        for(j=0;j<i;j++)
            if(b[i] == b[j] && c[i] == c[j]){                    
                repeat = 1;
                break;                    
            }
            
    }
    
    *period = i;
    
    return;
    
}

int dintdivide(int num[],int den[]){//gives (int) num/den
    
    int i = 2, temp[DIGS] = {0};
    
    if(dgreater(den,num))
        return 0;
    
    while(1){
        
        dassign(temp,den);
        
        dmult(temp,i);
        
        if(dgreater(temp,num))
            return i-1;
            
        i++;
        
    }
    
}

void dshift(int digs[], int num){//multiplies digs[] by 10^n by shifting digits
    
    int i;
    
    for(i=digs[0];i>0;i--)
        digs[i+num] = digs[i];
    
    for(i=num;i>0;i--)
        digs[i] = 0;
    
    digs[0] += num;
    
}

int findappx(int num[3][DIGS],int den[3][DIGS],int an, int dignum){
    
    int tempnum[DIGS],tempden[DIGS], i, dig, temp[DIGS];
    
    dassign(num[2],num[1]); //num[2] = an*num[1]+num[0]
    dmult(num[2],an);
    dsum(num[2],num[0]);
    
    dassign(den[2],den[1]); //den[2] = an*den[1]+den[0]
    dmult(den[2],an);
    dsum(den[2],den[0]);
    
    dassign(tempnum,num[2]);
    dassign(tempden,den[2]);
    
    dig = dintdivide(tempnum,tempden); //returns (int) num/den
    
    for(i=dignum;i>0;i--){
        
//      dig -> (int)((num/den - dig)*10)
        dassign(temp,den[2]); //num -> 10*(num - dig*den)
        dmult(temp,dig);
        dsub(tempnum,temp);
        dshift(tempnum,1);//multiply by 10 by shifting digits
        
        dig = dintdivide(tempnum,tempden);
        
    }
    
    return dig;
    
    
}


int main(){
    
    int coeff[COEFFN],period; //coefficients and period of expansion
    int num[3][DIGS], den[3][DIGS]; //previous, current, and next num and den of convergents
    int appx[DIGS], temp[DIGS];
    int curdignum, dig[3], n, iter, sum = 0, lim;
    int partsum;
    
    for(n=1;n<=NLIM;n++){
    
        sqrtexpansion(n,coeff,&period);
        
        if(period==0)//perfect square, don't count. All the other square roots are irrational
            continue;
        
        memset(num,0,sizeof(num));
        memset(den,0,sizeof(den));
        memset(appx,0,sizeof(appx));
        memset(temp,0,sizeof(temp));
        curdignum = 1;
        
        dig[0] = dig[1] = -1;
        
        //set initial conditions for recursion: convergent_n = num_n/den_n = (a_n*num_(n-1)+num_(n-2))/(a_n*den_(n-1)+den(n-2))
        
        num[0][0] = 1;
        num[0][1] = 1;
        den[0][0] = 0;
        
        numtodigs(coeff[0],temp); // num_0 = a_0
        dassign(num[1],temp);
        den[1][0] = 1;  // den_0 = 1
        den[1][1] = 1;
        
        partsum = 0;
        
        for(iter=1; iter<=num[1][0]; iter++) //initialize sum with the sum of the digits of the integer part
            partsum += num[1][iter];
        
        iter=1; //iteration index
        lim = LIM - num[1][0]; //how many more digits we need 
        
        while(curdignum<=lim){
            
            dig[2] = findappx(num,den,coeff[(iter-1) % period + 1],curdignum); //find next convergent and return curdignum-th digit
            dassign(num[0],num[1]);
            dassign(num[1],num[2]);
            dassign(den[0],den[1]);
            dassign(den[1],den[2]);
            
            if(dig[2]==dig[1] && dig[2]==dig[0]){//if curdignum-th digit has stabilized, save it and go to the next
                
                appx[curdignum] = dig[2];
                curdignum++;
                dig[0] = dig[1] = -1;
                
            } else {
                dig[0] = dig[1];
                dig[1] = dig[2];
            }
            
            iter++;
        }
        
        for(iter=1;iter<=lim;iter++)
            partsum += appx[iter];
        
        printf("%d: %d\n",n,partsum);
        
        sum += partsum;
        
    }
    
    printf("\n%d\n",sum);
    
    return 0;
    
}
