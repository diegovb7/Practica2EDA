#include <iostream>
#include "LNear.h"

int main(){
    LNear lista;
    Localidad loc1("Almoradi");
    Localidad loc2("Torrevieja");
    Localidad loc3("Guardamar");
    
    lista.insertaLocalidad(loc1, 20);
    lista.insertaLocalidad(loc2, 20);
    lista.insertaLocalidad(loc3, 10);
    cout<<"Esta es la lista: "<<endl;
    cout<<lista;
    /*
    lista.borraLocalidades(15);
    cout<<"Esta es la lista despues de borrar: "<<endl;
    cout<<lista;
    Localidad l=lista.getLocalidad(0);
    cout<<"la primera localidad es"<<endl<<l;
    */
    LNear lista2=lista;
    cout<<"Esta es la lista 2: "<<endl;
    cout<<lista2;

}