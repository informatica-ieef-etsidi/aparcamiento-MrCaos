//Marcos Velazquez Ruiz



#include <stdio.h>
#include <string.h> // Libreria para realizar funciones con cadenas
#include <time.h> //Libreria para poder poner la hora 
#include <windows.h> //Permite el uso del comando Sleep


struct TPlaza {

	int estado; // L = Libre O=Ocupada
	char tipo; // C=Coche M=Moto
	char matricula[8]; // Formato NNNNLLL
	int HoraE, HoraS; // Hora de entrada y salida
};

struct TUsuario {

	char user[50];
	char contrasena[50];
};


void main() {


	struct TPlaza plaza1 = { 'L', 'C' }, plaza2 = { 'L', 'C' }, plaza3 = { 'L', 'M' }, plaza4 = { 'L', 'M' };

	struct TUsuario persona1;

	int p;
	char opcion; // opcion del menu 
	char vehiculo; // Para seleccionar moto o coche 'M'=Moto 'C'=Coche

	char CompMatricula[8], BuscarMatricula[8];

	char username[7] = "Marcos";
	char password[7] = "qwerty";

	int bucle = 0;
	int i = 0;
	int j, num = 0; // Variables usadas para comprobar si una matricula es valida es decir  NNNNLLL con  las letras tanto mayusculas como minusculas (Si estan en minusculas las pasa a mayusculas) (Tampoco acepta vocales, ya que las matriculas actuales no las usan)

	float coste; // Coste en relacion a la diferencia entre entrada y salida, multiplicada por la tarifa, en este caso 0,05 cents/s


	do
	{
		system("cls");
		printf("Introduce tu username\n");
		gets(persona1.user);


		if (strcmp(persona1.user, username) == 0){

			printf("Introduce tu contrasena\n");
			gets(persona1.contrasena);

			if (strcmp(persona1.contrasena, password) == 0) {
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

	} while (i < 3);

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

			printf("Has seleccionado reservar una plaza.\n\n");
			printf("Seleccione el vehiculo a aparcar\n");
			printf("C - Coche\n");
			printf("M - Moto\n");
			scanf_s("%c", &vehiculo);

			if (plaza1.estado == 'O' && plaza2.estado == 'O' && plaza3.estado == 'O' && plaza4.estado == 'O')
				printf("El aparcamiento esta lleno, vuelva mas tarde\n");

			else {

				switch (vehiculo) {

				case 'C':
				case 'c':
					if (plaza1.estado == 'L') {
						printf("Introduce tu matricula:\n\n");
						scanf_s("%s", &plaza1.matricula, 8);
						getchar();
						for (j = 0; j < 4; j++) {
							if (48 <= plaza1.matricula[j] && plaza1.matricula[j] <= 57) {
								num = num + 1;
								if (num == 4) {
									for (j = 4; j < 7; j++) {
										if (66 <= plaza1.matricula[j] && plaza1.matricula[j] <= 90 && plaza1.matricula[j] != 69 && plaza1.matricula[j] != 73 && plaza1.matricula[j] != 79 && plaza1.matricula[j] != 85) {
											num = num + 1;
										}
										else if (98 <= plaza1.matricula[j] && plaza1.matricula[j] <= 122 && plaza1.matricula[j] != 101 && plaza1.matricula[j] != 105 && plaza1.matricula[j] != 111 && plaza1.matricula[j] != 117) {
											plaza1.matricula[j] = plaza1.matricula[j] - 32;
											num = num + 1;
										}
										else
											num = 0;
									}
								}
							}

							else
								num = 0;
						}

						if (num != 7)
							printf("Matricula invalida\n");

						if (num == 7) {
							printf("Matricula valida\n\n");
							Sleep(1500);
							printf("El coche con la matricula %s esta en la plaza 1\n", plaza1.matricula);
							plaza1.estado = 'O';
							plaza1.HoraE = time(NULL);
						}
						num = 0;
					}

					else if (plaza1.estado == 'O' && plaza2.estado == 'L') {
						printf("Introduce tu matricula:\n\n");
						scanf_s("%s", &plaza2.matricula, 8);
						getchar();
						for (j = 0; j < 4; j++) {
							if (48 <= plaza2.matricula[j] && plaza2.matricula[j] <= 57) {
								num = num + 1;
								if (num == 4) {
									for (j = 4; j < 7; j++) {
										if (66 <= plaza2.matricula[j] && plaza2.matricula[j] <= 90 && plaza2.matricula[j] != 69 && plaza2.matricula[j] != 73 && plaza2.matricula[j] != 79 && plaza2.matricula[j] != 85) {
											num = num + 1;
										}
										else if (98 <= plaza2.matricula[j] && plaza2.matricula[j] <= 122 && plaza2.matricula[j] != 101 && plaza2.matricula[j] != 105 && plaza2.matricula[j] != 111 && plaza2.matricula[j] != 117) {
											plaza2.matricula[j] = plaza2.matricula[j] - 32;
											num = num + 1;
										}
										else
											num = 0;
									}
								}
							}

							else
								num = 0;
						}

						if (num != 7)
							printf("Matricula invalida\n");

						if (num == 7) {
							printf("Matricula valida\n\n");
							Sleep(1500);
							printf("El coche con la matricula %s esta en la plaza 2\n", plaza2.matricula);
							plaza2.estado = 'O';
							plaza2.HoraE = time(NULL);
						}
						num = 0;
					}
					else {
						printf("No hay plazas de coche disponibles\n");
						Sleep(1500);
						getchar();
					}

					Sleep(1500);
					break;

				case 'M':
				case 'm':
					if (plaza3.estado == 'L') {
						printf("Introduce tu matricula:\n\n");
						scanf_s("%s", &plaza3.matricula, 8);
						getchar();
						for (j = 0; j < 4; j++) {
							if (48 <= plaza3.matricula[j] && plaza3.matricula[j] <= 57) {
								num = num + 1;
								if (num == 4) {
									for (j = 4; j < 7; j++) {
										if (66 <= plaza3.matricula[j] && plaza3.matricula[j] <= 90 && plaza3.matricula[j] != 69 && plaza3.matricula[j] != 73 && plaza3.matricula[j] != 79 && plaza3.matricula[j] != 85) {
											num = num + 1;
										}
										else if (98 <= plaza3.matricula[j] && plaza3.matricula[j] <= 122 && plaza3.matricula[j] != 101 && plaza3.matricula[j] != 105 && plaza3.matricula[j] != 111 && plaza3.matricula[j] != 117) {
											plaza3.matricula[j] = plaza3.matricula[j] - 32;
											num = num + 1;
										}
										else
											num = 0;
									}
								}
							}

							else
								num = 0;
						}

						if (num != 7)
							printf("Matricula invalida\n");

						if (num == 7) {
							printf("Matricula valida\n\n");
							Sleep(1500);
							printf("La moto con la matricula %s esta en la plaza 3\n", plaza3.matricula);
							plaza3.estado = 'O';
							plaza3.HoraE = time(NULL);
						}
						num = 0;
					}

					else if (plaza3.estado == 'O' && plaza4.estado == 'L') {
						printf("Introduce tu matricula:\n\n");
						scanf_s("%s", &plaza4.matricula, 8);
						getchar();
						for (j = 0; j < 4; j++) {
							if (48 <= plaza4.matricula[j] && plaza4.matricula[j] <= 57) {
								num = num + 1;
								if (num == 4) {
									for (j = 4; j < 7; j++) {
										if (66 <= plaza4.matricula[j] && plaza4.matricula[j] <= 90 && plaza4.matricula[j] != 69 && plaza4.matricula[j] != 73 && plaza4.matricula[j] != 79 && plaza4.matricula[j] != 85) {
											num = num + 1;
										}
										else if (98 <= plaza4.matricula[j] && plaza4.matricula[j] <= 122 && plaza4.matricula[j] != 101 && plaza4.matricula[j] != 105 && plaza4.matricula[j] != 111 && plaza4.matricula[j] != 117) {
											plaza4.matricula[j] = plaza4.matricula[j] - 32;
											num = num + 1;
										}
										else
											num = 0;
									}
								}
							}

							else
								num = 0;
						}

						if (num != 7)
							printf("Matricula invalida\n");

						if (num == 7) {
							printf("Matricula valida\n\n");
							Sleep(1500);
							printf("La moto con la matricula %s esta en la plaza 4\n", plaza4.matricula);
							plaza4.estado = 'O';
							plaza4.HoraE = time(NULL);
						}
						num = 0;
					}
					else {
						printf("No hay plazas de moto disponibles\n");
						Sleep(1500);
						getchar();

					}
					break;

				default:
					printf("No hay plaza para ese vehiculo\n");
					Sleep(1500);
					getchar();
					break;

				}
			}
			Sleep(1500); 
				break;

		case 'A':
		case 'a':

			if (plaza1.estado == 'L' && plaza2.estado == 'L' && plaza3.estado == 'L' && plaza4.estado == 'L') {
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
					if (plaza1.estado == 'O') {
						printf("Introduce tu matricula\n");
						scanf_s("%s", &CompMatricula, 8);
						for (j = 4; j < 7; j++) {
							if (98 <= CompMatricula[j] && CompMatricula[j] <= 122 && CompMatricula[j] != 101 && CompMatricula[j] != 105 && CompMatricula[j] != 111 && CompMatricula[j] != 117) {
								CompMatricula[j] = CompMatricula[j] - 32;
							}
						}
						getchar();

						 //Funcion para comparar dos strings
						if (strcmp(plaza1.matricula, CompMatricula) == 0) {
							printf("El vehiculo con matricula %s ha sido retirado del parking.\n", plaza1.matricula);
							plaza1.estado = 'L';

							Sleep(750);
							system("cls");

							plaza1.HoraS = time(NULL);
							printf("La tarifa es de 5 centimos por segundo\n");
							coste = 0.05*(plaza1.HoraS - plaza1.HoraE);
							printf("El total a abonar son %.2f euros\n", coste);

							memset(plaza1.matricula, 0, 8); //limpia las cadenas
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
					if (plaza2.estado == 'O') {
						printf("Introduce tu matricula\n");
						scanf_s("%s", &CompMatricula, 8);
						for (j = 4; j < 7; j++) {
							if (98 <= CompMatricula[j] && CompMatricula[j] <= 122 && CompMatricula[j] != 101 && CompMatricula[j] != 105 && CompMatricula[j] != 111 && CompMatricula[j] != 117) {
								CompMatricula[j] = CompMatricula[j] - 32;
							}
						}
						getchar();
						
						//Funcion para comparar dos strings

						if (strcmp(plaza2.matricula, CompMatricula) == 0) {
							printf("El vehiculo con matricula %s ha sido retirado del parking.\n", plaza2.matricula);
							plaza2.estado = 'L';

							Sleep(750);
							system("cls");

							plaza2.HoraS = time(NULL);
							printf("La tarifa es de 5 centimos por segundo\n");
							coste = 0.05*(plaza2.HoraS - plaza1.HoraE);
							printf("El total a abonar son %.2f euros\n", coste);

							memset(plaza2.matricula, 0, 8); //Limpia las cadenas
							memset(CompMatricula, 0, 8);
						}
						else
							printf("Esa matricula no esta registrada\n");
					}
					else {
						printf("En esta plaza no hay ningun coche\n");
						getchar();
					}

					Sleep(1500);
					system("cls");


					break;

				case 3:

					printf("Plaza 3 seleccionada.\n");
					if (plaza3.estado == 'O') {
						printf("Introduce tu matricula\n");
						scanf_s("%s", &CompMatricula, 8);
						for (j = 4; j < 7; j++) {
							if (98 <= CompMatricula[j] && CompMatricula[j] <= 122 && CompMatricula[j] != 101 && CompMatricula[j] != 105 && CompMatricula[j] != 111 && CompMatricula[j] != 117) {
								CompMatricula[j] = CompMatricula[j] - 32;
							}
						}
						getchar();


						if (strcmp(plaza3.matricula, CompMatricula) == 0) {
							printf("La moto con matricula %s ha sido retirado del parking.\n", plaza3.matricula);
							plaza3.estado = 'L';

							Sleep(750);
							system("cls");

							plaza3.HoraS = time(NULL);
							printf("La tarifa es de 5 centimos por segundo\n");
							coste = 0.05*(plaza3.HoraS - plaza3.HoraE);
							printf("El total a abonar son %.2f euros\n", coste);

							memset(plaza3.matricula, 0, 8); //Limpia las cadenas
							memset(CompMatricula, 0, 8);
						}
						else
							printf("Esa matricula no esta registrada\n");
					}
					else {
						printf("En esta plaza no hay ninguna moto\n");
						getchar();
					}

					Sleep(1500);
					system("cls");


					break;

				case 4:

					printf("Plaza 4 seleccionada.\n");
					if (plaza4.estado == 'O') {
						printf("Introduce tu matricula\n");
						scanf_s("%s", &CompMatricula, 8);
						for (j = 4; j < 7; j++) {
							if (98 <= CompMatricula[j] && CompMatricula[j] <= 122 && CompMatricula[j] != 101 && CompMatricula[j] != 105 && CompMatricula[j] != 111 && CompMatricula[j] != 117) {
								CompMatricula[j] = CompMatricula[j] - 32;
							}
						}
						getchar();

		

						if (strcmp(plaza4.matricula, CompMatricula) == 0) {
							printf("La moto con matricula %s ha sido retirado del parking.\n", plaza4.matricula);
							plaza4.estado = 'L';

							Sleep(750);
							system("cls");

							plaza4.HoraS = time(NULL);
							printf("La tarifa es de 5 centimos por segundo\n");
							coste = 0.05*(plaza4.HoraS - plaza4.HoraE);
							printf("El total a abonar son %.2f euros\n", coste);

							memset(plaza4.matricula, 0, 8); //Limpia las cadenas
							memset(CompMatricula, 0, 8);
						}
						else
							printf("Esa matricula no esta registrada\n");
					}
					else {
						printf("En esta plaza no hay ninguna moto\n");
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
			if (plaza1.estado == 'L' && plaza2.estado == 'L') {
				printf("Plaza 1 - Libre\n");
				printf("Plaza 2 - Libre\n");
			}
			else if (plaza1.estado == 'O' && plaza2.estado == 'L') {
				printf("Plaza 1 - Ocupada - Coche - %s\n", plaza1.matricula);
				printf("Plaza 2 - Libre\n");
			}
			else if (plaza1.estado == 'O' && plaza2.estado == 'O') {
				printf("Plaza 1 - Ocupada - Coche - %s\n", plaza1.matricula);
				printf("Plaza 2 - Ocupada - Coche - %s\n", plaza2.matricula);
			}
			else if (plaza1.estado == 'L' && plaza2.estado == 'O') {
				printf("Plaza 1 - Libre\n");
				printf("Plaza 2 - Ocupada - Coche - %s\n", plaza2.matricula);
			}
			if (plaza3.estado == 'L' && plaza4.estado == 'L') {
				printf("Plaza 3 - Libre\n");
				printf("Plaza 4 - Libre\n");
			}
			else if (plaza3.estado == 'O' && plaza4.estado == 'L') {
				printf("Plaza 3 - Ocupada - Moto - %s\n", plaza3.matricula);
				printf("Plaza 4 - Libre\n");
			}
			else if (plaza3.estado == 'O' && plaza4.estado == 'O') {
				printf("Plaza 3 - Ocupada - Moto  - %s\n", plaza3.matricula);
				printf("Plaza 4 - Ocupada - Moto  - %s\n", plaza4.matricula);
			}
			else if (plaza3.estado == 'L' && plaza4.estado == 'O') {
				printf("Plaza 3 - Libre\n");
				printf("Plaza 4 - Ocupada - Moto - %s\n", plaza4.matricula);
			}

			system("pause");
			system("cls");
			break;



		case 'b':
		case 'B':
			printf("Has seleccionado el buscador de matriculas\n");

			if (plaza1.estado == 'L' && plaza1.estado == 'L' && plaza3.estado == 'L' && plaza4.estado == 'L')
				printf("No hay matriculas registradas actualmente.\n");

			else {
				printf("Escribe la matricula a buscar\n");
				scanf_s("%s", &BuscarMatricula, 8);
				for (j = 4; j < 7; j++) {
					if (98 <= BuscarMatricula[j] && BuscarMatricula[j] <= 122 && BuscarMatricula[j] != 101 && BuscarMatricula[j] != 105 && BuscarMatricula[j] != 111 && BuscarMatricula[j] != 117) {
						BuscarMatricula[j] = BuscarMatricula[j] - 32;
					}
				}

				//Funcion para comparar dos strings
				if (strcmp(BuscarMatricula, plaza1.matricula) == 0) {
					printf("El vehiculo con matricula %s esta en la plaza 1.\n", plaza1.matricula);
					getchar();
				}
				else if (strcmp(BuscarMatricula, plaza2.matricula) == 0) {
					printf("El vehiculo con matricula %s esta en la plaza 2\n", plaza2.matricula);
					getchar();
				}

				else if (strcmp(BuscarMatricula, plaza3.matricula) == 0) {
					printf("El vehiculo con matricula %s esta en la plaza 3\n", plaza3.matricula);
					getchar();
				}

				else if (strcmp(BuscarMatricula, plaza4.matricula) == 0) {
					printf("El vehiculo con matricula %s esta en la plaza 4\n", plaza4.matricula);
					getchar();
				}

				else {
					printf("Esa matricula no esta registrada\n");
					getchar();
				}
			}
			memset(BuscarMatricula, 0, 8);


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