#include <stdio.h>
#include <string.h>
#define LIM 100
#define LEN 201 //number of digits of LIM^LIM 

int * mpow(int a, int b){
    
    static int num[LEN];
    int i,j,topdig = 1;
    
    memset(num, 0, sizeof(num));
    
    num[0] = 1;
    
    for(i=1;i<=b;i++){
        for(j=0;j<topdig;j++) num[j] *= a;
        for(j=0;j<topdig;j++){
            if (num[j] >= 10){
                
                num[j+1] += num[j]/10;
                num[j] %= 10;
                if((j+1)==topdig) topdig++;
                
            }
        } 
        
    }

    return num;   
    
}

// int main(){
//     
//     int a,b,j;
//     int * curnum;
//     scanf("%d %d",&a,&b);
//     curnum = mpow(a,b);
//     j=LEN-1;
//     while(*(curnum+j)==0)j--;
//     while(j>=0){printf("%d",*(curnum+j));j--;}
//     printf("\n");
//     
// }

int main(){
    
    int nums[LIM*LIM][LEN] = {{0}}, counter = 1, a, b;
    int i,j, diff;
    int *curnum;
    
    curnum = mpow(2,2);
    for(j=0;j<LEN;j++) nums[0][j] = *(curnum+j);
    
    for (a=2;a<=LIM;a++){        
        for (b=2;b<=LIM;b++){
            
            curnum = mpow(a,b);
            
            for(i=0;i<counter;i++){
                
                diff = 0;
                
                for(j=0;j<LEN;j++){
                    
                    if(*(curnum+j)!=nums[i][j]) {
                        
                        diff = 1;
                        break;
                        
                    }
                    
                }
                
                if (!diff) break;
                
            }
            
            if (diff) {
                
                for(j=0;j<LEN;j++) nums[counter][j] = *(curnum+j);
                counter++;
                
            }
            
            
        }
        
    }

    printf("%d\n", counter);
    return 0;
    
}
