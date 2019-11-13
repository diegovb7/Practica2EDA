#include "Provincia.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

int main(int argc, char *argv[]){
    Coleccion c;
    c.lectura(argv[1]);

    Localidad inicio;
    if(c.getLocalidades()[0].esCostera(c)){
        inicio=c.getLocalidades()[0];
    }
    else{
        
    }
}