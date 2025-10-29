#include "juegos.h"

void MostrarSalida(const Score &score);

using namespace std;

void juegos() {
    Personaje mario, luigi;
    char tablero[FILAS][COLUMNAS];
    char vacio[FILAS][COLUMNAS];
    cargarMatriz(vacio, ' ');
    cargarTablero(tablero);
    comparar(vacio, tablero);

    do {
        mario = crearpersonaje("Mario");
    } while (tablero[mario.celda.i][mario.celda.j] == 'X');

    do {
        luigi = crearpersonaje("Luigi");
    } while (mario.celda.j == luigi.celda.j or tablero[luigi.celda.i][luigi.celda.j] == 'X');

    mostrarSimulacion(tablero, mario, luigi);
}

void comparar(char vacio[][COLUMNAS], char tablero[][COLUMNAS]) {
    int filas, columnas, y = 0;
    Score score{0};
    bool hayError = false;
    do {
        system("cls");
        cout << CreateText("Juego mario BROS | SIMULACIÓN A\n", y, true, 0, 0);
        mostrarMatriz(vacio);
        cout << "\n\nDebes descubrir los obstáculos indicando las coordenadas i y j en las que se encuentran!\n\n";
        MostrarMarcador(score);
        cout << "Ingresa el valor de la coordenada i (o 99 para terminar el juego): ";
        MostrarMensajeCondicional(hayError, MENU_INVALIDA, y);
        if (hayError)EstablecerTituloVentana(APP_NAME" | Juego Super Mario Bros - Simulación A");
        cin >> filas;
        hayError = (filas > MAXIMO || filas < 0) && filas != EXIT_STATUS;
        if (!hayError) {
            if (filas == EXIT_STATUS) {
                cout << "Tu puntaje final es: " << score.aciertos << endl;
                system("pause");
                system("cls");
                MostrarLogo();
                system("pause");
                system("cls");

            } else {
                cout << "Ingresa el valor de la coordenada j: ";
                cin >> columnas;
                hayError = (columnas > MAXIMO || columnas < 0);
                if (!hayError) {
                    if ((tablero[filas][columnas] == '^' || tablero[filas][columnas] == 'X') &&
                        (vacio[filas][columnas] != '^' && vacio[filas][columnas] != 'X')) {
                        score.aciertos++;
                        cout << "Acierto" << endl;
                        if (filas < AVE_STATUS) {
                            vacio[filas][columnas] = '^';
                        } else
                            vacio[filas][columnas] = 'X';
                        if (score.aciertos == WIN_STATUS) {
                            cout << CreateText("Felicidades pasaste el juego!!", y, false, FOREGROUNDBLUE,
                                               BACKGROUNDWHITE);
                            system("cls");
                        }
                    } else if ((vacio[filas][columnas] != '^' && vacio[filas][columnas] != 'X')) {
                        score.fallos++;
                        if (filas < AIRE_STATUS) {
                            cout << "Aire" << endl;
                            vacio[filas][columnas] = '.';
                        } else {
                            cout << "Tierra" << endl;
                            vacio[filas][columnas] = '_';
                        }
                        system("pause");
                    }
                }
                score.intentos++;
            }
        }
    } while (score.aciertos != WIN_STATUS && filas != EXIT_STATUS);
}

void MostrarMarcador(Score score) {
    int y = 0;
    cout << "---------- Marcador ----------\n";
    cout << "==============================\n";
    cout << CreateText("", y, false, FOREGROUNDBLUE, BACKGROUNDWHITE);
    cout << "| Intentos: " << score.intentos << setw(10) << setfill(' ') << "|\n";
    cout << "| Aciertos: " << score.aciertos << setw(10) << setfill(' ') << "|\n";
    cout << "| Fallados: " << score.fallos << setw(10) << setfill(' ') << "|\n";
    cout << restoreConsole();
    cout << "==============================" << endl;
}

void MostrarLogo() {
    cout << "Ahora revelaremos el Reino Champignon y comenzará la simulación del encuentro de hermanos!\n"
            "\n"
            "  _____      _                _____ _                           _\n"
            " |  __ \\    (_)              / ____| |                         (_)\n"
            " | |__) |___ _ _ __   ___   | |    | |__   __ _ _ __ ___  _ __  _  __ _ _ __   ___  _ __\n"
            " |  _  // _ \\ | '_ \\ / _ \\  | |    | '_ \\ / _` | '_ ` _ \\| '_ \\| |/ _` | '_ \\ / _ \\| '_ \\\n"
            " | | \\ \\  __/ | | | | (_) | | |____| | | | (_| | | | | | | |_) | | (_| | | | | (_) | | | |\n"
            " |_|  \\_\\___|_|_| |_|\\___/   \\_____|_| |_|\\__,_|_| |_| |_| .__/|_|\\__, |_| |_|\\___/|_| |_|\n"
            "                                                         | |       __/ |       Simulación\n"
            "                                                         |_|      |___/\n";
}

void mostrarSimulacion(char tablero[][COLUMNAS], Personaje &mario, Personaje &luigi) {
    bool ultimapos, caida = false;

    tablero[mario.celda.i][mario.celda.j] = 'M';
    tablero[luigi.celda.i][luigi.celda.j] = 'L';
    mostrarMatriz(tablero);
    mostrarEstado(mario);
    do {
        if (tablero[mario.celda.i][posig(mario)] == 'X') {
            sortearobstaculo(mario, tablero, 'M', caida);
            ultimapos = true;
        } else {
            moverse(mario, tablero);
            mario.puntaje++;
            ultimapos = true;
            mostrarMatriz(tablero);
            mostrarEstado(mario);
        }

        if (abs(mario.celda.j - luigi.celda.j) != 1) {
            if (tablero[luigi.celda.i][posig(luigi)] == 'X') {
                sortearobstaculo(luigi, tablero, 'L', caida);
                ultimapos = false;
            } else {
                moverse(luigi, tablero);
                luigi.puntaje++;
                ultimapos = false;
                mostrarMatriz(tablero);
                mostrarEstado(luigi);
            }
        }

    } while (abs(mario.celda.j - luigi.celda.j) != 1);
    FinDeJuego(caida, ultimapos, tablero, mario, luigi);
}

void FinDeJuego(bool caida, bool ultimapos, char tablero[][COLUMNAS], const Personaje &mario, const Personaje &luigi) {
    if (luigi.celda.i == 9 && tablero[luigi.celda.i][luigi.celda.j] != 'B' &&
        tablero[luigi.celda.i][luigi.celda.j] != 'X')
        tablero[luigi.celda.i][luigi.celda.j] = '_';
    else if (tablero[luigi.celda.i][luigi.celda.j] != 'B' && tablero[luigi.celda.i][luigi.celda.j] != 'X')
        tablero[luigi.celda.i][luigi.celda.j] = '.';
    if (mario.celda.i == 9 && tablero[mario.celda.i][mario.celda.j] != 'B' &&
        tablero[mario.celda.i][mario.celda.j] != 'X')
        tablero[mario.celda.i][mario.celda.j] = '_';
    else if (tablero[mario.celda.i][mario.celda.j] != 'B' && tablero[mario.celda.i][mario.celda.j] != 'X')
        tablero[mario.celda.i][mario.celda.j] = '.';
    if (!caida) {
        if (ultimapos && tablero[9][posig(luigi)] != 'X') {
            tablero[9][posig(luigi)] = 'B';
        } else if (tablero[9][posig(mario)] != 'X') {
            tablero[9][posig(mario)] = 'B';
        }
    }
    system("cls");
    mostrarMatriz(tablero);
    MostrarMensajeFinDeJuego(mario.puntaje, luigi.puntaje);
}

void MostrarMensajeFinDeJuego(int pmario, int pluigi) {
    int y = 0;
    cout << "Los hermanos se han unido!" << endl << endl;
    cout << "Hola, soy Luigi" << endl;
    cout << "Hola, soy Mario" << endl << endl;
    cout << "Movimiento de ";
    cout << CreateText("Mario", y, false, FOREGROUNDGREEN, BACKGROUNDWHITE);
    cout << ": " << pmario << endl << "Movimientos de ";
    cout << CreateText("Luigi", y, false, FOREGROUNDRED, BACKGROUNDWHITE);
    cout << ": " << pluigi << endl << endl;

    if (pluigi > pmario) {
        cout << CreateText("Mario", y, false, FOREGROUNDGREEN, BACKGROUNDWHITE);
        cout << " es el ganador!";
    } else if (pluigi < pmario) {
        cout << CreateText("Luigi", y, false, FOREGROUNDRED, BACKGROUNDWHITE);
        cout << " es el ganador!";
    } else cout << "FUE UN EMPATE";
    cout << endl;
    system("pause");
    system("cls");
}
