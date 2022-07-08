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
        std::cout<<"3. Buscar nodo"<<std::endl;
        std::cout<<"4. Recorrido en PreOrden"<<std::endl;
        std::cout<<"5. Recorrido en InOrden"<<std::endl;
        std::cout<<"6. Recorrido en PostOrden"<<std::endl;
        std::cout<<"7. Eliminar un nodo del arbol"<<std::endl;
        std::cout<<"8. Altura del arbol"<<std::endl;
        std::cout<<"9. Salir"<<std::endl;
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
                    a1.insertarArbol(arbol,valor,NULL);
                    std::cout<<std::endl;
                    system("pause");
                    break;
            case 2: std::cout<<std::endl;
                    std::cout<<"Mostrando el arbol:\n\n";
                    a1.mostrarArbol(arbol,contador);
                    std::cout<<std::endl;
                    system("pause");
                    break;
            case 3: std::cout<<std::endl;
                    std::cout<<"Ingrese el elemento a buscar: ";
                    std::cin>>valor;
                    if(a1.busqueda(arbol,valor) == true){
                        std::cout<<std::endl;
                        std::cout<<"Elemento "<<valor<<" a sido en contrado en el arbol"<<std::endl;
                    }else{
                        std::cout<<"\nElemento no encontrado"<<std::endl;
                    }
                    std::cout<<std::endl;
                    system("pause");
                    break;
            case 4: std::cout<<std::endl;
                    std::cout<<"Recorrido en PreOrden: ";
                    a1.preOrden(arbol);
                    std::cout<<"\n\n";
                    system("pause");
                    break;
            case 5: std::cout<<std::endl;
                    std::cout<<"Recorrido en InOrden: ";
                    a1.inOrden(arbol);
                    std::cout<<"\n\n";
                    system("pause");
                    break;
            case 6: std::cout<<std::endl;
                    std::cout<<"Recorrido en PostOrden: ";
                    a1.postOrden(arbol);
                    std::cout<<"\n\n";
                    system("pause");
                    break;
            case 7: std::cout<<std::endl;
                    std::cout<<"Ingrese el elemento a eliminar: ";
                    std::cin>>valor;
                    a1.eliminar(arbol,valor);
                    std::cout<<"\n\n";
                    system("pause");
                    break;
            case 8: std::cout<<std::endl;
                    int h;
                    h= a1.alturaAB(arbol);
                    std::cout<<"Altura: "<<h+1<<std::endl;
                    std::cout<<"\n\n";
                    system("pause");
                    break;
            default: std::cout<<"Ingreso invalido"<<std::endl;
        }
        system("cls");
    }while(opcion !=9);
    return 0;
}

