#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "trabajo.h"

int initTabajo(eTrabajo *list, int len) {
	int i;
	int retorno = -1;
	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			list[i].isEmpty = 0;
			retorno = 0;
		}
	} else {
		retorno = -1;
	}

	return retorno;
}

int buscaLibre(eTrabajo pArray[], int len) {
	int retorno = -1;
	int i;

	if (pArray != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (pArray[i].isEmpty == 0) {
				retorno = i;
				break;
			}
		}

	}
	return retorno;
}

void printTrabajo(eTrabajo aArray) {
	switch (aArray.idServicio) {
	case 1:
		printf("\n %d  %10s %5d %10s %5d/%d/%d ", aArray.idTrabajo,
				aArray.marcaBiclieta, aArray.rodadoBicicleta, "limpieza",
				aArray.fecha.dia, aArray.fecha.mes, aArray.fecha.anio);
		break;
	case 2:
		printf("\n %d  %10s %5d %10s %5d/%d/%d ", aArray.idTrabajo,
				aArray.marcaBiclieta, aArray.rodadoBicicleta, "parche",
				aArray.fecha.dia, aArray.fecha.mes, aArray.fecha.anio);
		break;
	case 3:
		printf("\n %d  %10s %5d %10s %5d/%d/%d ", aArray.idTrabajo,
				aArray.marcaBiclieta, aArray.rodadoBicicleta, "centrado",
				aArray.fecha.dia, aArray.fecha.mes, aArray.fecha.anio);
		break;
	case 4:
		printf("\n %d  %10s %5d %10s %5d/%d/%d ", aArray.idTrabajo,
				aArray.marcaBiclieta, aArray.rodadoBicicleta, "cadena",
				aArray.fecha.dia, aArray.fecha.mes, aArray.fecha.anio);
		break;
	}
}


int printsTrabajos(eTrabajo aArray[], int len) {
	int i;
	int retorno = -1;

	//CABECERA
	printf("\n LISTADO trabajo\n");
	printf("%-5s  %-20s %-20s %-20s %-20s ", "Id", "Marca bicileta", "Rodado bicileta ", "Servicio", "Fechas");
	if (aArray != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (aArray[i].isEmpty == 0) {
				continue;
			} else {
				printTrabajo(aArray[i]);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int altaTrabajo(eTrabajo aArray[], int cantidadDeArray, int* contadorId){
	int retorno = -1;
	int posicion;
	eTrabajo auxTrabajo;

	if(aArray != NULL && cantidadDeArray > 0 && contadorId != NULL){
		posicion = buscaLibre(aArray, cantidadDeArray);
			if(posicion == -1){
				printf("\nNo hay lugares libres");
			}else{
				if((utn_getString(auxTrabajo.marcaBiclieta, "Ingrese la marca de bicileta:","Error.Ingrese la marca de bicicleta:", 2) == 0)
				&& (utn_getInt(&auxTrabajo.rodadoBicicleta,"Ingrese el rodado de la bicicleta(del 1 al 100):",	"Error.Ingrese el rodado de la bicicleta(del 1 al 100):", 1, 100, 2) == 0)
				&&(utn_getInt(&auxTrabajo.idServicio,"Ingrese el servicio(del 1 al 4):",	"Error.Ingrese el servicio(del 1 al 4):", 1, 4, 2) == 0)
				&&(utn_getInt(&auxTrabajo.fecha.dia,"Ingrese el dia(del 1 al 31):",	"Error.Ingrese el dia(del 1 al 31):", 1, 31, 2) == 0)
				&&(utn_getInt(&auxTrabajo.fecha.mes,"Ingrese el mes(del 1 al 12):",	"Error.Ingrese el mes(del 1 al 12):", 1, 31, 2) == 0)
				&&(utn_getInt(&auxTrabajo.fecha.anio,"Ingrese el a�o:",	"Error.Ingrese el servicio(del 2018 al 2040):", 2018, 2040, 2) == 0)){

					auxTrabajo.idTrabajo = *contadorId + 1;
					printf("Estos son los datos, desea continuar:");
					printTrabajo(auxTrabajo);

					if (utn_getConfirm() == 0) {
						(*contadorId)++;
						auxTrabajo.isEmpty = 1;
						aArray[posicion] = auxTrabajo;
						retorno = 0;

					}
				}
			}
	}

	return retorno;
}

int findTrabajoById(eTrabajo aArray[], int len) {
	int retorno = -1;
	int i;
	int auxID;
	if (aArray != NULL && len > 0) {
		printf("Ingrese ID del trabajo:");
		scanf("%d", &auxID);
		for (i = 0; i < len; i++) {
			if (aArray[i].idTrabajo == auxID && aArray[i].isEmpty == 1) {
				retorno = i;
				break;
			}
		}
		if (retorno == -1) {
			printf("El numero de ID %d no existe", auxID);
		}
	}
	return retorno;
}


int modificaEmployee(eTrabajo aArray[], int posicion) {
	int retorno = -1;
	int respuesta;
	eTrabajo auxTrabajo;
	if (aArray != NULL && posicion != -1) {

		printTrabajo(aArray[posicion]);

		printf("\n�Que desea modificar?\n");
		printf("1_la marca \n");
		printf("2_el servicio\n");
		scanf("%d", &respuesta);

		while (respuesta > 2 || respuesta < 1) {
			printf(	"\nError. no ingreso una opcion correcta (opciones del 1 al 4)");
			printf("�Que desea modificar?\n");
			printf("1_la marca \n");
			printf("2_el servicio\n");
			scanf("%d", &respuesta);
		}
		switch (respuesta) {
		case 1:
			utn_getString(auxTrabajo.marcaBiclieta, "Ingrese la nueva marca:",
					"Error. Ingrese la nueva marca:", 1);
			printf("�Estas seguro que queres cambiar la marca a %s? ",
					auxTrabajo.marcaBiclieta);
			if (utn_getConfirm() == 0) {
				strcpy(aArray[posicion].marcaBiclieta, auxTrabajo.marcaBiclieta);
			}
			break;
		case 2:
			utn_getInt(&auxTrabajo.idServicio,"Ingrese el nuevo servicio(del 1 al 4):",	"Error.Ingrese el nuevo servicio(del 1 al 4):", 1, 4, 2);

			if (utn_getConfirm() == 0) {
				aArray[posicion].idServicio= auxTrabajo.idServicio;
			}
			break;
		}
		printTrabajo(aArray[posicion]);
		retorno = 0;

	}
	return retorno;
}

int eliminarTrabajo(eTrabajo *aArray, int posicion) {
	int retorno = -1;
	if (aArray != NULL && posicion != -1) {

		printf("\n�Desea borrar el trabajo?\n");
		if (utn_getConfirm() == 0) {
			aArray[posicion].isEmpty = 0;
			retorno = 0;
		}
	}
	printsTrabajos(aArray,LEN_STRUCT_TRABAJO);
	return retorno;
}



























