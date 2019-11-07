#ifndef INFOTUR_h //directiva de preprocesamiento para evitar incluir dos veces el fichero #define INFOTUR_h
#define INFOTUR_h
#include <iostream> 
#include <string> 
#include <vector>

using namespace std;

class InfoTur{ 
	private:
	//estructuras que definen la clase
	int museo;
	int monumento;
	int hotel;
	int restaurante;
	bool aeropuerto;
	string top;

	public:
	//declaracion de operaciones canonicas, operadores y metodos
	InfoTur(){museo=0; monumento=0; hotel=0; restaurante=0; aeropuerto=false; top="";} //constructor por defecto
	InfoTur(int mu, int mo, int ho, int r, bool ae); //constructor normal y corriente
	InfoTur(const InfoTur &); //constructor de copia
	~InfoTur(); //destructor que inicializa todos los datos a los por defectos
	InfoTur & operator=(const InfoTur &); //sobrecarga del operador de asignacion. devuelve una copia exacta del objeto

	bool operator!=(const InfoTur &); //sobrecarga del operador !=
	bool operator==(const InfoTur &); //sobrecarga del operador ==
	vector<int> getInfoTur(); //devuelve la infomacion turistica en un vector del mismo orden que se han definido las variables
	string getMasFrecuente(); ////devuelve el elemento turistico del que haya mas cantidad. si hay mas de uno, sera en orden lexico
	void setTop(string n); //actualiza la variable top
	string getTop(); //devuelve la variable top
	bool getAeropuerto();


	//operaciones amigas (friend)
	friend ostream & operator<<(ostream &, const InfoTur &); //devuelve todo separado por espacios y al final un salto.

};
//fin de fichero
#endif
