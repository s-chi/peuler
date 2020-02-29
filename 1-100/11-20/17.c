#include <stdio.h>

int letters(int num){
    
    int count=0;
    //one(3), two(3), three(5), four(4), five(4), six(3), seven(5), eight(5), nine(4)
    int digs[10] = {0,3,3,5,4,4,3,5,5,4};
//ten(3), eleven(6), twelve(6), thirteen(8), fourteen(8), fifteen(7), sixteen(7), seventeen(9),
//eighteen(8), nineteen(8)
    int teens[10] = {3,6,6,8,8,7,7,9,8,8};
//ten(3), twenty(6), thirty(6), forty(5), fifty(5), sixty(5), seventy(7), eighty(6), ninety(6)
    int tens[10] = {0,3,6,6,5,5,5,7,6,6};
    
//     char cdigs[10][6] = {"","one","two","three","four","five","six","seven","eight","nine"};
//     char cteens[10][10] = {"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen",
//                            "seventeen","eighteen","nineteen"};
//     char ctens[10][8] = {"","ten","twenty","thirty","forty","fifty","sixty","seventy","eighty",
//                         "ninety"};
    
    if (num/1000) {/*printf("one thousand: ");*/return 11;}//one thousand
    if (num/100) {
        count += digs[num/100] + 7;//"n" hundred
//         printf("%s hundred", cdigs[num/100]);
        if (num % 100) {
            count += 3; //and
//             printf(" and ");
            num %= 100;            
        } else return count;
        
    }
    if (num/10){
        
        if (num < 20) {/*printf("%s: ",cteens[num%10]);*/ return count + teens[num%10];}
        count += tens[num/10];
//         printf("%s", ctens[num/10]);
        num %= 10;
//         if (num) printf("-");
        
    }
    if (num) {/*printf("%s: ",cdigs[num]);*/ return count + digs[num];}
//     printf(": ");
    return count;   
    
}

int main(){
    
    int i, sum=0, num;
    
    for(i=1;i<=1000;i++) {num = letters(i); sum += num; /*printf("%d\n",num);*/}
    printf("%d\n", sum);
    return 0;
    
}


// int main(){
//     
//     int num = 1;
//     
//     while(num>0){
//     scanf("%d",&num);
//     printf("%d\n",letters(num));}
//     return 0;
//     
// }


