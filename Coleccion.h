#ifndef COLECCION_h
#define COLECCION_h
#include "Localidad.h"
#include <iostream> 
#include <string> 
#include <vector>

using namespace std;

class Coleccion{
    private:
        vector<vector<char> > mapa;
        vector<Localidad> localidades;

    public:
        Coleccion(){}
        ~Coleccion();
        Coleccion(const Coleccion &);
        Coleccion & operator=(const Coleccion &);
        void lectura(string);
        vector<vector<char> > & getMapa();
        vector<Localidad> & getLocalidades();
        char getCoorMapa(Coordenadas );

        friend ostream & operator<<(ostream &, const Coleccion &);
};

#endif
