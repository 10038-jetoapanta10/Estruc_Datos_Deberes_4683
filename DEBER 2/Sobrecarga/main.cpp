/* UFA-ESPE
*Sobrecarga de operador >
*Autores: Diego Torres y Jonathan Toapanta
*Fecha de creacion: 2022/05/15
*Fecha de modificacion: 2022/05/16
*Grupo 17
*github del grupo: jetoapanta10@espe.edu.ec  y dftorres8@espe.edu.ec
*version: 1
*Estructura de Datos 4683
*/

#include <iostream>
#include "A.h"

using namespace std;

int main(int argc, char** argv) {
	A persona("Diego",20);
    persona>persona;//sobrecarga
    return 0;
}