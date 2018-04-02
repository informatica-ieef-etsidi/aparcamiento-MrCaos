//Marcos Velazquez Ruiz
//Practica 4 del aparcamiento


#include <stdio.h>
#include <string.h> // Libreria para realizar funciones con cadenas
#include <time.h> //Libreria para poder poner la hora 
#include <windows.h> //Permite el uso del comando Sleep


#define NPLAZASC 3
#define NPLAZASM 3
#define NUSERS 3


struct TPlaza {

	int estado; // L = Libre O=Ocupada
	char matricula[8]; // Formato NNNNLLL
	int HoraE, HoraS; // Hora de entrada y salida
};

struct TUsuario {

	char user[50];
	char contrasena[50];
};


void main() {


	struct TPlaza coche[NPLAZASC];
	struct TPlaza moto[NPLAZASM];


	struct TUsuario persona[NUSERS] = { { "Marcos", "qwerty" },{ "User", "4321" }, { "Admin", "1234" } }; // Defino cuantos usuarios y sus contraseñas para acceder

	char opcion; // opcion del menu 
	char vehiculo; // Para seleccionar moto o coche 'M'=Moto 'C'=Coche

	char CompMatricula[8], BuscarMatricula[8];

	char username[50];
	char password[50];

	int bucle = 0;
	int i, j;
	int  num = 0; // Variables usadas para comprobar si una matricula es valida es decir  NNNNLLL con  las letras tanto mayusculas como minusculas (Si estan en minusculas las pasa a mayusculas) (Tampoco acepta vocales, ya que las matriculas actuales no las usan)

	float coste; // Coste en relacion a la diferencia entre entrada y salida, multiplicada por la tarifa, en este caso 5 cents/s para coche y 3 cents/s para moto

	//Fija la condicion de libre para todas las plazas
	for (i = 0; i < NPLAZASC; i++) {
		coche[i].estado = 'L';
	}

	for (j = 0; j < NPLAZASC; j++) {
		moto[j].estado = 'L';
	}

	//Comprueba que el usuario esta registrado

		for (i = 0; i < 3; i++) {
			system("cls");
			if (bucle != 1) {
				printf("Introduce tu username\n");
				gets(username);
				num = 0;

				for (j = 0; j <= NUSERS; j++) {
					if (strcmp(persona[j].user, username) == 0) {
						num = 1;
						printf("Introduce tu contrase%ca\n",164); // 164 para poner la letra ñ
						gets(password);

						if (strcmp(persona[j].contrasena, password) == 0) {
							bucle = 1;
							system("cls");
							printf("Iniciando el programa...\n");
							Sleep(1500);
							break;


						}
						else {
							printf("Contrasena incorrecta\n");
							system("pause");
						}
					}
				}
				if (num != 1) {
					printf("Usuario no registrado\n");
					system("pause");
				}
			}
		}

	//Tras 3 intentos te echa del programa
	if (bucle == 0) {
		system("cls");
		system("color 0C");
		printf("Abandonando el programa...\n");
		Sleep(1500);
	}

	//Si el registro es correcto se accede al menu principal
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


		case 'R':
		case 'r':
			num = 0;
			printf("Has seleccionado reservar una plaza.\n\n");
			printf("Seleccione el vehiculo a aparcar\n");
			printf("C - Coche\n");
			printf("M - Moto\n");
			scanf_s("%c", &vehiculo);
			getchar();

			switch (vehiculo) {

			case 'C':
			case 'c':

				for (i = 0; i <= NPLAZASC; i++) {
					if (coche[i].estado == 'O')
						num = num + 1;
				}
				if (num == NPLAZASC)
					printf("Todas las plazas ocupadas\n");


				else {

					num = 0;
					for (i = 0; i <= NPLAZASC; i++) {
						if (coche[i].estado == 'L') {
							printf("Introduzca la matricula de su coche:\n\n");
							scanf_s("%s", &coche[i].matricula, 8);
							getchar();



							for (j = 4; j <= 7; j++) {
								if (98 <= coche[i].matricula[j] && coche[i].matricula[j] <= 122 && coche[i].matricula[j] != 101 && coche[i].matricula[j] != 105 && coche[i].matricula[j] != 111 && coche[i].matricula[j] != 117)
									coche[i].matricula[j] = coche[i].matricula[j] - 32;
							}

							strcpy_s(CompMatricula, 8, coche[i].matricula);

							for (j = 0; j <= NPLAZASC; j++) {	//Comprueba que una matricula no este registrada en otra plaza, ya sea de moto o coche
								if (strcmp(CompMatricula, coche[j].matricula) == 0) {
									num = num + 1;
								}
								if (strcmp(CompMatricula, moto[j].matricula) == 0) {
									num = num + 1;
								}
							}
							if (num  > 1) {
								printf("Esa matricula ya esta registrada\n");
								memset(coche[i].matricula, 0, 8); //Limpia la cadena
								break;
							}

							else {
								num = 0;


								for (j = 0; j <= 4; j++) {
									if (48 <= coche[i].matricula[j] && coche[i].matricula[j] <= 57) {
										num = num + 1;
									}
								}
								if (num == 4) {
									for (j = 4; j < 7; j++) {
										if (66 <= coche[i].matricula[j] && coche[i].matricula[j] <= 90 && coche[i].matricula[j] != 69 && coche[i].matricula[j] != 73 && coche[i].matricula[j] != 79 && coche[i].matricula[j] != 85) {
											num = num + 1;
										}
										else if (98 <= coche[i].matricula[j] && coche[i].matricula[j] <= 122 && coche[i].matricula[j] != 101 && coche[i].matricula[j] != 105 && coche[i].matricula[j] != 111 && coche[i].matricula[j] != 117) {
											coche[i].matricula[j] = coche[i].matricula[j] - 32;
											num = num + 1;
										}
										else
											num = 0;
									}
								}

								else
									num = 0;


								if (num != 7)
									printf("Matricula invalida\n");

								if (num == 7) {	//Si la matricula es correcta guarda la hora y cambia a ocupado esa plaza
									printf("Matricula valida\n\n");
									Sleep(1500);
									printf("El coche con la matricula %s esta en la plaza %d\n", coche[i].matricula, i + 1);
									coche[i].estado = 'O';
									coche[i].HoraE = time(NULL);
								}
								num = 0;
								break;

							}
						}

					}
				}

				break;

			case 'M':
			case 'm':

				for (i = 0; i <= NPLAZASM; i++) {
					if (moto[i].estado == 'O')
						num = num + 1;
				}
				if (num == NPLAZASM)
					printf("Todas las plazas ocupadas\n");



				else {

					num = 0;
					for (i = 0; i <= NPLAZASM; i++) {
						if (moto[i].estado == 'L') {
							printf("Introduzca la matricula de su moto:\n\n");
							scanf_s("%s", &moto[i].matricula, 8);
							getchar();



							for (j = 4; j <= 7; j++) {
								if (98 <= moto[i].matricula[j] && moto[i].matricula[j] <= 122 && moto[i].matricula[j] != 101 && moto[i].matricula[j] != 105 && moto[i].matricula[j] != 111 && moto[i].matricula[j] != 117)
									moto[i].matricula[j] = moto[i].matricula[j] - 32;
							}

							strcpy_s(CompMatricula, 8, moto[i].matricula);

							for (j = 0; j <= NPLAZASC; j++) {
								if (strcmp(CompMatricula, moto[j].matricula) == 0) {
									num = num + 1;
								}
								if (strcmp(CompMatricula, coche[j].matricula) == 0) {
									num = num + 1;
								}
							}
							if (num > 1) {
								printf("Esa matricula ya esta registrada\n");
								memset(moto[i].matricula, 0, 8);
								break;
							}

							else {
								num = 0;


								for (j = 0; j <= 4; j++) {
									if (48 <= moto[i].matricula[j] && moto[i].matricula[j] <= 57) {
										num = num + 1;
									}
								}
								if (num == 4) {
									for (j = 4; j < 7; j++) {
										if (66 <= moto[i].matricula[j] && moto[i].matricula[j] <= 90 && moto[i].matricula[j] != 69 && moto[i].matricula[j] != 73 && moto[i].matricula[j] != 79 && moto[i].matricula[j] != 85) {
											num = num + 1;
										}
										else if (98 <= moto[i].matricula[j] && moto[i].matricula[j] <= 122 && moto[i].matricula[j] != 101 && moto[i].matricula[j] != 105 && moto[i].matricula[j] != 111 && moto[i].matricula[j] != 117) {
											moto[i].matricula[j] = moto[i].matricula[j] - 32;
											num = num + 1;
										}
										else
											num = 0;
									}
								}

								else
									num = 0;


								if (num != 7)
									printf("Matricula invalida\n");

								if (num == 7) {
									printf("Matricula valida\n\n");
									Sleep(1500);
									printf("La moto con la matricula %s esta en la plaza %d\n", moto[i].matricula, i + 1);
									moto[i].estado = 'O';
									moto[i].HoraE = time(NULL);
								}
								num = 0;
								break;

							}
						}

					}
				}

			default:
				system("cls");
				system("color 0C");
				printf("Opcion no valida.\n");

				Sleep(1500);
				
		
			}
			system("pause");
			break;


			case 'A':
			case 'a':


				printf("Has seleccionado abandonar una plaza.\n");
				printf("Introduzca su matricula\n");
				scanf_s("%s", &BuscarMatricula, 8);

				for (j = 4; j <= 7; j++) {
					if (98 <= BuscarMatricula[j] && BuscarMatricula[j] <= 122 && BuscarMatricula[j] != 101 && BuscarMatricula[j] != 105 && BuscarMatricula[j] != 111 && BuscarMatricula[j] != 117)
						BuscarMatricula[j] = BuscarMatricula[j] - 32;
				}

				//Comprueba si una matricula esta en una plaza de coche o de moto y la saca de ahi

				for (i = 0; i < NPLAZASC; i++) {

					if (strcmp(BuscarMatricula, coche[i].matricula) == 0) {

						break;
					}
				}
				for (j = 0; j < NPLAZASM; j++) {

					if (strcmp(BuscarMatricula, moto[j].matricula) == 0) {

						break;
					}
				}

				if (strcmp(BuscarMatricula, coche[i].matricula) == 0) {
					printf("El coche con matricula %s ha abandonado la plaza %d\n", coche[i].matricula, i + 1);
					coche[i].estado = 'L';
					coche[i].HoraS = time(NULL);
					printf("La tarifa es de 5 centimos por segundo\n");
					coste = 0.05*(coche[i].HoraS - coche[i].HoraE);
					printf("El total a abonar son %.2f euros\n", coste);

					memset(BuscarMatricula, 0, 8);
					memset(coche[i].matricula, 0, 8);
				}

				else if (strcmp(BuscarMatricula, moto[j].matricula) == 0) {
					printf("La moto con matricula %s ha abandonado la plaza %d\n", moto[j].matricula, j + 1);
					moto[j].estado = 'L';
					moto[j].HoraS = time(NULL);
					printf("La tarifa es de 3 centimos por segundo\n");
					coste = 0.03*(moto[j].HoraS - moto[j].HoraE);
					printf("El total a abonar son %.2f euros\n", coste);

					memset(BuscarMatricula, 0, 8);
					memset(moto[j].matricula, 0, 8);
				}

				else {
					printf("No hay ningun vehiculo con la matricula %s en el aparcamiento\n", BuscarMatricula);
					memset(BuscarMatricula, 0, 8);
				}

				Sleep(1500);
				system("pause");
				getchar();


				break;

			case 'E':
			case 'e':
				system("color 0D");
				printf("Has seleccionado ver el estado del aparcamiento.\n\n");

				printf("Plazas de coche:\n");
				for (i = 0; i < NPLAZASC; i++) {
					if (coche[i].estado == 'L')
						printf("Plaza %d - Libre\n", i + 1);

					else {
						printf("Plaza %d - Coche - %s\n", i + 1, coche[i].matricula);
					}
				}

				printf("\nPlazas de moto:\n");
				for (i = 0; i < NPLAZASM; i++) {
					if (moto[i].estado == 'L')
						printf("Plaza %d - Libre\n", i + 1);

					else {
						printf("Plaza %d - Moto - %s\n", i + 1, moto[i].matricula);
					}
				}

				printf("\n");
				system("pause");

				break;



			case 'b':
			case 'B':
				printf("Has seleccionado el buscador de matriculas\n");
				printf("Introduzca la matricula a buscar\n");
				scanf_s("%s", BuscarMatricula, 8);

				for (j = 4; j <= 7; j++) {
					if (98 <= BuscarMatricula[j] && BuscarMatricula[j] <= 122 && BuscarMatricula[j] != 101 && BuscarMatricula[j] != 105 && BuscarMatricula[j] != 111 && BuscarMatricula[j] != 117)
						BuscarMatricula[j] = BuscarMatricula[j] - 32;
				}

				for (i = 0; i < NPLAZASC; i++) {

					if (strcmp(BuscarMatricula, coche[i].matricula) == 0) {

						break;
					}
				}
				for (j = 0; j < NPLAZASM; j++) {

					if (strcmp(BuscarMatricula, moto[j].matricula) == 0) {

						break;
					}
				}

				if (strcmp(BuscarMatricula, coche[i].matricula) == 0) {
					printf("El coche con  matricula %s se encuentra en la plaza %d\n", coche[i].matricula, i + 1);
					memset(BuscarMatricula, 0, 8);
				}

				else if (strcmp(BuscarMatricula, moto[j].matricula) == 0) {
					printf("La moto con matricula %s se encuentra en la plaza  %d\n", moto[j].matricula, j + 1);
					memset(BuscarMatricula, 0, 8);
				}

				else {
					printf("La matricula %s no esta registrada\n", BuscarMatricula);
					memset(BuscarMatricula, 0, 8);
				}

				system("pause");
				getchar();
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


