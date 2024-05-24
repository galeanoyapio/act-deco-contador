#include "MKL25Z4.h"
#include "libdecoycontador.h"
int salidas[7]={1,2,3,4,5,6,7};

//             y  x
int OutputEst[10][7]={
   //a,b,c,d,e,f,g 
    {1,1,1,1,1,1,0}, //0
    {0,1,1,0,0,0,0}, //1
    {1,1,0,1,1,0,1}, //2
    {1,1,1,1,0,0,1},
    {0,1,1,0,0,1,1},
    {1,0,1,1,0,1,1},
    {1,0,1,1,1,1,1},
    {1,1,1,0,0,0,0},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1} //9
    };

void deco7seg(char num){
        
    switch(num){
        case '0':
            for(int i=0;i<7;i++){
                PTA -> PSOR|=((OutputEst[0][i])<<salidas[i]);
            }
            break;
        case '1':
            for(int i=0;i<7;i++){
                PTA -> PSOR|=((OutputEst[1][i])<<salidas[i]);
            }
            break;
        case '2':
            for(int i=0;i<7;i++){
                PTA -> PSOR|=((OutputEst[2][i])<<salidas[i]);
            }
            break;
        case '3':
            for(int i=0;i<7;i++){
                PTA -> PSOR|=((OutputEst[3][i])<<salidas[i]);
            }
            break;
        case '4':
            for(int i=0;i<7;i++){
                PTA -> PSOR|=((OutputEst[4][i])<<salidas[i]);
            }
            break;
        case '5':
            for(int i=0;i<7;i++){
                PTA -> PSOR|=((OutputEst[5][i])<<salidas[i]);
            }
            break;
        case '6':
            for(int i=0;i<7;i++){
                PTA -> PSOR|=((OutputEst[6][i])<<salidas[i]);
            }
            break;
        case '7':
            for(int i=0;i<7;i++){
                PTA -> PSOR|=((OutputEst[7][i])<<salidas[i]);
            }
            break;
        case '8':
            for(int i=0;i<7;i++){
                PTA -> PSOR|=((OutputEst[8][i])<<salidas[i]);
            }
            break;
        case '9':
            for(int i=0;i<7;i++){
                PTA -> PSOR|=((OutputEst[9][i])<<salidas[i]);
            }
            break;
        default:
            break;
    }   
}