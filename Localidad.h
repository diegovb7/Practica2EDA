#ifndef LOCALIDAD_h
#define LOCALIDAD_h
#include "Coordenadas.h"
#include "InfoTur.h"
#include <iostream> 
#include <string> 
#include <vector>

using namespace std;

class Localidad{
    private:
        string nombre;
        Coordenadas coor;
        InfoTur info;
        int id;

    public:
        Localidad();
        Localidad(string n);
        Localidad(const Localidad &);
        ~Localidad();
        Localidad & operator=(const Localidad &);
        int setCoor(int, int, vector<vector<char> > &);
        void setInfo(InfoTur );
        string getNombre();
        Coordenadas & getCoor();
        InfoTur & getInfo();
        int getId();

        friend ostream & operator<<(ostream &, const Localidad &);
};


#endif
