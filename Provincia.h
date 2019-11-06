#include "LNear.h"

class Provincia{
    private:
        Localidad lc;
        LNear locprox;

    public:
        Provincia();
        Provincia(Localidad );
        Provincia(const Provincia &);
        ~Provincia();
        Provincia & operator=(const Provincia &);
        void calculaCercanas(Coleccion &, int );
        int borraLocalidad(string );
        LNear & getCercanas();
        string getCostera(Coleccion & );
        LNear getCosteras(Coleccion & );
        string getConAeropuerto();

        friend ostream & operator<<(ostream &, Provincia & );

};