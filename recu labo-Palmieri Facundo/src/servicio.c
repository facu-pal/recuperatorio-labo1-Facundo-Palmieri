#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "servicio.h"

void printServicio(eServicio aArray) {

		printf("\n %-5d  %-10s %10.2f ", aArray.idServicio,aArray.descripcion,aArray.precio);

}


int printsServicios(eServicio aArray[], int len) {
	int i;
	int retorno = -1;

	//CABECERA
	printf("\n LISTADO servico\n");
	printf("%-5s  %-10s %10s  ", " Id", "Descripcion", "precio");
	if (aArray != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (aArray[i].isEmpty == 0) {
				continue;
			} else {
				printServicio(aArray[i]);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int buscarPrecio(int idServicio, eServicio *aArray,int tamanio){
	int returno = -1;

	if(aArray != NULL){
		for(int i=0;i<tamanio;i++){
			if(idServicio ==aArray[i].idServicio ){
				returno = aArray[i].precio;
				break;
			}
		}
	}

	return returno;
}

