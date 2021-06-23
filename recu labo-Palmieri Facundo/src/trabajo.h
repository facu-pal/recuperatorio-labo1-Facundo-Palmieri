/*
 * trabajo.h
 *
 *  Created on: 23 jun. 2021
 *      Author: facun
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_
#define LEN_STRUCT_TRABAJO 100

typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int idTrabajo;
	char marcaBiclieta[25];
	int rodadoBicicleta;
	int idServicio;
	eFecha fecha;
	int isEmpty;
}eTrabajo;


/** \brief  inicializa en el campo isEmpty en 0, libre
* \param pArray el puntero al primer array
* \param cantidadDeArray int, a recorrer
* \return int Returo (-1) si Error (0) si todo Ok
*/
int initTabajo(eTrabajo pArray[], int cantidadDeArray);

/** \brief  busca en el campo isEmpty del array, con 0 para saber que esta libre
* \param pArray el puntero al primer array
* \param cantidadDeArray int, a recorrer
* \return int Retorno (-1) si Error, retorna un int de posicion si todo Ok
*/
int buscaLibre(eTrabajo pArray[], int len);

void printTrabajo(eTrabajo aArray);

int printsTrabajos(eTrabajo aArray[], int len);

/** \brief  crea un nuevo trabajo
* \param pArray el puntero al primer array
* \param cantidadDeArray int, a recorrer
* \param contadorId para saber cual es el proximo id que debe ser ingresado
* \return int Returo (-1) si Error (0) si todo Ok
*/
int altaTrabajo(eTrabajo aArray[], int cantidadDeArray, int* contadorId);

/*\brief Busca un empleado en el array.
* \param list Employee* pasa la array
* \param len int pasa el tamanio de la array
* \return Return devuelve la ID*/
int findTrabajoById(eTrabajo aArray[], int len);


/*brief modifica a un empleado
 * param1 empleado[] employe pasa la array
 * param2 posicion int pasa solo la posicion de la array que se quiere modificar*/
int modificaEmployee(eTrabajo aArray[], int posicion);

/** \brief Elimina de manera logica (isEmpty Flag en 0) un empleado recibiendo como parametro su Id.
* \param list Employee* pasa la array
* \param posicion int pasa la posicion que se quiere dar de baja
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok*/
int eliminarTrabajo(eTrabajo *aArray, int posicion);


#endif /* TRABAJO_H_ */
