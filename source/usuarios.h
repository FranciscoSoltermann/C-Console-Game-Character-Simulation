//
// Created by Dakot on 14/11/2021.
//

#ifndef MAIN_CPP_USUARIOS_H
#define MAIN_CPP_USUARIOS_H

#define LIMITE_INTENTO 3

#include <iostream>
#include <fstream>
#include "utils.h"

typedef char NombreDeUsuario[USER_LIMIT_MAX];
typedef char Password[PASSWORD_LIMIT_MAX];
struct Fecha {
    int dia, mes, anio, hora, min, seg;
};
struct Usuario {
    NombreDeUsuario usuario;
    Password password;
    Fecha ultimo_acceso;
};
struct Requisitos {
    bool user;
    int max;
    int illegal;
    int num;
    int upper;
    int lower;
    bool length;
};

void loadUsers(Usuario *, int &);

void IniciarSesion(bool &, Usuario *, int &, const int &);
void Registro(bool &, Usuario *, int &, int &);

void EncriptadoPassword(std::string &);

void EncontrarUsuario(int &key, const std::string&, Usuario *, int limit);

void UpdateUltimoAcceso(int &key, Usuario *, int);

void setupUsuario(const std::string&, std::string, Usuario *);
void setupFecha(Fecha *);

void CumpleRequisitos(const std::string &, Requisitos &);

void CumpleRequisitosClave(const std::string&, bool &);

void CumpleRequisitosUsuario(const std::string &, bool &);


#endif //MAIN_CPP_USUARIOS_H
