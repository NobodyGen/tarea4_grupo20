all: Tarea4

Tarea4: Main.o Funciones.o Arboles.o
	g++ -Wall -o Tarea4 Main.o Funciones.o Arboles.o

Main.o: Main.cpp Funciones.h
	g++ -Wall -c Main.cpp
	
Funciones.o: Funciones.cpp Funciones.h
	g++ -Wall -c Funciones.cpp

Arboles.o: Arboles.cpp Funciones.h
	g++ -Wall -c Arboles.cpp

clean:
	rm *.o*~