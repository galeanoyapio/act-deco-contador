#include "libdecoycontador.h"
#include "MKL25Z4.h"
int main(){
    SIM -> SCGC5 |= SIM_SCGC5_PORTA_MASK;
    keyboardInit('b');
    int salidas[7];
    for(int i=0;i<7;i++){
        PORTA->PCR[i]|=PORT_PCR_MUX(1);
    }

    while(1){
        char tecla = keyboardRead('a');
        deco7seg(tecla);


    }
}