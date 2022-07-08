#ifndef ARBOL_H
#define ARBOL_H
#include <iostream>

class Arbol{
    private:
        int dato;
        Arbol *derecho;
        Arbol *izquierdo;
    public:
        Arbol *crearArbol(int);
        void insertarArbol(Arbol *&,int);
        void mostrarArbol(Arbol *,int);
        bool busqueda(Arbol *,int);
};

#endif // ARBOL_H
