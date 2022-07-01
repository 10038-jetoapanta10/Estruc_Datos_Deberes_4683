#include "Vector.h"

Vector::Vector(int* nuevo_arreglo) {
    this->arreglo = nuevo_arreglo;
}

void Vector::set_arreglo(int* nuevo_arreglo) {
    this->arreglo = nuevo_arreglo;
}

int* Vector::get_arreglo() {
    return arreglo;
}