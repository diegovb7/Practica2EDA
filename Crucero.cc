#include "Provincia.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

bool esCostera(Coleccion &, Localidad l);
int vista0(vector<Coordenadas> &, Coordenadas &, Coleccion &);
int vista1(vector<Coordenadas> &, Coordenadas &, Coleccion &);
int vista23456(vector<Coordenadas> &, Coordenadas &, Coleccion &, int);
int vista7(vector<Coordenadas> &, Coordenadas &, Coleccion &);
vector<Coordenadas> cambiarCoordenadas(Coordenadas &, Coordenadas &, Coordenadas &, Coordenadas &, Coordenadas &, Coordenadas &, Coordenadas &, Coordenadas &, Coordenadas &);

int main(int argc, char *argv[]){
    Coleccion c;
    c.lectura(argv[1]);
    vector<int> movimientos;
    if(!c.getLocalidades().empty()){
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
    
    Provincia inicio;
    
    if(p.soyCostera(c)){
        //cout<<"Es costera la inicial"<<endl;
        inicio=p;
    }else{
        Provincia aux(p.getCosteras(c).getLocalidad(0));
        inicio=aux;
        cout<<c.getLocalidades()[0].getNombre()<<" "<<p.getCosteras(c).getLocalidad(0).getNombre()<<" "<<p.calculaDistancia(c.getLocalidades()[0], p.getCosteras(c).getLocalidad(0))<<endl;
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
    vector<Coordenadas> vector_inicial;
    //cout<<inicio.getLocalidad().getCoor()<<endl;
    vector_inicial=cambiarCoordenadas(d0, d1, d2, d3, d4, d5, d6, d7, inicio.getLocalidad().getCoor());
    int direccion_inicial=0;
    Coordenadas nuevaCoordenada=inicio.getLocalidad().getCoor();
    direccion_inicial=vista0(vector_inicial, nuevaCoordenada, c);
    //cout<<nuevaCoordenada<<endl;
    
    if(direccion_inicial!=-1){

    
    
    movimientos.push_back(direccion_inicial);
    int recorridoLocalidades=1;

    Localidad p_anterior=inicio.getLocalidadSR();
    Localidad p_nueva;

    if(c.getCoorMapa(nuevaCoordenada)=='L'){
            for(unsigned int i=0;i<c.getLocalidades().size();i++){
                if(nuevaCoordenada.getFila()==c.getLocalidades()[i].getCoor().getFila() && nuevaCoordenada.getColumna()==c.getLocalidades()[i].getCoor().getColumna()){
                    p_nueva=c.getLocalidades()[i];
                }
            }
            cout<<p_anterior.getNombre()<<" "<<p_nueva.getNombre()<<" "<<recorridoLocalidades<<endl;
            recorridoLocalidades=0;
            p_anterior=p_nueva;
        }

    while(!(p_nueva==inicio.getLocalidad())){
        //cout<<"Direccion: "<<direccion_inicial<<endl;
        vector_inicial.clear();
        vector_inicial=cambiarCoordenadas(d0, d1, d2, d3, d4, d5, d6, d7, nuevaCoordenada);
        direccion_inicial=(direccion_inicial+5)%8;
        //cout<<"Nueva direccion"<<direccion_inicial<<endl;

        switch(direccion_inicial){
            case 0: 
                direccion_inicial=vista0(vector_inicial, nuevaCoordenada, c);
                break;
            case 1:
                direccion_inicial=vista1(vector_inicial, nuevaCoordenada, c);
                break;
            case 2:
                direccion_inicial=vista23456(vector_inicial, nuevaCoordenada, c, direccion_inicial);
                break;
            case 3:
                direccion_inicial=vista23456(vector_inicial, nuevaCoordenada, c, direccion_inicial);
                break;
            case 4:
                direccion_inicial=vista23456(vector_inicial, nuevaCoordenada, c, direccion_inicial);
                break;
            case 5:
                direccion_inicial=vista23456(vector_inicial, nuevaCoordenada, c, direccion_inicial);
                break;
            case 6:
                direccion_inicial=vista23456(vector_inicial, nuevaCoordenada, c, direccion_inicial);
                break;
            case 7: 
                direccion_inicial=vista7(vector_inicial, nuevaCoordenada, c);
                break;
        }
        //cout<<"siguiente"<<direccion_inicial<<endl;
        //break;
        recorridoLocalidades+=1;
        movimientos.push_back(direccion_inicial);
        if(c.getCoorMapa(nuevaCoordenada)=='L'){
            for(unsigned int i=0;i<c.getLocalidades().size();i++){
                if(nuevaCoordenada.getFila()==c.getLocalidades()[i].getCoor().getFila() && nuevaCoordenada.getColumna()==c.getLocalidades()[i].getCoor().getColumna()){
                    p_nueva=c.getLocalidades()[i];
                }
            }
            cout<<p_anterior.getNombre()<<" "<<p_nueva.getNombre()<<" "<<recorridoLocalidades<<endl;
            recorridoLocalidades=0;
            p_anterior=p_nueva;
        }        
    }
    }
    }
    
    cout<<"total="<<movimientos.size()<<endl;
    for(unsigned int i=0;i<movimientos.size();i++){
        cout<<movimientos[i];
    }
    cout<<endl;
    
}

bool esCostera(Coleccion &c, Localidad l){
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

vector<Coordenadas> cambiarCoordenadas(Coordenadas &d0, Coordenadas &d1, Coordenadas &d2, Coordenadas &d3, Coordenadas &d4, Coordenadas &d5, Coordenadas &d6, Coordenadas &d7, Coordenadas &ref){
    d0=Coordenadas(ref.getFila(), ref.getColumna()+1);
    d1=Coordenadas(ref.getFila()+1, ref.getColumna()+1);
    d2=Coordenadas(ref.getFila()+1, ref.getColumna());
    d3=Coordenadas(ref.getFila()+1, ref.getColumna()-1);
    d4=Coordenadas(ref.getFila(), ref.getColumna()-1);
    d5=Coordenadas(ref.getFila()-1, ref.getColumna()-1);
    d6=Coordenadas(ref.getFila()-1, ref.getColumna());
    d7=Coordenadas(ref.getFila()-1, ref.getColumna()+1);
    vector<Coordenadas> ret;
    ret.push_back(d0);
    ret.push_back(d1);
    ret.push_back(d2);
    ret.push_back(d3);
    ret.push_back(d4);
    ret.push_back(d5);
    ret.push_back(d6);
    ret.push_back(d7);
    return ret;
}

int vista0(vector<Coordenadas> &v, Coordenadas &coor, Coleccion &c){
    int ret=-1;
    bool coordenada_encontrada=false;
    for(unsigned int i=1;i<=v.size() && !coordenada_encontrada;i++){
        if(c.getCoorMapa(v[i-1])=='M' && (c.getCoorMapa(v[i])=='T' || c.getCoorMapa(v[i])=='L')){
            ret=i;
            coordenada_encontrada=true;
            coor=v[i];
        }
    }
    if(c.getCoorMapa(v[7])=='M' && (c.getCoorMapa(v[0])=='T' || c.getCoorMapa(v[0])=='L')){
        ret=0;
        coor=v[0];
    }
    return ret;
}

int vista1(vector<Coordenadas> &v, Coordenadas &coor, Coleccion &c){
    int ret=0;
    bool encontrada=false;
    for(int i=2;i!=1 && !encontrada;i++){
        if(c.getCoorMapa(v[i-1])=='M' && (c.getCoorMapa(v[i])=='T' || c.getCoorMapa(v[i])=='L')){
            ret=i;
            encontrada=true;
            coor=v[i];
        }
        if(i==7){
            int aux=i;
            i=1;
            if(c.getCoorMapa(v[aux])=='M' && (c.getCoorMapa(v[i-1])=='T' || c.getCoorMapa(v[i-1])=='L')){
                ret=i-1;
                encontrada=true;
                coor=v[i-1];
            }
        }
        if(i==1 && !encontrada){
            if(c.getCoorMapa(v[i-1])=='M' && (c.getCoorMapa(v[i])=='T' || c.getCoorMapa(v[i])=='L')){
                ret=i;
                encontrada=true;
                coor=v[i];
            }
            i--;
        } 
    }
    return ret;
}

int vista23456(vector<Coordenadas> &v, Coordenadas &coor, Coleccion &c, int n){
    int ret=-1;
    bool encontrada=false;
    for(int i=n;i!=n-1 && !encontrada;i++){
            if(i==7){
                if(c.getCoorMapa(v[i-1])=='M' && (c.getCoorMapa(v[i])=='T' || c.getCoorMapa(v[i])=='L')){
                    
                    ret=i;
                    encontrada=true;
                    coor=v[i];
                }
                i=-1;
            }
            else{
                if(i!=n-2){
                    if(i==0){
                        if(c.getCoorMapa(v[7])=='M' && (c.getCoorMapa(v[0])=='T' || c.getCoorMapa(v[0])=='L')){
                            
                            ret=i;
                            encontrada=true;
                            coor=v[i];
                        }
                    }
                    else{
                        if(c.getCoorMapa(v[i-1])=='M' && (c.getCoorMapa(v[i])=='T' || c.getCoorMapa(v[i])=='L')){
                            
                            ret=i;
                            encontrada=true;
                            coor=v[i];
                        }
                    }
                }   
            }
            if(i==n-2){
                if(c.getCoorMapa(v[i-1])=='M' && (c.getCoorMapa(v[i])=='T' || c.getCoorMapa(v[i])=='L')){
                    
                    ret=i;
                    encontrada=true;
                    coor=v[i];
                }
                else if(c.getCoorMapa(v[i])=='M' && (c.getCoorMapa(v[i+1])=='T' || c.getCoorMapa(v[i+1])=='L')){
                    
                        ret=i+1;
                        encontrada=true;
                        coor=v[i+1];
                    }
            }
        }
        return ret;
}

int vista7(vector<Coordenadas> &v, Coordenadas &coor, Coleccion &c){
    int ret=0;
    bool encontrada=false;
    if(c.getCoorMapa(v[7])=='M' && (c.getCoorMapa(v[0])=='T' || c.getCoorMapa(v[0])=='L')){
        ret=0;
        encontrada=true;
        coor=v[0];
    }
    for(int i=1;i!=8 && !encontrada;i++){
        if(c.getCoorMapa(v[i-1])=='M' && (c.getCoorMapa(v[i])=='T' || c.getCoorMapa(v[i])=='L')){
            ret=i;
            encontrada=true;
            coor=v[i];
        }
    }
    return ret;
}