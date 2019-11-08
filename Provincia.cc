#include <string.h>
#include <vector>
#include <iostream>
#include "Provincia.h"


Provincia::Provincia(){
    lc=Localidad();
    locprox=LNear();
}

Provincia::Provincia(Localidad l){
    lc=l;
    locprox=LNear();
}

Provincia::Provincia(const Provincia &p){
    lc=p.lc;
    locprox=p.locprox;
}

Provincia & Provincia::operator=(const Provincia &p){
    if(this!=&p){
        lc=p.lc;
        locprox=p.locprox;
    }
    return *this;
}

Provincia::~Provincia(){
    lc=Localidad();
    locprox=LNear();
}

void Provincia::calculaCercanas(Coleccion &c, int distancia){
    
}
