/* UFA-ESPE
*ORDENAMIENTO QUICKSORT
*Autores: Diego Torres y Jonathan Toapanta
*Fecha de creacion: 2022/06/30
*Fecha de modificacion: 2022/06/30
*Grupo 17
*github del grupo: jetoapanta10@espe.edu.ec  y dftorres8@espe.edu.ec
*version: 2.0
*Estructura de Datos*/

#include <iostream>
#include <cstdlib>
#include "Sorts.h"
#include "val.h"
#include "Vector.h"
#include "Ordenar_Toapanta_jonathan.h"
using namespace std;

int main()
{
    Arreglo<int> arreglo;

	Vector vector;

    int opcion, tamanio = 0;

    vector.set_arreglo(new int[tamanio]);

    
    bool repetir = true;

            rewind(stdin);
            arreglo.encerar();
            do {
                float n = val::leerNumero("ingrese un numero: ");
                arreglo.agregar(n);
            } while (val::confirmar("Desea agregar otro numero?"));

            arreglo.imprimir();
            arreglo.quicksort();
            arreglo.imprimir();

    return 0;
}