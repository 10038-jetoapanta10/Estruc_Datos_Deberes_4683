/* UFA-ESPE
*USO DE PUNTEROS EN CLASES
*Autores: Diego Torres y Jonathan Toapanta
*Fecha de creacion: 2022/05/20
*Fecha de modificacion: 2022/05/20
*Grupo 17
*github del grupo: jetoapanta10@espe.edu.ec  y dftorres8@espe.edu.ec
*version: 1
*Estructura de Datos 4683
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "Puntero.h"
/*void ingreso(int *,int );
void proceso(int *,int);
void impresion(int *,int);
*/


int main(int argc, char** argv) {
	Puntero puntero;// crear un obj de la clase 
int t;
int *ptr=new int[10];
std::cout<<"Ingrese el tamaño "<<std::endl;
std::cin>>t;
puntero.ingreso(ptr,t);
puntero.impresion(ptr,t);
puntero.proceso(ptr,t);
puntero.impresion(ptr,t);
return 0;
}

/*void ingreso(int *p,int t){
int i;
for(i=0;i<t;i++){
scanf("%d",*(&p)+i);
}
}
void impresion(int *p,int t){
int i;
printf("{ ");
for(i=0;i<t;i++){
printf("%d ",*(&(*p)));
*(p++);
}
printf(" }");
}
void proceso(int *p,int t){
int i,e;
printf("\nIngrese el escalar ");
scanf("%d",&e);
for(i=0;i<t;i++){
*p=(*(&(*p)))*e;
*(p++);
}
}*/
