#include <stdio.h>
#include <math.h>
#define LIM 10000

int * tritable(){
    
    static int array[LIM];
    int n, num = 0;
    
    for(n=45; num<LIM; n++){
        
        num = (n*(n+1))/2;
        array[num] = n;
        
    }
    
    return array;
    
}

int * sqtable(){
    
    static int array[LIM];
    int n, num = 0;
    
    for(n=32; num<LIM; n++){
        
        num = n*n;
        array[num] = n;
        
    }
    
    return array;
    
}

int * pentable(){
    
    static int array[LIM];
    int n, num = 0;
    
    for(n=26; num<LIM; n++){
        
        num = (n*(3*n-1))/2;
        array[num] = n;
        
    }
    
    return array;
    
}

int * hextable(){
    
    static int array[LIM];
    int n, num = 0;
    
    for(n=23; num<LIM; n++){
        
        num = n*(2*n-1);
        array[num] = n;
        
    }
    
    return array;
    
}

int * heptable(){
    
    static int array[LIM];
    int n, num = 0;
    
    for(n=21; num<LIM; n++){
        
        num = (n*(5*n-3))/2;
        array[num] = n;
        
    }
    
    return array;
    
}

int * octable(){
    
    static int array[LIM];
    int n, num = 0;
    
    for(n=19; num<LIM; n++){
        
        num = n*(3*n-2);
        array[num] = n;
        
    }
    
    return array;
    
}

int findcycle(int num, int nums[6], int *ispoly[6], int ord[6], int tofind){
    
    int lnum, i, res, start;
    
    if(tofind==0){       
        
        if(nums[ord[5]] % 100 == nums[ord[0]] / 100)
            return 1;
        else
            return 0;        
    }
    
    start = num * 100 + 10;
    
    for(lnum = start; lnum < start + 90; lnum++){
        
        for(i=0;i<6;i++){
            
            if(!nums[i] && *(ispoly[i] + lnum)){
                
                nums[i] = lnum;
                ord[6-tofind] = i;
                
                res = findcycle(lnum % 100, nums, ispoly, ord, tofind - 1);
                
                if(res){ 
                    
                    return 1;                    
                }
                else
                    nums[i] = 0;
                
            }
        }
    }
    
    return 0;
    
}


int main(){
    
    int *ispoly[6];
    int nums[6] = {0}, i, j, res, ord[6] = {0}, sum = 0;
    
    
    ispoly[0] = tritable();
    ispoly[1] = sqtable();
    ispoly[2] = pentable();
    ispoly[3] = hextable();
    ispoly[4] = heptable();
    ispoly[5] = octable();
    
    
    for(i=10;i<100;i++){
        
        res = findcycle(i, nums, ispoly, ord, 6);
        
        if(res){
            
            for(j=0;j<6;j++){
                printf("P_%d(%3d) = %d\n", ord[j] + 3, *(ispoly[ord[j]] + nums[ord[j]]), nums[ord[j]]);
                sum += nums[j];
            }
            
            printf("Sum = %d\n",sum);
            
            return 0;
            
        }
    }
    
    return 0;  
    
}
