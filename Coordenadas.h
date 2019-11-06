#ifndef COORDENADAS_h
#include <iostream> 
#include <string> 
#include <vector>

using namespace std;

class Coordenadas{
    private:
        int fila;
        int columna;

    public:
        Coordenadas(){fila=-1; columna=-1;} // constructor por defecto
        Coordenadas(int f, int c); // constructor por parametros
        Coordenadas(const Coordenadas &);
        ~Coordenadas();
        Coordenadas & operator=(const Coordenadas &);
        int getFila();
        int getColumna();

        friend ostream & operator<<(ostream &, const Coordenadas &);

};

#endif