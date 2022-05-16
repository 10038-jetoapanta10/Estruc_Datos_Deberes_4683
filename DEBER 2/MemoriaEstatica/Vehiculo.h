#include <iostream>
#include <string>
using namespace std;

class Vehiculo{
	private:
 		string placa;
 		string marca;
 		string modelo;
 		float kilometraje;
 	public:
 		Vehiculo(string placa,string marca,string modelo, float kilometraje);
 		//void setklm();
 		//void gatklm();
 		void encender();
 		void acelerar();
 		void frenar();
};