#include <iostream>
#include "Provincia.h"

int main(int argc, char *argv[]){
    /*
    Coleccion colec=Coleccion();
    colec.lectura(argv[1]);
    cout<<"La coleccion es: "<<endl<<colec<<endl;
    cout<<colec.getLocalidades().size()<<endl;
    Provincia pr(colec.getLocalidades()[1]);
    cout<<pr.getCostera(colec)<<endl;
    */
   Coleccion colec=Coleccion();
	string muestra;
	
	colec.lectura(argv[1]);
    cout<<colec;

	for(unsigned int i=0;i<colec.getLocalidades().size();i++){
		string nombre=colec.getLocalidades()[i].getNombre();
		Coordenadas coor=colec.getLocalidades()[i].getCoor();
		string relevante=colec.getLocalidades()[i].getInfo().getMasFrecuente();
		string top=colec.getLocalidades()[i].getInfo().getTop();
		if(top!=""){
			cout<<nombre<<" "<<coor<<": "<<relevante<<" - "<<top<<endl;
		}
		else{
			cout<<nombre<<" "<<coor<<": "<<relevante<<endl;
		}
	}
}