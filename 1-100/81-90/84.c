#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DSIDES 4
#define SQNUM 40
#define ITE 100000000

#define G2J 30
#define JAIL 10
#define CC1 2
#define CC2 17
#define CC3 33
#define CH1 7
#define CH2 22
#define CH3 36
#define R1 5
#define R2 15
#define R3 25
#define R4 35
#define U1 12
#define U2 28

#define COMS 16
#define CHANS 16
//Monte Carlo
//Can't reproduce exactly the stated probabilities for d6 (after trying several variations of the rules, which are not completely clear), 
//but the most frequently visited squares seem to be right 


int drawcc(int cur){
    
    int card;
    
    card = random() % COMS;
    
    if(card == 0)
        return 0;
    
    if(card == 1)
        return JAIL;
    
    return cur;
}

int drawch(int cur){
    
    int card;
    
    card = random() % CHANS;
    
    switch(card){
        
        case 0:
            return 0;
        case 1:
            return JAIL;
        case 2:
            return 11;
        case 3:
            return 24;
        case 4:
            return 39;
        case 5:
            return R1;
        case 6:
        case 7:
            while(cur!=R1 && cur!=R2 && cur!=R3 && cur!=R4)
                cur = (cur+1) % SQNUM;
            return cur;
        case 8:
            while(cur!=U1 && cur!=U2)
                cur = (cur+1) % SQNUM;
            return cur;
        case 9:
//             cur = cur - 3;//no risk of going negative
//             if(cur == CC3)//going back 3 squares from CH3 lands on CC3
//                 return drawcc(cur);
            return cur - 3;
        default:
            return cur;
    }
    
}

int roll(int cur, int *doubles){
    
    int d1,d2;
    
    d1 = random() % DSIDES + 1;
    d2 = random() % DSIDES + 1;
    
    cur =  (cur + d1 + d2) % SQNUM;
    
    if(cur == G2J)//go to jail
        cur=JAIL;
    
    if(cur == CC1 || cur == CC2 || cur == CC3)
        cur = drawcc(cur);
    
    if(cur == CH1 || cur == CH2 || cur == CH3)
        cur = drawch(cur);
    
    if(cur!=JAIL && d1==d2){
        
        if(*doubles == 2){//third double roll: go to jail, reset double counter
            *doubles = 0;
            cur = JAIL;
        } else
            *doubles++;
    } else
        *doubles = 0;//if the current roll is not double or if we are in jail, reset double counter
    
    return cur;
    
}

int main(){
    
    int i, cur, histo[SQNUM] = {0}, doubles = 0;
    
    srandom(time(NULL));
    
    cur = 0;
    
    for(i=0;i<ITE;i++){
        
        cur = roll(cur,&doubles);
        
        histo[cur]++;        
        
    }
    
    for(i=0;i<SQNUM;i++)
        printf("%d: %.2f\n",i, ((double) histo[i])/ITE * 100);
    
    return 0;
    
}
