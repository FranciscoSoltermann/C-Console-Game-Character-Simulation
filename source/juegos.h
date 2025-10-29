
#include "personaje.h"
#include <cstdlib>
#include <ctime>
#include "stdpanel.h"
#include <iostream>
#include "utils.h"

void juegos();

void comparar(char [][MAXIMO], char[][MAXIMO]);

struct Score {
    int intentos;
    int aciertos;
    int fallos;
};

void MostrarMarcador(Score score);

void MostrarLogo();

void mostrarEstado(const Personaje &personaje);

void MostrarMensajeFinDeJuego(int pmario, int pluigi);

void mostrarSimulacion(char tablero[][20], Personaje &m, Personaje &l);

void FinDeJuego(bool, bool, char [][20], const Personaje &, const Personaje &);
