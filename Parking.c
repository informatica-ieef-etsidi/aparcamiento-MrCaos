#include <stdio.h>
#include <string.h> // Libreria para realizar funciones con cadenas
#include <time.h> //Libreria para poder poner la hora en un futuro
#include <windows.h>


void main() {

	int p1 = 'L', p2 = 'L', p3 = 'L', p4 = 'L', p;//p = plaza L=Libre O=Ocupada p1 y p2 plazas de coche, p3 y p4 plazas de moto
	char opcion; // opcion del menu 
	char vehiculo; // Para seleccionar moto o coche 'M'=Moto 'C'=Coche
	char matricula[8], matricula2[8], matricula3[8], matricula4[8], CompMatricula[8], BuscarMatricula[8]; // Matriculas, comprobacion para el caso A y buscar para el caso B
	int compUser, compPass; // Para comparar el username y la password escritos con las del usuario
	int orden, orden2; // para comparar las matriculas en el caso A

	char username[7] = "Marcos";
	char password[7] = "qwerty";
	char contrasena[7], usuario[7];
	int bucle = 0;
	int i = 0;
	int j, num = 0; // Variables usadas para comprobar si una matricula es valida es decir  NNNNLLL con  las letras tanto mayusculas como minusculas (Si estan en minusculas las pasa a mayusculas) (Tampoco acepta vocales, ya que las matriculas actuales no las usan)

	int HoraE1, HoraE2, HoraE3, HoraE4; // Hora entrada para la plaza 1 y 2
	int HoraS1, HoraS2, HoraS3, HoraS4; // Hora salida para la plaza 1 y 2
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

			if (p1 == 'O' && p2 == 'O' && p3 == 'O' && p4 == 'O')
				printf("El aparcamiento esta lleno, vuelva mas tarde\n");

			else{

				switch (vehiculo) {

				case 'C':
				case 'c':
					if (p1 == 'L') {
						printf("Introduce tu matricula:\n\n");
						scanf_s("%s", &matricula, 8);
						getchar();
						for (j = 0; j < 4; j++) {
							if (48 <= matricula[j] && matricula[j] <= 57) {
								num = num + 1;
								if (num == 4) {
									for (j = 4; j < 7; j++) {
										if (66 <= matricula[j] && matricula[j] <= 90 && matricula[j] != 69 && matricula[j] != 73 && matricula[j] != 79 && matricula[j] != 85) {
											num = num + 1;
										}
										else if (98 <= matricula[j] && matricula[j] <= 122 && matricula[j] != 101 && matricula[j] != 105 && matricula[j] != 111 && matricula[j] != 117) {
											matricula[j] = matricula[j] - 32;
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
							printf("El coche con la matricula %s esta en la plaza 1\n", matricula);
							p1 = 'O';
							HoraE1 = time(NULL);
						}
						num = 0;
					}

					else if (p1 == 'O' && p2 == 'L') {
						printf("Introduce tu matricula:\n\n");
						scanf_s("%s", &matricula2, 8);
						getchar();
						for (j = 0; j < 4; j++) {
							if (48 <= matricula2[j] && matricula2[j] <= 57) {
								num = num + 1;
								if (num == 4) {
									for (j = 4; j < 7; j++) {
										if (66 <= matricula2[j] && matricula2[j] <= 90 && matricula2[j] != 69 && matricula2[j] != 73 && matricula2[j] != 79 && matricula2[j] != 85) {
											num = num + 1;
										}
										else if (98 <= matricula2[j] && matricula2[j] <= 122 && matricula2[j] != 101 && matricula2[j] != 105 && matricula2[j] != 111 && matricula2[j] != 117) {
											matricula2[j] = matricula2[j] - 32;
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
							printf("El coche con la matricula %s esta en la plaza 2\n", matricula);
							p2 = 'O';
							HoraE2 = time(NULL);
						}
						num = 0;
					}
					else{
						printf("No hay plazas de coche disponibles\n");
					Sleep(1500);
					getchar();
				}

				Sleep(1500);
				break;

			case 'M':
			case 'm':
				if (p3 == 'L') {
					printf("Introduce tu matricula:\n\n");
					scanf_s("%s", &matricula3, 8);
					getchar();
					for (j = 0; j < 4; j++) {
						if (48 <= matricula3[j] && matricula3[j] <= 57) {
							num = num + 1;
							if (num == 4) {
								for (j = 4; j < 7; j++) {
									if (66 <= matricula3[j] && matricula3[j] <= 90 && matricula3[j] != 69 && matricula3[j] != 73 && matricula3[j] != 79 && matricula3[j] != 85) {
										num = num + 1;
									}
									else if (98 <= matricula3[j] && matricula3[j] <= 122 && matricula3[j] != 101 && matricula3[j] != 105 && matricula3[j] != 111 && matricula3[j] != 117) {
										matricula3[j] = matricula3[j] - 32;
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
						printf("La moto con la matricula %s esta en la plaza 3\n", matricula3);
						p3 = 'O';
						HoraE3 = time(NULL);
					}
					num = 0;
				}

				else if (p3 == 'O' && p4 == 'L') {
					printf("Introduce tu matricula:\n\n");
					scanf_s("%s", &matricula4, 8);
					getchar();
					for (j = 0; j < 4; j++) {
						if (48 <= matricula4[j] && matricula4[j] <= 57) {
							num = num + 1;
							if (num == 4) {
								for (j = 4; j < 7; j++) {
									if (66 <= matricula4[j] && matricula4[j] <= 90 && matricula4[j] != 69 && matricula4[j] != 73 && matricula4[j] != 79 && matricula4[j] != 85) {
										num = num + 1;
									}
									else if (98 <= matricula4[j] && matricula4[j] <= 122 && matricula4[j] != 101 && matricula4[j] != 105 && matricula4[j] != 111 && matricula4[j] != 117) {
										matricula4[j] = matricula4[j] - 32;
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
						printf("La moto con la matricula %s esta en la plaza 4\n", matricula4);
						p4 = 'O';
						HoraE4 = time(NULL);
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
			break;

		case 'A':
		case 'a':

			if (p1 == 'L' && p2 == 'L' && p3=='L' && p4=='L'){
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
							printf("En esta plaza no hay ningun coche\n");
							getchar();
						}

						Sleep(1500);
						system("cls");


						break;

				case 3:

					printf("Plaza 3 seleccionada.\n");
					if (p3 == 'O') {
						printf("Introduce tu matricula\n");
						scanf_s("%s", &CompMatricula, 8);
						getchar();

						orden = strcmp(matricula3, CompMatricula);//Funcion para comparar dos strings

						if (orden == 0) {
							printf("La moto con matricula %s ha sido retirado del parking.\n", matricula3);
							p3 = 'L';

							Sleep(750);
							system("cls");

							HoraS3 = time(NULL);
							printf("La tarifa es de 5 centimos por segundo\n");
							coste = 0.05*(HoraS3 - HoraE3);
							printf("El total a abonar son %.2f euros\n", coste);

							memset(matricula3, 0, 8); //Limpia las cadenas
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
					if (p4 == 'O') {
						printf("Introduce tu matricula\n");
						scanf_s("%s", &CompMatricula, 8);
						getchar();

						orden = strcmp(matricula4, CompMatricula);//Funcion para comparar dos strings

						if (orden == 0) {
							printf("La moto con matricula %s ha sido retirado del parking.\n", matricula4);
							p3 = 'L';

							Sleep(750);
							system("cls");

							HoraS4 = time(NULL);
							printf("La tarifa es de 5 centimos por segundo\n");
							coste = 0.05*(HoraS4 - HoraE4);
							printf("El total a abonar son %.2f euros\n", coste);

							memset(matricula4, 0, 8); //Limpia las cadenas
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
				if (p1 == 'L' && p2 == 'L') {
					printf("Plaza 1 - Libre\n");
					printf("Plaza 2 - Libre\n");
				}
				else if (p1 == 'O' && p2 == 'L') {
					printf("Plaza 1 - Ocupada - Coche - %s\n", matricula);
					printf("Plaza 2 - Libre\n");
				}
				else if (p1 == 'O' && p2 == 'O') {
					printf("Plaza 1 - Ocupada - Coche - %s\n", matricula);
					printf("Plaza 2 - Ocupada - Coche - %s\n", matricula2);
				}
				if (p3 == 'L' && p4 == 'L') {
					printf("Plaza 3 - Libre\n");
					printf("Plaza 4 - Libre\n");
				}
				else if (p3 == 'O' && p4 == 'L') {
					printf("Plaza 3 - Ocupada - Moto - %s\n", matricula3);
					printf("Plaza 4 - Libre\n");
				}
				else if (p3 == 'O' && p4 == 'O') {
					printf("Plaza 1 - Ocupada - Moto  - %s\n", matricula3);
					printf("Plaza 2 - Ocupada - Moto  - %s\n", matricula4);
				}
		
				system("pause");
				system("cls");
				break;



			case 'b':
			case 'B':
				printf("Has seleccionado el buscador de matriculas\n");

				if (p1 == 'L' && p2 == 'L' && p3 == 'L' && p4 == 'L')
					printf("No hay matriculas registradas actualmente.\n");

				else {
					printf("Escribe la matricula a buscar\n");
					scanf_s("%s", &BuscarMatricula, 8);

					//Funcion para comparar dos strings
					if (strcmp(BuscarMatricula, matricula) == 0){
						printf("El vehiculo con matricula %s esta en la plaza 1.\n", matricula);
						getchar();
					}
					else if (strcmp(BuscarMatricula, matricula2) == 0){
						printf("El vehiculo con matricula %s esta en la plaza 2\n", matricula2);
					getchar();
				}

					else if (strcmp(BuscarMatricula, matricula3) == 0){
						printf("El vehiculo con matricula %s esta en la plaza 3\n", matricula3);
					getchar();
				}

					else if (strcmp(BuscarMatricula, matricula4) == 0){
						printf("El vehiculo con matricula %s esta en la plaza 4\n", matricula4);
					getchar();
				}

					else{
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