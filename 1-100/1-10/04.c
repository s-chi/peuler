#include <stdio.h>

int main(){
    
    int digits[6], fac1, fac2, num, min = 99, temp, i, j, pali = 0, flag, pfac1, pfac2;
    
    for(fac1 = 999; fac1 > min; fac1--)
        for(fac2 = fac1; fac2 > min; fac2--){
            
            num = fac1 * fac2;
            
            if (num > pali){
            
                temp = num;
                
                i = 0;
                
                digits[5] = 0;
                
                while (temp > 0){
                    
                    digits[i] = temp % 10;
                    temp /= 10;
                    i++;
                    
                }
                
                flag = 1;
                j=0;
                i--;
                while(i>j){
                    
                    if (digits[i]!=digits[j]){
                        flag = 0;
                        break;
                    }
                    j++;
                    i--;
                    
                }
                
                if (flag) {
                    pali = num;
                    pfac1 = fac1;
                    pfac2 = fac2;
                    min = fac2;
                    
                }
                
            
            }            
            
            
        }
        
    if(pali){
        printf("%d * %d = %d\n", pfac1, pfac2, pali);
    } else printf("No palindrome found\n");
    
    
    return 0;   
    
}
