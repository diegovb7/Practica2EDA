#include "Coordenadas.h"

Coordenadas::Coordenadas(int f, int c){
    if(f<0 || c<0){
        f=-1;
        c=-1;
    }
    fila=f;
    columna=c;
}

Coordenadas::Coordenadas(const Coordenadas &c){
    fila=c.fila;
    columna=c.columna;
}

Coordenadas::~Coordenadas(){
    fila=-1;
    columna=-1;
}

Coordenadas & Coordenadas::operator=(const Coordenadas &c){
    if(this!=&c){
        fila=c.fila;
        columna=c.columna;
    }

    return *this;
}

int Coordenadas::getFila(){
    return fila;
}

int Coordenadas::getColumna(){
    return columna;
}

ostream & operator<<(ostream &os, const Coordenadas &c){
    os<<"("<<c.fila<<","<<c.columna<<")";

    return os;
}