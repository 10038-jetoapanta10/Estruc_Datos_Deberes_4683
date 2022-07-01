#include "Arreglo.h"

void Arreglo::encerar(int *vec, int tam){
    for(int i=0; i<tam ; i++){
        *(vec+i)=0;
    }
}
void Arreglo::ingresar(int *vec, int tam){
    for(int i=0; i<tam ; i++){
        printf("\nIngrese el dato: ");
        scanf("%d", *(&vec)+i);
    }
}
void Arreglo::imprimir(int *vec, int tam){
    for(int i=0; i<tam ; i++){
        printf("%d - ", *(&(*vec)));
        *(vec++);
    }
}
void Arreglo::procesar(int *vec, int tam, int e){
    for(int i=0; i<tam ; i++){
        *vec=(*(&(*vec)))*e;
        *(vec++);
    }
}






