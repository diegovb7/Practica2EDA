OBJETOS=InfoTur.o Coordenadas.o Localidad.o Coleccion.o LNear.o Provincia.o
OPS=-std=c++11
All: $(OBJETOS) Crucero

Crucero: Crucero.cc LNear.h
	g++ $(OPS) -g -Wall -o Crucero Crucero.cc $(OBJETOS)

InfoTur.o: InfoTur.h InfoTur.cc
	g++ $(OPS) -g -Wall -c InfoTur.cc

Coordenadas.o: Coordenadas.cc Coordenadas.h
	g++ $(OPS) -g -Wall -c Coordenadas.cc

Localidad.o: Localidad.cc Localidad.h Coordenadas.h InfoTur.h
	g++ $(OPS) -g -Wall -c Localidad.cc

Coleccion.o: Coleccion.cc Coleccion.h Localidad.h
	g++ $(OPS) -g -Wall -c Coleccion.cc

LNear.o: LNear.cc LNear.h Coleccion.h
	g++ $(OPS) -g -Wall -c LNear.cc

Provincia.o: Provincia.cc Provincia.h LNear.h
	g++ $(OPS) -g -Wall -c Provincia.cc
	
clean:
	rm -rf *.o *~ Crucero 
