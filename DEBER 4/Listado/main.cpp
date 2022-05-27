/* UFA-ESPE
*USO DE LISTAS
*Autores: Diego Torres y Jonathan Toapanta
*Fecha de creacion: 2022/05/26
*Fecha de modificacion: 2022/05/27
*Grupo 17
*github del grupo: jetoapanta10@espe.edu.ec  y dftorres8@espe.edu.ec
*version: 1
*Estructura de Datos 4683
*/

#include <iostream>
#include <Listado.h>

using namespace std;

int main()
{
    Listado *fch;
    Listado *lista=NULL;
    int opciones,dato;
    do{
        system("cls");
        cout<<"Que desea realizar?\n"<<endl;
        cout<<"1.Insertar un elemento"<<endl;
        cout<<"2.Mostrar elementos"<<endl;
        cout<<"3.Buscar elemento"<<endl;
        cout<<"4.Eliminar un elemento"<<endl;
        cout<<"5.Salir\n"<<endl;
        cout<<"Elija la opcion que desea ejecutar: ";
        cin>>opciones;

        switch(opciones){
            case 1: cout<<"\nDigite un numero: ";
                    cin>>dato;
                    fch->insertarLista(lista,dato);
                    cout<<endl;
                    system("pause");
                    break;
            case 2: fch->mostrarLista(lista);
                    cout<<endl;
                    system("pause");
                    break;
            case 3: cout<<"\nDigite un numero a buscar: ";
                    cin>>dato;
                    fch->buscarLista(lista,dato);
                    cout<<endl;
                    system("pause");
                    break;
            case 4: cout<<"\nDigite el elemento que desea eliminar: ";
                    cin>>dato;
                    fch->elimarLista(lista,dato);
                    system("pause");
        }
        system("cls");
    }while(opciones != 5);
    return 0;
}
