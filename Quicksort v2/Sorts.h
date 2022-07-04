/* UNIVERSIDAD DE LAS FUERZAS ARMADAS (ESPE)
Nombre del programa: Ordenamiento externo - Mezcla Natural
Autor: Esteban Chablay & Paul Mena
Fecha de creacion: 27/06/2022
Fecha de modificacion: 27/06/2022
4683 ESTRUCTURA DE DATOS
*/

#include "Arreglo.h"

//Quick
template <class T>
void Arreglo<T>::intercambioQ(int& x, int& y) {
    int aux;
    aux = x;
    x = y;
    y = aux;
}
//The Quicksort 
template <class T>
void Arreglo<T>::quicksort() {
    quicksortImpl(0, _tamano - 1);
}

//Q
template <class T>
void Arreglo<T>::quicksortImpl(int primero, int ultimo) {
    int i, j, central, pivote;

    central = (primero + ultimo) / 2;
    pivote = *(_datos + central);
    i = primero;
    j = ultimo;

    do {
        while (*(_datos + i) < pivote)i++;
        while (*(_datos + j) > pivote)j--;

        if (i <= j) {
            intercambioQ(*(_datos + i), *(_datos + j));
            i++;
            j--;
        }
    } while (i <= j);

    if (primero < j) {
        quicksortImpl(primero, j);
    }
    if (i < ultimo) {
        quicksortImpl(i, ultimo);
    }
}

template <class T>
void Arreglo<T>::ordenarIntercambio() {
    int aux;
    for (int i = 0; i < _tamano -2; i++) {
        for (int j = i+1; j < _tamano - 1; j++) {
            if (*(_datos + i) > *(_datos + j + 1)) {
                aux = *(_datos + i);
                *(_datos + i) = *(_datos + j + 1);
                *(_datos + j + 1) = aux;
            }
        }
      
    }
    
}