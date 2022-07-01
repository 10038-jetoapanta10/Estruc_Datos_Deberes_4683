#pragma once
#include<iostream>
#include<conio.h>
#include"Ordenar_Toapanta_jonathan.h"

using namespace std;

void Ordenar_Toapanta_jonathan:: LeerArreglo(int Numero) {
    int i;
    for (i = 1; i <= Numero; i++)
    {
        cout << "Arreglo[" << i << "]=";
        cin >> Arreglo[i];
    }
}

void Ordenar_Toapanta_jonathan::EscribeArreglo(int Numero) {
    int i;
    cout << "Los elementos ordenados son:" << endl;
    for (i = 1; i <= Numero; i++)
    {

        cout << "\t" << Arreglo[i];
    }
}

void Ordenar_Toapanta_jonathan::Shell(int Numero) {
    int i, j, k, incremento, aux;

    incremento = Numero / 2;

    while (incremento > 0) {
        for (i = incremento + 1; i <= Numero; i++) {
            j = i - incremento;
            while (j > 0) {
                if (Arreglo[j] >= Arreglo[j + incremento]) {
                    aux = Arreglo[j];
                    Arreglo[j] = Arreglo[j + incremento];
                    Arreglo[j + incremento] = aux;
                }
                else {
                    j = 0;
                }
                j = j - incremento;
            }
        }
        incremento = incremento / 2;
    }
}