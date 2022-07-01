/* UFA-ESPE
*PROYECTO PRIMER PARCIAL
*Autores: Diego Torres ,Jonathan Toapanta,Myckel Chamorro y Gabriel Reinoso
*Fecha de creacion: 2022/06/20
*Fecha de modificacion: 2022/06/21
*Grupo 3 y 17
*version: v1
*Estructura de Datos 4683
*/

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "Arreglo.h"
#include "Procesos.h"

using namespace std;

int main()
{

    int tamanio;

    printf("\nIngrese el tamanio del arreglo: ");
    scanf("%d",&tamanio);

    int *vec = new int[tamanio];

    Arreglo arreglo;
    Procesos p;

    arreglo.encerar(vec,tamanio);
    arreglo.imprimir(vec,tamanio);

    printf("\nIngreso del arreglo: ");
    arreglo.ingresar(vec,tamanio);
    printf("\n|||||||||||||||||||||||||\n");
    printf("Arreglo sin Ordenar: ");
    printf("\n");
    arreglo.imprimir(vec,tamanio);

    printf("\nArreglo Ordenado: ");
    p.quicksort(vec,tamanio,0,tamanio-1);
    printf("\n");
    arreglo.imprimir(vec,tamanio);


    return 0;
}
