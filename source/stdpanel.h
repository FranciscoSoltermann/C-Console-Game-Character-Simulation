#include <iostream>
#include <cstdlib>
#include <ctime>
#include "utils.h"

#define CANT_AVES 10
#define CANT_PIEDRAS 5
#define MAXIMO 20
#define COLUMNAS 20
#define FILAS 10
#define AIRE_STATUS 9
#define AVE_STATUS 7

void cargarTablero(char [][MAXIMO]); // carga el tablero recibido por par�metro con piedras y aves
void cargarObstaculos(char tablero[][MAXIMO], const int tamanio_obstaculos[], bool tipo, int filas, int columnas);

bool disponible(char tablero[][MAXIMO], int j, int filas);

void cargarMatriz(char[][MAXIMO], char);

void mostrarMatriz(char[FILAS][MAXIMO]);

void MostrarColorML(char k);
