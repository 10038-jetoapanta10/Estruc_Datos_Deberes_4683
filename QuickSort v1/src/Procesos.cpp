#include "Procesos.h"
#include "Arreglo.h"

void Procesos::intercambio(int &x,int &y){
    int aux;
    aux = x;
    x = y;
    y = aux;
}
void Procesos::quicksort(int *vec,int tam,int primero, int ultimo){
    int i,j,central,pivote;

    central = (primero+ultimo)/2;
    pivote = *(vec+central);
    i = primero;
    j = ultimo;

    do{
        while( *(vec+i) < pivote)i++;
        while(*(vec + j) > pivote)j--;

        if(i <= j){
            intercambio(*(vec + i), *(vec + j));
            i++;
            j--;
        }
    }while(i<=j);

    if(primero < j){
        quicksort(vec,tam,primero,j);
    }
    if(i < ultimo){
        quicksort(vec,tam,i,ultimo);
    }

}





