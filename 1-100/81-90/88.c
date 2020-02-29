#include <stdio.h>
#include <stdlib.h>
#define LIM 12000

//for each number, for each way it can be written as sum, find if product is equal to sum

void isprodsum(int num, int max, int termind, int minums[LIM], int *counter, int sum, int prod){
    
    int i;
    
    if(num==1){
        
        if(sum > prod)
            return;
        
        termind += prod - sum; //padding with 1s
        
        if(termind>LIM) //too many terms
            return;
        
        if(!minums[termind-1]){
            
            minums[termind-1] = prod; //minums[i]: min product-sum number for k=i+1
            (*counter)++;
            
        }
        
        
        return;
        
    }
    
     if(termind >= LIM)
        return;
    
    if(max>num)
        max = num;
    
    for(i=max;i>1;i--){
        
        if(num%i)
            continue;
               
        isprodsum(num/i,i,termind+1,minums,counter,sum+i,prod);
        
    }
    
    return;
    
}

int cmp(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(){
    
    int minums[LIM] = {0}, sum, num=4, counter=0, terms[LIM] = {0},i;
    
    while(1){
        
        isprodsum(num,num/2,0,minums,&counter,0,num);
        
        if(counter>=LIM-1)
            break;        
        
        num++;
        
    }
    
    qsort(minums,LIM,sizeof(int),cmp);
    
    sum = minums[1];
    
    for(i=2;i<LIM;i++)
        if(minums[i]!=minums[i-1])
            sum += minums[i];
    
    printf("%d\n",sum);
    
    return 0;
    
}
