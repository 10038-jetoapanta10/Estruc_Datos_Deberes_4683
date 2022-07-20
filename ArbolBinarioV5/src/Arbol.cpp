#include "Arbol.h"

 Arbol *Arbol::crearArbol(int n,Arbol *padr){
    Arbol *nuevo_arbol = new Arbol;

    nuevo_arbol->dato = n;
    nuevo_arbol->derecho = NULL;
    nuevo_arbol->izquierdo = NULL;
    nuevo_arbol->padre = padr;

    return nuevo_arbol;
 }

void Arbol::insertarArbol(Arbol *&arbol,int n,Arbol *padr){
    if(arbol == NULL){
        Arbol *nuevo_arbol = crearArbol(n,padr);
        arbol =  nuevo_arbol;
    }
    else{
        int valorRaiz = arbol->dato;
        if(n < valorRaiz){
            insertarArbol(arbol->izquierdo,n,arbol);
        }else{
            insertarArbol(arbol->derecho,n,arbol);
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

void Arbol::preOrden(Arbol *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		std::cout<<arbol->dato<<" - ";
		preOrden(arbol->izquierdo);
		preOrden(arbol->derecho);
	}
}

void Arbol::inOrden(Arbol *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		inOrden(arbol->izquierdo);
		std::cout<<arbol->dato<<" - ";
		inOrden(arbol->derecho);
	}
}

void Arbol::postOrden(Arbol *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		postOrden(arbol->izquierdo);
		postOrden(arbol->derecho);
		std::cout<<arbol->dato<<" - ";
	}
}

Arbol *Arbol::unirArbol(Arbol *izq,Arbol *der){
    if(izq==NULL)return der;
    if(der==NULL)return izq;

    Arbol *centro = unirArbol(izq->derecho,der->izquierdo);
    izq->derecho = centro;
    der->izquierdo = izq;
    return der;
}

void Arbol::eliminar(Arbol *&arbol,int n){
    if(arbol == NULL) return;

    if(n < arbol->dato)
        eliminar(arbol->izquierdo,n);
    else if(n > arbol->dato)
        eliminar(arbol->derecho,n);
    else{
        Arbol *p = arbol;
        arbol = unirArbol(arbol->izquierdo,arbol->derecho);
        delete p;
    }
}

int Arbol:: alturaAB(Arbol *arbol){
    int AltIzq, AltDer;

    if(arbol==NULL)
        return -1;
    else
    {
        AltIzq = alturaAB(arbol->izquierdo);
        AltDer = alturaAB(arbol->derecho);

        if(AltIzq>AltDer)
            return AltIzq+1;
        else
            return AltDer+1;
    }
}

void Arbol:: diagonalSumUtil(Arbol* arbol,int vd, std::map<int, int> &diagonalSum){
    if (!arbol){
        return;

    }else{

       diagonalSum[vd] += arbol->dato;

       diagonalSumUtil(arbol->izquierdo, vd + 1, diagonalSum);

       diagonalSumUtil(arbol->derecho, vd, diagonalSum);
    }
}

void Arbol:: diagonalSum(Arbol* arbol){

    std::map<int, int> diagonalSum;

    diagonalSumUtil(arbol, 0, diagonalSum);

    std::map<int, int>::iterator i;

    std::cout<< "\n\n La suma diagonal de nuestro arbolito es: "<<std::endl;

    for(i = diagonalSum.begin();
                i != diagonalSum.end(); ++i)
    {
        std::cout << i->second << " ";
    }
}



