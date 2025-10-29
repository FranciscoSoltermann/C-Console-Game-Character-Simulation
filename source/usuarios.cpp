//
// Created by Dakot on 14/11/2021.
//

#include "usuarios.h"

using namespace std;

/*
 * Recibe FSTREAM &
 * Recibe BOOL & logged
 * Recibe Usuario * pUsuario
 * Recibe int & key
 * */
void IniciarSesion(bool &logged, Usuario *pUsuario, int &key, const int &cantUsuarios) {
    /*
   * Se declaran las variables
   * */
    int y = 1;
    logged = false;
    int i = 0;
    bool cumple = false, cumpleUsuario = true, cumplePassword = true;
    string usuario;
    key = -1;
    /*
       * Titulo ventana
       * */
    EstablecerTituloVentana(APP_NAME" | Menu LOGIN");
    do {
        LimpiarPantalla(y);
        /*
        * Titulo en centro arriba
        * */
        cout << CreateText("Menu LOGIN", y, true, 0, 0);

        MostrarBarra(0, y);
        /*
         * Pide ingresar el usuario
         * */
        cout << CreateText("Ingresa tu nombre de usuario", y, true, 0, 0);
        /*
         * Se mueve la posicion a X, Y
         * */
        MostrarMensajeCondicional(!cumpleUsuario && i > 0, USUARIO_INVALIDADO, y);
        MostrarMensajeCondicional(!cumplePassword && i > 0, PASSWORD_INVALIDA, y);
        cout << CreateText("Intento " + to_string(i + 1) + " de 3", y, true, FOREGROUNDBLUE, BACKGROUNDWHITE);
        MostrarMensajeCondicional(i == 2 && !cumple, ULTIMA_OPORTUNIDAD, y);

        moveTo(POSICIONX, y);
        /*
         * Espera el ingreso de datos
         * */
        cin >> usuario;

        /*
         * Comprueba que sea unicos el nombre de usuario
         * Además cambia el valor pasado por referencia de total.
         * */

        if (cantUsuarios > 0)EncontrarUsuario(key, usuario, pUsuario, cantUsuarios);
        /*
          * Muestra mensaje condicional
          * de acuerdo al valor de key
          * */
        /*
         * Muestra mensaje condicional
         * de acuerdo al valor de key
         *
         * Dentro es muy parecido al registro
         * Se encripta password ingresado
         * se compara
         *
         * Muestra mensaje condicional si no es verdadero
         *
         * Si es verdadero, se actualiza en el archivo
         * y muestra la pantalla de bienvenida
         *
         *
         * Muestra mensaje de ÚLTIMA OPORTUNIDAD si es falso,
         * espera reingreso un total de 4 veces.
         * */
        cumpleUsuario = key >= 0;
        cumple = cumpleUsuario;
        if (cumple) {
            LimpiarPantalla(y);
            /*
             * Titulo en centro arriba
             * */
            cout << CreateText("Menu LOGIN", y, true, 0, 0);
            /*
             * Barra
             * */
            MostrarBarra(0, y);
            cout << CreateText("Ingresa tu contraseña", y, true, 0, 0);
            string password;
            moveTo(POSICIONX, y);
            cin >> password;
            EncriptadoPassword(password);
            string password1 = pUsuario[key].password;
            cumplePassword = (password1 == password);
            cumple &= cumplePassword;
        }
        i++;
    } while (!cumple && i < 3);
    if (cumple) {
        LimpiarPantalla(y);
        MostrarBarra(0, y);
        cout << CreateText("Bienvenido " + string(pUsuario[key].usuario), y, true, FOREGROUNDGREEN,
                           BACKGROUNDWHITE);
        MostrarBarra(0, y);
        cout << CreateText("Tu ultimo ingreso exitoso fue: " + to_string(pUsuario[key].ultimo_acceso.dia) + " / " +
                           to_string(pUsuario[key].ultimo_acceso.mes) + " / " +
                           to_string(pUsuario[key].ultimo_acceso.anio), y, true, 0, 0);
        cout << CreateText("A la hora: " + to_string(pUsuario[key].ultimo_acceso.hora) + " : " +
                           to_string(pUsuario[key].ultimo_acceso.min) + " : " +
                           to_string(pUsuario[key].ultimo_acceso.seg), y, true, 0, 0);
        MostrarBarra(0, y);
        UpdateUltimoAcceso(key, pUsuario, cantUsuarios);
        EncontrarUsuario(key, usuario, pUsuario, cantUsuarios);
        logged = cumple;
    } else {
        key = -2;
    }

    PausarPantalla(y);
}


/*
 * Recibe FSTREAM &
 * Recibe bool & logged
 * */
void Registro(bool &logged, Usuario *pUsuario, int &key, int &cantUsuarios) {
    int y = 1;
    key = -1;
    bool saved = false;
    fstream f;
    f.open(FILE_DATA, ios::binary | ios::app | ios::in | ios::out);
    if (!f.fail()) {
        Usuario user{};
        bool cumpleUsuario = true, cumplePassword = true, cumpleComprobacion = true;
        int o = 0;
        do {
            LimpiarPantalla(y);
            /*
             * Titulo ventana
             * */
            EstablecerTituloVentana(APP_NAME" | Menu REGISTRO");
            /*
            * Titulo en centro arriba
            * */
            cout << CreateText("Menu REGISTRO", y, true, 0, 0);
            /*
             * Barra
             * */
            MostrarBarra(0, y);
            /*
             * Pide ingresar el usuario
             * */
            cout << CreateText("Ingresa tu nombre de usuario", y, true, 0, 0);
            /*
            * Se declaran las variables
            * */
            string usuario;
            string password1;
            /*
             * Se mueve la posicion a X, Y
             * */

            if (o == 0) {
                cout << CreateText("*El usuario debe ser de 6 a 10 caracteres.", y, false, FOREGROUNDGREEN,
                                   BACKGROUNDWHITE);
                cout << CreateText("*El usuario comenzar con una letra minúscula.", y, false, FOREGROUNDGREEN,
                                   BACKGROUNDWHITE);
                cout << CreateText("*El usuario debe tener al menos 2 letras mayúsculas.", y, false, FOREGROUNDGREEN,
                                   BACKGROUNDWHITE);
                cout << CreateText("*El usuario debe tener como maximo 3 digitos.", y, false, FOREGROUNDGREEN,
                                   BACKGROUNDWHITE);
            } else {
                EstablecerTituloVentana(APP_NAME" | Menu REGISTRO");
                /*
                 * Muestra mensaje condicional si no encuentra el usuario
                 * Pero además si la cantidad es mayor o
                 * igual al LÍMITE de usuarios totales.
                 * */
                MostrarMensajeCondicional(!cumpleUsuario, USUARIO_REQ_INVALIDO, y);

                MostrarMensajeCondicional(!cumpleComprobacion, CONFIRMACION_INVALIDA, y);

                MostrarMensajeCondicional(cantUsuarios >= USERS_LIMIT_MAX && key == -1, CANTIDAD_INVALIDA, y);
                /*
                 * Muestra mensaje condicional si encuentra un usuario
                 * */
                MostrarMensajeCondicional(key != -1, USUARIO_INVALIDO, y);
                /*
                 * Si no encuentra usuario y no supera el limite
                 * continua
                 * */
                cout << CreateText("Intento " + to_string(o + 1) + " de " + to_string(LIMITE_INTENTO), y, true,
                                   FOREGROUNDBLUE, BACKGROUNDWHITE);
                MostrarMensajeCondicional(o == LIMITE_INTENTO - 1, ULTIMA_OPORTUNIDAD, y);
            }
            moveTo(POSICIONX, y);
            /*
             * Espera el ingreso de datos
             * */
            cin >> usuario;
            /*
             * Comprueba los requisitos
             * cambia el valor cumple
             * */
            CumpleRequisitosUsuario(usuario, cumpleUsuario);
            /*
            * Muestra mensaje condicional
            * de acuerdo al valor negado de cumple
            * */
            /*
             * Pausa la pantalla, pero deja el mensaje centrado
             *
             */
            if (cumpleUsuario) {
                /*
                 * Comprueba que sea unico el nombre de usuario
                 * Además cambia el valor pasado por referencia de total.
                 * */
                if (cantUsuarios > 0)EncontrarUsuario(key, usuario, pUsuario, cantUsuarios);
                if (key == -1 && cantUsuarios < USERS_LIMIT_MAX) {
                    int i = 0;
                    /*
                     * Si cumple es false ingresa
                     * indicando que no cumple requisitos,
                     * y lo pide tres veces la clave repitiendo lo anterior
                     * */
                    do {
                        LimpiarPantalla(y);
                        /*
                       * Titulo en centro arriba
                       * */
                        cout << CreateText("Menu REGISTRO", y, true, 0, 0);
                        /*
                        * Barra
                        * */
                        MostrarBarra(0, y);
                        /*
                           * Muestra mensaje indicando que ingrese contraseña
                           */
                        cout << CreateText("Ingresa tu contraseña", ++y, true, 0, 0);
                        /*
                       * Muestra los requisitos con fondo blanco
                       * Muestra letras en azul
                       * */
                        if (i == 0) {
                            cout << CreateText("*No debe contener espacios", y, false, FOREGROUNDGREEN,
                                               BACKGROUNDWHITE);
                            cout << CreateText("*Debe estar entre 6 y 37 caracteres", y, false, FOREGROUNDGREEN,
                                               BACKGROUNDWHITE);
                            cout << CreateText("*Debe ser únicamente letras sin acentos y numeros.", y, false,
                                               FOREGROUNDGREEN, BACKGROUNDWHITE);
                            cout << CreateText("*Debe contener como minima una mayúscula, una minúscula y un numero;",
                                               y,
                                               false, FOREGROUNDGREEN, BACKGROUNDWHITE);
                        } else {
                            EstablecerTituloVentana(APP_NAME" | Menu REGISTRO");
                            MostrarMensajeCondicional(!cumplePassword, REQ_INVALIDO, y);
                            cout << CreateText("Intento " + to_string(i + 1) + " de 3", y, true, FOREGROUNDBLUE,

                                               BACKGROUNDWHITE);
                        }
                        MostrarMensajeCondicional(i == LIMITE_INTENTO - 1 && !cumplePassword, ULTIMA_OPORTUNIDAD, y);
                        /*
                         * Mueve el curso a la posicion X, Y
                         * */
                        moveTo(POSICIONX, ++y);
                        /*
                         * Espera el ingreso
                         * */
                        cin >> password1;
                        /*
                         * Cumple requisitos Clave
                         * Actualiza U
                         * */
                        CumpleRequisitosClave(password1, cumplePassword);
                        if (!cumplePassword) i++;
                    } while (!cumplePassword && i < LIMITE_INTENTO);
                    if (cumplePassword) {
                        LimpiarPantalla(y);
                        /*
                       * Titulo en centro arriba
                       * */
                        cout << CreateText("Menu REGISTRO", y, true, 0, 0);
                        /*
                        * Barra
                        * */
                        MostrarBarra(0, y);
                        cout << CreateText("Confirma tu contraseña", y, true, 0, 0);
                        /*
                         * Aca entro si cumple los requisitos
                         * Muestra mensaje arriba
                         * Muestra mensaje con color VERDE y fondo BLANCO
                         * */
                        cout << CreateText("*Solo tenes una oportunidad;", y, true, FOREGROUNDGREEN, BACKGROUNDWHITE);
                        string password2;
                        moveTo(POSICIONX, y);
                        cin >> password2;
                        /*
                         * Compara las dos contraseña
                         * */
                        cumpleComprobacion = password1 == password2;
                        if (cumpleComprobacion) {
                            LimpiarPantalla(y);
                            /*
                             * Titulo en centro arriba
                             * */
                            cout << CreateText("Menu REGISTRO", y, true, 0, 0);
                            /*
                            * Barra
                            * */
                            MostrarBarra(0, y);
                            setupUsuario(usuario, password1, &user);
                            f.seekp(0, std::fstream::end);
                            f.clear();
                            /*
                             * Arriba limpia de errores.
                             * Abajo si f.good devuelve TRUE, escribe al archivo al final
                             * */
                            if (f.good()) {
                                f.write((char *) &user, sizeof(Usuario));
                                /*
                                 * Muestra mensajes de cortesía
                                 * Informa que se creó la cuenta.*/
                                cout << CreateText("Felicidades, ya tienes tu cuenta", y, true, FOREGROUNDGREEN,
                                                   BACKGROUNDWHITE);
                                cout << CreateText("Tu nombre de usuario es: " + string(user.usuario), y,
                                                   false, 0, 0);
                                saved = true;
                            } else {
                                cout << f.fail() << " | " << f.bad() << endl;
                            }
                        }
                    }
                }
            }
            o++;
        } while (o < LIMITE_INTENTO && (!cumpleUsuario || !cumpleComprobacion || !cumplePassword || key != -1));
        f.close();
        PausarPantalla(y);
        if ((!cumpleUsuario || !cumpleComprobacion || !cumplePassword || key != -1)) {
            LimpiarPantalla(y);
            /*
             * Titulo en centro arriba
             * */
            cout << CreateText("Menu REGISTRO", y, true, 0, 0);
            /*
             * Barra
             * */
            MostrarBarra(0, y);
            cout << CreateText("No se pudo continuar con el registro por sucesivos errores", y, true, FOREGROUNDBLUE,
                               BACKGROUNDWHITE);
            MostrarBarra(0, y);
            MostrarMensajeCondicional(!cumpleUsuario, USUARIO_REQ_INVALIDO, y);

            MostrarMensajeCondicional(!cumpleComprobacion, CONFIRMACION_INVALIDA, y);

            MostrarMensajeCondicional(!cumplePassword, PASSWORD_INVALIDA, y);
            if (!(o < LIMITE_INTENTO))
                cout << CreateText("Se acabaron los intentos", y, true, FOREGROUNDBLUE,
                                   BACKGROUNDWHITE);

            MostrarBarra(0, y);
            PausarPantalla(y);
        } else if (saved) {
            int Op;
            LimpiarPantalla(y);
            /*
           * Titulo en centro arriba
           * */
            cout << CreateText("Menu REGISTRO", y, true, 0, 0);
            /*
            * Barra
            * */
            MostrarBarra(0, y);
            cout << CreateText("Elige una opcion:", y, true, 0, 0);
            cout << CreateText("1. Para inicar sesion", y, true, 0, 0);
            cout << CreateText("0. Para volver al menu de acceso", y, true, 0, 0);
            moveTo(POSICIONX, y);
            cin >> Op;
            if (Op == 1) {
                loadUsers(pUsuario, cantUsuarios);
                EncontrarUsuario(key, user.usuario, pUsuario, cantUsuarios);
                logged = key != -1;
            } else {
                logged = false;
                key = -1;
            }
        }
    } else {
        LimpiarPantalla(y);
        cout << CreateText("No se pudo lograr abrir el archivo", y, true, FOREGROUNDRED, BACKGROUNDWHITE);
        PausarPantalla(y);
    }


}

void setupUsuario(const string &usuario, string password1, Usuario *pUsuario) {
    /*
      * Encripta la contraseña
      * */
    EncriptadoPassword(password1);
    /*
     * Copia las cadenas a una variable única
     * */
    strncpy(pUsuario->usuario, usuario.c_str(), sizeof(NombreDeUsuario));
    strncpy(pUsuario->password, password1.c_str(), sizeof(Password));
    setupFecha(&pUsuario->ultimo_acceso);

}


/*
 * Recibe la estructura de dato FECHA
 * en forma de PUNTERO
 * */
void setupFecha(Fecha *pUltimo_acceso) {
    time_t ahora;
    time(&ahora);
    struct tm *fecha;
    fecha = localtime(&ahora);
    pUltimo_acceso->dia = fecha->tm_mday;
    pUltimo_acceso->mes = fecha->tm_mon + 1;
    pUltimo_acceso->anio = fecha->tm_year + 1900;
    pUltimo_acceso->hora = fecha->tm_hour;
    pUltimo_acceso->min = fecha->tm_min;
    pUltimo_acceso->seg = fecha->tm_sec;
}

/*
 * Recibe FSTREAM y se actualiza
 * Recibe int key y se actualiza
 * Recibe struc Usuario y se actualiza
 * Recibe total y se actualiza
 * */
void UpdateUltimoAcceso(int &key, Usuario *pUsuario, int cantUsuarios) {
    setupFecha(&pUsuario[key].ultimo_acceso);
    int y = 0;
    ofstream out;
    out.open(FILE_DATA, ios::binary);
    if (!out.fail()) {
        int j = 0;
        out.seekp(0);
        while (j < cantUsuarios) {
            out.write((char *) &pUsuario[j], sizeof(Usuario));
            j++;
        }
        out.close();
    } else {
        cout << CreateText("No se ha podido guardar el ultimo acceso", y, true, 0, 0);
    }
}

/*
 * Recibe const Password
 * Recibe bool & u*/
void CumpleRequisitosClave(const string &password, bool &u) {
    Requisitos req{true, int(password.length()), 0, 0, 0, 0,
                   req.max > PASSWORD_LIMIT_MIN && req.max < PASSWORD_LIMIT_MAX};
    CumpleRequisitos(password, req);
    u = req.length && req.illegal == 0 && req.num > 0 && req.upper > 0 && req.lower > 0;
}

/*
 * Recibe const NombreDeUsuario
 * Recibe bool & u
 * */

void CumpleRequisitosUsuario(const string &usuario, bool &u) {
    Requisitos req{false, int(usuario.length()), 0, 0, 0, 0, req.max > USER_LIMIT_MIN && req.max < USER_LIMIT_MAX};
    CumpleRequisitos(usuario, req);
    u = req.length && req.illegal == 0 && req.num < 4 && req.upper > 1 && usuario[0] == tolower(usuario[0]);
}

/*
 * Recibe const char[]
 * Recibe bool & u
 * */

void CumpleRequisitos(const string &str, Requisitos &req) {
    int i = 0;
    while (i < req.max && req.length && req.illegal == 0) {
        int letter = int(str[i]);
        if (letter > 47 && letter < 58) req.num++;
        else if (letter > 64 && letter < 91) req.upper++;
        else if (letter > 96 && letter < 123) req.lower++;
        else if (((letter < 34 || letter > 126) && !req.user) || req.user)req.illegal++;
        i++;
    }
}

/*
 * Recibe Password y se actualiza
 *
 * */
void EncriptadoPassword(string &password) {
    int j = 0;
    size_t f = password.length() - 1;
    while (j <= f) {
        if (f / 2 >= j) {
            char s = char(int(password[j]) - 1);
            password[j] = password[f - j];
            password[f - j] = s;
        }
        if (int(password[j]) > 64) password[j] = char(int(password[j]) + 3);
        j++;
    }
}

void EncontrarUsuario(int &key, const string &usuario, Usuario *user, int limit) {
    int i = 0;
    string str1 = user[i].usuario;
    key = -1;
    while (i < limit && str1 != usuario) {
        i++;
        str1 = user[i].usuario;
    }
    if (usuario == user[i].usuario) {
        key = i;
    }
}

void loadUsers(Usuario *user, int &total) {
    int y = 1;
    fstream entrada;
    entrada.open(FILE_DATA, ios::binary | ios::app | ios::in);
    if (!entrada.fail()) {
        total = 0;
        entrada.seekg(ios_base::beg);
        while (!entrada.eof()) {
            entrada.read((char *) &user[total], sizeof(Usuario));
            total++;
        }
        total++;
        entrada.close();
    } else {
        LimpiarPantalla(y);
        cout << CreateText("No se pudo lograr abrir el archivo para cargar los usuarios", y, true, FOREGROUNDRED,
                           BACKGROUNDWHITE);
        PausarPantalla(y);
    }

}
