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


/*void Arbol::eliminar(Arbol *arbol,int n){
	if(arbol == NULL){
		return;
	}
	else if(n < arbol->dato){
		eliminar(arbol->izquierdo,n);
	}
	else if(n > arbol->dato){
		eliminar(arbol->derecho,n);
	}
	else{
		eliminarNodo(arbol);
	}
}

void Arbol::eliminarNodo(Arbol *nodoEliminar){
	if(nodoEliminar->izquierdo && nodoEliminar->derecho){
		Arbol *menor = minimo(nodoEliminar->derecho);
		nodoEliminar->dato = menor->dato;
		eliminarNodo(menor);
	}
	else if(nodoEliminar->izquierdo){
		reemplazar(nodoEliminar,nodoEliminar->izquierdo);
		destruirNodo(nodoEliminar);
	}
	else if(nodoEliminar->derecho){
		reemplazar(nodoEliminar,nodoEliminar->derecho);
		destruirNodo(nodoEliminar);
	}
	else{
		reemplazar(nodoEliminar,NULL);
		destruirNodo(nodoEliminar);
	}
}

Arbol *Arbol::minimo(Arbol *arbol){
	if(arbol == NULL){
		return NULL;
	}
	if(arbol->izquierdo){
		return minimo(arbol->izquierdo);
	}
	else{
		return arbol;
	}
}


void Arbol::reemplazar(Arbol *arbol,Arbol *nuevoNodo){
	if(arbol->padre){

		if(arbol->dato == arbol->padre->izquierdo->dato){
			arbol->padre->izquierdo = nuevoNodo;
		}
		else if(arbol->dato == arbol->padre->derecho->dato){
			arbol->padre->derecho = nuevoNodo;
		}
	}
	if(nuevoNodo){
		nuevoNodo->padre = arbol->padre;
	}
}


void Arbol::destruirNodo(Arbol *nodo){
	nodo->izquierdo = NULL;
	nodo->derecho = NULL;
	delete nodo;
}*/
