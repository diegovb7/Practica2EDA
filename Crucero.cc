#include "Provincia.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

int main(int argc, char *argv[]){
    Coleccion c;
    c.lectura(argv[1]);

    cout<<"MAPA:"<<endl<<c<<endl;

    Provincia p(c.getLocalidades()[0]);
    p.calculaCercanas(c, 100000);
    cout<<"PROVINCIA INICIAL:"<<endl<<p<<endl;
    
    Provincia inicio;
    
    if(p.soyCostera(c)){
        //cout<<"Es costera la inicial"<<endl;
        inicio=p;
    }else{
        Provincia aux(p.getCosteras(c).getLocalidad(0));
        inicio=aux;
        cout<<c.getLocalidades()[0].getNombre()<<" "<<p.getCosteras(c).getLocalidad(0).getNombre()<<" "<<p.calculaDistancia(c.getLocalidades()[0], p.getCosteras(c).getLocalidad(0))<<endl;
    }

    
}