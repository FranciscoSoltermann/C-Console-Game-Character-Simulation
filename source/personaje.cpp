#include "personaje.h"

using namespace std;

void caminar(Personaje &p) {
    if (p.orientacion == 'D') {
        p.celda.j++;
    } else {
        p.celda.j--;
    }
}

void girar(Personaje &p) {
    if (p.orientacion == 'D') {
        p.orientacion = 'I';
    } else {
        p.orientacion = 'D';
    }
}

Personaje crearpersonaje(string nombre) {
    srand(time(nullptr));
    Personaje p;
    p.nombre = std::move(nombre);
    p.celda.i = FILAS - 1;
    p.celda.j = rand() % COLUMNAS;
    if ((rand() % 2) == 1)
        p.orientacion = 'D';
    else
        p.orientacion = 'I';
    p.puntaje = 0;
    return p;
}

void trepar(Personaje &p) {
    p.celda.i--;
}

void saltar(Personaje &p) {
    if (p.orientacion == 'D') {
        p.celda.j++;
        p.celda.i--;
    } else {
        p.celda.j--;
        p.celda.i--;
    }
}

void caer(Personaje &p) {
    if (p.orientacion == 'D') {
        p.celda.j++;
        p.celda.i = 9;
    } else {
        p.celda.j--;
        p.celda.i = 9;
    }

}

void mostrarEstado(const Personaje &p) {
    int y=0;
    cout << "\n\n---------- Estado ----------\n";
    cout << "==============================\n";
    int color = p.nombre[0] == 'M' ? FOREGROUNDGREEN : FOREGROUNDRED;
    char a[5];
    if (p.orientacion == 'D') {
        strncpy(a, "Der", strlen("Der"));
    } else {
        strncpy(a, "Izq", strlen("Izq"));
    }
    cout << CreateText("", y, false, color, BACKGROUNDWHITE);
    cout << "| Turno de: " << p.nombre << setw(15) << setfill(' ') << "|\n";
    cout << "| Orientación: " << a << setw(14) << setfill(' ') << "|\n";
    cout << "| Movimientos: " << p.puntaje << setw(16 - (p.puntaje > 9 ? 1 : 0)) << setfill(' ') << "|\n";
    cout << restoreConsole();
    cout << "==============================" << endl;
#if defined WIN32 || defined _WIN32 || defined WIN64 || defined _WIN64
    Sleep(1500);
#else
    sleep(2);
#endif

    system("cls");
}

void sortearobstaculo(Personaje &p, char tablero[FILAS][COLUMNAS], char t, bool &caida) {
    if (tablero[p.celda.i - 2][posig(p)] == 'X') {
        tablero[p.celda.i][p.celda.j] = '_';
        trepar(p);
        p.puntaje++;
        tablero[p.celda.i][p.celda.j] = t;
        mostrarMatriz(tablero);
        mostrarEstado(p);

        tablero[p.celda.i][p.celda.j] = '.';
        trepar(p);
        p.puntaje++;
        tablero[p.celda.i][p.celda.j] = t;
        mostrarMatriz(tablero);
        mostrarEstado(p);

        tablero[p.celda.i][p.celda.j] = '.';
        saltar(p);
        p.puntaje++;
        tablero[p.celda.i][p.celda.j] = t;
        mostrarMatriz(tablero);
        mostrarEstado(p);
        tablero[p.celda.i][p.celda.j] = '.';
        if (tablero[9][posig(p)] == 'M' or tablero[9][posig(p)] == 'L') {
            tablero[9][posig(p)] = 'B';
            caida = true;
            mostrarMatriz(tablero);
        } else {
            caer(p);
            p.puntaje++;
            tablero[p.celda.i][p.celda.j] = t;
            mostrarMatriz(tablero);
        }

    } else if (tablero[p.celda.i - 1][posig(p)] == 'X') {
        tablero[p.celda.i][p.celda.j] = '_';
        trepar(p);
        p.puntaje++;
        tablero[p.celda.i][p.celda.j] = t;
        mostrarMatriz(tablero);
        mostrarEstado(p);

        tablero[p.celda.i][p.celda.j] = '.';
        saltar(p);
        p.puntaje++;
        tablero[p.celda.i][p.celda.j] = t;
        mostrarMatriz(tablero);
        mostrarEstado(p);
        tablero[p.celda.i][p.celda.j] = '.';
        if (tablero[9][posig(p)] == 'M' or tablero[9][posig(p)] == 'L') {
            tablero[9][posig(p)] = 'B';
            caida = true;
            mostrarMatriz(tablero);
        } else {
            caer(p);
            p.puntaje++;
            tablero[p.celda.i][p.celda.j] = t;
            mostrarMatriz(tablero);
        }
    } else if (tablero[p.celda.i][posig(p)] == 'X') {
        tablero[p.celda.i][p.celda.j] = '_';
        saltar(p);
        p.puntaje++;
        tablero[p.celda.i][p.celda.j] = t;
        mostrarMatriz(tablero);
        mostrarEstado(p);
        tablero[p.celda.i][p.celda.j] = '.';
        if (tablero[9][posig(p)] == 'M' or tablero[9][posig(p)] == 'L') {
            tablero[9][posig(p)] = 'B';
            caida = true;
            mostrarMatriz(tablero);
        } else {
            caer(p);
            p.puntaje++;
            tablero[p.celda.i][p.celda.j] = t;
            mostrarMatriz(tablero);
        }
    }
    mostrarEstado(p);
}

void moverse(Personaje &p, char tablero[][COLUMNAS]) {
    caminar(p);
    if (p.celda.j == COLUMNAS or p.celda.j == -1) {
        girar(p);
        caminar(p);
        tablero[p.celda.i][p.celda.j] = p.nombre[0];
    } else {
        tablero[p.celda.i][p.celda.j] = p.nombre[0];
        if (p.orientacion == 'D') {
            tablero[p.celda.i][(p.celda.j) - 1] = '_';
        } else
            tablero[p.celda.i][(p.celda.j) + 1] = '_';
    }
}

int posig(const Personaje &p) {

    if (p.orientacion == 'D')
        return p.celda.j + 1;
    else
        return p.celda.j - 1;

}
