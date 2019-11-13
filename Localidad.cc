#include "Localidad.h"

Localidad::Localidad(){
    nombre="";
    id=-1;
    coor=Coordenadas();
    info=InfoTur();
}

Localidad::Localidad(string n){
    nombre=n;
    id=-1;
}

Localidad::Localidad(const Localidad &l){    
    nombre=l.nombre;
    coor=l.coor;
    info=l.info;
    id=l.id;    
}

Localidad::~Localidad(){
    nombre="";
    id=-1;
    coor=Coordenadas();
    info=InfoTur();
}

Localidad & Localidad::operator=(const Localidad &l){
    if(this!=&l){
        nombre=l.nombre;
        coor=l.coor;
        info=l.info;
        id=l.id;
    }
    return *this;
}

bool Localidad::esCostera(Coleccion &c){
    bool ret=false;
    bool m_arriba=false, m_abajo=false, m_izquierda=false, m_derecha=false;

    
    if(getCoor().getFila()-1>-1 && c.getMapa()[getCoor().getFila()-1][getCoor().getColumna()]=='M'){
        m_arriba=true;
    }

    unsigned int u_f1=getCoor().getFila()+1;

    if(u_f1<c.getMapa().size() && c.getMapa()[getCoor().getFila()+1][getCoor().getColumna()]=='M'){
        m_abajo=true;
    }

    if(getCoor().getColumna()-1>-1 && c.getMapa()[getCoor().getFila()][getCoor().getColumna()-1]=='M'){
        m_izquierda=true;
    }

    unsigned int u_c1=getCoor().getColumna()+1;

    if(u_c1<c.getMapa()[0].size() && c.getMapa()[getCoor().getFila()][getCoor().getColumna()+1]=='M'){
        m_derecha=true;
    }

    if(m_arriba || m_abajo || m_izquierda || m_derecha){
        ret=true;
    }
    
    return ret;
}

int Localidad::setCoor(int f, int c, vector<vector<char> > &mapa){
    int ret=-1;
	unsigned int u_f=f;
	unsigned int u_c=c;
    if(coor.getFila()==-1 && coor.getColumna()==-1 && f>-1 && u_f<mapa.size() && c>-1 && u_c<mapa[0].size()){
        if(mapa[f][c]=='T'){
            coor=Coordenadas(f,c);
            mapa[f][c]='L';
            id=mapa[0].size()*f+c;
            ret=id;
        }
    }
	return ret;
}

void Localidad::setInfo(InfoTur inf){
    info=inf;
}

string Localidad::getNombre(){
    return nombre;
}

Coordenadas & Localidad::getCoor(){
    return coor;
}

InfoTur & Localidad::getInfo(){
    return info;
}

int Localidad::getId(){
    return id;
}

ostream & operator<<(ostream &os, const Localidad &l){
    os << l.id << "-" << l.nombre << "-" << l.coor << endl << l.info;
	return os;
}
