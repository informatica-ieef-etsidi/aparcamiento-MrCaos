#include <stdio.h>
#include <string.h> // Libreria para realizar funciones con cadenas
#include <time.h> //Libreria para poder poner la hora en un futuro
#include <windows.h>


void main() {

	int p1 = 'L', p2 = 'L', p;//p = plaza L=Libre O=Ocupada
	char opcion; // opcion del menu 
	char vehiculo, v1, v2; // Para seleccionar moto o coche 'M'=Moto 'C'=Coche
	char matricula[8], matricula2[8], CompMatricula[8], BuscarMatricula[8]; // Matriculas, comprobacion para el caso A y buscar para el caso B
	int compUser, compPass; // Para comparar el username y la password escritos con las del usuario
	int orden, orden2; // para comparar las matriculas en el caso A

	char username[7] = "Marcos";
	char password[7] = "qwerty";
	char contrasena[7], usuario[7];
	int bucle = 0;
	int i = 0;

	int HoraE1, HoraE2; // Hora entrada para la plaza 1 y 2
	int HoraS1, HoraS2; // Hora salida para la plaza 1 y 2
	float coste; // Coste en relacion a la diferencia entre entrada y salida, multiplicada por la tarifa, en este caso 0,05 cents/s


	do
	{
		system("cls");
		printf("Introduce tu username\n");
		scanf_s("%s", &usuario, 7);
		getchar();
		compUser = strcmp(usuario, username);
		
		if (compUser == 0) {
			
			printf("Introduce tu contrasena\n");
			scanf_s("%s", &contrasena, 7);
			compPass = strcmp(contrasena, password);
			getchar();

			if (compPass == 0) {
				bucle = 1;
				i = 5;
				system("cls");
				printf("Iniciando el programa...\n");
				Sleep(1500);
			}
			else {
				printf("Contrasena incorrecta\n");
				system("pause");
			}
		}
		else {
			printf("Ese username no esta registrado\n");
			system("pause");
		}
		i++;

	} while (i<3); 

	if (i < 5) {
		system("cls");
		system("color 0C");
		printf("Abandonando el programa...\n");
		Sleep(1500);
	}
	
	
	
		while (bucle) { // Bucle infinito

			system("cls");
			system("color 0B");

			time_t result = time(NULL);
			char str[26];
			ctime_s(str, sizeof str, &result);
			printf("%s\n", str);

			printf("Bienvenido al aparcamiento.\n\n");
			printf("Pulse R para reservar una plaza.\n");
			printf("Pulse A para abandonar una plaza.\n");
			printf("Pulse E para ver el estado del aparcamiento.\n");
			printf("Pulse B para buscar una matricula.\n");
			printf("Pulse S para salir\n");
			scanf_s("%c", &opcion);
			getchar();
			system("cls");

			switch (opcion) {
				system("cls");

			case 'R':
			case 'r':
			
				if (p1 == 'L') {
					printf("Has seleccionado reservar una plaza.\n\n");
					printf("Seleccione el vehiculo a aparcar\n");
					printf("C - Coche\n");
					printf("M - Moto\n");
					scanf_s("%c", &vehiculo);
					
					switch (vehiculo) {
						
					case 'C':
					case 'c':
						printf("Introduce tu matricula:\n");
						scanf_s("%s", &matricula, 8);
						getchar();
						printf("El coche con la matricula %s esta en la plaza 1\n", matricula);
						p1 = 'O';
						v1 = 'C';
						HoraE1 = time(NULL);
						break;

					case 'M':
					case 'm':
						printf("Introduce tu matricula:\n");
						scanf_s("%s", &matricula, 8);
						getchar();
						printf("La moto con la matricula %s esta en la plaza 1\n", matricula);
						p1 = 'O';
						v1 = 'M';
						HoraE1 = time(NULL);
						break;


					default:
						printf("No hay plaza para ese vehiculo");
						getchar();
						break;

					}
				}
				else if (p1 == 'O' && p2 == 'L') {
					printf("Has seleccionado reservar una plaza.\n\n");
					printf("Seleccione el vehiculo a aparcar\n");
					printf("C - Coche\n");
					printf("M - Moto\n");
					scanf_s("%c", &vehiculo);
					switch (vehiculo) {
					
					case 'C':
					case 'c':
						printf("Introduce tu matricula:\n");
						scanf_s("%s", &matricula2, 8);
						getchar();
						printf("El coche con la matricula %s esta en la plaza 2\n", matricula2);
						p2 = 'O';
						v2 = 'C';
						HoraE2 = time(NULL);
						break;

					case 'M':
					case 'm':
						printf("Introduce tu matricula:\n");
						scanf_s("%s", &matricula2, 8);
						getchar();
						printf("La moto con la matricula %s esta en la plaza 2\n", matricula2);
						p2 = 'O';
						v2 = 'M';
						HoraE2 = time(NULL);
						break;


					default:
						printf("No hay plaza para ese vehiculo");
						getchar();
						break;
					}
				}
					
				else if (p1 == 'O' && p2 == 'O')
					printf("No hay plazas disponibles\n");

				Sleep(1500);
				system("cls");
				break;

			case 'A':
			case 'a':

				if (p1 == 'L' && p2 == 'L') {
					printf("No hay plazas ocupadas en este momento.\n");
					Sleep(1500);
					system("cls");
				}

				else {

					printf("Has seleccionado abandonar una plaza.\n");
					printf("Seleciona la plaza con el vehiculo a retirar\n");
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
								printf("El vehiculo con matricula %s ha sido retirado del parking.\n", matricula);
								p1 = 'L';

								Sleep(750);
								system("cls");

								HoraS1 = time(NULL);
								printf("La tarifa es de 5 centimos por segundo\n");
								coste = 0.05*(HoraS1 - HoraE1);
								printf("El total a abonar son %.2f euros\n", coste);

								memset(matricula, 0, 8); //limpia las cadenas
								memset(CompMatricula, 0, 8);
							}
							else
								printf("Esa matricula no esta registrada\n");
						}
						else {
							printf("En esta plaza no hay ningun vehiculo\n");
							getchar();
						}

						Sleep(1500);
						system("pause");

						break;


					case 2:

						printf("Plaza 2 seleccionada.\n");
						if (p2 == 'O') {
							printf("Introduce tu matricula\n");
							scanf_s("%s", &CompMatricula, 8);
							getchar();

							orden = strcmp(matricula2, CompMatricula);//Funcion para comparar dos strings

							if (orden == 0) {
								printf("El vehiculo con matricula %s ha sido retirado del parking.\n", matricula2);
								p2 = 'L';

								Sleep(750);
								system("cls");

								HoraS2 = time(NULL);
								printf("La tarifa es de 5 centimos por segundo\n");
								coste = 0.05*(HoraS2 - HoraE2);
								printf("El total a abonar son %.2f euros\n", coste);

								memset(matricula2, 0, 8); //Limpia las cadenas
								memset(CompMatricula, 0, 8);
							}
							else
								printf("Esa matricula no esta registrada\n");
						}
						else {
							printf("En esta plaza no hay ningun vehiculo\n");
							getchar();
						}

						Sleep(1500);
						system("cls");


						break;

					default:
						printf("Plaza actualmente en obras\n");
						getchar();

						Sleep(1500);
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
				else if (p1 == 'O' && p2 == 'L' && v1 == 'C') {
					printf("Plaza 1 - Ocupada - Coche - %s\n", matricula);
					printf("Plaza 2 - Libre\n");
				}
				else if (p1 == 'O' && p2 == 'L' && v1 == 'M') {
					printf("Plaza 1 - Ocupada - Moto - %s\n", matricula);
					printf("Plaza 2 - Libre\n");
				}
				else if (p1 == 'O' && p2 == 'O' && v1 == 'C' && v2 == 'C') {
					printf("Plaza 1 - Ocupada - Coche - %s\n", matricula);
					printf("Plaza 2 - Ocupada - Coche - %s\n", matricula2);
				}
				else if (p1 == 'O' && p2 == 'O' && v1 == 'M' && v2 == 'M') {
					printf("Plaza 1 - Ocupada - Moto - %s\n", matricula);
					printf("Plaza 2 - Ocupada - Moto - %s\n", matricula2);
				}
				else if (p1 == 'O' && p2 == 'O' && v1 == 'C' && v2 == 'M') {
					printf("Plaza 1 - Ocupada - Coche - %s\n", matricula);
					printf("Plaza 2 - Ocupada - Moto  - %s\n", matricula2);
				}
				else if (p1 == 'O' && p2 == 'O' && v1 == 'M' && v2 == 'C') {
					printf("Plaza 1 - Ocupada - Moto  - %s\n", matricula);
					printf("Plaza 2 - Ocupada - Coche - %s\n", matricula2);
				}
				else if (p1 == 'L' && p2 == 'O' && v2 == 'C') {
					printf("Plaza 1 - Libre\n");
					printf("Plaza 2 - Ocupada - Coche - %s\n", matricula2);
				}
				else if (p1 == 'L' && p2 == 'O' && v2 == 'M') {
					printf("Plaza 1 - Libre\n");
					printf("Plaza 2 - Ocupada - Moto -%s\n", matricula2);
				}
			
				system("pause");
				system("cls");
				break;



			case 'b':
			case 'B':
				printf("Has seleccionado el buscador de matriculas\n");

				if (p1 == 'L' && p2 == 'L')
					printf("No hay matriculas registradas actualmente.\n");

				else {
					printf("Escribe la matricula a buscar\n");
					scanf_s("%s", &BuscarMatricula, 8);

					orden2 = strcmp(BuscarMatricula, matricula);  //Funcion para comparar dos strings
					if (orden2 == 0) {
						printf("El vehiculo con matricula %s esta en la plaza 1.\n", matricula);
						getchar();
					}
					else if (orden2 != 0) {

						orden2 = strcmp(BuscarMatricula, matricula2);

						if (orden2 == 0)
							printf("El vehiculo con matricula %s esta en la plaza 2\n", matricula2);
						else
							printf("Esa matricula no esta registrada\n");
						getchar();
					}
				}


				Sleep(2500);
				system("cls");
				break;

			case 's':
			case 'S':
				system("color 0A");
				printf("Has salido del programa\n");
				printf("Pase un buen dia\n");
				bucle = 0;
				system("pause");
				break;

			default:
				system("color 0C");
				printf("Opcion no valida.\n");

				Sleep(1500);
				system("cls");
				break;


			}


		}

	}
