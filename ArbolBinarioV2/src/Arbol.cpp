#include "Arbol.h"

 Arbol *Arbol::crearArbol(int n){
    Arbol *nuevo_arbol = new Arbol;

    nuevo_arbol->dato = n;
    nuevo_arbol->derecho = NULL;
    nuevo_arbol->izquierdo = NULL;

    return nuevo_arbol;
 }

void Arbol::insertarArbol(Arbol *&arbol,int n){
    if(arbol == NULL){
        Arbol *nuevo_arbol = crearArbol(n);
        arbol =  nuevo_arbol;
    }
    else{
        int valorRaiz = arbol->dato;
        if(n < valorRaiz){
            insertarArbol(arbol->izquierdo,n);
        }else{
            insertarArbol(arbol->derecho,n);
        }
    }
}

void Arbol::mostrarArbol(Arbol *arbol,int contador){
    if(arbol == NULL){
        return;
    }else{
        mostrarArbol(arbol->derecho,contador+1);
        for(int i=0;i<contador;i++){
            std::cout<<"   ";
        }
        std::cout<<arbol->dato<<std::endl;
        mostrarArbol(arbol->izquierdo,contador+1);
    }
}

bool Arbol::busqueda(Arbol *arbol,int n){
    if(arbol == NULL){
        return false;
    }
    else if(arbol->dato == n){
        return true;
    }
    else if(n < arbol->dato){
        return busqueda(arbol->izquierdo,n);
    }else{
        return busqueda(arbol->derecho,n);
    }
}
