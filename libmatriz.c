#include "MKL25Z4.h"
#include "libmatriz.h"
#include <ctype.h> //toupper(char) -mayus , tolower(char) -min

int columnas[4]={1,2,3,4};
int filas[4]={11,12,13,14};
char coordenadas[4][4]={
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};
void keyboardInit(char port){
    char port = toupper(port);
    switch (port){
    case 'A':
        for(int j=0;j<=4;j++){
            for(int i=0;i<=4;i++){
                PORTA -> PCR[columnas[i]]|= PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
                PORTA -> PCR[filas[j]]|=PORT_PCR_MUX(1);
            }
        }
        break;
    case 'B':
        SIM -> SCGC5|=SIM_SCGC5_PORTB_MASK;
        for(int j=0;j<=4;j++){
            for(int i=0;i<=4;i++){
                PORTA -> PCR[columnas[i]]|= PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
                PORTA -> PCR[filas[j]]|=PORT_PCR_MUX(1);
            }
        }
        break;
    case 'C':
        for(int j=0;j<=4;j++){
            for(int i=0;i<=4;i++){
                PORTA -> PCR[columnas[i]]|= PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
                PORTA -> PCR[filas[j]]|=PORT_PCR_MUX(1);
            }
        }
        break;
    case 'D':
        for(int j=0;j<=4;j++){
            for(int i=0;i<=4;i++){
                PORTA -> PCR[columnas[i]]|= PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
                PORTA -> PCR[filas[j]]|=PORT_PCR_MUX(1);
            }
        }    
        break;
    case 'E':
        for(int j=0;j<=4;j++){
            for(int i=0;i<=4;i++){
                PORTA -> PCR[columnas[i]]|= PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
                PORTA -> PCR[filas[j]]|=PORT_PCR_MUX(1);
            }
        }    
        break;
    }
}
char keyboardRead(char port){
    char port = toupper(port);
    switch (port){
    case 'A':
        for(int j=0;j<4;j++){ //filas
        PTA -> PSOR |= (0u<<filas[j]);
        for(int i=0;i<4;i++){ //columnas
            if((PTA -> PDIR & (0u<<columnas[i]))==0){
                return coordenadas[i][j];
            }
        }
        PTA -> PSOR |= (1u<<filas[j]);
    }
    case 'B':
        for(int j=0;j<4;j++){ //filas
        PTB -> PSOR |= (0u<<filas[j]);
        for(int i=0;i<4;i++){ //columnas
            if((PTB -> PDIR & (0u<<columnas[i]))==0){
                return coordenadas[i][j];
            }
        }
        PTB -> PSOR |= (1u<<filas[j]);
    }
    case 'C':
        for(int j=0;j<4;j++){ //filas
        PTC -> PSOR |= (0u<<filas[j]);
        for(int i=0;i<4;i++){ //columnas
            if((PTC -> PDIR & (0u<<columnas[i]))==0){
                return coordenadas[i][j];
            }
        }
        PTC -> PSOR |= (1u<<filas[j]);
    }
    case 'D':
        for(int j=0;j<4;j++){ //filas
        PTD -> PSOR |= (0u<<filas[j]);
        for(int i=0;i<4;i++){ //columnas
            if((PTD -> PDIR & (0u<<columnas[i]))==0){
                return coordenadas[i][j];
            }
        }
        PTD -> PSOR |= (1u<<filas[j]);
    }
    case 'E':
        for(int j=0;j<4;j++){ //filas
        PTE -> PSOR |= (0u<<filas[j]);
        for(int i=0;i<4;i++){ //columnas
            if((PTE -> PDIR & (0u<<columnas[i]))==0){
                return coordenadas[i][j];
            }
        }
        PTE -> PSOR |= (1u<<filas[j]);
        }   
    }
}