#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define WLEN 20 //max word length
#define WNUM 2000 //max number of words
#define ANSETN 50
#define ANSETLEN 5

int isanagram(char word1[WLEN], char word2[WLEN]){
    
    int  i, j, letterfound, last=WLEN-1;
    char comp[WLEN];
    
    if(word1[last] != word2[last]) //if words have different length they can't be anagrams
        return 0;
    
    strcpy(comp,word2);
    
    for(i=0;i<word2[last];i++){
        
        letterfound = 0;
        
        for(j=0;j<word2[last];j++)
            if(word1[i] == comp[j]){                
                comp[j] = -1;
                letterfound = 1;
                break;
            }
            
        if(!letterfound)
            break;        
            
    }
    
    if(!letterfound)
        return 0;
    
    return 1;
    
}

int cmp(const void * a, const void * b) {
    
    char *w1, *w2;
    
    w1 = a;
    w2 = b;
    
    if(w1[WLEN-1] == w2[WLEN-1])
        return strcmp(w1,w2);
    
    return w1[WLEN-1] - w2[WLEN-1] ;
}


int issquare(int num){
    
    int root;
    
    root = sqrt(num);
    
    if(root*root == num)
        return root;
    
    return 0;    
    
}

void checksubs(int anagset[ANSETLEN], char words[WNUM][WLEN], int anagnum, int nums[ANSETLEN][WLEN], int pos){
    
    int i,j,k, wlen, count=0, flag;
    int eqletters[ANSETLEN][WLEN] = {0};
    int wnums[ANSETLEN] = {0}, rootn[ANSETLEN] = {0};
    
    wlen = words[anagset[0]][WLEN-1];
    
    if(pos == wlen){
        
        for(i=0;i<anagnum;i++)            
            for(j=0;j<wlen;j++)                
                wnums[i] += nums[i][j] * pow(10,wlen-1-j);
            
        for(i=0;i<anagnum;i++){
            
            if(nums[i][0]==0) //don't consider numbers with leading zero
                continue;
            
            rootn[i] = issquare(wnums[i]);
            
            if(rootn[i])
                count++;
            
        }
        
        if(count > 1){
            
            for(i=0;i<anagnum;i++)
                if(rootn[i]){
                    printf("%s --> %d = %d^2\n",words[anagset[i]],wnums[i],rootn[i]);
                }
            
            printf("\n");
            
            
        }            
            
        return;
        
    }
    
    
    for(j=0;j<pos;j++) //if we have already met the current letter (-->already substituted), go on to the next one
        if(words[anagset[0]][j] == words[anagset[0]][pos]){
            
            checksubs(anagset,words,anagnum,nums,pos+1);
            return;
            
        }
    
    
    eqletters[0][pos] = 1;//eqletters[i][j] is one if jth letter of ith word in anagram set is equal to current (pos) letter in first word
    
    for(j=pos+1;j<wlen;j++)
        if(words[anagset[0]][j] == words[anagset[0]][pos])
            eqletters[0][j] = 1;
        
    for(j=1;j<anagnum;j++)
        for(k=0;k<wlen;k++)
            if(words[anagset[j]][k] == words[anagset[0]][pos])
                eqletters[j][k] = 1;
            
                
    for(i=0;i<10;i++){//try all possible substitutions for current letter
        
        flag = 0;
        
        for(j=0;j<pos;j++)//if we have already used this i, try another
            if(nums[0][j] == i){
                flag = 1;
                break;
            }
            
        if(flag)
            continue;
        
        for(j=0;j<anagnum;j++)
            for(k=0;k<wlen;k++)
                if(eqletters[j][k])
                    nums[j][k] = i;
        
        checksubs(anagset,words,anagnum,nums,pos+1);
                                        
    }
    
    
    return;
                
}

int main(){
    
    char words[WNUM][WLEN] = {0}, checked[WNUM] = {0};
    int i,j, anagsetind, anagind, anagset[ANSETN][ANSETLEN] = {0}, wordn, nums[ANSETLEN][WLEN];
    FILE *fp;
    
    
    fp=fopen("98_words.txt","r");
    fscanf(fp,"\"%[^\"]s", words[0]);
    words[0][WLEN-1] = strlen(words[0]);
    
    i=1;
    while(!feof(fp)){
        
        fscanf(fp,"\",\"%[^\"]s", words[i]);
        words[i][WLEN-1] = strlen(words[i]); //save length of word in last element of array 
        i++;
        
    }   
    
    fclose(fp);
    
    wordn = i-1;
    
    qsort(words, wordn, WLEN, cmp);
    
    i=0;
    while(words[i][WLEN-1]<3) i++;
    
    anagsetind = 0;
    
    for(;i<wordn;i++){
        
        anagind = 1;
        
        for(j=i+1;j<wordn;j++){
            
            if(checked[j])  //words[j] was already an anagram of some previous words[i], no need to check again
                continue;
            
            if(words[j][WLEN-1] > words[i][WLEN-1]) //from now on words[j] has more letters than words[i], so it can't be an anagram
                break;
            
            if(isanagram(words[i],words[j])){
                
                anagset[anagsetind][0] = i;
                anagset[anagsetind][anagind] = j;
                checked[j] = 1;
                anagind++;
                
//                 if(anagind > ANSETLEN){
//                     printf("increase ANSETLEN\n");
//                     return 0;
//                 }
                
            }
            
        }
        
        if(anagset[anagsetind][0]){
            
//             for(anagind=0;anagset[anagsetind][anagind];anagind++)
//                 printf("%s ",words[anagset[anagsetind][anagind]]);
//             printf("\n");
            
            anagsetind++;
            
//             if(anagsetind>ANSETN){
//                 printf("increase ANSETN\n");
//                 return 0;                
//             }     
        }
    }
    
    for(i=anagsetind-1;i>=0;i--){
        
        memset(nums,0,sizeof(nums));
        
        j=1;
        while(anagset[i][j]) 
            j++;
        
        checksubs(anagset[i],words,j,nums,0);
        
        
    }
    
    return 0;
    
}
