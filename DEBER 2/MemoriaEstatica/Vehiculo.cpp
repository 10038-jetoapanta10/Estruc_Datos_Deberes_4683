#include <iostream>
#include <String>
#include "Vehiculo.h"

using namespace std;
Vehiculo::Vehiculo(string placa,string marca,string modelo, float kilometraje){
		this -> placa = placa; 
		this -> marca = marca;
		this -> modelo = modelo;
		this -> kilometraje = kilometraje;
		 }
/*void Vehiculo::getklm(float kilometraje){
	return kilometraje;
}	

void Vehiculo::setklm(float kilometraje){
	kilometraje=kilometraje;
}
*/
		 
void Vehiculo::encender(){
	cout<<"el auto "<<marca<<" de placa: "<<placa<<" se ha encendido"<<endl;
}

void Vehiculo::frenar(){
	cout<<"el auto "<<marca<<" modelo "<<modelo<< "ha freando"<<endl;
}

void Vehiculo::acelerar(){
	cout<<"el vehiculo "<<marca<<"esta acelerando , kilometraje del vehiculo: "<<kilometraje <<endl;
}