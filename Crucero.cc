#include "Provincia.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

int vista0(Coleccion &, Provincia &, Coordenadas &);
int vista1(Coleccion &, Provincia &, Coordenadas &);
int vista2(Coleccion &, Provincia &, Coordenadas &);
int vista3(Coleccion &, Provincia &, Coordenadas &);
int vista4(Coleccion &, Provincia &, Coordenadas &);
int vista5(Coleccion &, Provincia &, Coordenadas &);
int vista6(Coleccion &, Provincia &, Coordenadas &);
int vista7(Coleccion &, Provincia &, Coordenadas &);


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
    
    Coordenadas d0(inicio.getLocalidad().getCoor().getFila(), inicio.getLocalidad().getCoor().getColumna()+1);
    Coordenadas d1(inicio.getLocalidad().getCoor().getFila()+1, inicio.getLocalidad().getCoor().getColumna()+1);
    Coordenadas d2(inicio.getLocalidad().getCoor().getFila()+1, inicio.getLocalidad().getCoor().getColumna());
    Coordenadas d3(inicio.getLocalidad().getCoor().getFila()+1, inicio.getLocalidad().getCoor().getColumna()-1);
    Coordenadas d4(inicio.getLocalidad().getCoor().getFila(), inicio.getLocalidad().getCoor().getColumna()-1);
    Coordenadas d5(inicio.getLocalidad().getCoor().getFila()-1, inicio.getLocalidad().getCoor().getColumna()-1);
    Coordenadas d6(inicio.getLocalidad().getCoor().getFila()-1, inicio.getLocalidad().getCoor().getColumna());
    Coordenadas d7(inicio.getLocalidad().getCoor().getFila()-1, inicio.getLocalidad().getCoor().getColumna()+1);
    int direccion_inicial=0;
    Coordenadas nuevaCoordenada;

    if(c.getCoorMapa(d0)=='M' || (c.getCoorMapa(d1)=='L' || c.getCoorMapa(d1)=='T')){
        direccion_inicial=1;
        nuevaCoordenada=d1;
    }
    else{
        if(c.getCoorMapa(d1)=='M' || (c.getCoorMapa(d2)=='L' || c.getCoorMapa(d2)=='T')){
            direccion_inicial=2;
            nuevaCoordenada=d2;
        }
        else{
            if(c.getCoorMapa(d2)=='M' || (c.getCoorMapa(d3)=='L' || c.getCoorMapa(d3)=='T')){
                direccion_inicial=3;
                nuevaCoordenada=d3;
            }
            else{
                if(c.getCoorMapa(d3)=='M' || (c.getCoorMapa(d4)=='L' || c.getCoorMapa(d4)=='T')){
                    direccion_inicial=4;
                    nuevaCoordenada=d4;
                }
                else{
                    if(c.getCoorMapa(d4)=='M' || (c.getCoorMapa(d5)=='L' || c.getCoorMapa(d5)=='T')){
                        direccion_inicial=5;
                        nuevaCoordenada=d5;
                    }
                    else{
                        if(c.getCoorMapa(d5)=='M' || (c.getCoorMapa(d6)=='L' || c.getCoorMapa(d6)=='T')){
                            direccion_inicial=6;
                            nuevaCoordenada=d6;
                        }
                        else{
                            if(c.getCoorMapa(d6)=='M' || (c.getCoorMapa(d7)=='L' || c.getCoorMapa(d7)=='T')){
                                direccion_inicial=7;
                                nuevaCoordenada=d7;
                            }
                            else{
                                direccion_inicial=0;
                                nuevaCoordenada=d0;
                            }
                        }
                    }
                }
            }
        }
    } 

    vector<int> movimientos;
    movimientos.push_back(direccion_inicial);

    cout<<"El primer movimiento va en direccion: "<<direccion_inicial<<endl;
    cout<<"La nueva coordenada es: "<<nuevaCoordenada<<endl;
    int recorridoLocalidades=0;

    Localidad p_anterior=inicio.getLocalidadSR();
    Localidad p_nueva;



    while(nuevaCoordenada.getFila()!=inicio.getLocalidad().getCoor().getFila() && nuevaCoordenada.getColumna()!=inicio.getLocalidad().getCoor().getColumna()){
        direccion_inicial=(direccion_inicial+5)%8;
        switch(direccion_inicial){
            case 0: 
                direccion_inicial=vista0(c, inicio, nuevaCoordenada);
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7: 
                break;
        }
        recorridoLocalidades+=1;
        movimientos.push_back(direccion_inicial);
        if(c.getCoorMapa(nuevaCoordenada)=='L'){
            for(unsigned int i=0;i<c.getLocalidades().size();i++){
                if(nuevaCoordenada.getFila()==c.getLocalidades()[i].getCoor().getFila && nuevaCoordenada.getColumna()==c.getLocalidades().getCoor().getColumna()){
                    p_nueva=c.getLocalidades()[i];
                }
            }
            cout<<p_anterior.getNombre()<<" "<<p_nueva.getNombre()<<" "<<recorrido<<endl;
            p_anterior=p_nueva;
        }
    }

    
}

int vista0(Coleccion &c, Provincia &inicio, Coordenadas &nuevaCoordenada){

    Coordenadas d0(inicio.getLocalidad().getCoor().getFila(), inicio.getLocalidad().getCoor().getColumna()+1);
    Coordenadas d1(inicio.getLocalidad().getCoor().getFila()+1, inicio.getLocalidad().getCoor().getColumna()+1);
    Coordenadas d2(inicio.getLocalidad().getCoor().getFila()+1, inicio.getLocalidad().getCoor().getColumna());
    Coordenadas d3(inicio.getLocalidad().getCoor().getFila()+1, inicio.getLocalidad().getCoor().getColumna()-1);
    Coordenadas d4(inicio.getLocalidad().getCoor().getFila(), inicio.getLocalidad().getCoor().getColumna()-1);
    Coordenadas d5(inicio.getLocalidad().getCoor().getFila()-1, inicio.getLocalidad().getCoor().getColumna()-1);
    Coordenadas d6(inicio.getLocalidad().getCoor().getFila()-1, inicio.getLocalidad().getCoor().getColumna());
    Coordenadas d7(inicio.getLocalidad().getCoor().getFila()-1, inicio.getLocalidad().getCoor().getColumna()+1);
    int direccion_inicial=0;
    //Coordenadas nuevaCoordenada;

    if(c.getCoorMapa(d0)=='M' || (c.getCoorMapa(d1)=='L' || c.getCoorMapa(d1)=='T')){
        direccion_inicial=1;
        nuevaCoordenada=d1;
    }
    else{
        if(c.getCoorMapa(d1)=='M' || (c.getCoorMapa(d2)=='L' || c.getCoorMapa(d2)=='T')){
            direccion_inicial=2;
            nuevaCoordenada=d2;
        }
        else{
            if(c.getCoorMapa(d2)=='M' || (c.getCoorMapa(d3)=='L' || c.getCoorMapa(d3)=='T')){
                direccion_inicial=3;
                nuevaCoordenada=d3;
            }
            else{
                if(c.getCoorMapa(d3)=='M' || (c.getCoorMapa(d4)=='L' || c.getCoorMapa(d4)=='T')){
                    direccion_inicial=4;
                    nuevaCoordenada=d4;
                }
                else{
                    if(c.getCoorMapa(d4)=='M' || (c.getCoorMapa(d5)=='L' || c.getCoorMapa(d5)=='T')){
                        direccion_inicial=5;
                        nuevaCoordenada=d5;
                    }
                    else{
                        if(c.getCoorMapa(d5)=='M' || (c.getCoorMapa(d6)=='L' || c.getCoorMapa(d6)=='T')){
                            direccion_inicial=6;
                            nuevaCoordenada=d6;
                        }
                        else{
                            if(c.getCoorMapa(d6)=='M' || (c.getCoorMapa(d7)=='L' || c.getCoorMapa(d7)=='T')){
                                direccion_inicial=7;
                                nuevaCoordenada=d7;
                            }
                            else{
                                direccion_inicial=0;
                                nuevaCoordenada=d0;
                            }
                        }
                    }
                }
            }
        }
    }

    return direccion_inicial; 
}