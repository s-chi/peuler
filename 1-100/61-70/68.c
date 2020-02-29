#include <stdio.h> 
#include <math.h>
#define NVERT 5
#define NPERM 24//number of permutations of vertices. Excluding cyclical permutations, (NVERT-1)!
#define NPART 16

//The problem asks for a 16-digit string ==> 10 appears only once, so it must be in external node
//It can be shown that both the sums of internal and external nodes must be multiples of NVERT --> limited number of partitions of 1-10 between internal and external nodes (2^(NVERT-1))
//It can also be shown that the constant sum of the lines C = (2*NVERT+1) + Sum(internal)/NVERT = 2*(2*NVERT+1) - Sum(external)/NVERT

int genperm(int vpool[NVERT], int vertperm[NPERM][NVERT], int ind, int permnum){
    
    int i,j,flag;
    
    if(ind==0){    
        for(i=0;i<NPERM;i++)
            vertperm[i][0] = vpool[0];//keep first element fixed to avoid cyclical perms
            
        return genperm(vpool,vertperm,1,0);
    } 
    
    if(ind==NVERT)
        return permnum + 1;
    
    for(i=1;i<NVERT;i++){
        
        flag=0;
        
        for(j=1;j<ind;j++)
            if(vertperm[permnum][j] == vpool[i]){
                flag=1;
                break;
            }
            
        if(flag) continue;
        
        for(j=permnum;j<NPERM;j++)
            vertperm[j][ind] = vpool[i];
        
        permnum = genperm(vpool,vertperm,ind + 1, permnum);
        if(permnum == NPERM)
            break;
        
    }
    
    return permnum;    
    
}

void genpool(int pool[NPART][2*NVERT]){
    
    int i, j, k, l, temp;
    for(i=0;i<2*NVERT;i++)
        for(j=0;j<NPART;j++)
        pool[j][i] = i+1;//no exchange
    
    for(i=0; i<NVERT-1; i++){//1 exchange
        temp = pool[i+1][i];
        pool[i+1][i] = pool[i+1][i+5];
        pool[i+1][i+5] = temp;        
    }
        
    j=NVERT;
    
    for(i=0;i<NVERT-2;i++){//2 exchanges
        for(k=i+1;k<NVERT-1;k++){
            
            temp = pool[j][i];
            pool[j][i] = pool[j][i+5];
            pool[j][i+5] = temp;
            temp = pool[j][k];
            pool[j][k] = pool[j][k+5];
            pool[j][k+5] = temp;
            j++;
            
        }
    }
        
    for(i=0;i<NVERT-3;i++){//3 exchanges
        for(k=i+1;k<NVERT-2;k++){
            for(l=k+1;l<NVERT-1;l++){
                
                temp = pool[j][i];
                pool[j][i] = pool[j][i+5];
                pool[j][i+5] = temp;
                temp = pool[j][k];
                pool[j][k] = pool[j][k+5];
                pool[j][k+5] = temp;
                temp = pool[j][l];
                pool[j][l] = pool[j][l+5];
                pool[j][l+5] = temp;
                j++;
                
            }
        }  
    }
    
    for(i=0;i<NVERT-1;i++){//4 exchanges
        temp = pool[j][i];
        pool[j][i] = pool[j][i+5];
        pool[j][i+5] = temp;        
    }
    
    return;
    
}


int main(){
    
    int vertperm[NPERM][NVERT] = {0}, ext[NVERT], pool[NPART][2*NVERT], epool[NVERT], sols[10][2*NVERT] = {0}, tempsol[2*NVERT];
    int i, j, k, partind, solind = 0;
    int sum;
    long solnums[10], maxnum = 0, poww;
    
    genpool(pool);
    
    for(partind=0;partind<NPART;partind++){
        
        genperm(pool[partind], vertperm, 0, 0);
        
        sum = 0;
        for(i=0;i<NVERT;i++)
            sum += pool[partind][i];
        sum /= 5;
        sum += 2 * NVERT + 1;
            
        for(i=0;i<NPERM;i++){
            
            for(j=0;j<NVERT;j++){
                ext[j] = 0;
                epool[j] = pool[partind][j+5];
            }
            
            for(j=0;j<NVERT;j++){
                
                for(k=0;k<NVERT;k++){
                    
                    if(epool[k] && epool[k] + vertperm[i][j] + vertperm[i][(j+1) % 5] == sum){
                        
                        ext[j] = epool[k];
                        epool[k] = 0;
                        break;
                        
                    }
                    
                }
                
                if(!ext[j])
                    break;
                
            }
            
            if(ext[NVERT-1]){
                
                for(j=0;j<NVERT;j++){
                    
                    sols[solind][j] = vertperm[i][j];
                    sols[solind][j+5] = ext[j];
                    
                }
                solind++;
                
            }
            
        }
        
    }
    
   
//     for(i=0;i<solind;i++){
//         
//         printf("%2d) vert: ",i+1);
//         for(j=0;j<NVERT;j++)
//             printf("%d ", sols[i][j]);
//         printf(" ext: ");
//         for(j=0;j<NVERT;j++)
//             printf("%d ", sols[i][j+5]);
//         printf("\n");
//         
//     }
    
    
//     printf("%d\n",solind);
    
    for(i=0;i<solind;i++){//reorder solutions starting from smallest external node
        
        k = 0;
        
        for(j=1;j<NVERT;j++)            
            if(sols[i][j+NVERT] < sols[i][k+NVERT])                
                k = j;
            
        for(j=0;j<NVERT;j++){
            
            tempsol[j] = sols[i][(j+k) % NVERT];
            tempsol[j+5] = sols[i][(j+k) % NVERT + 5];
            
        }
        
        for(j=0;j<2*NVERT;j++)
            sols[i][j] = tempsol[j];
            
    }
    
//     for(i=0;i<solind;i++){
//         
//         printf("%2d) vert: ",i+1);
//         for(j=0;j<NVERT;j++)
//             printf("%d ", sols[i][j]);
//         printf(" ext: ");
//         for(j=0;j<NVERT;j++)
//             printf("%d ", sols[i][j+5]);
//         printf("\n");
//         
//     }
    
    for(i=0;i<solind;i++){//generate numbers corresponding to string of digits requested by the problem and find max
        
        poww = pow(10,15);
        solnums[i] = 0;
        
        for(j=0;j<NVERT;j++){
            
            if(sols[i][j+NVERT] == 10)
                poww /=10;
            solnums[i] += sols[i][j+NVERT] * poww;
            poww /= 10;
            solnums[i] += sols[i][j] * poww;
            poww /= 10;
            solnums[i] += sols[i][(j+1) % NVERT] * poww;
            poww /= 10;            
            
        }
        
        if (solnums[i] > maxnum)
            maxnum = solnums[i];
        
        
    }
    
//     for(i=0;i<solind;i++)
//         printf("%ld\n",solnums[i]);
    
    printf("%ld\n",maxnum);
    
    
    return 0;
    
}
