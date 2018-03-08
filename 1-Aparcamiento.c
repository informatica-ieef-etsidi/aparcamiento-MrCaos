#include <stdio.h>
#include <string.h> // Libreria para realizar funciones con cadenas
#include <time.h> //Libreria para poder poner la hora en un futuro

void main() {

	int p1 = 'L', p2 = 'L'; //p = plaza L=Libre O=Ocupada
	char opcion; 
	char matricula[8], CompMatricula[8];
	char matricula2[8];
	int orden, p;
	
	

	
	while (1) { // Bucle infinito

		system("color 0B");

		printf("Bienvenido al aparcamiento.\n\n");
		printf("Pulse R para reservar una plaza.\n");
		printf("Pulse A para abandonar una plaza.\n");
		printf("Pulse E para ver el estado del aparcamiento.\n");
		scanf_s("%c", &opcion);
		getchar();
		system("cls");

		switch (opcion) {

		case 'R':
		case 'r':
			printf("Has seleccionado reservar una plaza.\n\n");
			
			if (p1 == 'L') {
				printf("Introduce tu matricula:\n");
				scanf_s("%s", &matricula, 8);
				getchar();
				printf("El coche con la matricula %s esta en la plaza 1\n", matricula);
				p1 = 'O';
			}
			else if (p1 == 'O' && p2 == 'L') {
				printf("Introduce tu matricula:\n");
				scanf_s("%s", &matricula2, 8);
				getchar();
				printf("El coche con la matricula %s esta en la plaza 2\n", matricula2);
				p2 = 'O';
			}
			else if (p1 == 'O' && p2 == 'O')
				printf("No hay plazas disponibles\n");

			system("pause");
			system("cls");
			break;

		case 'A':
		case 'a':


			if (p1 == 'L' && p2 == 'L') {
				printf("No hay plazas ocupadas en este momento.\n");
				system("pause");
				system("cls");
			}

			else {

				printf("Has seleccionado abandonar una plaza.\n");
				printf("Seleciona la plaza con el coche a retirar\n");
				scanf_s("%d", &p);

				switch (p) {

				case 1:

					printf("Plaza 1 seleccionada.\n");
					if (p1 == 'O') {
						printf("Introduce tu matricula\n");
						scanf_s("%s", &CompMatricula, 8);
						getchar();

						orden = strcmp(matricula, CompMatricula); //Funcion para comparar dos strings
						if (orden == 0) {
							printf("El coche con matricula %s ha sido retirado del parking.\n", matricula);
							p1 = 'L';
						}
						else
							printf("Esa matricula no esta registrada\n");
					}
					else {
						printf("En esta plaza no hay ningun coche\n");
						getchar();
					}
			
					system("pause");
					system("cls");

					break;


				case 2:

					printf("Plaza 2 seleccionada.\n");
					if (p2 == 'O') {
						printf("Introduce tu matricula\n");
						scanf_s("%s", &CompMatricula, 8);
						getchar();

						orden = strcmp(matricula2, CompMatricula);//Funcion para comparar dos strings

						if (orden == 0) {
							printf("El coche con matricula %s ha sido retirado del parking.\n", matricula2);
							p2 = 'L';
						}
						else
							printf("Esa matricula no esta registrada\n");
					}
					else {
						printf("En esta plaza no hay ningun coche\n");
						getchar();
					}

					system("pause");
					system("cls");
					

					break;

				default:
					printf("Plaza actualmente en obras\n");
					getchar();

					system("pause");
					system("cls");

					break;
				}
			}
			
		
			break; 

		case 'E':
		case 'e':
			system("color 0D");
			printf("Has seleccionado ver el estado del aparcamiento.\n\n");
			if (p1 == 'L' && p2 == 'L') {
				printf("Plaza 1 - Libre\n");
				printf("Plaza 2 - Libre\n");
			}
			else if (p1 == 'O' && p2 == 'L') {
				printf("Plaza 1 - Ocupada - %s\n", matricula);
				printf("Plaza 2 - Libre\n");
			}
			else if (p1 == 'O' && p2 == 'O') {
				printf("Plaza 1 - Ocupada - %s\n", matricula);
				printf("Plaza 2 - Ocupada - %s\n", matricula2);
			}
			else if (p1 == 'L' && p2 == 'O') {
				printf("Plaza 1 - Libre\n");
				printf("Plaza 2 - Ocupada - %s\n", matricula2);
			}
			system("pause");
			system("cls");
			break;

		default:
			system("color 0C");
			printf("Opcion no valida.\n");
			system("pause");
			system("cls");
			break;
		

		}
		
		
	}
}