/*
 ============================================================================
 Name        : recu.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "trabajo.h"
#include "servicio.h"
#include "informes.h"



int main(void) {
	setbuf(stdout, NULL);
	int option;
	int cantTrabajo=0;
	int auxContadorId = 0;
	int idEmpledoBuscar;
	int subMenu;
	eTrabajo trabajo[LEN_STRUCT_TRABAJO];
	eServicio servicios[LEN_STRUCT_SERVICIO]={{20000,"limpieza",250,1},{20001,"parche",300,1},{20002,"centrado",400,1},{20003,"cadena",350,1}};

	initTabajo(trabajo,LEN_STRUCT_TRABAJO);


	 do {

			if (utn_getInt(&option," Menu:\n"
					"1. Alta de trabajo.\n"
					"2. Modificar trabajo.\n"
					"3. Baja de trabajo\n"
					"4. Listar trabajo\n"
					"5. Listar servicios\n"
					"6. Total\n"
					"7. Informes \n"
					"8. Salir\n"
					"Selecionar opcion: ","Error. Menu:\n"
					"1. Alta de trabajo.\n"
					"2. Modificar trabajo.\n"
					"3. Baja de trabajo\n"
					"4. Listar trabajo\n"
					"5. Listar servicios\n"
					"6. Total\n"
					"7. Informes \n"
					"8. Salir\n"
					"Selecionar opcion(del 1 al 8): ", 1, 8, 3) == 0) {
				switch (option) {
				case 1:
					if (altaTrabajo(trabajo, LEN_STRUCT_TRABAJO, &auxContadorId) == 0) {
						printf("Carga exitosa\n");
						cantTrabajo++;
						printsTrabajos(trabajo,LEN_STRUCT_TRABAJO);
					}
					printf("\n \n ");
					break;
				case 2:
					printf("\n \n ");
					if (cantTrabajo > 0) {
						printsTrabajos(trabajo,LEN_STRUCT_TRABAJO);
						printf("\n");
						idEmpledoBuscar = findTrabajoById(trabajo, LEN_STRUCT_TRABAJO);
						modificaEmployee(trabajo, idEmpledoBuscar);
						idEmpledoBuscar = -1;
					} else {
						printf("Error.No hay empleados, porfavor ingrese algun empleado(opcion 1)");
					}

					printf("\n \n ");
					break;
				case 3:
					printf("\n \n ");
					if (cantTrabajo > 0) {
						printsTrabajos(trabajo,LEN_STRUCT_TRABAJO);
						printf("\n");
						idEmpledoBuscar = findTrabajoById(trabajo, LEN_STRUCT_TRABAJO);
						eliminarTrabajo(trabajo,idEmpledoBuscar);
						cantTrabajo--;
						idEmpledoBuscar = -1;
					} else {
						printf("Error.No hay empleados, porfavor ingrese empleado(opcion 1)");
					}
					printf("\n \n ");

					break;
				case 4:
					printf("\n \n ");
					if (cantTrabajo > 0) {
					printsTrabajos(trabajo,LEN_STRUCT_TRABAJO);
					}else {
						printf("Error.No hay empleados, porfavor ingrese empleado(opcion 1)");
					}
					printf("\n \n ");

					break;
				case 5:
					printf("\n \n ");
					printsServicios(servicios, LEN_STRUCT_SERVICIO);

					printf("\n \n ");

					break;
				case 6:
					printf("\n \n ");
					if (cantTrabajo > 0) {
					totalServicio(trabajo, LEN_STRUCT_TRABAJO, servicios, LEN_STRUCT_SERVICIO);
					}
					printf("\n \n ");

					break;
			case 7:
				if (cantTrabajo > 0) {
					do {
						if (utn_getInt(&subMenu, " Sub menu informes:\n"
								"1. Informe 1.\n"
								"2. Informe 2.\n"
								"3. Salir\n", "Error. Sub menu informes:\n"
								"1. Informe 1.\n"
								"2. Informe 2.\n"
								"3. Salir\n"
								"subMenu opcion(del 1 al 8): ", 1, 3, 3) == 0) {
							switch (subMenu) {
							case 1:
								informesA(trabajo, LEN_STRUCT_TRABAJO);
								break;

							case 2:
								informesB(trabajo, LEN_STRUCT_TRABAJO,servicios,LEN_STRUCT_SERVICIO);

								break;
							case 3:
								printf("Salio del sub menu de informes\n");
								break;

							}
						}

					} while (subMenu != 3);
				}

				break;
				case 8:
					printf("\n Gracias por la aplicacion \n ");

					break;

				}
			}
		} while (option != 8);



	return EXIT_SUCCESS;
}
