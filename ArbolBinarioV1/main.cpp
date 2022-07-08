#include <iostream>
#include "Arbol.h"
#include "Validar.h"

int main()
{
    Arbol *arbol = NULL;
    Arbol a1;
    Validar *v1;
    int valor,opcion,contador=0;
    char *entrada;
    bool valido=false;
    do{
        std::cout<<"\t.:MENU:."<<std::endl;
        std::cout<<"1. Insertar un nuevo arbol"<<std::endl;
        std::cout<<"2. Mostrar arbol"<<std::endl;
        std::cout<<"3. Salir"<<std::endl;
        do{
            entrada=v1->ingresarDato("Opcion");
            valido=v1->validar_numero(entrada);
        }while(valido==false);
        opcion=atoi(entrada);

        switch(opcion){
            case 1: std::cout<<std::endl;
                    do{
                        entrada=v1->ingresarDato("Ingrese un numero: ");
                        valido=v1->validar_numero(entrada);
                    }while(valido==false);
                    valor=atoi(entrada);
                    a1.insertarArbol(arbol,valor);
                    std::cout<<std::endl;
                    system("pause");
                    break;
            case 2: std::cout<<std::endl;
                    std::cout<<"Mostrando el arbol:\n\n";
                    a1.mostrarArbol(arbol,contador);
                    std::cout<<std::endl;
                    system("pause");
                    break;
            default: std::cout<<"Ingreso invalido"<<std::endl;
        }
        system("cls");
    }while(opcion !=3);
    return 0;
}
