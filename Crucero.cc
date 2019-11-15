#include "Provincia.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

int main(int argc, char *argv[]){
    Coleccion c;
    c.lectura(argv[1]);

    Provincia inicio_aux(c.getLocalidades()[0]);
    bool primera_costera=false;
    if(inicio_aux.esCostera(c, c.getLocalidades()[0])){
       primera_costera=true; 
    }

    Provincia inicio;

    if(primera_costera){
        Provincia p(c.getLocalidades()[0]);
        inicio=p;
    }else{
        Provincia p(inicio_aux.getCosteras(c).getLocalidad(0));
        inicio=p;
    }

    

}