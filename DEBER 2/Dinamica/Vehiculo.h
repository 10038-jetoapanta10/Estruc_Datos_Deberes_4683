#ifndef VEHICULO_H_INCLUDED
#define VEHICULO_H_INCLUDED
#include <iostream>

using namespace std;

class Vehiculo{
    private:
        string placa;
        string marca;
        string modelo;
        float kilometraje;
    public:
        Vehiculo(string placa, string marca, string modelo, float kilometraje);
        Vehiculo();
        ~Vehiculo();
        float getkilometraje();
        int indiceVehiculo(Vehiculo vehiculo[],int n );
        void mostrarVehiculo();

};

#endif // VEHICULO_H_INCLUDED
