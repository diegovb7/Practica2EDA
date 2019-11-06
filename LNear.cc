#include <string.h>
#include <vector>
#include <iostream>
#include "LNear.h"

LNear::LNear(){
    pr=NULL;
    ul=NULL;
    error=Localidad();
}

LNear::~LNear(){
    if(!esVacia()){
        NodoL *borrado;
        borrado=pr;
        while(borrado!=NULL){
            pr=pr->next;
            delete borrado;
            borrado=pr;
        }
    }
}

LNear::LNear(const LNear &l){
    NodoL *aux=l.pr;
    pr=NULL;
    ul=NULL;
    while(aux!=NULL){
        insertaLocalidad(aux->localidad, aux->distancia);
        aux=aux->next;
    }
}

LNear & LNear::operator=(const LNear &l){
    if(this!=&l){
        NodoL *aux=l.pr;
        while(aux!=NULL){
            insertaLocalidad(aux->localidad, aux->distancia);
            aux=aux->next;
        }
    }
    return *this;
}

bool LNear::esVacia(){
    bool ret=false;

    if(pr==NULL){
        ret=true;
    }

    return ret;
}

int LNear::rango(){
    int ret=-1;
    if(ul!=NULL){
        ret=ul->distancia;
    }
    return ret;
}

void LNear::insertaLocalidad(Localidad p, int d){
    NodoL *aux=new NodoL(p);
    bool iguales=false;
    aux->distancia=d;

    NodoL *recorre;
    recorre=pr;
    if(esVacia()){ //si esta vacia, metemos el elemento a saco
        pr=aux;
        ul=aux;
    }
    else{
        while(recorre!=NULL){ //compruebo que no hay ningun nodo con la misma distancia y el mismo nombre de localidad
            if(aux->localidad.getNombre()==recorre->localidad.getNombre() && aux->distancia==recorre->distancia){
                iguales=true;
            }
            recorre=recorre->next;
        }
        if(!iguales){
            bool dentro=false;
            NodoL *insercion;
            insercion=pr;
            if(d>ul->distancia){ //si la distancia ya es mayor que la ultima, directamente se mete al final
                aux->prev=ul;
                ul->next=aux;
                ul=aux;
                dentro=true;
            }
            else{ //si no es mas, puede ser igual
                if(d==ul->distancia){ //si la distancia es la misma
                    if(strcmp(insercion->localidad.getNombre().c_str(), aux->localidad.getNombre().c_str())<0){ //comparamos las cadenas
                        aux->prev=ul;
                        ul->next=aux;
                        ul=aux;
                        dentro=true;
                    }
                }
            }
            while(insercion!=NULL && !dentro){
                if(d<insercion->distancia){
                    if(insercion==pr){ //si donde tengo que meterlo es al principio
                        insercion->prev=aux;
                        aux->next=insercion;
                        pr=aux;
                        dentro=true;
                    }
                    else{ //si no es al principio
                        insercion->prev->next=aux;
                        aux->prev=insercion->prev;
                        insercion->prev=aux;
                        aux->next=insercion;
                        dentro=true;
                    }        
                }
                else{
                    if(d==insercion->distancia){
                        if(strcmp(aux->localidad.getNombre().c_str(), insercion->localidad.getNombre().c_str())<0){
                            if(insercion==pr){
                                insercion->prev=aux;
                                aux=insercion;
                                pr=aux;
                                dentro=true;
                            }
                            else{
                                insercion->prev->next=aux;
                                aux->prev=insercion->prev;
                                insercion->prev=aux;
                                aux->next=insercion;
                                dentro=true;
                            }
                        }
                    }
                }
            }
        }
    }
}

int LNear::borraLocalidad(string s){
    int ret=-1;
    bool borrado=false;
    NodoL *aux=pr;
    if(!esVacia()){
        while(aux!=NULL && !borrado){
            if(aux->localidad.getNombre()==s){
                if(aux==pr && aux==ul){ //cuando solo hay un elemento en la lista
                    ret=aux->distancia;
                    pr=NULL;
                    ul=NULL;
                    delete aux;
                    borrado=true;
                }
                else{
                    if(aux==pr){ //cuando hay mas de un elemento en la lista y queremos borrar el primero
                        ret=aux->distancia;
                        aux->next->prev=NULL;
                        pr=aux->next;
                        aux->next=NULL;
                        delete aux;
                        borrado=true;
                    }
                    else{
                        if(aux==ul){ //cuando hay mas de un elemento en la lista y queremos borrar el ultimo
                            ret=aux->distancia;
                            aux->prev->next=NULL;
                            ul=aux->prev;
                            aux->prev=NULL;
                            delete aux;
                            borrado=true;
                        }
                        else{ //cuando hay mas de un elemento en la lista y queremos borrar alguno que no sea ni el primero ni el ultimo
                            ret=aux->distancia;
                            aux->prev->next=aux->next;
                            aux->next->prev=aux->prev;
                            aux->prev=NULL;
                            aux->next=NULL;
                            delete aux;
                            borrado=true;
                        }
                    }
                }
            }
            aux=aux->next;
        }
    }
    return ret;
}

void LNear::borraLocalidades(int d){
    NodoL *aux=pr;
    NodoL *aux2;
    if(!esVacia()){
        while(aux!=NULL){
            aux2=aux->next;
            if(aux->distancia>d){
                cout<<"estoy en el nodo: "<<*aux<<endl;
                if(aux==pr && aux==ul){ //cuando solo hay un elemento en la lista
                    pr=NULL;
                    ul=NULL;
                    delete aux;
                }
                else{
                    if(aux==pr){ //cuando hay mas de un elemento en la lista y queremos borrar el primero
                        aux->next->prev=NULL;
                        pr=aux->next;
                        aux->next=NULL;
                        delete aux;
                    }
                    else{
                        if(aux==ul){ //cuando hay mas de un elemento en la lista y queremos borrar el ultimo
                            aux->prev->next=NULL;
                            ul=aux->prev;
                            aux->prev=NULL;
                            delete aux;
                        }
                        else{ //cuando hay mas de un elemento en la lista y queremos borrar alguno que no sea ni el primero ni el ultimo
                            aux->prev->next=aux->next;
                            aux->next->prev=aux->prev;
                            aux->prev=NULL;
                            aux->next=NULL;
                            delete aux;
                        }
                    }
                }
            }
            aux=aux2;
        }
    }
}

Localidad & LNear::getLocalidad(int i){
    NodoL *aux=pr;
    int contador=0;
    while(aux!=NULL){
        if(i==contador){
            return aux->localidad;
        }
        contador++;
        aux=aux->next;
    }
    return error;
}
    
ostream & operator<<(ostream &os, const LNear &l){
    LNear::NodoL *aux;
    aux=l.pr;
    while(aux!=NULL){
        os<<*aux<<endl;
        aux=aux->next;
    }

    return os;
}