#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "informes.h"


int informesA(eTrabajo *aArray,int tamanio){
	int retorno = -1;
	eTrabajo aux[tamanio];
	eTrabajo auxBurbujeo;
	if(aArray!= NULL && tamanio > 0){

		for(int i=0;i< tamanio;i++){
			aux[i]= aArray[i];
		}//fin del for

		for (int i = 0; i < tamanio-1; i++) {
			for (int j = i + 1; i < tamanio; j++) {

				if (strcmp(aux[i].marcaBiclieta,aux[j].marcaBiclieta)>0) {
					auxBurbujeo = aux[i];
					aux[i] = aux[j];
					aux[i] = auxBurbujeo ;

				}
			}
		}
		retorno = 0;

	}//fin del if

	printsTrabajos(aux,tamanio);
	return retorno;
}

int informesB(eTrabajo *aArray,int tamanio){
	int retorno =-1;
	int servicio1=0;
	int servicio2=0;
	int servicio3=0;
	int servicio4=0;

	if (aArray != NULL && tamanio) {

		for (int i = 0; i < tamanio; i++) {
			if(aArray[i].isEmpty == 1){
				switch (aArray[i].idServicio) {
				case 20000:
					servicio1++;
					break;
				case 20001:
					servicio2++;
					break;
				case 20002:
					servicio3++;
					break;
				case 20003:
					servicio4++;
					break;
				}
			}
		}
		retorno = 0;
	}

	if(servicio1 > servicio2 && servicio1 > servicio3 &&servicio1 > servicio4){
		printf("El servicio con mas trabajo es limpieza con:%d trabajos realizados\n",servicio1);

	}else if(servicio2 > servicio1 && servicio2 > servicio3 && servicio2 > servicio4) {
		printf("El servicio con mas trabajo es parche con:%d trabajos realizados\n",servicio2);

	}else if(servicio3 > servicio1 && servicio3 > servicio2 && servicio3 > servicio4){
		printf("El servicio con mas trabajo es centrado con:%d trabajos realizados\n",servicio3);

	}else if(servicio4 > servicio1 && servicio4 > servicio2 && servicio4 > servicio3){
		printf("El servicio con mas trabajo es cadena con:%d trabajos realizados\n",servicio4);

	}


	return retorno;
}
