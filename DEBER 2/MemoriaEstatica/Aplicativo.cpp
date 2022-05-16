/* UFA-ESPE
*Memoria Estatica
*Autores: Diego Torres y Jonathan Toapanta
*Fecha de creacion: 2022/05/15
*Fecha de modificacion: 2022/05/16
*Grupo 17
*github del grupo: jetoapanta10@espe.edu.ec  y dftorres8@espe.edu.ec
*version: 1
*Estructura de Datos 4683
*/

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "Vehiculo.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Vehiculo v1 = Vehiculo("P0-87","Audi","R8",22.4);
	
	v1.encender();
	
	return 0;
}