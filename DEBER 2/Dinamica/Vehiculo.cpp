#include <iostream>
#include "vehiculo.h"

using namespace std;

Vehiculo::Vehiculo(string _placa, string _marca, string _modelo, float _kilometraje){
             placa = _placa;
             marca = _marca;
             modelo = _modelo;
             kilometraje = _kilometraje;
}
Vehiculo::Vehiculo(){
}
Vehiculo::~Vehiculo(){
}
float Vehiculo::getkilometraje(){
    return kilometraje;
}
int Vehiculo::indiceVehiculo(Vehiculo vehiculo[],int n){
    float kilometraje;
    int indice = 0;

    kilometraje = vehiculo[0].getkilometraje();
    for(int i=1;i<n;i++){
        if(vehiculo[i].getkilometraje() < kilometraje){
            kilometraje = vehiculo[i].getkilometraje();
            indice = i;
        }
    }
    return indice;
}
void Vehiculo::mostrarVehiculo(){
    cout<<"Placa del vehiculo: "<<placa<<endl;
    cout<<"Modelo: "<<modelo<<endl;
    cout<<"Kilometraje: "<<kilometraje<<endl;
}
