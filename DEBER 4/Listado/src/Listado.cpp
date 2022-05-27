#include <iostream>
#include "Listado.h"

using namespace std;

Listado::Listado()
{
}

Listado::~Listado()
{
}

void Listado::insertarLista(Listado *&lista, int n){
    Listado *nueva_lista = new Listado();
    nueva_lista->num=n;

    Listado *aux1 = lista;
    Listado *aux2;

    while((aux1 != NULL)&&(aux1->num < n )){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    if(lista == aux1){
        lista = nueva_lista;
    }else{
        aux2->siguiente=nueva_lista;
    }
    nueva_lista->siguiente = aux1;
    cout<<"Elemento ingresado"<<endl;
}

void Listado::mostrarLista(Listado *lista){
    Listado *actual = new Listado();
    actual = lista;

    while(actual != NULL){
            cout<<actual->num<<" ->";
            actual = actual->siguiente;
    }
}

void Listado::buscarLista(Listado *lista, int n){
    bool bandera = false;

    Listado *actual = new Listado();
    actual =  lista;

    while((actual != NULL)&& (actual->num <= n )){
        if(actual->num == n){
            bandera = true;
        }
        actual = actual->siguiente;
    }

    if(bandera == true ){
        cout<<"Elemento "<<n<<" Si a sido encontrado el elemento en la lista\n";
    }else{
        cout<<"Elemento "<<n<<" No a sido encontrado el elemento en la lista\n";
    }
}

void Listado::elimarLista(Listado *&lista, int n){
    if(lista != NULL){
        Listado *aux_borrar;
        Listado *anterior = NULL;

        aux_borrar = lista;

        while((aux_borrar != NULL)&&(aux_borrar->num != n)){
            anterior = aux_borrar;
            aux_borrar = aux_borrar->siguiente;
        }
        if(aux_borrar == NULL){
            cout<<"El elemento ha sido encontrado";
        }else if(anterior == NULL){
            lista = lista->siguiente;
            delete aux_borrar;
        }else{
            anterior->siguiente = aux_borrar->siguiente;
            delete aux_borrar;
        }
    }
}

