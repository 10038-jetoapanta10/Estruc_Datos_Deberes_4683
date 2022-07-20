#ifndef ARBOL_H
#define ARBOL_H
#include <iostream>
#include <bits/stdc++.h>

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


        void diagonalSumUtil(Arbol* arbol,int vd, std::map<int, int> &diagonalSum);

        void diagonalSum(Arbol* arbol);

};

#endif // ARBOL_H
