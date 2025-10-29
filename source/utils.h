//
// Created by Dakot on 15/11/2021.
//

#ifndef MAIN_CPP_UTILS_H
#define MAIN_CPP_UTILS_H
/*
 * ERRORES PARA EL SWITCH
 * */
#define MENU_INVALIDA 54
#define NATURAL_INVALIDO 55
#define ULTIMA_OPORTUNIDAD 57
#define CONFIRMACION_INVALIDA 58
#define REQ_INVALIDO 59
#define ARCHIVO_INVALIDO 60
#define USUARIO_INVALIDO 61
#define USUARIO_INVALIDADO 63
#define PASSWORD_INVALIDA 64
#define USUARIO_REQ_INVALIDO 65
#define CANTIDAD_INVALIDA 66
#define MENU_NODISPONIBLE 67
/*
 * Some old MinGW/CYGWIN distributions don't define this:
 * */

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING  0x0004
#endif

/*
 * EL ARCHIVO DONDE SE GUARDA LOS DATOS
 * */
#define FILE_DATA "./usuarios.dat"

/*
 * NOMBRE DE LA APLICACION
 * */
#define APP_NAME "ALGORUTNOS"
/*
 * DEFINICION DE ANSI CODE PARA TODOS LOS COLORES; CENTRADO; POSICIONAMIENTO.
 * DEFINICION DE ANCHO Y ALTO DE LA VENTANA
 * */

#define ESC "\x1b"
#define CSI ESC"["
#define POSICIONX 50
#define POSICIONY 1
#define MAIN_WIDTH 130
#define MAIN_HEIGHT 40

/*
 *
 * Value    Description                  Behavior
 * 0        Default                     Returns all attributes to the default state prior to modification
 * 1        Bold/Bright                 Applies brightness/intensity flag to foreground color
 * 22       No bold/bright              Removes brightness/intensity flag from foreground color
 * 4        Underline                   Adds underline
 * 24       No underline                Removes underline
 * 7        Negative                    Swaps foreground and background colors
 * 27       Positive (No negative)      Returns foreground/background to normal
 * 30       Foreground Black            Applies non-bold/bright black to foreground
 * 31       Foreground Red              Applies non-bold/bright red to foreground
 * 32       Foreground Green            Applies non-bold/bright green to foreground
 * 33       Foreground Yellow           Applies non-bold/bright yellow to foreground
 * 34       Foreground Blue             Applies non-bold/bright blue to foreground
 * 35       Foreground Magenta          Applies non-bold/bright magenta to foreground
 * 36       Foreground Cyan             Applies non-bold/bright cyan to foreground
 * 37       Foreground White            Applies non-bold/bright white to foreground
 * 38       Foreground Extended         Applies extended color value to the foreground (see details below)
 * 39       Foreground Default          Applies only the foreground portion of the defaults (see 0)
 *
 *
*/
#define FOREGROUNDBLUE 34
#define FOREGROUNDRED 31
#define FOREGROUNDGREEN 32
/*
*
* 40       Background Black            Applies non-bold/bright black to background
* 41       Background Red              Applies non-bold/bright red to background
* 42       Background Green            Applies non-bold/bright green to background
* 43       Background Yellow           Applies non-bold/bright yellow to background
* 44       Background Blue             Applies non-bold/bright blue to background
* 45       Background Magenta          Applies non-bold/bright magenta to background
* 46       Background Cyan             Applies non-bold/bright cyan to background
* 47       Background White            Applies non-bold/bright white to background
* 48       Background Extended         Applies extended color value to the background (see details below)
* 49       Background Default          Applies only the background portion of the defaults (see 0)
*/
#define BACKGROUNDBLUE 44
#define BACKGROUNDWHITE 47
#define BACKGROUNDRED 41

/*
 * LIMITES DE CONTRASEÑA Y USUARIO
 * LIMITE DE CANTIDAD DE USUARIOS TOTAL
 * */

#define PASSWORD_LIMIT_MAX 37
#define PASSWORD_LIMIT_MIN 5
#define USER_LIMIT_MIN 5
#define USER_LIMIT_MAX 10
#define USERS_LIMIT_MAX 100
#define EXIT_STATUS 99
#define WIN_STATUS 21

#include <iostream>
#include <ctime>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <cstring>
#include "usuarios.h"
#include <string>

#if defined WIN32 || defined _WIN32 || defined WIN64 || defined _WIN64

#include <windows.h>

#else
#include <unistd.h>
#endif

/* Recibe un
 * const bool &hayError
 * const int ColorAMostrar
 * const int BackgroundColor
 * const int NumeroDeError
 * */
void MostrarMensajeCondicional(const bool &, int, int &);

std::string CreateText(const std::string &, int &y, bool, const int &, const int &);

void MensajeDeSalida(time_t, int);

void MostrarBarra(int, int &);

void EstablecerTituloVentana(const std::string &);

void moveUp(int positions);

void moveDown(int positions);

void moveRight(int positions);

void moveLeft(int positions);

void moveTo(unsigned int, int &);

void LimpiarPantalla(int &);

void setupConsole();

std::string restoreConsole();

void PausarPantalla(int &);


#endif //MAIN_CPP_UTILS_H
