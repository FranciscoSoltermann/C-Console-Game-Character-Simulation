//
// Created by Dakot on 13/11/2021.
//

#ifndef MAIN_CPP_MENU_H
#define MAIN_CPP_MENU_H
#define MENU_OP_SALIDA 9
#define MENU_NUM_INICIAL 0
#define MENU_OP_UNO 1
#define MENU_OP_DOS 2
#define MENU_OP_TRES 3
#define MENU_OP_CUATRO 4
#define MENU_OP_CINCO 5

#define BINARIO_ITERATIVO_MENU_OPN 112
#define BINARIO_RECURSIVO_MENU_OPN 122
#define BINARIO_ITERATIVO_VDEF_MENU_OPN 111
#define BINARIO_RECURSIVO_VDEF_MENU_OPN 121
#define SUMA_TRIANGULAR_VDEF_MENU_OPN 151
#define SUMA_TRIANGULAR_MENU_OPN 152
#define MALA_SUERTE_ITERATIVO_MENU_OPN 132
#define MALA_SUERTE_ITERATIVO_VDEF_MENU_OPN 131
#define MALA_SUERTE_RECURSIVO_MENU_OPN 142
#define MALA_SUERTE_RECURSIVO_VDEF_MENU_OPN 141

#include <iostream>
#include "utils.h"
#include "usuarios.h"
#include "juegos.h"

struct Menu {
    int MenuInicial;
    int SubMenu;
    int SubMenuFinal;
    int Opcion;
    int TotalOpciones;
    int PosicionY;
    bool hayError;
};

void menu();

void MostrarOpcionesDeMenu(bool, Menu &, Usuario *);

void EjecutarPorOpcionAlgoritmo(Menu &);

void EjecutarPorOpcionJuego(Menu &);

std::string MostrarTituloMenuAlgoritmo(int);

void LogicaDeSalida(Menu &);


void logoUTN();

void logoGrupo();

void logo();

void MostrarEstrategiaDeResolucion(const int &, int &);

void EnteroABin_Iterativo();

void numerosMalaSuerte_iterativa();

void numerosMalaSuerte_recursiva();

void numerosMalaSuerte(unsigned long long int &x, bool &y);

void EnteroABin_Recursiva();

void enteroBinarioRecurEje(long long int);

void sumaTriangular();

unsigned long long int sumaTriangular_iter(unsigned long long int);



#endif //MAIN_CPP_MENU_H
