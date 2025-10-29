//
// Created by Dakot on 13/11/2021.
//

#include "menu.h"


using namespace std;

/*
* Únicamente muestra las opción es de los MENUs basados en la estructura pasa como parámetro.
*/
void
MostrarOpcionesDeMenu(const bool logged, Menu &menu, Usuario *user) {
    menu.PosicionY = 5;
    if (menu.MenuInicial == MENU_OP_SALIDA || menu.SubMenu == MENU_OP_SALIDA) {
        EstablecerTituloVentana(APP_NAME" | Menu salida");
        cout << CreateText(string("Menu Salida"), menu.PosicionY, true, 0, 0);
        MostrarBarra(0, menu.PosicionY);
        cout << CreateText(string("Elige una opción "), ++menu.PosicionY, true, 0, 0);
        cout << CreateText(string("1.- Para confirmar"), menu.PosicionY, true, 0, 0);
        cout << CreateText(string("2.- Para cancelar"), menu.PosicionY, true, 0, 0);
        cout << CreateText(string("3.- Para Ir al menu de inicio"), menu.PosicionY, true, 0, 0);
        MostrarBarra(0, menu.PosicionY);
        cout << CreateText(string("Ingrese una opción :"), ++menu.PosicionY, true, 0, 0);
        menu.TotalOpciones = 3;
    } else if (!logged) {

        EstablecerTituloVentana(APP_NAME" | Menu LOGIN - REGISTRO");
        cout << CreateText(string("Menu Principal"), menu.PosicionY, true, 0, 0);
        MostrarBarra(0, menu.PosicionY);
        cout << CreateText(string("1.- Iniciar Sesion"), ++menu.PosicionY, true, 0, 0);
        cout << CreateText(string("2.- Registrar"), menu.PosicionY, true, 0, 0);
        cout << CreateText(string("9.- Cerrar la aplicacion"), menu.PosicionY, true, 0, 0);
        MostrarBarra(0, menu.PosicionY);
        cout << CreateText(string("Ingrese una opción :"), ++menu.PosicionY, true, 0, 0);
        menu.TotalOpciones = 2;
    } else {
        if ((menu.MenuInicial == MENU_NUM_INICIAL && menu.SubMenu == MENU_NUM_INICIAL)) {
            EstablecerTituloVentana(APP_NAME" | Menu principal | Bienvenido " + string(user->usuario));
            cout << CreateText("Menu Principal\t|\tBienvenido " + string(user->usuario), menu.PosicionY, true, 0, 0);
            MostrarBarra(0, menu.PosicionY);
            cout << CreateText("1.- Algoritmos Numericos", ++menu.PosicionY, true, 0, 0);
            cout << CreateText("2.- Juego Super Mario Bros", menu.PosicionY, true, 0, 0);
            cout << CreateText("9.- Cerrar la aplicacion", menu.PosicionY, true, 0, 0);
            MostrarBarra(0, menu.PosicionY);
            cout << CreateText("Ingrese una opción :", ++menu.PosicionY, true, 0, 0);
            menu.TotalOpciones = 2;
        } else if (menu.SubMenu == MENU_NUM_INICIAL) {
            if (menu.MenuInicial == MENU_OP_UNO) { //El menu es igual a 1 (Algoritmo)
                //se verifica que sea igual a 0 el submenu, es decir no este dentro del menu final
                EstablecerTituloVentana(APP_NAME" | Menu algoritmos numericos | Hola " + string(user->usuario));
                cout << CreateText("Menu Algoritmos Numericos", menu.PosicionY, true, 0, 0);
                MostrarBarra(0, menu.PosicionY);
                cout << CreateText("1.- " + MostrarTituloMenuAlgoritmo(MENU_OP_UNO), ++menu.PosicionY, true, 0, 0);
                cout << CreateText("2.- " + MostrarTituloMenuAlgoritmo(MENU_OP_DOS), menu.PosicionY, true, 0, 0);
                cout << CreateText("3.- " + MostrarTituloMenuAlgoritmo(MENU_OP_TRES), menu.PosicionY, true, 0, 0);
                cout << CreateText("4.- " + MostrarTituloMenuAlgoritmo(MENU_OP_CUATRO), menu.PosicionY, true, 0, 0);
                cout << CreateText("5.- " + MostrarTituloMenuAlgoritmo(MENU_OP_CINCO), menu.PosicionY, true, 0, 0);
                cout << CreateText("9.- Salir", menu.PosicionY, true, 0, 0);
                MostrarBarra(0, menu.PosicionY);
                cout << CreateText("Ingrese una opción :", ++menu.PosicionY, true, 0, 0);
                menu.TotalOpciones = 5;
            } else if (menu.MenuInicial == MENU_OP_DOS) {
                EstablecerTituloVentana(APP_NAME" | Menu Juego Mario Bros | Hola " + string(user->usuario));
                cout << CreateText("Menu de Juego Super Mario Bros", menu.PosicionY, true, 0, 0);
                MostrarBarra(0, menu.PosicionY);
                cout << CreateText("1.- Simulacion de encuentro entre Mario y Luigi", ++menu.PosicionY, true, 0, 0);
                cout << CreateText("2.- Simulacion de busqueda de Princesa Peach", menu.PosicionY, true, 0, 0);
                cout << CreateText("9.- Salir", menu.PosicionY, true, 0, 0);
                MostrarBarra(0, menu.PosicionY);
                cout << CreateText("Ingrese una opción :", ++menu.PosicionY, true, 0, 0);
                menu.TotalOpciones = 2;
            }
        } else if (menu.SubMenu > MENU_NUM_INICIAL) { //Se verifica que sea mayor a
            if (menu.MenuInicial == MENU_OP_UNO) { //El menu es igual a 1 (Algoritmo)
                EstablecerTituloVentana(APP_NAME" | SubMenu algoritmos numericos | Hola " + string(user->usuario));
                MostrarTituloMenuAlgoritmo(menu.SubMenu);
                MostrarBarra(0, menu.PosicionY);
                cout << CreateText("1.- Ver definicion", ++menu.PosicionY, true, 0, 0);
                cout << CreateText("2.- Ejecutar", menu.PosicionY, true, 0, 0);
                cout << CreateText("9.- Volver al menu anterior", menu.PosicionY, true, 0, 0);
                MostrarBarra(0, menu.PosicionY);
                cout << CreateText("Ingrese una opción :", ++menu.PosicionY, true, 0, 0);
                menu.TotalOpciones = 2;
            } else if (menu.MenuInicial == MENU_OP_DOS) {
                EstablecerTituloVentana(
                        APP_NAME" | Juego Super Mario Bros - Simulación A | Hola " + string(user->usuario));
                cout << CreateText("Menu de Juego Super Mario Bros", menu.PosicionY, true, 0, 0);
                MostrarBarra(0, menu.PosicionY);
                cout << CreateText("1.- Ver instrucciones", ++menu.PosicionY, true, 0, 0);
                cout << CreateText("2.- Jugar y simular", menu.PosicionY, true, 0, 0);
                cout << CreateText("9.- Volver al menu anterior", menu.PosicionY, true, 0, 0);
                MostrarBarra(0, menu.PosicionY);
                cout << CreateText("Ingrese una opción :", ++menu.PosicionY, true, 0, 0);
                menu.TotalOpciones = 2;
            }
        } else {
            EstablecerTituloVentana(APP_NAME" | Menu No disponible | Hola " + string(user->usuario));
            cout << CreateText("Menu No disponible", menu.PosicionY, true, 0, 0);
            cout << CreateText("Op " + to_string(menu.MenuInicial) + "OpS " + to_string(menu.SubMenu) + "Op",
                               menu.PosicionY, true, 0, 0);
        }
    }
}

/*
* Unicamente muestra los titulos del Submenu basados en los parametros pasados.
* opción es posibles son menu.SubMenu.
* Es una constante asi que no se pueden modificar.
*/

string MostrarTituloMenuAlgoritmo(const int SubMenuOpcion) {
    string string1;
    switch (SubMenuOpcion) {
        case MENU_OP_UNO:
            string1 = "Conversion de Decimal a Binario (Iterativa)";
            break;
        case MENU_OP_DOS:
            string1 = "Conversion de Decimal a Binario (Recursiva)";
            break;
        case MENU_OP_TRES:
            string1 = "Numeros de Mala Suerte pequeños (Iterativa)";
            break;
        case MENU_OP_CUATRO:
            string1 = "Numeros de Mala Suerte pequeños (Recursiva)";
            break;
        case MENU_OP_CINCO:
            string1 = "Funcion de suma triangular (Funciones)";
            break;
        default:
            break;
    }
    return string1;

}

/*
* Ejecutar por SubMenuFinal, recibe una estructura de datos STRUCT
* MENU
* */
void EjecutarPorOpcionAlgoritmo(Menu &menu) {
    menu.PosicionY = 1;
    //Como pasamos un numero de tres cifras, pasamos la del medio que indica que submenu es.
    cout << CreateText(MostrarTituloMenuAlgoritmo(menu.SubMenu), menu.PosicionY, true, 0, 0);
    MostrarBarra(0, menu.PosicionY);
    switch (menu.MenuInicial * 100 + menu.SubMenu * 10 + menu.SubMenuFinal) {
        case MALA_SUERTE_ITERATIVO_MENU_OPN: //opción 2 del submenu 3 (ejecutar)
            numerosMalaSuerte_iterativa();
            break;
        case MALA_SUERTE_RECURSIVO_MENU_OPN: //opción 2 del submenu 3 (ejecutar)
            numerosMalaSuerte_recursiva();
            break;
        case BINARIO_ITERATIVO_MENU_OPN://opción 2 del submenu 1 (ejecutar)
            EnteroABin_Iterativo();
            break;
        case BINARIO_RECURSIVO_MENU_OPN://opción 2 del submenu 2 (ejecutar)
            EnteroABin_Recursiva();
            break;
            //suma triangular ejecutar Menu opción 
        case SUMA_TRIANGULAR_MENU_OPN://opción 2 del submenu 4 (ejecutar)
            sumaTriangular();
            break;
            //decimal a binario recursivo ver definicion Menu opción 
        case BINARIO_ITERATIVO_VDEF_MENU_OPN: //opción 1 del submenu 1 (Ver definicion)
            //decimal a binario recursivo Ejecutar Menu opción 
        case BINARIO_RECURSIVO_VDEF_MENU_OPN://opción 1 del submenu 2 (Ver definicion)
            // entero a binario recursivo
            cout << CreateText(
                    "Las computadoras utilizan el sistema binario para representar numeros; hace mas facil su diseño.",
                    menu.PosicionY, true, 0, 0);
            cout << CreateText(
                    "Un numero entero positivo, llamemoslo n, se puede convertir a su forma binaria de la siguiente manera:",
                    menu.PosicionY, true, 0, 0);
            cout << CreateText("Se realiza la division entera de n sobre 2", menu.PosicionY, true, 0, 0);
            cout << CreateText("Se anota el residuo de la division anterior", menu.PosicionY, true, 0, 0);
            cout << CreateText("Se repite lo anterior con n = n/2 desde el paso 1 hasta llegar a n=0.", menu.PosicionY,
                               true, 0, 0);
            cout << CreateText(
                    "Se escribe el numero desde el ultimo residuo obtenido hasta el primer residuo obtenido.",
                    menu.PosicionY, true, 0, 0);
            MostrarBarra(0, menu.PosicionY);
            cout << CreateText("Entrada", menu.PosicionY, true, 0, 0);
            MostrarBarra(0, menu.PosicionY);
            cout << CreateText("Se ingresa por teclado un numero N (entero sin signo, 0<=N<=1000000000)",
                               menu.PosicionY,
                               true, 0, 0);
            MostrarBarra(0, menu.PosicionY);
            cout << CreateText("Salida", ++menu.PosicionY, true, 0, 0);
            MostrarBarra(0, menu.PosicionY);
            cout << CreateText("CreateText el nimero binario correspondiente al decimal N ingresado en la entrada.",
                               menu.PosicionY, true, 0, 0);
            MostrarEstrategiaDeResolucion(menu.SubMenu, menu.PosicionY);
            PausarPantalla(menu.PosicionY);
            break;
            // numeros de mala suerte
            //mala suerte iterativo Ver Definicion Menu opción 
        case MALA_SUERTE_ITERATIVO_VDEF_MENU_OPN://opción 1 del submenu 3 (Ver definicion)
            //mala suerte recursivo Ver Definicion Menu opción 
        case MALA_SUERTE_RECURSIVO_VDEF_MENU_OPN://opción 1 del submenu 4 (Ver definicion)
            // numeros de mala suerte recursivo
            cout << CreateText(
                    "Un numero de Mala Suerte es aquel que entre sus digitos contiene un 1 seguido por un 3.",
                    menu.PosicionY, false, 0, 0);
            cout << CreateText("Por ejemplo el numero 341329 es un numero de Mala Suerte,", menu.PosicionY, false, 0, 0);
            cout << CreateText("mientras que el numero 26771 no lo es.", menu.PosicionY, false, 0, 0);
            MostrarBarra(0, ++menu.PosicionY);
            cout << CreateText("Entrada", menu.PosicionY, true, 0, 0);
            MostrarBarra(0, ++menu.PosicionY);
            cout << CreateText("La entrada consta de un entero positivo N (0 <= N <= 10^100).", menu.PosicionY, false,
                               0, 0);
            cout << CreateText("Salida", menu.PosicionY, true, 0, 0);
            MostrarBarra(0, menu.PosicionY);
            cout << CreateText(
                    R"(Imprima el mensaje "N es de Mala Suerte" si es un numero de Mala Suerte, en caso contrario imprimir "N NO es de Mala Suerte".)",
                    menu.PosicionY, false, 0, 0);
            MostrarEstrategiaDeResolucion(menu.SubMenu, menu.PosicionY);
            PausarPantalla(menu.PosicionY);
            break;
            //Suma Triangular Ver Definicion Menu opción 
            // suma triangular
        case SUMA_TRIANGULAR_VDEF_MENU_OPN://opción 1 del submenu 5 (Ver definición)
            cout << CreateText("Dada una función f(n) definida como sigue:", menu.PosicionY, false, 0, 0);
            cout << CreateText("f(n) =", menu.PosicionY, false, 0, 0);
            cout << CreateText("1 + 2 + ... + (n-1) + n +", menu.PosicionY, false, 0, 0);
            cout << CreateText("1 + 2 + ... + (n-1) +", menu.PosicionY, false, 0, 0);
            cout << CreateText("1 + 2 + ... +", menu.PosicionY, false, 0, 0);
            cout << CreateText("1 + 2 +", menu.PosicionY, false, 0, 0);
            cout << CreateText("1", menu.PosicionY, false, 0, 0);
            cout << CreateText("Escriba un programa que calcule f ( f ( f (n) ) ). ", menu.PosicionY, false, 0, 0);
            cout << CreateText("Tenga en cuenta que el resultado puede no caber en un entero de 32 bit.",
                               menu.PosicionY,
                               true, 0, 0);
            MostrarBarra(0, menu.PosicionY);

            cout << CreateText("Entrada", ++menu.PosicionY, false, 0, 0);
            MostrarBarra(0, menu.PosicionY);
            cout << CreateText("La entrada consiste de un unicos entero N (1 <= N <= 7).", menu.PosicionY, true, 0, 0);

            cout << CreateText("Salida", ++menu.PosicionY, true, 0, 0);
            MostrarBarra(0, menu.PosicionY);
            cout << CreateText("Imprima por pantalla el resultado de realizar f ( f ( f (n) ) ).", menu.PosicionY, true,
                               0, 0);
            MostrarEstrategiaDeResolucion(menu.SubMenu, menu.PosicionY);
            PausarPantalla(menu.PosicionY);
            break;
        default:
            cout << CreateText("Algo Salio mal, la combinación de submenu y opción final no debio llegar hasta aqui",
                               menu.PosicionY, false, 0, 0);
            PausarPantalla(menu.PosicionY);
            break;
    }
    LimpiarPantalla(menu.PosicionY);
}

void EjecutarPorOpcionJuego(Menu &menu) {
    if (menu.SubMenu == MENU_OP_UNO && menu.SubMenuFinal == MENU_OP_DOS) {
        juegos();
    } else if (menu.SubMenu == MENU_OP_UNO && menu.SubMenuFinal == MENU_OP_UNO) {
        menu.PosicionY = 1;
        cout << CreateText("A.- Simulación de encuentro entre Mario y Luigi", menu.PosicionY, true, 0, 0);
        cout << CreateText("Armado del Reino Champiñón", menu.PosicionY, false, 0, 0);
        cout << CreateText(
                "Al ingresar se deberá generar automáticamente el tablero que representa al Reino Champiñón,",
                menu.PosicionY, false, 0, 0);
        cout << CreateText("haciendo uso de la función cargarTablero de la librería stdpanel (descargar).",
                           menu.PosicionY,
                           false, 0, 0);
        cout << CreateText(
                "La función cargarTablero ubica en forma aleatoria y oculta al usuario, aves y obstáculos (piedras)",
                menu.PosicionY, false, 0, 0);
        cout << CreateText("según se indica a continuación:", menu.PosicionY, false, 0, 0);
        cout << CreateText("● 10 aves: cada una ocupará una celda [i,j] que cumpla con las siguientes condiciones:",
                           menu.PosicionY, false, 0, 0);
        cout << CreateText("i <= 2, es decir, en la parte más alta del cielo del Reino Champiñón", menu.PosicionY,
                           false, 0, 0);
        cout << CreateText("j, cualquier valor válido en la matriz para este índice", menu.PosicionY, false, 0, 0);
        cout << CreateText(
                "● 5 piedras, dos de las cuales tendrán altura 3, otras dos tendrán altura 2 y una tendrá altura",
                menu.PosicionY, false, 0, 0);


        PausarPantalla(menu.PosicionY);
        LimpiarPantalla(menu.PosicionY);


        cout << CreateText("uno. La base deberá estar en la línea de tierra, ocupando celdas hacia arriba según la",
                           menu.PosicionY, false, 0, 0);
        cout << CreateText("altura de la piedra.", menu.PosicionY, false, 0, 0);
        cout << CreateText("● No puede haber dos piedras en una misma posición.", menu.PosicionY, false, 0, 0);
        cout << CreateText("● No puede haber dos piedras en ubicaciones consecutivas.", menu.PosicionY, false, 0, 0);
        cout << CreateText(
                "● No puede haber una piedra ni en la celda inicial ni en la celda final de la línea de tierra.",
                menu.PosicionY, false, 0, 0);
        cout << CreateText(
                "Al comenzar el juego el usuario ve por pantalla al Reino Champiñón vacío, incluso sin marcas de",
                menu.PosicionY, false, 0, 0);
        cout << CreateText("cielo ni de línea de tierra:", menu.PosicionY, false, 0, 0);
        cout << CreateText(
                "Luego, el usuario deberá descubrir celdas (es decir, pares de valores i,j) hasta identificar todas las",
                menu.PosicionY, true, 0, 0);
        cout << CreateText(
                "aves y piedras en base al tablero que se generó con cargarTablero; o hasta que el usuario ingrese el",
                menu.PosicionY, true, 0, 0);
        cout << CreateText("número 99 para el valor de i. Las posibles respuestas son:", menu.PosicionY, false, 0, 0);
        cout << CreateText("● Aire o Tierra, si en la casilla no hay ni un ave ni una piedra (ni una parte de ella).",
                           menu.PosicionY, false, 0, 0);
        cout << CreateText("● Acierto, si la casilla corresponde a un ave, o a alguna piedra (o una parte de ella).",
                           menu.PosicionY, false, 0, 0);
        cout << CreateText(
                "Si se produce Aire o Tierra, se deberá refrescar la pantalla reemplazando la celda vacía por el",
                menu.PosicionY, false, 0, 0);
        cout << CreateText("carácter correspondiente a cielo o tierra según ya se indicó anteriormente.",
                           menu.PosicionY,
                           false, 0, 0);
        cout << CreateText(
                "Si se produce un Acierto se deberá refrescar el tablero reemplazando el valor de la celda por el",
                menu.PosicionY, false, 0, 0);

        PausarPantalla(menu.PosicionY);
        LimpiarPantalla(menu.PosicionY);

        cout << CreateText("caracter correspondiente, a saber:", menu.PosicionY, false, 0, 0);
        cout << CreateText("● ‘^’ (acento circunflejo): Ave.", menu.PosicionY, false, 0, 0);
        cout << CreateText("● ‘X’ (equis mayúscula): Bloque de piedra.", menu.PosicionY, false, 0, 0);
        cout << CreateText(
                "Una vez que el usuario haya descubierto dónde estaban todas las aves y las piedras o cuando el",
                menu.PosicionY, false, 0, 0);
        cout << CreateText(
                "usuario ingresa 99 para el valor de i, se mostrará el puntaje obtenido que resulta de sumar el total",
                menu.PosicionY, false, 0, 0);
        cout << CreateText("de aciertos de aves y piedras.", menu.PosicionY, false, 0, 0);
        cout << CreateText(
                "De ahora en adelante el Reino Champiñón siempre estará visible en pantalla incluyendo todas las",
                menu.PosicionY, false, 0, 0);
        cout << CreateText(
                "aves y piedras que existan (hayan sido halladas o no en la etapa anterior) junto con las zonas de",
                menu.PosicionY, false, 0, 0);
        cout << CreateText("cielo y línea de tierra. Ejemplo:", menu.PosicionY, false, 0, 0);
        cout << CreateText("Simulación:", menu.PosicionY, false, 0, 0);
        cout << CreateText("A partir de ahora comienza la simulación, en la que se pide:", menu.PosicionY, false, 0, 0);
        cout << CreateText(
                "● Crear a Mario sabiendo que comienza el juego en una celda aleatoria de la línea de tierra,",
                menu.PosicionY, false, 0, 0);
        PausarPantalla(menu.PosicionY);
        LimpiarPantalla(menu.PosicionY);

        cout << CreateText("y con una orientación, “Derecha” o “Izquierda”, que será también aleatoria. Crear a Luigi",
                           menu.PosicionY, false, 0, 0);
        cout << CreateText("con los mismos criterios que a Mario. Considerar que:", menu.PosicionY, false, 0, 0);
        cout << CreateText("\tLuigi y Mario no pueden iniciar la simulación ubicados en la misma celda.",
                           menu.PosicionY,
                           false, 0, 0);
        cout << CreateText("\tLa ubicación de los personajes debe ser en celdas libres, es decir, sin piedras.",
                           menu.PosicionY, false, 0, 0);
        cout << CreateText("● En la pantalla deberá aparecer el Reino Champiñón y los dos personajes, L y M, cada uno",
                           menu.PosicionY, false, 0, 0);
        cout << CreateText("en su celda inicial.", menu.PosicionY, false, 0, 0);
        cout << CreateText("● Ambos tienen que moverse en forma alternada hasta encontrarse, mostrando su",
                           menu.PosicionY,
                           false, 0, 0);
        cout << CreateText("ubicación por pantalla a cada paso. Los personajes se encuentran cuando coinciden en la",
                           menu.PosicionY, false, 0, 0);
        cout << CreateText("misma celda. Cada vez que uno de los personajes avanza, se debe refrescar la pantalla",
                           menu.PosicionY, false, 0, 0);
        cout << CreateText("mostrando nuevamente al Reino Champiñón con los personajes en su nueva ubicación.",
                           menu.PosicionY, false, 0, 0);
        cout << CreateText("● Si un personaje llega a algún límite del Reino Champiñón debe girar para cambiar su",
                           menu.PosicionY, false, 0, 0);
        PausarPantalla(menu.PosicionY);
        LimpiarPantalla(menu.PosicionY);

        cout << CreateText("orientación y así poder avanzar en su siguiente turno.", menu.PosicionY, false, 0, 0);
        cout << CreateText("● Debe haber una espera entre cada movimiento para que se pueda visualizar la simulación.",
                           menu.PosicionY, false, 0, 0);
        cout << CreateText("● En el camino pueden encontrarse con piedras, y deberán moverse en consecuencia:",
                           menu.PosicionY, false, 0, 0);
        cout << CreateText("○ Si la piedra es de altura 1, salta una vez sobre ella, y luego deberá bajar cayendo a",
                           menu.PosicionY, false, 0, 0);
        cout << CreateText("la línea de tierra.", menu.PosicionY, false, 0, 0);
        cout << CreateText("○ Si es de altura mayor a 1, la trepará tantas veces según sea su altura-", menu.PosicionY,
                           false, 0, 0);
        cout << CreateText(
                "1. Al llegar a tope deberá saltar sobre el último nivel de la piedra, para luego bajar cayendo a la",
                menu.PosicionY, false, 0, 0);
        cout << CreateText("línea de tierra.", menu.PosicionY, false, 0, 0);
        cout << CreateText("● Se debe contar cada movimiento que haga cada personaje: caminar, girar, saltar, trepar,",
                           menu.PosicionY, false, 0, 0);
        PausarPantalla(menu.PosicionY);
        LimpiarPantalla(menu.PosicionY);

        cout << CreateText("bajar. Los movimientos se van alternando por turno entre personajes, pero si alguno se",
                           menu.PosicionY, false, 0, 0);
        cout << CreateText("encuentra con una piedra seguirá moviéndose hasta sortearla por completo y llegar a la",
                           menu.PosicionY, false, 0, 0);
        cout << CreateText("línea de tierra. Luego se volverá a mover el otro personaje.", menu.PosicionY, false, 0, 0);
        cout << CreateText("● Cuando se encuentran, debe aparecer por pantalla un mensaje que indique que se",
                           menu.PosicionY, false, 0, 0);
        cout << CreateText("encontraron, y luego ambos se tienen que saludar. En la celda del encuentro deberá",
                           menu.PosicionY, false, 0, 0);
        cout << CreateText("aparecer una B (Brothers en inglés).", menu.PosicionY, false, 0, 0);
        cout << CreateText("● Al finalizar la simulación se muestra por pantalla cuántos movimientos tuvo que hacer",
                           menu.PosicionY, false, 0, 0);
        cout << CreateText("cada uno: gana el que haya hecho la menor cantidad! Si la cantidad de movimientos es",
                           menu.PosicionY, false, 0, 0);
        cout << CreateText("igual, debe aparecer un mensaje de empate.", menu.PosicionY, false, 0, 0);
        PausarPantalla(menu.PosicionY);
        PausarPantalla(menu.PosicionY);
        LimpiarPantalla(menu.PosicionY);
    } else {
        menu.hayError = true;
    }
}

/**
* Logica de salida, Establece las variables con la variable pasada por referencia
* opción , dependiendo del valor elegido.
* opción == Uno
* */
void LogicaDeSalida(Menu &menu) {
    if (menu.Opcion == MENU_OP_UNO) {
        menu.MenuInicial = EXIT_STATUS;
    } else if (menu.Opcion == MENU_OP_DOS) {
        if (menu.MenuInicial == MENU_OP_SALIDA) {
            menu.MenuInicial = MENU_NUM_INICIAL;
        } else if (menu.SubMenu == MENU_OP_SALIDA) {
            menu.SubMenu = MENU_NUM_INICIAL;
        }
    } else if (menu.Opcion == MENU_OP_TRES) {
        menu.MenuInicial = MENU_NUM_INICIAL;
        menu.SubMenu = MENU_NUM_INICIAL;
    }
}

/*
* Muestra la EstrategiaDeResolucion de acuerdo al submenu en que se esté. */
void MostrarEstrategiaDeResolucion(const int &SubMenu, int &y) {
    cout << CreateText("Estrategia de resolucion", y, false, 0, 0);
    MostrarBarra(0, y);
    switch (SubMenu) {
        case MENU_OP_UNO:
            cout << CreateText("La función pide el ingreso de un entero n positivo.", y, false, 0, 0);
            cout << CreateText("Luego entra en un ciclo while con la condicion inicial n mayor que 0", y, false, 0, 0);
            cout << CreateText("y a una variable suma le asigna el valor n modulo 2 multiplicado por x,", y, false, 0,
                               0);
            cout << CreateText("donde x es un entero inicializado en 1, ", y, false, 0, 0);
            cout << CreateText("y se actualiza n con su valor dividido dos", y, false, 0, 0);
            cout << CreateText("y a x se la multiplica por 10. ", y, false, 0, 0);
            cout << CreateText("Al finalizar el ciclo while se despliega el valor de suma", y, false, 0, 0);
            break;
        case MENU_OP_DOS:
            cout << CreateText("El programa pide el ingreso de un entero n positivo ", y, false, 0, 0);
            cout << CreateText("luego llama a una función que compara N con 1.", y, false, 0, 0);
            cout << CreateText("Si es mayor que uno se llama a la misma función con parametro N divido 2.", y, false, 0,
                               0);
            cout << CreateText("El cual entra en la función nuevamente si hasta que N no es mayor que 1", y, false, 0,
                               0);
            cout << CreateText(
                    "en tal caso muestra en pantalla n modulo 2, cuando termina vuelve a la función anterior",
                    y, false, 0, 0);
            cout << CreateText("muestra n modulo 2 y asi hasta salir llegar a la función que lo llamo.", y, false, 0, 0);
            break;
        case MENU_OP_TRES:
            cout << CreateText("El algoritmo pide el ingreso de un entero n con el cual va a comenzar", y, false, 0, 0);
            cout << CreateText(
                    "un bucle while con la condicion n mayor que 0. Dentro del bucle a un entero z se le asigna", y,
                    false, 0, 0);
            cout << CreateText("el valor de n modulo 100, realiza una comparacion si z es igual a 13, se despliega", y,
                               false, 0,
                               0);
            cout << CreateText("N es de Mala Suerte,", y, false, 0, 0);
            cout << CreateText("nen caso contrario si no es igual a 13 n se divide por 10", y, false, 0, 0);
            cout << CreateText("y se repite el ciclo. Si al salir del bucle z nunca fue igual a 13 se despliega", y,
                               false, 0, 0);
            cout << CreateText("N No es de Mala Suerte", y, false, 0, 0);
            break;
        case MENU_OP_CUATRO:
            cout << CreateText("La función recibe dos parametros por referencia un entero y ", y, false, 0, 0);
            cout << CreateText("un booleano que por defecto es false.", y, false, 0, 0);
            cout << CreateText("Dentro de la función se compara el entero modulo 100 con 13 ", y, false, 0, 0);
            cout << CreateText("si son iguales el booleano se vuelve true y despliega", y, false, 0, 0);
            cout << CreateText("N Es de mala Suerte. ", y, false, 0, 0);
            cout << CreateText("Caso contrario, la función se llama a si misma, ", y, false, 0, 0);
            cout << CreateText("pero ahora con el entero dividido 10, si n es igual a 0 ", y, false, 0, 0);
            cout << CreateText("y nunca es igual a 13 se despliega", y, false, 0, 0);
            cout << CreateText("N No es de mala suerte", y, false, 0, 0);
            break;
        case MENU_OP_CINCO:
            cout << CreateText(
                    "La función recibe un entero n entre 1 y 7 que se encarga de realizar la suma entre (n)*1+(n-1)*2+... ",
                    y, false, 0, 0);
            cout << CreateText("hasta que n sea igual a 0. Al resultado se le aplica de nuevo la función ", y, false, 0,
                               0);
            cout << CreateText("y al segundo resultado se le aplica una tercera vez.", y, false, 0, 0);
            break;
        default:
            break;

    }
}

/*
* Logo App
* */
void logo() {
    int y = POSICIONY;
    int x = POSICIONX - 30;
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);
    std::stringstream date;
    date << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << " " << 1 + ltm->tm_hour << ":"
         << 1 + ltm->tm_min << ":" << 1 + ltm->tm_sec;
    logoUTN();
    LimpiarPantalla(y);
    logoGrupo();
    LimpiarPantalla(y);
    //TODO: PROBAR ESTO EN OTROS SISTEMAS.
    // system("cls");
    EstablecerTituloVentana(APP_NAME" | LOGO APLICACION | Bienvenido");
    moveTo(x, y);
    MostrarBarra(85, y);
    x = POSICIONX - 25;
    moveTo(x, ++y);
    cout << " █████╗ ██╗      ██████╗  ██████╗ ██████╗ ██╗   ██╗████████╗███╗   ██╗ ██████╗ ";
    moveTo(x, y);
    cout << "██╔══██╗██║     ██╔════╝ ██╔═══██╗██╔══██╗██║   ██║╚══██╔══╝████╗  ██║██╔═══██╗";
    moveTo(x, y);
    cout << "███████║██║     ██║  ███╗██║   ██║██████╔╝██║   ██║   ██║   ██╔██╗ ██║██║   ██║";
    moveTo(x, y);
    cout << "██╔══██║██║     ██║   ██║██║   ██║██╔══██╗██║   ██║   ██║   ██║╚██╗██║██║   ██║";
    moveTo(x, y);
    cout << "██║  ██║███████╗╚██████╔╝╚██████╔╝██║  ██║╚██████╔╝   ██║   ██║ ╚████║╚██████╔╝";
    moveTo(x, y);
    cout << "╚═╝  ╚═╝╚══════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝ ╚═════╝    ╚═╝   ╚═╝  ╚═══╝ ╚═════╝ ";
    moveTo(x, y);
    cout << "                                                                               ";
    MostrarBarra(85, y);
    x = POSICIONX - 30;
    moveTo(x + 40, y);
    cout << "Descripcion:";
    moveTo(x, y);
    cout << "Una Aplicacion dinamica con menu disponible para resolver algoritmos y ver";
    moveTo(x, y);
    cout << "sus definiciones";
    moveTo(x, y);
    MostrarBarra(85, y);
    moveTo(x + 15, y);
    cout << "Autores:";
    moveTo(x + 30, y);
    cout << "Agustin Scotta - - Comision A";
    moveTo(x + 30, y);
    cout << "Elias Nicolas Gomez - - Comision A";
    moveTo(x + 30, y);
    cout << "Francisco Soltermann - - Comision A";
    moveTo(x, y);
    MostrarBarra(85, y);
    moveTo(x + 30, y);
    cout << "UNIVERSIDAD TECNOLOGICA NACIONAL";
    moveTo(x + 33, y);
    cout << "FACULTAD REGIONAL SANTA FE";
    moveTo(x, y);
    MostrarBarra(85, y);
    moveTo(x + 40, y);
    cout << "Version 2.0";
    moveTo(x, y);
    MostrarBarra(85, y);
    cout << CreateText(date.str(), y, true, 0, 0);
    PausarPantalla(y);
}

/*
* Logo UTN
* */
void logoUTN() {
    EstablecerTituloVentana(APP_NAME" | LOGO UTN | Bienvenido");
    int y = 5;
    int x = 50;
    moveTo(x, y);
    cout << "$$$$$       $$$$$       $$$$$";
    moveTo(x, y);
    cout << " $$$$$      $$$$$      $$$$$";
    moveTo(x, y);

    cout << "  $$$$$     $$$$$     $$$$$";
    moveTo(x, y);
    cout << "   $$$$$    $$$$$    $$$$$";
    moveTo(x, y);
    cout << "    $$$$$$$$$$$$$$$$$$$$$";
    moveTo(x, y);
    cout << "     $$$$$$$$$$$$$$$$$$$";
    moveTo(x, y);
    cout << "      $$$$$$$$$$$$$$$$$";
    moveTo(x, y);
    cout << " $$$$$$$$$$$$$$$$$$$$$$$$$$$";
    moveTo(x, y);
    cout << " $$$$$$$$$$$$$$$$$$$$$$$$$$$";
    moveTo(x, y);
    cout << " $$$$$$$$$$$$$$$$$$$$$$$$$$$";
    moveTo(x, y);
    cout << " $$$$$$$$$$$$$$$$$$$$$$$$$$$";
    moveTo(x, y);
    cout << "      $$$$$$$$$$$$$$$$$";
    moveTo(x, y);
    cout << "     $$$$$$$$$$$$$$$$$$$";
    moveTo(x, y);
    cout << "    $$$$$$$$$$$$$$$$$$$$$";
    moveTo(x, y);
    cout << "   $$$$$    $$$$$    $$$$$";
    moveTo(x, y);
    cout << "  $$$$$     $$$$$     $$$$$";
    moveTo(x, y);
    cout << " $$$$$      $$$$$      $$$$$";
    moveTo(x, y);
    cout << "$$$$$       $$$$$       $$$$$";
    moveTo(x, y);
    moveTo(x, y);
    moveTo(x, y);
    cout << " $$  $$    $$$$$$    $$   $$";
    moveTo(x, y);
    cout << " $$  $$    $$$$$$    $$$  $$";
    moveTo(x, y);
    cout << " $$  $$      $$      $$$$$$$";
    moveTo(x, y);
    cout << " $$$$$$      $$      $$  $$$";
    moveTo(x, y);
    cout << " $$$$$$      $$      $$   $$";
    moveTo(x, y);
    moveTo(x, y);
    cout << "UNIVERSIDAD TECNOLOGICA NACIONAL";
    moveTo(x, y);
    cout << "  FACULTAD REGIONAL SANTA FE";
    PausarPantalla(y);
}

/*
* Logo Grupo 14
* */
void logoGrupo() {
    EstablecerTituloVentana(APP_NAME" | LOGO GRUPO | Bienvenido");
    int y = POSICIONY;
    short x = POSICIONX - 3;
    moveDown(y);
    moveRight(x);
    MostrarBarra(40, y);
    moveTo(x, y);
    cout << "||    /$$$$$$     /$$   /$$   /$$  ||";
    moveTo(x, y);
    cout << "||   /$$__  $$  /$$$$  | $$  | $$  ||";
    moveTo(x, y);
    cout << "||  | $$  \\__/ |_  $$  | $$  | $$  ||";
    moveTo(x, y);
    cout << "||  | $$ /$$$$   | $$  | $$$$$$$$  ||";
    moveTo(x, y);
    cout << "||  | $$|_  $$   | $$  |_____  $$  ||";
    moveTo(x, y);
    cout << "||  | $$  \\ $$   | $$        | $$  ||";
    moveTo(x, y);
    cout << "||  |  $$$$$$/  /$$$$$$      | $$  ||";
    moveTo(x, y);
    cout << "||   \\______/  |______/      |__/  ||";
    MostrarBarra(40, y);
    moveTo(x, y);
    cout << CreateText("GRUPO 14", y, true, 0, 0);
    moveTo(x, y);
    MostrarBarra(40, y);
    PausarPantalla(y);
}

/*
* Funciones de algoritmos
*/

void EnteroABin_Iterativo() {
    unsigned long long int suma = 0;
    unsigned long long int x = 1;
    unsigned long long int n;
    int y = 0;

    cout << "\nIngresa un numero entero positivo para convertir a binario:\n";
    cin >> n;

    while (n > 0) {
        suma = suma + (n % 2) * x;
        x = x * 10;
        n = n / 2;
    }
    cout << suma << endl;
    PausarPantalla(y);

}

void numerosMalaSuerte_iterativa() {
    unsigned long long int n;
    unsigned long long numero;
    bool x = false;
    int y = 0;
    cout << "\nIngrese un numero entero positivo para comprobar si es o no de mala suerte\n";
    cin >> numero;
    n = numero;
    while (numero > 0) {
        unsigned long long z = numero % 100;
        if (z == 13) {
            cout << n << " es de Mala Suerte\n" << endl;
            x = true;
        }
        numero = numero / 10;
    }
    if (!x) {
        cout << n << " NO es de Mala Suerte\n" << endl;
    }
    PausarPantalla(y);
}

void numerosMalaSuerte_recursiva() {
    unsigned long long int x;
    bool y = false;
    int yy = 0;
    unsigned long long int z;
    cout << "\nIngrese un numero entero positivo para saber si es de mala suerte:\n";
    cin >> x;
    z = x;
    numerosMalaSuerte(x, y);

    if (!y) {
        cout << z << " NO es de Mala Suerte\n" << endl;
    } else {
        cout << z << " es de Mala Suerte\n" << endl;
    }
    PausarPantalla(yy);

}

void numerosMalaSuerte(unsigned long long int &x, bool &y) {
    if (x % 100 == 13) {
        x = 0;
        y = true;
    } else if (x > 0) {
        x = x / 10;
        numerosMalaSuerte(x, y);
    }
}


void EnteroABin_Recursiva() {
    int y = 0;
    long long int x;
    cout << "\nIngrese un numero entero positivo para convertir a binario:\n";
    cin >> x;
    if (x < 0) {
        int i = 0;
        while (x < 0 && i < 4) {
            if ((0 > x)) {
                cout << CreateText("Entrada invalida\n", y, false, FOREGROUNDRED, BACKGROUNDWHITE);
                cout << CreateText("Ingrese un numero Natural\n", y, false, FOREGROUNDRED, BACKGROUNDWHITE);
            }
            if (i == 3) {
                cout << CreateText("Ultima Oportunidad\n", y, false, FOREGROUNDBLUE, BACKGROUNDWHITE);
            }
            cin >> x;
            i++;
        }
    }
    if (x >= 0) {
        enteroBinarioRecurEje(x);
        cout << endl;
    }
    PausarPantalla(y);
}

void enteroBinarioRecurEje(long long int x) {
    if (x > 1) {
        enteroBinarioRecurEje(x / 2);
    }
    cout << x % 2;
}

void sumaTriangular() {
    unsigned long long int x;
    int y = 0;
    cout << "\nIngrese un numero del 1 al 7 para hacer la suma:\n";
    cin >> x;
    if (x > 7 || x < 1) {
        int i = 0;
        while ((x > 7 || x < 1) && i < 4) {
            if ((x > 7 || x < 1)) {
                cout << CreateText("Entrada invalida\n", y, false, FOREGROUNDRED, BACKGROUNDWHITE);
                cout << CreateText("Ingrese un numero del 1 al 7\n", y, false, FOREGROUNDRED, BACKGROUNDWHITE);
            }
            if (i == 3) {
                cout << CreateText("Ultima Oportunidad\n", y, false, FOREGROUNDBLUE, BACKGROUNDWHITE);
            }
            cin >> x;
            i++;
        }
    }
    if (x <= 7 && x > 0)cout << sumaTriangular_iter(sumaTriangular_iter(sumaTriangular_iter(x))) << endl;
    PausarPantalla(y);
}

unsigned long long int sumaTriangular_iter(unsigned long long int x) {
    unsigned long long int sumador = 0;
    int z = 1;
    for (long double i = x; i >= 0; i--) {
        sumador += i * z;
        z++;
    }
    return sumador;
}
