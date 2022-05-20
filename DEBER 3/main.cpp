/* UFA-ESPE
*MCM Y MCD CON FUNCIONES RECURSIVAS
*Autores: Diego Torres y Jonathan Toapanta
*Fecha de creacion: 2022/05/19
*Fecha de modificacion: 2022/05/20
*Grupo 17
*github del grupo: jetoapanta10@espe.edu.ec  y dftorres8@espe.edu.ec
*version: 1
*Estructura de Datos 4683
*/
#include <iostream>
#include "Operaciones.cpp"

using namespace std;


int main()
{
    int n1,n2;
    Operaciones C;

	cout<<"ingrese el numero 1:"<<endl;
	cin>>n1;
	cout<<"ingrese el numero 2:"<<endl;
	cin>>n2;

	cout<<"El maximo comun divisor es: "<<C.MCD(n1,n2)<<endl;
	cout<<"El minimo comun multiplo es: "<<C.MCM(n1,n2)<<endl;

	return 0;
}
