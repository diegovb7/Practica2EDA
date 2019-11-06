#include "Coleccion.h"
#include <fstream>
#include <string.h>
#include <sstream>
#include <cstdlib>

Coleccion::~Coleccion(){
   mapa.clear();
   localidades.clear();
}

Coleccion::Coleccion(const Coleccion &c){
    mapa=c.mapa;
    localidades=c.localidades;
}

Coleccion & Coleccion::operator=(const Coleccion &c){
    if(this!=&c){
        mapa=c.mapa;
        localidades=c.localidades;
    }
    return *this;
}

/*

COMPROBAR TODO ESTE METODO NO SE SI ESTA BIEN DA MIL ERRORES


*/
void Coleccion::lectura(string n){
    ifstream fichero(n.c_str());
    string linea;
    getline(fichero, linea);
    int mu=0, mo=0, ho=0, re=0;
    bool ae=false;
    string top="";
    while(linea!="<LOCALIDAD>" && !fichero.eof()){
        int size = linea.length();
        char cadena_char[size]; // preguntar a alicia como se usa el c_str() adecuadamente
        strcpy(cadena_char, linea.c_str());
        vector<char> linea_mapa;
        for(unsigned int i=0;i<sizeof(cadena_char);i++){
            linea_mapa.push_back(cadena_char[i]); //voy metiendo elementos en el vector auxiliar para guardar la fila del mapa
        }
        mapa.push_back(linea_mapa); //añado el vector auxiliar al vector del mapa final
        getline(fichero, linea);
    }
    //hemos leido y guardado el mapa
    while(getline(fichero, linea)){//leemos el nombre de la localidad
        if(linea=="<LOCALIDAD>"){ //en el caso de que hayamos leido localidad, volvemos a leer
            getline(fichero, linea);
        }
        Localidad loc(linea); //creamos el objeto localidad con el nombre leido
        getline(fichero, linea); //leemos las coordenadas de la localidad
        istringstream isstream(linea); //creamos el string stream para separar las cadenas
        vector<int> vector_coor; //creamos un vector para meter las cosas que vamos separando
        while(!isstream.eof()){
            string temp;
            isstream>>temp; //asignamos a temp la subcadena
            int aux=atoi(temp.c_str()); //convertimos de string a int 
            vector_coor.push_back(aux); //añadimos al final del vector el int asociado a la subcadena
        }
        loc.setCoor(vector_coor[0], vector_coor[1], mapa); //creamos la coordenada de la localidad con dos primeros numeros de las coordenadas
        getline(fichero, linea); //aqui leemos la linea <INFO>
         //aqui leemos la primera linea de la informacion
        while(getline(fichero, linea) && linea!="<LOCALIDAD>"){
            //if(linea!="<LOCALIDAD>"){
                istringstream isstream(linea);
                vector<string> separar_info;
                while(!isstream.eof()){
                    string temp2;
                    isstream>>temp2;
                    separar_info.push_back(temp2);
                }

                if(separar_info[0]=="museo"){
                    mu=atoi(separar_info[1].c_str());
                }
                else{
                    if(separar_info[0]=="monumento"){
                        mo=atoi(separar_info[1].c_str());
                    }
                    else{
                        if(separar_info[0]=="hotel"){
                            ho=atoi(separar_info[1].c_str());
                        }
                        else{
                            if(separar_info[0]=="aeropuerto"){
                                ae=true;
                            }
			                 else{
				                if(separar_info[0]=="restaurante"){
				                	re=atoi(separar_info[1].c_str());
				                }
				                else{
                                    if(separar_info[0][0]=='*'){
                                        top=linea;
                                    }
                         	     }
			               }  
                        }
                    }
               // }
            }
            //getline(fichero, linea);
        }
        InfoTur info(mu, mo, ho, re, ae);
        info.setTop(top);
        loc.setInfo(info);
	    if(getCoorMapa(loc.getCoor())=='L'){
            localidades.push_back(loc);
	    }
        mu=0;
        mo=0;
        ho=0;
        re=0;
        ae=false;
        top="";
    }

    fichero.close();
}

vector<vector<char> > & Coleccion::getMapa(){
    return mapa;
}

vector<Localidad> & Coleccion::getLocalidades(){
    return localidades;
}

char Coleccion::getCoorMapa(Coordenadas coor){
    char ret='X';
	unsigned int u_fila=coor.getFila();
	unsigned int u_col=coor.getColumna();

    if(coor.getFila()>-1 && u_fila<mapa.size() && coor.getColumna()>-1 && u_col<mapa[0].size()){
        ret=mapa[coor.getFila()][coor.getColumna()];
    }

    return ret;
}

ostream & operator<<(ostream &os, const Coleccion &c){
    string ret="";
    string aux;

    for(unsigned int i=0;i<c.mapa.size();i++){
        for(unsigned int j=0;j<c.mapa[i].size();j++){
            ret=ret+c.mapa[i][j];
        }
        ret=ret+"\n";
    }
	os<<ret;
    for(unsigned int i=0;i<c.localidades.size();i++){
	os<<c.localidades[i];
    }
  

	return os;
}
