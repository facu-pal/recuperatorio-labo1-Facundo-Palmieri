/*
 * servicio.h
 *
 *  Created on: 23 jun. 2021
 *      Author: facun
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_
#define LEN_STRUCT_SERVICIO 4

typedef struct
{
	int idServicio;
	char descripcion[25];
	float precio;
	int isEmpty;
}eServicio;

void printServicio(eServicio aArray);

int printsServicios(eServicio aArray[], int len);



#endif /* SERVICIO_H_ */
