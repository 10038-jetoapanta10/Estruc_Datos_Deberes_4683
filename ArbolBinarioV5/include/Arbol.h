#ifndef ARBOL_H
#define ARBOL_H
#include <iostream>

class Arbol{
    private:
        int dato;
        Arbol *derecho;
        Arbol *izquierdo;
        Arbol *padre;
    public:
        Arbol *crearArbol(int,Arbol *);
        void insertarArbol(Arbol *&,int,Arbol *);
        void mostrarArbol(Arbol *,int);
        bool busqueda(Arbol *,int);
        void preOrden(Arbol *);
        void inOrden(Arbol *);
        void postOrden(Arbol *);
        Arbol *unirArbol(Arbol *izq,Arbol *der);
        void eliminar(Arbol *&arbol,int n);
        int alturaAB(Arbol *arbol);
        /*void eliminar(Arbol *,int);
        void eliminarNodo(Arbol *);
        Arbol *minimo(Arbol *);
        void reemplazar(Arbol *,Arbol *);
        void destruirNodo(Arbol *);*/

};

#endif // ARBOL_H
