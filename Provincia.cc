#include <string.h>
#include <vector>
#include <iostream>
#include "Provincia.h"
#include <stdlib.h>
#include <stdio.h>


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

int Provincia::calculaDistancia(Localidad a, Localidad b){
    int distancia=0;
    distancia=abs(a.getCoor().getFila()-b.getCoor().getFila())+abs(a.getCoor().getColumna()-b.getCoor().getColumna());
    return distancia;
}

void Provincia::calculaCercanas(Coleccion &c, int distancia){
    if(!locprox.esVacia()){
        locprox.borraLocalidades(-1);
    }
    else{
        for(unsigned int i=0;i<c.getLocalidades().size();i++){
            int nueva_distancia=calculaDistancia(lc, c.getLocalidades()[i]);
            if(nueva_distancia<=distancia){
                locprox.insertaLocalidad(c.getLocalidades()[i], nueva_distancia);
            }
        }
    }
}

int Provincia::borraLocalidad(string s){
    int ret;
    ret=locprox.borraLocalidad(s);
    return ret;
}

LNear & Provincia::getCercanas(){
    return locprox;
}

bool Provincia::esCostera(Coleccion &c, Localidad l){
    bool ret=false;
    if(c.getMapa()[l.getCoor().getFila()-1][l.getCoor().getColumna()]=='M' ||
        c.getMapa()[l.getCoor().getFila()+1][l.getCoor().getColumna()]=='M' || 
        c.getMapa()[l.getCoor().getFila()][l.getCoor().getColumna()-1]=='M' || 
        c.getMapa()[l.getCoor().getFila()][l.getCoor().getColumna()+1]=='M'){
        ret=true;
    }
    return ret;
}

vector<Localidad> Provincia::vectorCosteras(Coleccion &c){
    vector<Localidad> costeras;
    for(unsigned int i=0;i<c.getLocalidades().size();i++){
        if(esCostera(c, c.getLocalidades()[i])){
            costeras.push_back(c.getLocalidades()[i]);
        }
    }
    return costeras;
}

/* METODO DE ORDENACION DEL VECTOR DEPENDIENDO DE LA DISTANCIA A LA CAPITAL
void ordenarArray(tArray miArray){
	float temporal;
	
	for (int i = 0;i < DIM; i++){
		for (int j = 0; j< DIM-1; j++){
			if (miArray[j] < miArray[j+1]){ // Ordena el array de mayor a menor, cambiar el "<" a ">" para ordenar de menor a mayor
			temporal = miArray[j]; 
			miArray[j] = miArray[j+1]; 
			miArray[j+1] = temporal;
			}
		}
	}
}
*/

string Provincia::getCostera(Coleccion &c){
    vector<Localidad> costeras=vectorCosteras(c);
    if(costeras.empty()){
        return "no hay ninguna localidad costera";
    }
    else{
        Localidad aux;
        for(unsigned int i=0;i<costeras.size();i++){
            for(unsigned int j=0;j<costeras.size()-1;j++){
                int d1=calculaDistancia(lc, costeras[j]);
                int d2=calculaDistancia(lc, costeras[j+1]);
                if(d1>d2){
                    aux=costeras[j];
                    costeras[j]=costeras[j+1];
                    costeras[j+1]=aux;
                }
            }
        }
        return costeras[0].getNombre();
    }
}
