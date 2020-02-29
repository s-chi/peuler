#include <stdio.h>
#include <math.h>
#define LIM 1000

int main(){
    
    FILE *fp;
    int i, base, exp, maxline;
    double explogbase, explogbasemax = 0.;
    
    fp=fopen("99_base_exp.txt","r");
    
    fscanf(fp,"%d,%d",&base,&exp);
    explogbasemax = exp * log(base);
    
    maxline = 1;
    
    for(i=1;i<LIM;i++){
        fscanf(fp,"%d,%d",&base,&exp);
        explogbase = exp * log(base);
        
        if(explogbase > explogbasemax){            
            explogbasemax = explogbase;
            maxline = i+1;            
        }     
        
    }
    
    fclose(fp);
    
    
    printf("%d\n",maxline);
    
    return 0;
    
}
