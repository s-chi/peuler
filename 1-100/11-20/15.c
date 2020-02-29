#include <stdio.h>
#define SIZE 20
//the result is (2*size)!/(size! *size!), but numbers are huge --> simplify

int main(){
    
    int k;
    double prod=1.;
    
    for(k=0;k<SIZE;k++) prod *= 4.-2./(SIZE-k);
    
    printf("%ld\n", (long) prod);    
    return 0;
    
}
