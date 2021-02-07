#include "Provincia.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

bool esCostera(Coleccion &, Localidad l);
int vista0(vector<Coordenadas> &, Coordenadas &, Coleccion &);
vector<Coordenadas> cambiarCoordenadas(Coordenadas &, Coordenadas &, Coordenadas &, Coordenadas &, Coordenadas &, Coordenadas &, Coordenadas &, Coordenadas &, Coordenadas &);

int main(int argc, char *argv[]){
    //jhfdjghdf
    //comentario
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
            inicio=p;
        }else{
            Provincia aux(p.getCosteras(c).getLocalidad(0));
            inicio=aux;
            cout<<c.getLocalidades()[0].getNombre()<<" "<<p.getCosteras(c).getLocalidad(0).getNombre()<<" "<<p.calculaDistancia(c.getLocalidades()[0], p.getCosteras(c).getLocalidad(0))<<endl;
        }
        
        Coordenadas d0;
        Coordenadas d1;
        Coordenadas d2;
        Coordenadas d3;
        Coordenadas d4;
        Coordenadas d5;
        Coordenadas d6;
        Coordenadas d7;
        vector<Coordenadas> vector_inicial;
        vector_inicial=cambiarCoordenadas(d0, d1, d2, d3, d4, d5, d6, d7, inicio.getLocalidad().getCoor());
        int direccion_inicial=0;
        Coordenadas nuevaCoordenada=inicio.getLocalidad().getCoor();
        direccion_inicial=vista0(vector_inicial, nuevaCoordenada, c);
        
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
                vector_inicial.clear();
                vector_inicial=cambiarCoordenadas(d0, d1, d2, d3, d4, d5, d6, d7, nuevaCoordenada);
                direccion_inicial=(direccion_inicial+5)%8;
                while(c.getCoorMapa(vector_inicial[direccion_inicial])=='M'){
                    direccion_inicial=(direccion_inicial+1)%8;
                }
                nuevaCoordenada=vector_inicial[direccion_inicial];
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
    if(c.getCoorMapa(v[7])=='M' && !coordenada_encontrada && (c.getCoorMapa(v[0])=='T' || c.getCoorMapa(v[0])=='L')){
        ret=0;
        coor=v[0];
    }
    return ret;
}
