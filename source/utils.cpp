//
// Created by Dakot on 17/11/2021.
//
/*
* Muestra un mensaje de salida
* Y la duracion de la sesion
* */
#include "utils.h"


using namespace std;

void MensajeDeSalida(time_t t_start, int key) {
    int y = 5;
    LimpiarPantalla(y);
    auto start = std::chrono::system_clock::from_time_t(t_start);
    auto end_now = std::chrono::system_clock::now();
    auto duracion_segundos = std::chrono::duration_cast<std::chrono::seconds>(end_now - start);
    std::chrono::minutes min = std::chrono::duration_cast<std::chrono::minutes>(duracion_segundos);
    long long Minutos = min.count();
    short x = 20;
    moveTo(x, ++y);
    cout << "Hasta luego !!!\n";

    if (key == -2) {
        MostrarBarra(0, y);
        moveRight(x);
        cout << CreateText("Se ha cerrado forzadamente, por posible violacion de seguridad", y, true, FOREGROUNDRED,
                           BACKGROUNDWHITE);
    }
    MostrarBarra(0, y);
    moveTo(x, ++y);
    cout << "Duracion de la sesion " << fixed << setprecision(0) << Minutos << " Minutos y ";
    cout << fixed << setprecision(0) << duracion_segundos.count() - (Minutos * 60) << " segundos" << endl;
    PausarPantalla(y);


}

string CreateText(const string &string1, int &y, bool extraEspaciado, const int &color, const int &background) {
    string string2 = string1;
    if (y > 0) {
        unsigned int x = (MAIN_WIDTH - string1.length()) / 2;
        moveTo(x, y);
        if (string1.length() == 0) y--;
        if (extraEspaciado) ++y;
    }
    if (color > 0 && background > 0) {
        string2 = ESC"[" + to_string(color) + ";" + to_string(background) + "m" + string1;
        if (string1.length() > 0) string2 += restoreConsole();
    }
    return string2;
}

void MostrarBarra(int n, int &y) {
    if (n == 0) n = 50;
    int x = (MAIN_WIDTH - n) / 2;
    if (n == 85)x = 20;
    moveTo(x, y);
    cout << setw(n) << setfill('=') << "=";
}

/*
*
*Utilidades de mostrar errores y posicion.
*
*/
void LimpiarPantalla(int &y) {
    cout << CSI "1;1H" << endl;// Clear screen, tab stops, set, stop at columns 16, 32
    cout << CSI "2J" << endl; // Clear screen
    if (y > 0)y = POSICIONY;
}

void MostrarMensajeCondicional(const bool &hayError, const int NumeroDeError, int &y) {
    int ColorAMostrar = FOREGROUNDRED, ColorBackground = BACKGROUNDWHITE;
    if (hayError) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }
        EstablecerTituloVentana("Hubo un error, UH-OH");
        switch (NumeroDeError) {
            case MENU_INVALIDA:
                cout << CreateText("Opcion invalida:", y, false, ColorAMostrar, ColorBackground);
                cout << CreateText("Intente nuevamente", y, true, ColorAMostrar, ColorBackground);
                break;
            case NATURAL_INVALIDO:
                cout << CreateText("Entrada invalida:", y, false, ColorAMostrar, ColorBackground);
                cout << CreateText("Ingrese un numero entero positivo", y, true, ColorAMostrar, ColorBackground);
                break;
            case CONFIRMACION_INVALIDA:
                cout << CreateText("La confirmacion de contraseña no es correcta", y, true, ColorAMostrar,
                                   ColorBackground);
                break;
            case REQ_INVALIDO:
                cout << CreateText("La contraseña no cumple los requisitos.;", y, true, ColorAMostrar,
                                   ColorBackground);
                cout << CreateText("*No debe contener espacios", y, false, ColorAMostrar, ColorBackground);
                cout << CreateText("*Debe estar entre 6 y 37 caracteres", y, false, ColorAMostrar,
                                   ColorBackground);
                cout << CreateText("*Debe ser únicamente letras sin acentos y numeros.", y, false,
                                   ColorAMostrar, ColorBackground);
                cout << CreateText("*Debe contener como minima una mayúscula, una minúscula y un numero;", y,
                                   true, ColorAMostrar, ColorBackground);
                break;
            case ARCHIVO_INVALIDO:
                cout << CreateText("No se pudo abrir el archivo:", y, false, ColorAMostrar, ColorBackground);
                cout << CreateText(string("Error: ") + strerror(errno), y, true, ColorAMostrar, ColorBackground);
                break;
            case USUARIO_INVALIDO:
                cout << CreateText("El nombre de usuario ya existe", y, true, ColorAMostrar, ColorBackground);
                break;
            case USUARIO_INVALIDADO:
                cout << CreateText("El nombre de usuario es invalido o no existe", y, true, ColorAMostrar,
                                   ColorBackground);
                break;
            case PASSWORD_INVALIDA:
                cout << CreateText("La contraseña es errónea", y, true, ColorAMostrar, ColorBackground);
                break;
            case USUARIO_REQ_INVALIDO:
                cout << CreateText("El usuario no cumple con los requisitos para un nombre de usuario valido", y, true,
                                   ColorAMostrar, ColorBackground);
                cout << CreateText("El usuario debe ser de 6 a 10 caracteres.", y, false, ColorAMostrar,
                                   ColorBackground);
                cout << CreateText("El usuario comenzar con una letra minúscula.", y, false, ColorAMostrar,
                                   ColorBackground);
                cout << CreateText("El usuario debe tener al menos 2 letras mayúsculas.", y, false, ColorAMostrar,
                                   ColorBackground);
                cout << CreateText("El usuario debe tener como maximo 3 digitos.", y, true, ColorAMostrar,
                                   ColorBackground);
                break;
            case CANTIDAD_INVALIDA:
                cout << CreateText(
                        "El registro esta cerrado, el limite es " + to_string(USERS_LIMIT_MAX) + " personas.",
                        y,
                        true, ColorAMostrar, ColorBackground);
                break;
            case MENU_NODISPONIBLE:
                cout << CreateText("Opcion no desarrollada", y, false, FOREGROUNDGREEN, ColorBackground);
                cout << CreateText("Intente nuevamente:", y, true, FOREGROUNDGREEN, ColorBackground);
                break;
            case ULTIMA_OPORTUNIDAD:
                cout << CreateText("Ultima Oportunidad", y, true, FOREGROUNDGREEN, ColorBackground);
                break;
            default:
                cout << CreateText("Error desconocido. NumeroDeError:" + to_string(NumeroDeError), y, true, 0, 0);
                break;
        }
        cout << restoreConsole();
    }
}


void EstablecerTituloVentana(const string &string1) {
    cout << ESC"]0;" << string1 << "\x07" << endl;
}

void moveUp(int positions) {
    printf("\x1b[%dA", positions);
}

void moveDown(int positions) {
    cout << ESC << "[" + to_string(positions) + "B";
}

void moveRight(int positions) {
    cout << ESC << "[" << positions << "C";
}

void moveLeft(int positions) {
    printf("\x1b[%dD", positions);
}

void moveTo(unsigned int x, int &y) {
    cout << CSI + to_string(y) + ";" + to_string(x) + "f";
    y++;
}

void setupConsole() {
#if defined WIN32 || defined _WIN32 || defined WIN64 || defined _WIN64
    system(string("mode con: cols=" + to_string(MAIN_WIDTH) + " lines=" + to_string(MAIN_HEIGHT)).c_str());
    SetConsoleOutputCP(65001);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
    // References:
    //SetConsoleMode() and ENABLE_VIRTUAL_TERMINAL_PROCESSING?
    //https://stackoverflow.com/questions/38772468/setconsolemode-and-enable-virtual-terminal-processing
    // Windows console with ANSI colors handling
    // https://superuser.com/questions/413073/windows-console-with-ansi-colors-handling
#else
#endif

}

string restoreConsole() {
    string str1 = ESC"[0m";
    return str1;
}

/*
 * Recibe posicion Y
 * */
void PausarPantalla(int &y) {
#if defined WIN32 || defined _WIN32 || defined WIN64 || defined _WIN64
    if (y > 0)moveTo(POSICIONX, y);
    system("pause");
#else

#endif
}
