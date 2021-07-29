#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "informes.h"
#include "trabajo.h"


int informesA(eTrabajo *aArrayTrabajo,int tamanioTrabajo){
	int retorno = -1;
	eTrabajo aux[tamanioTrabajo];
	eTrabajo auxBurbujeo;
	if(aArrayTrabajo!= NULL && tamanioTrabajo > 0){

		for(int i=0;i< tamanioTrabajo;i++){
			aux[i]= aArrayTrabajo[i];
		}//fin del for

		for (int i = 0; i < tamanioTrabajo - 1; i++) {
			for (int j = i + 1; i < tamanioTrabajo; j++) {
				if (aux[i].isEmpty == 1 && aux[j].isEmpty == 1) {
					if (strcmp(aux[i].marcaBiclieta, aux[j].marcaBiclieta)>0) {
						auxBurbujeo = aux[i];
						aux[i] = aux[j];
						aux[i] = auxBurbujeo;
					}
				}
			}
		}
		retorno = 0;

	}//fin del if

	printsTrabajos(aux,tamanioTrabajo);
	return retorno;
}

int informesB(eTrabajo *aArrayTrabajo,int tamanioTrabajo, eServicio *aArrayServicio, int tamanioServicio){//paso los 2 array y su cantidad de elementos
	int retorno =-1;
	int max=0;
	int idMaxSer;
	int cant=0;

	if (aArrayTrabajo != NULL && tamanioTrabajo > 0 && aArrayServicio != NULL	&& tamanioServicio > 0) {
		for (int i = 0; tamanioServicio > i; i++) {
			for (int j = 0; tamanioTrabajo > j; j++) {
				if (aArrayTrabajo[i].isEmpty == 1) {
					if (aArrayTrabajo[j].idServicio	== aArrayServicio[i].idServicio) {
						cant++;
					}
				}
			}
			if ((cant > max) || max == 0) {
				max = cant;
				idMaxSer = aArrayServicio[i].idServicio;
			}
			cant=0;
		}

	}
	printf("El servicio con mas trabajo es el id de servicio:%d con:%d trabajos realizados\n",idMaxSer,max);


	return retorno;
}
