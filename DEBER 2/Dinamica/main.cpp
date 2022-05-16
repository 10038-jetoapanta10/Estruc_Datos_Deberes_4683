/* UFA-ESPE
*Memoria Dinamica
*Autores: Diego Torres y Jonathan Toapanta
*Fecha de creacion: 2022/05/15
*Fecha de modificacion: 2022/05/16
*Grupo 17
*github del grupo: jetoapanta10@espe.edu.ec  y dftorres8@espe.edu.ec
*version: 1
*Estructura de Datos 4683
*/

#include <iostream>
#include "vehiculo.h"
#include <string>
using namespace std;

int main()
{
    Vehiculo* carros;
    int numcarros;
    string placa;
    string marca;
    string modelo;
    float kilometraje;
    int indice;

    cout<<"Ingrese el numero de vehiculos: ";
    cin>>numcarros;

    carros = new Vehiculo[numcarros];

    for(int i=0;i<numcarros;i++){
        cout<<"\nIngrese los datos del vehiculo "<<i+1<<": "<<endl;
        fflush(stdin);
        cout<<"Ingrese la placa: ";
        getline(cin,placa);
        fflush(stdin);
        cout<<"Ingrese el marca: ";
        getline(cin,marca);
        fflush(stdin);
        cout<<"Ingrese el modelo: ";
        getline(cin,modelo);
        fflush(stdin);
        cout<<"Ingrese el kilometraje(km): ";
        cin>>kilometraje;
        fflush(stdin);
        cout<<endl;
        carros[i] = Vehiculo(placa,marca,modelo,kilometraje);
    }

    indice = carros->indiceVehiculo(carros,numcarros);
    cout<<"El carro con menor kilometraje es: "<<endl;
    (carros+indice)->mostrarVehiculo();
    return 0;
}
