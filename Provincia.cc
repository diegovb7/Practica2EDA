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
        for(unsigned int i=1;i<c.getLocalidades().size();i++){
            int nueva_distancia=calculaDistancia(lc, c.getLocalidades()[i]);
            if(nueva_distancia<distancia){
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
    bool m_arriba=false, m_abajo=false, m_izquierda=false, m_derecha=false;

    
    if(l.getCoor().getFila()-1>-1 && c.getMapa()[l.getCoor().getFila()-1][l.getCoor().getColumna()]=='M'){
        m_arriba=true;
    }

    unsigned int u_f1=l.getCoor().getFila()+1;

    if(u_f1<c.getMapa().size() && c.getMapa()[l.getCoor().getFila()+1][l.getCoor().getColumna()]=='M'){
        m_abajo=true;
    }

    if(l.getCoor().getColumna()-1>-1 && c.getMapa()[l.getCoor().getFila()][l.getCoor().getColumna()-1]=='M'){
        m_izquierda=true;
    }

    unsigned int u_c1=l.getCoor().getColumna()+1;

    if(u_c1<c.getMapa()[0].size() && c.getMapa()[l.getCoor().getFila()][l.getCoor().getColumna()+1]=='M'){
        m_derecha=true;
    }

    if(m_arriba || m_abajo || m_izquierda || m_derecha){
        ret=true;
    }
    
    return ret;
}

vector<Localidad> Provincia::vectorCosteras(Coleccion &c){
    vector<Localidad> costeras;
    for(int i=0;i<locprox.numeroNodos()-1;i++){
        if(esCostera(c, locprox.getLocalidad(i))){
            costeras.push_back(locprox.getLocalidad(i));
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
        /*
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
        */
        return costeras[0].getNombre();
    }
}

LNear Provincia::getCosteras(Coleccion &c){
    LNear lista;

    vector<Localidad> costeras=vectorCosteras(c);
    for(unsigned int i=0;i<costeras.size();i++){
        cout<<"VOY POR LA CIUDAD CON NOMBRE: "<<costeras[i].getNombre()<<endl;
        int distancia=calculaDistancia(lc, costeras[i]);
        lista.insertaLocalidad(costeras[i], distancia);
    }

    return lista;
}

string Provincia::getConAeropuerto(){
    if(lc.getInfo().getAeropuerto()){
        return "propio";
    }
    else{
        for(int i=0;i<locprox.numeroNodos();i++){
            if(locprox.getLocalidad(i).getInfo().getAeropuerto()){
                return locprox.getLocalidad(i).getNombre();
            }
        }
        return "sin aeropuerto";
    }
}

ostream & operator<<(ostream &os, Provincia &p){
    os<<p.lc.getNombre()<<endl<<p.locprox;
    return os;
}
