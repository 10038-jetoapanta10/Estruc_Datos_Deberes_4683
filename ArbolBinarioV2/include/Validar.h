#ifndef VALIDAR_H
#define VALIDAR_H
#include <conio.h>
#include <cstdlib>
#include <string.h>
#include <iostream>

class Validar
{
    public:
    bool validar_numero(char numero[]);
    char *ingresarDato(const char *msg);
};

#endif // VALIDAR_H
