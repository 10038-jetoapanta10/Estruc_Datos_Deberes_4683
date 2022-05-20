#include "Operaciones.h"

int Operaciones::MCD (int num1 , int num2){
    if(num1 == 0){
		return num2;
	}
	return MCD(num2 % num1, num1);//recursividad directa
}

int Operaciones::MCM (int num1,int num2){
	int r=(num1*num2)/MCD(num1,num2); //recursividad indirecta
	return r;
}
