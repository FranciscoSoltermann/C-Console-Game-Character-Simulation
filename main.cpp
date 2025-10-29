#include <iostream>
#include "source/menu.h"

using namespace std;

int main() {
    setupConsole();
    time_t start = std::chrono::system_clock::to_time_t(
            std::chrono::system_clock::now());
    logo();
    /*
    * Se declaran como 0 las variables, igual por ser la primera vez, muestra el menu principal si es asi, pero si no, muestra un mensaje de error */
    bool logged = false;
    Usuario usr[USER_LIMIT_MAX]{};
    Menu menu = {MENU_NUM_INICIAL};
    int key = -1;
    menu.PosicionY = 13, menu.TotalOpciones = MENU_NUM_INICIAL, menu.Opcion = MENU_NUM_INICIAL;
    menu.hayError = false;
    int totalUsers=0;
    bool OpcionNoDisponible = false;
    do {
        /*
        * Imprime el menu principal
        */
        LimpiarPantalla(menu.PosicionY);

        /*
        * Se llama a CreateText opción es de Menu para que imprima el menu
        * Luego nos establece TotalDeOpciones por referencia
        * que luego utilizamos para verificar que la opción dada por el usuario
        * sea entre el rango de disponible.
        */
        MostrarOpcionesDeMenu(logged, menu, &usr[key]);

        /*
        * Se llama a CreateText Mensaje de Error para que en caso de que sea hayError true
        * muestre un error. Ademas se pasa los colores; ErrorColor es rojo.
        */
        MostrarMensajeCondicional(OpcionNoDisponible, MENU_NODISPONIBLE, menu.PosicionY);
        MostrarMensajeCondicional(menu.hayError && !OpcionNoDisponible, MENU_INVALIDA, menu.PosicionY);

        /*
        * Pide la opción al usuario
        */
        moveTo(POSICIONX, menu.PosicionY);
        cin >> menu.Opcion;
        /*
        * Se establece el estado de error, en caso de que sea verdadero,
        * no se ejecuta ninguna logica
        */

        OpcionNoDisponible =
                logged && menu.MenuInicial == MENU_OP_DOS && menu.SubMenu == MENU_NUM_INICIAL &&
                menu.Opcion == MENU_OP_DOS;
        menu.hayError = menu.Opcion < 1 ||
                        (menu.Opcion > menu.TotalOpciones && menu.Opcion != MENU_OP_SALIDA &&
                         menu.TotalOpciones != 3) ||
                        (menu.Opcion > menu.TotalOpciones && menu.TotalOpciones == 3) || OpcionNoDisponible;
        if (!menu.hayError) {
            /*Limpia la pantalla
             * y pasa la posicion Y
             * */
            LimpiarPantalla(menu.PosicionY);

            if (menu.Opcion == MENU_OP_SALIDA && menu.SubMenu > MENU_NUM_INICIAL) {
                /*
                * Si la opción es de salida, 9, y estamos en un SubMenuFinal
                * Restablece las variables para mostrar el menu anterior.
                */
                menu.SubMenuFinal = MENU_NUM_INICIAL;
                menu.SubMenu = MENU_NUM_INICIAL;
            } else if (menu.MenuInicial == MENU_OP_SALIDA || menu.SubMenu == MENU_OP_SALIDA) {
                /*
                * Si una la opción Menu es de salida, 9, o estamos en un submenu;
                * CreateText La logica de salida.
                */
                LogicaDeSalida(menu);
            } else if (logged) {
                /*
                * Si ninguna opción coincide, entra a esta seccion
                */
                if (menu.MenuInicial == MENU_NUM_INICIAL) {
                    /*
                    * menu.MenuInicial es decir, Menu principal es inicial, 0, entonces se establece a esa variable.
                    */
                    menu.MenuInicial = menu.Opcion;
                    menu.SubMenu = MENU_NUM_INICIAL;
                    menu.SubMenuFinal = MENU_NUM_INICIAL;
                } else if (menu.SubMenu == MENU_NUM_INICIAL) {
                    /*
                    * menu.SubMenu es decir, SubMenu Algoritmo
                    * es inicial, 0, entonces se establece a esa variable.
                    */
                    menu.SubMenu = menu.Opcion;
                    menu.SubMenuFinal = MENU_NUM_INICIAL;
                } else if (menu.SubMenu > MENU_NUM_INICIAL) {
                    /*
                    * menu.SubMenuFinal es decir, SubMenu de un Algoritmo
                    * es inicial, 0, entonces se establece a esa variable.
                    */
                    menu.SubMenuFinal = menu.Opcion;
                }
                /*
                * menu.MenuInicial  es inicial, 1
                */
                if (menu.MenuInicial == MENU_OP_UNO && menu.SubMenuFinal != MENU_NUM_INICIAL) {
                    EjecutarPorOpcionAlgoritmo(menu);
                    menu.SubMenuFinal = MENU_NUM_INICIAL;
                } else if (menu.MenuInicial == MENU_OP_DOS && menu.SubMenuFinal != MENU_NUM_INICIAL) {
                    EjecutarPorOpcionJuego(menu);
                    menu.SubMenuFinal = MENU_NUM_INICIAL;
                }
            } else {
                if (menu.Opcion == MENU_OP_UNO || menu.Opcion == MENU_OP_DOS) {
                        loadUsers(usr, totalUsers);
                        if (menu.Opcion == MENU_OP_UNO) {
                            IniciarSesion(logged, usr, key, totalUsers);
                        } else if (menu.Opcion == MENU_OP_DOS) {
                            Registro(logged, usr, key, totalUsers);

                        }
                } else if (menu.Opcion == MENU_OP_SALIDA) {
                    menu.MenuInicial = menu.Opcion;
                }
            }
        }

    } while (menu.MenuInicial != EXIT_STATUS && key != -2); // si opción es igual a 99 se termina el loop.
    MensajeDeSalida(start, key);
    return 0;
}
