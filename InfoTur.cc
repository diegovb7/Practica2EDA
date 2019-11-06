#include "InfoTur.h"

//constructores

InfoTur::InfoTur( int m, int n, int h, int r, bool a ){
	if(m<0){
		museo=0;
	}
	else{
		museo=m;
	}
	if(n<0){
		monumento=0;
	}
	else{
		monumento=n;
	}
	if(h<0){
		hotel=0;
	}
	else{
		hotel=h;
	}
	if(r<0){
		restaurante=0;
	}
	else{
		restaurante=r;
	}
	/*museo=m;
	monumento=n;
	hotel=h;
	restaurante=r;
	*/
	top="";
	aeropuerto=a;
} 

InfoTur::InfoTur( const InfoTur &t ){
	museo=t.museo;
	monumento=t.monumento;
	hotel=t.hotel;
	restaurante=t.restaurante;
	aeropuerto=t.aeropuerto;
	top=t.top;
}

//destructor

InfoTur::~InfoTur(){ 
	museo=0; 
	monumento=0; 
	hotel=0; 
	restaurante=0; 
	aeropuerto=false; 
	top="";
} 

//operadores 

InfoTur & InfoTur::operator=(const InfoTur &t){ 
	if(this!=&t){
		museo=t.museo;
		monumento=t.monumento;
		hotel=t.hotel;
		restaurante=t.restaurante;
		aeropuerto=t.aeropuerto;
		top=t.top;
	}
	
	return *this;
} 

bool InfoTur::operator!=(const InfoTur &t){
	bool ret=false;

	if(museo!=t.museo || monumento!=t.monumento || hotel!=t.hotel || restaurante!=t.restaurante ||
	 aeropuerto!=t.aeropuerto || top!=t.top){
		ret=true;
	}

	return ret;
} 
bool InfoTur::operator==(const InfoTur &t){
	bool ret=false;

	if(museo==t.museo && monumento==t.monumento && hotel==t.hotel && restaurante==t.restaurante &&
		aeropuerto==t.aeropuerto && top==t.top){
		ret=true;
	}

	return ret;
}

//metodos

vector<int> InfoTur::getInfoTur() { 
	vector<int> v(5);
	v[0]=museo;
	v[1]=monumento;
	v[2]=hotel;
	v[3]=restaurante;
	if(aeropuerto){
		v[4]=1;
	}
	else{
		v[4]=0;
	}

	return v;
}  
string InfoTur::getMasFrecuente() { 
	string ret;
	vector<int> v=getInfoTur();
	vector<int> s(5);
	int pos=0;

	s[0]=v[4];
	s[1]=v[2];
	s[2]=v[1];
	s[3]=v[0];
	s[4]=v[3];

	for(int i=0;i<5;i++){
		if(s[pos]<s[i]){
			pos=i;
		}
	}

	switch(pos){
		case 0: ret="aeropuerto";
			break;
		case 1: ret="hotel";
			break;
		case 2: ret="monumento";
			break;
		case 3: ret="museo";
			break;
		case 4: ret="restaurante";
			break;
	}

	return ret;
} 

bool InfoTur::getAeropuerto(){
	return aeropuerto;
}

string InfoTur::getTop() {
	return top;
} 

void InfoTur::setTop( string s ){ 
	top=s;
}

ostream & operator<<(ostream &os, const InfoTur &c){ //funcion amiga sobrecarga del operador salida 
	os << c.museo << " " << c.monumento << " " << c.hotel << " " << c.restaurante << " " << c.aeropuerto << " " << c.top << endl;
	return os;
}