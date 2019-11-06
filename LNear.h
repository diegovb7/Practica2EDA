#include "Coleccion.h"

class LNear{
    //parte privada de la lista
    private:
        class NodoL{
            //segun los apuntes de como se crea una lista, la subclase de nodo no debe tener una parte privada
            public:
                Localidad localidad;
                int distancia;
                NodoL *next;
                NodoL *prev;

            
            //tiene que haber un constructor por defecto de NodoL?
                NodoL(){
                    localidad=Localidad();
                    distancia=-1;
                    next=NULL;
                    prev=NULL;
                }

                NodoL(Localidad l){
                    localidad=l;
                    distancia=-1;
                    next=NULL;
                    prev=NULL;
                }  

                NodoL(const NodoL &n){
                    localidad=n.localidad;
                    distancia=n.distancia;
                    next=n.next;
                    prev=n.prev;
                }

                NodoL & operator=(const NodoL &n){
                    if(this!=&n){
                        localidad=n.localidad;
                        distancia=n.distancia;
                        next=n.next;
                        prev=n.prev;
                    }
                    return *this;
                }

                ~NodoL(){
                    localidad=Localidad();
                    distancia=-1;
                    next=NULL;
                    prev=NULL;
                }
                
                friend ostream & operator<<(ostream &os, NodoL &n){
                    os<<n.localidad.getNombre()<<" ("<<n.distancia<<")";

                    return os;
                }
                
                /*
                NodoL();
                NodoL(Localidad );
                NodoL(const NodoL &);
                NodoL & operator=(const NodoL &);
                ~NodoL();
                */
                //friend ostream & operator<<(ostream &, const NodoL &);

        };
        NodoL *pr;
        NodoL *ul;
        Localidad error;
    //comienzo de la parte publica de la clase
    public:
    //constructor por defecto, con parametros, copia, destructor, asignacion
        LNear();
        ~LNear();
        LNear(const LNear &);
        LNear & operator=(const LNear &);
        bool esVacia();
        int rango();
        void insertaLocalidad(Localidad , int );
        int borraLocalidad(string );
        void borraLocalidades(int );
        Localidad & getLocalidad(int );

        friend ostream & operator<<(ostream &, const LNear &);

};
/*
class LNear::NodoL{
    private:
        Localidad localidad;
        int distancia;
        NodoL *next;
        NodoL *prev;

    public:
    //tiene que haber un constructor por defecto de NodoL?
        NodoL(){
            localidad=Localidad();
            distancia=-1;
            next=NULL;
            prev=NULL;
        }

        NodoL(Localidad l){
            localidad=l;
            distancia=-1;
            next=NULL;
            prev=NULL;
        }  

        NodoL(const NodoL &n){
            localidad=n.localidad;
            distancia=n.distancia;
            next=n.next;
            prev=n.prev;
        }

        NodoL & operator=(const NodoL &n){
            if(this!=&n){
                localidad=n.localidad;
                distancia=n.distancia;
                next=n.next;
                prev=n.prev;
            }
        }

        ~NodoL(){
            localidad=Localidad();
            distancia=-1;
            next=NULL;
            prev=NULL;
        }

        int getDistancia(){
            return distancia;
        }

        void setDistancia(int d){
            distancia=d;
        }

        Localidad & getLocalidad(){
            return localidad;
        }

        NodoL & getNext(){
            return *next;
        }

        NodoL & getPrev(){
            return *prev;
        }

        friend ostream & operator<<(ostream &os, const NodoL &n){
            os<<n.localidad<<" ("<<n.distancia<<")";

            return os;
        }
        
        NodoL();
        NodoL(Localidad );
        NodoL(const NodoL &);
        NodoL & operator=(const NodoL &);
        ~NodoL();
        
        //friend ostream & operator<<(ostream &, const NodoL &);

};
*/
