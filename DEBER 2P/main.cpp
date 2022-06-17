/* UFA-ESPE
*Practica de transformacion de expresiones infijas a postfijas y prefijas
*Autores: Diego Torres y Jonathan Toapanta
*Fecha de creacion: 2022/06/17
*Fecha de modificacion: 2022/06/17
*Grupo 17
*github del grupo: jetoapanta10@espe.edu.ec  y dftorres8@espe.edu.ec
*version: 1.0
*Estructura de Datos 4683
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

#define tam 20

int prioridad(char simbolo);
int main()
{
 	 
	int opcion,tope=-1,pos=-1,tamexp;
	int pila[tam],epos[tam],epre[tam];
	char expinf[tam],simbolo;
	do{
		system("cls");
	 	printf("\n +++++++++++++++++++++++++++++++++++++++++++++++++++++");
		printf("\n         	--------Menu de Opciones--------           ");
		printf("\n  1.-->Convertir una Expresion de Infija a Postfija");
		printf("\n  2.-->Convertir una Expresion de Infija a Prefija");
		printf("\n  3.-->Salir del Menu");
		printf("\n +++++++++++++++++++++++++++++++++++++++++++++++++++++");
		printf("\n Ingrese su opcion: ");
		scanf("%d",&opcion);
		switch(opcion)
 		{
		case 1:
  			system("cls");
  			printf("\n  ==================== Postfija ===================");
  			printf("\n Ingrese la expresion en notacion Infija: ");
    		scanf("%s",&expinf);
    		
    		tope=-1;
    		pos=-1;
    		tamexp=strlen(expinf);//conta nun char
    		
    		for(int i=0; i<tamexp; i++){
    			simbolo=expinf[i];
    			if(simbolo=='('){
    				tope=tope+1;
    				pila[tope]=simbolo;
    				
				}else if(simbolo==')'){
					while(pila[tope]!= '('){
						pos=pos+1;
						epos[pos]=pila[tope];
						tope=tope-1;
						
					}
					tope=tope-1;
					
				}else if((simbolo>='a')&&(simbolo<='z')||(simbolo>='A')&&(simbolo<='Z')){
					pos=pos+1;
					epos[pos]=simbolo;
				}else{
					while(tope> -1 && (prioridad(simbolo)<=prioridad(pila[tope]))){
						pos=pos+1;
						epos[pos]=pila[tope];
						tope=tope-1;
					}
					tope=tope+1;
					pila[tope]=simbolo;
				}
			}
			
			while(tope>-1){
				pos=pos+1;
				epos[pos]=pila[tope];
				tope=tope-1;
			}
			printf("\n La expresion en postfija es:");
			for(int i=0;i<=pos; i++){
				printf("%c",epos[i]);
			
			}
			
			getch();
    	
		break;
	
		case 2:
			system("cls");
			printf("\n  ==================== Prefija ===================");
			printf("\n Ingrese la expresion en notacion Infija: ");
			scanf("%s",&expinf);
			
			tope=-1;
    		pos=-1;
    		tamexp=strlen(expinf);//conta nun char
    		
    		for(int i=tamexp-1; i>=0; i--){
    			simbolo=expinf[i];
    			if(simbolo==')'){
    				tope=tope+1;
    				pila[tope]=simbolo;
    				
				}else if(simbolo=='('){
					while(pila[tope]!= ')'){
						pos=pos+1;
						epre[pos]=pila[tope];
						tope=tope-1;
						
					}
					tope=tope-1;
					
				}else if((simbolo>='a')&&(simbolo<='z')||(simbolo>='A')&&(simbolo<='Z')){
					pos=pos+1;
					epre[pos]=simbolo;
				}else{
					while((prioridad(simbolo)<prioridad(pila[tope]))){
						pos=pos+1;
						epre[pos]=pila[tope];
						tope=tope-1;
					}
					tope=tope+1;
					pila[tope]=simbolo;
				}
			}
			
			while(tope>-1){
				pos=pos+1;
				epre[pos]=pila[tope];
				tope=tope-1;
			}
			printf("\n La expresion en prefija es:");
			for(int i=pos;i>=0; i--){
				printf("%c",epre[i]);
			
			}
			
			getch();
    	
    	
		break;
	
		case 3:
		break;
	
		default: printf("\n Por favor seleccione una opcion valida...");
		getch();
		break;
		}
	
	}while(opcion!=3);
	getch();
}

int prioridad(char simbolo){
	int priori;
	switch(simbolo){
		/*case'sin':priori=4;break;
		case'cos':priori=4;break;
		case'tan':priori=4;break;*/
		case'^':priori=3;break;
		case'/':priori=2;break;
		case'*':priori=2;break;
		case'-':priori=1;break;
		case'+':priori=1;break;
		case')':priori=0;break;
		case'(':priori=0;break;
	}	
	return priori;
}
