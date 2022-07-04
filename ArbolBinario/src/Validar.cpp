#include "Validar.h"

bool Validar::validar_numero(char numero[]){
    for(int i=0; i<strlen(numero);i++){
        if((numero[i]>=48&& numero[i]<=57)){
            //printf("\nSolo ingresa numeros\n");
            return true;
        }else{
            printf("\nSolo ingresa numeros\n");
            return false;
        }
    }

}

char *Validar::ingresarDato(const char *msg){
	char *dato=new char[10];
	char c;
	int i=0;
	printf("%s\n",msg);
	while((c=getch())!=13) {
		if(c>='0' && c<='9'){
			printf("%c",c);
			dato[i++]=c;
		}else if (c>=65 && c<=122){
		    printf("%c",c);
			dato[i++]=c;
		}else if(  c==42 || c==45 || c==47 || c==92 || c==46){
		    printf("%c",c);
			dato[i++]=c;
		}else if(c==32 || c==8){
			printf("%c",c);
			dato[i++]=c;
		}
	}
	return dato;
}
