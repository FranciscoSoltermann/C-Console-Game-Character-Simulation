
#include <string>
#include <iostream>
#include "stdpanel.h"

struct posicion {
    int i, j;
};
struct Personaje {
    std::string nombre;
    posicion celda;
    char orientacion;
    int puntaje;
};

void saludar(Personaje);

void caminar(Personaje &);

void girar(Personaje &);

void trepar(Personaje &);

void saltar(Personaje &);

void caer(Personaje &);

int posig(const Personaje &);

void sortearobstaculo(Personaje &, char [FILAS][COLUMNAS], char, bool &);

void moverse(Personaje &p, char [][MAXIMO]);

void mostrarEstado(const Personaje &personaje);

Personaje crearpersonaje(std::string nombre);
	
	
