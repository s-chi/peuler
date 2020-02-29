#include <stdio.h>

int isleap(int year){
    
    if (year%400 == 0) return 1;
    if (year%100 == 0) return 0;
    if (year%4   == 0) return 1;
    return 0;
    
}


int main(){
    
    int year=1901, month=1, day=1, wday=366, counter=0;
    int mlen[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    
    while(wday % 7){
        day++;
        wday++;
    }    
    
    
    while(year<2001){
        
        if (day==1) counter++;
        
        day+=7;
        
        if (day>mlen[month]){
            
            day %= mlen[month];
            month++;
            
            if (month==13){
                
                month = 1;
                year++;
                
                if(isleap(year)) mlen[2] = 29;
                else mlen[2] = 28;
                
            }
            
        }
        
    }
    
    if (day==1) counter--;
    printf("%d\n", counter);
    return 0;
    
}
