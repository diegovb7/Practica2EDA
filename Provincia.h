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

        friend ostream & operator<<(ostream &, Provincia & );

};