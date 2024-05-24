#include "MKL25Z4.h"

int est=1;
int decoUnidades[4]={1,2,3,4};
int decoDecenas[4]={5,6,7,8};
int cont[9][4]={
    {0,0,0,0},
    {0,0,0,1},       
    {0,0,1,0},
    {0,0,1,1},
    {0,1,0,0},
    {0,1,0,1},
    {0,1,1,0},
    {0,1,1,1},
    {1,0,0,0},
    {1,0,0,1}
    };
                int contB=0;

int main(){
    SIM -> SCGC5 |= SIM_SCGC5_PORTA_MASK;
    est=PTA->PDIR&(1u<<5);
    PORTA->PCR[est]|=PORT_PCR_MUX(0);
    for(int q=0;q<4;q++){
        PORTA->PCR[(decoUnidades[q])]|=PORT_PCR_MUX(1);
        PORTA->PCR[(decoDecenas[q])]|=PORT_PCR_MUX(1);
    }

    while(1){
        if(est==0){ //cuenta para delante
            for(int i=0;i<10;i++){ //filas X  //se repite mientras que i sea menor a 10
                for(int j=0;j<4;j++){ //columnas Y o Pines
                                    //y  x
                    PTA->PSOR|=((cont[i][j])<<(decoUnidades[j])); //la posicion del cont
                }                                                 //remplaza al decounidades en el eje x 
            if(i==9){
                contB++;
                for(int j=0;j<4;j++){ //columnas Y o Pines
                                    //y  x
                    PTA->PSOR|=((cont[contB][j])<<(decoUnidades[j])); //la posicion del cont
                }      
                i=0;                                        
            }
            }
        }else{
           for(int i=10;i>0;i--){ //filas X
                for(int j=4;j>0;j--){ //columnas Y o Pines
                                    //y  x
                    PTA->PSOR|=((cont[i][j])<<(decoUnidades[j])); //la posicion del cont
                }                                                 //remplaza al decounidades en el eje x 
            if(i==0){
                contB--;
                for(int j=4;j>0;j--){ //columnas Y o Pines
                                    //y  x
                    PTA->PSOR|=((cont[contB][j])<<(decoUnidades[j])); //la posicion del cont
                }      
                i=9;                                        
            }
            }
        }
    }
}