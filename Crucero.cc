#include "Provincia.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

int vista0(Coleccion &, Provincia &, Coordenadas &);
/*
int vista1(Coleccion &, Provincia &, Coordenadas &);
int vista2(Coleccion &, Provincia &, Coordenadas &);
int vista3(Coleccion &, Provincia &, Coordenadas &);
int vista4(Coleccion &, Provincia &, Coordenadas &);
int vista5(Coleccion &, Provincia &, Coordenadas &);
int vista6(Coleccion &, Provincia &, Coordenadas &);
int vista7(Coleccion &, Provincia &, Coordenadas &);
*/
vector<Coordenadas> creaVista0(vector<Coordenadas> &);


void cambiarCoordenadas(Coordenadas &, Coordenadas &, Coordenadas &, Coordenadas &, Coordenadas &, Coordenadas &, Coordenadas &, Coordenadas &, Coordenadas &);


int main(int argc, char *argv[]){
    Coleccion c;
    c.lectura(argv[1]);
    cout<<"MAPA:"<<endl<<c<<endl;
    cout<<"*************************************"<<endl;
    int posicion_de_la_primera_costera=0;
    for(unsigned int i=1;i<c.getLocalidades().size() && posicion_de_la_primera_costera==0;i++){
        Localidad aux=c.getLocalidades()[i];
        int fila=aux.getCoor().getFila();
        int columna=aux.getCoor().getColumna();
        if(c.getMapa()[fila-1][columna]=='M' || c.getMapa()[fila+1][columna]=='M' || c.getMapa()[fila][columna+1]=='M' || c.getMapa()[fila][columna-1]=='M'){
        posicion_de_la_primera_costera=i;
        }
    }

    

    Provincia p(c.getLocalidades()[0]);
    p.calculaCercanas(c, 100000);
    cout<<"PROVINCIA INICIAL:"<<endl<<p<<endl;
    
    Provincia inicio;
    
    if(p.soyCostera(c)){
        //cout<<"Es costera la inicial"<<endl;
        inicio=p;
    }else{
        Provincia aux(c.getLocalidades()[posicion_de_la_primera_costera]);
        inicio=aux;
        cout<<c.getLocalidades()[0].getNombre()<<" "<<c.getLocalidades()[posicion_de_la_primera_costera].getNombre()<<" "<<p.calculaDistancia(c.getLocalidades()[0], c.getLocalidades()[posicion_de_la_primera_costera])<<endl;
    }

    //hasta aqui ya se ha mostrado, en el caso de que la localidad primera no sea costera, el nombre de la primera, la primera costera y la 
    //distancia de manhatan entre ellas. en el caso de que la primera si que sea costera, no se va a mostrar nada

    //ahora que ya tenemos la localidad de partida del crucero, tenemos que ver cual va a ser la primera direccion
    
    Coordenadas d0;
    Coordenadas d1;
    Coordenadas d2;
    Coordenadas d3;
    Coordenadas d4;
    Coordenadas d5;
    Coordenadas d6;
    Coordenadas d7;
    cambiarCoordenadas(d0, d1, d2, d3, d4, d5, d6, d7, inicio.getLocalidad().getCoor());
    int direccion_inicial=0;
    Coordenadas nuevaCoordenada;
    vector<Coordenadas> vector_inicial;
    vector_inicial.push_back(d0);
    vector_inicial.push_back(d1);
    vector_inicial.push_back(d2);
    vector_inicial.push_back(d3);
    vector_inicial.push_back(d4);
    vector_inicial.push_back(d5);
    vector_inicial.push_back(d6);
    vector_inicial.push_back(d7);
    bool coordenada_encontrada=false;
    for(unsigned int i=1;i<=vector_inicial.size() && !coordenada_encontrada;i++){
        if(c.getCoorMapa(vector_inicial[i-1])=='M' && (c.getCoorMapa(vector_inicial[i])=='T' || c.getCoorMapa(vector_inicial[i])=='L')){
            direccion_inicial=i;
            coordenada_encontrada=true;
            nuevaCoordenada=vector_inicial[i];
        }
    }
    
    vector<int> movimientos;
    movimientos.push_back(direccion_inicial);

    cout<<"El primer movimiento va en direccion: "<<direccion_inicial<<endl;
    cout<<"La nueva coordenada es: "<<nuevaCoordenada<<endl;
    int recorridoLocalidades=0;

    Localidad p_anterior=inicio.getLocalidadSR();
    Localidad p_nueva;


    /*
    while(nuevaCoordenada.getFila()!=inicio.getLocalidad().getCoor().getFila() && nuevaCoordenada.getColumna()!=inicio.getLocalidad().getCoor().getColumna()){
        cout<<"Siguiente direccion: "<<direccion_inicial<<endl;

        direccion_inicial=(direccion_inicial+5)%8;
        switch(direccion_inicial){
            case 0: 
                direccion_inicial=vista0(c, inicio, nuevaCoordenada);
                break;
            case 1:
                direccion_inicial=vista1(c, inicio, nuevaCoordenada);
                break;
            case 2:
                direccion_inicial=vista2(c, inicio, nuevaCoordenada);
                break;
            case 3:
                direccion_inicial=vista3(c, inicio, nuevaCoordenada);
                break;
            case 4:
                direccion_inicial=vista4(c, inicio, nuevaCoordenada);
                break;
            case 5:
                direccion_inicial=vista5(c, inicio, nuevaCoordenada);
                break;
            case 6:
                direccion_inicial=vista6(c, inicio, nuevaCoordenada);
                break;
            case 7: 
                direccion_inicial=vista6(c, inicio, nuevaCoordenada);
                break;
        }
        recorridoLocalidades+=1;
        movimientos.push_back(direccion_inicial);
        if(c.getCoorMapa(nuevaCoordenada)=='L'){
            for(unsigned int i=0;i<c.getLocalidades().size();i++){
                if(nuevaCoordenada.getFila()==c.getLocalidades()[i].getCoor().getFila() && nuevaCoordenada.getColumna()==c.getLocalidades()[i].getCoor().getColumna()){
                    p_nueva=c.getLocalidades()[i];
                }
            }
            cout<<p_anterior.getNombre()<<" "<<p_nueva.getNombre()<<" "<<recorridoLocalidades<<endl;
            p_anterior=p_nueva;
        }
    }
    */
}

void cambiarCoordenadas(Coordenadas &d0, Coordenadas &d1, Coordenadas &d2, Coordenadas &d3, Coordenadas &d4, Coordenadas &d5, Coordenadas &d6, Coordenadas &d7, Coordenadas &ref){
    d0=Coordenadas(ref.getFila(), ref.getColumna()+1);
    d1=Coordenadas(ref.getFila()+1, ref.getColumna()+1);
    d2=Coordenadas(ref.getFila()+1, ref.getColumna());
    d3=Coordenadas(ref.getFila()+1, ref.getColumna()-1);
    d4=Coordenadas(ref.getFila(), ref.getColumna()-1);
    d5=Coordenadas(ref.getFila()-1, ref.getColumna()-1);
    d6=Coordenadas(ref.getFila()-1, ref.getColumna());
    d7=Coordenadas(ref.getFila()-1, ref.getColumna()+1);
}

vector<Coordenadas> creaVista(vector<Coordenadas> &v){
    vector<Coordenadas> ret;
    ret.push_back(v[0]);
    ret.push_back(v[1]);
    ret.push_back(v[2]);
    ret.push_back(v[3]);
    ret.push_back(v[4]);
    ret.push_back(v[5]);
    ret.push_back(v[6]);
    ret.push_back(v[7]);
}

int vista0(Coleccion &c, Provincia &p, Coordenadas &coor){

}

