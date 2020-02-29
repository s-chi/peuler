#include <stdio.h>
#define NUM 1000
int is_flush(int suits[5]){
    
    int i, suit;
    
    suit = suits[0];
    
    for(i=1;i<5;i++)
        if(suits[i]!=suit) return 0;
        
    return 1;
    
}

int is_straight(int values[5]){
    
    int i, flag;
    
    if(values[0]==14 && values[4] == 2){
        
        for(i=0;i<4;i++)
            values[i] = values[i+1];
        
        values[4] = 1;        
    }
    
    flag = 1;
    
    for(i=1;i<5;i++)
        if(values[i-1]!=values[i]+1){
            flag = 0;
            break;
        }
        
    if(flag) return 1;
    
    if(values[4]==1){
        
        for(i=4;i>0;i--)
            values[i] = values[i-1];
        
        values[0] = 14;        
    }
    
    return 0;
    
}

int is_sflush(int values[5], int suits[5]){
    
    if(!is_flush(suits))
        return 0;
    
    if(!is_straight(values))
        return 0;
    
    return 1;
    
}

int is_four(int values[5], int* card){
    
    if(values[0] == values[3] || values[1] == values[4]){
        
        *card = values[1];
        return 1;
        
    }
    
    return 0;
    
}

int is_full(int values[5], int card[2]){
    
    if(values[0]==values[2]&&values[3]==values[4]){
        
        card[0] = values[0];
        card[1] = values[3];
        return 1;
        
    }
    
    if(values[0]==values[1]&&values[2]==values[4]){
        
        card[0] = values[2];
        card[1] = values[0];
        return 1;
        
    }
    
    return 0;
    
}

int is_three(int values[5], int *card){
    
    if(values[0]==values[2]||values[1]==values[3]||values[2]==values[4]){
        
        *card = values[2];
        return 1;
        
    }
    
    return 0;
    
}

int is_dtwo(int values[5], int card[2]){
    
    if(values[0]==values[1])
        if(values[2]==values[3]||values[3]==values[4]){
            card[0] = values[0];
            card[1] = values[3];
            return 1;
        }
    if(values[1]==values[2]&&values[3]==values[4]){
        card[0] = values[1];
        card[1] = values[3];
        return 1;
    }
    return 0;    
}

int is_two(int values[5], int *card){
    
    int i;
    
    for(i=1;i<5;i++)
        if(values[i] == values[i-1]){
            *card = values[i];
            return 1;            
        }
    
    return 0;
}

void evaluateHand(int values[5], int suits[5], int points[6]){
    
    int i, j, card[2];
    
    for(i=0;i<6;i++)
        points[i] = 0;
    
    if (is_sflush(values, suits)){
        
        points[0] = 8;
        points[1] = values[0];
        
    } else if (is_four(values, card)) {
        
       points[0] = 7;
       points[1] = card[0];
       if(values[0]==card[0]) 
           points[2] = values[4];
       else points[2] = values[0];
        
    } else if (is_full(values, card)) {
        
        points[0] = 6;
        points[1] = card[0];
        points[2] = card[1];
        
    } else if (is_flush(suits)) {
        
       points[0] = 5;
       for(i=0;i<5;i++)
           points[i+1] = values[i];
        
    } else if (is_straight(values)) {
        
        points[0] = 4;
        points[1] = values[0];
        
    } else if (is_three(values, card)) {
        
        points[0] =  3;
        points[1] = card[0];
        if(values[0]==card[0]){
            points[2] = values[3];
            points[3] = values[4];            
        } else if(values[1]==card[0]){
            points[2] = values[0];
            points[3] = values[4];            
        } else {
            points[2] = values[0];
            points[3] = values[1];
        }
        
    } else if (is_dtwo(values, card)) {
        
        points[0] = 2;
        points[1] = card[0];
        points[2] = card[1];
        i=0;
        while(values[i]==card[0]||values[i]==card[1]) 
            i++;
        points[3] = values[i];
        
    } else if (is_two(values, card)) {
        
     points[0] =  1;
     points[1] = card[0];
     for(i=0,j=2;i<5;i++)
         if(values[i]!=card[0]){
             points[j] = values[i];
             j++;
        }
             
    } else {
        
        points[0] = 0;
        for (i=0;i<5;i++){
            
            points[i+1] = values[i];
            
        }
    }
    
    return;
    
}

void handsort(int values[5],int suits[5]){
    
    int temp, i, j, max = 0, imax;
    
    for(i=0;i<5;i++){
        for(j=i;j<5;j++)
            if(values[j] > max){                
                max = values[j];
                imax = j;                
            }
        temp = values[i];
        values[i] = values[imax];
        values[imax] = temp;
        temp = suits[i];
        suits[i] = suits[imax];
        suits[imax] = temp;
        max = 0;
        
    }
    return;    
    
}

int compare(char hands[2][5][3]){
    
    int values[2][5], suits[2][5], i, j, points[2][6];
    char cur;
    
    int k;
    
    for(j=0;j<2;j++){
        for(i=0;i<5;i++){
            
            cur = hands[j][i][0];
            
            switch(cur){
                
                case 'T':
                    values[j][i] = 10;
                    break;
                case 'J':
                    values[j][i] = 11;
                    break;
                case 'Q':
                    values[j][i] = 12;
                    break;
                case 'K':
                    values[j][i] = 13;
                    break;
                case 'A':
                    values[j][i] = 14;
                    break;
                default:
                    values[j][i] = cur - 48;
                    
            }
            
            cur = hands[j][i][1];
            
            switch(cur){
                
                case 'H':
                    suits[j][i] = 0;
                    break;
                case 'D':
                    suits[j][i] = 1;
                    break;
                case 'C':
                    suits[j][i] = 2;
                    break;
                case 'S':
                    suits[j][i] = 3;
                    break;
                    
            }
            
        }
        
        handsort(values[j],suits[j]);
        evaluateHand(values[j],suits[j],points[j]);
        
    }
    
    
    for(j=0;j<6;j++)
        if (points[0][j]>points[1][j]) 
            return 1;
        else if (points[0][j]<points[1][j])
            return 0;
        
    return 0;
    
}

int main(){
    
    FILE *fp;
    int i, j, counter = 0;
    char hands[2][5][3];
    
    fp = fopen("54_poker.txt","r");
    
    for(j=0;j<NUM;j++){    
        
        for(i=0;i<5;i++)
            fscanf(fp,"%2s",hands[0][i]);
        
        for(i=0;i<5;i++)
            fscanf(fp,"%2s",hands[1][i]);
        
        if(compare(hands))
            counter++;
        
    }
        
    
    fclose(fp);
    
    printf("%d\n", counter);
    
    return 0;
    
}
