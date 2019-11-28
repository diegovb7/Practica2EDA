#ifndef PROVINCIA_h
#define PROVINCIA_h
#include "LNear.h"

class Provincia{
    private:
        Localidad lc;
        LNear locprox;
        LNear costeras;

    public:
        Provincia();
        Provincia(Localidad );
        Provincia(const Provincia &);
        ~Provincia();
        Provincia & operator=(const Provincia &);
        int calculaDistancia(Localidad, Localidad );
        void calculaCercanas(Coleccion &, int );
        int borraLocalidad(string );
        LNear & getCercanas();
        bool esCostera(Coleccion &, Localidad );
        vector<Localidad> vectorCosteras(Coleccion &);
        string getCostera(Coleccion & );
        LNear getCosteras(Coleccion & );
        string getConAeropuerto();
        bool soyCostera(Coleccion &);
        Localidad & getLocalidad();
        Localidad getLocalidadSR();

        friend ostream & operator<<(ostream &, Provincia & );

};
#endif