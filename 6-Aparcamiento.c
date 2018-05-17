//Marcos Velazquez Ruiz
//Practica 6 del aparcamiento


#include <stdio.h>
#include <string.h> // Libreria para realizar funciones con cadenas
#include <time.h> //Libreria para poder poner la hora 
#include <windows.h> //Permite el uso del comando Sleep


int esDigitoValido(char caracter);
int esLetraValida(char caracter);
int esMatriculaValida(char matricula[8]);
int existeUsuario(struct TUsuario usuarioValido, char username[50], char password[50]);
void inicializar(struct TPlaza parking[], int dim);
int buscarPlazaLibre(struct TPlaza parking[], int dim, char tipo);
void recuento(struct Tplaza parking[], int dim, int *nLibresCoches, int *nLibresMotos);
int buscarVehiculo(struct TPlaza parking[], int dim, char matricula[]);

#define NPLAZAS 10 
#define NUSERS 3


struct TPlaza {

	int estado; // L = Libre O=Ocupada
	char tipo;
	char matricula[8]; // Formato NNNNLLL
	int HoraE, HoraS; // Hora de entrada y salida
};

struct TUsuario {

	char user[50];
	char contrasena[50];
};


void main() {


	struct TPlaza parking[NPLAZAS];


	struct TUsuario persona[NUSERS] = { { "Marcos", "qwerty" },{ "User", "4321" }, { "Admin", "1234" } }; // Defino cuantos usuarios y sus contraseñas para acceder

	char opcion; // opcion del menu 
	char vehiculo; // Para seleccionar moto o coche 'M'= Moto 'C'= Coche

	char CompMatricula[8], BuscarMatricula[8];

	char username[50];
	char password[50];

	int bucle = 0;
	int i, j, CLibres = 0,MLibres=0,busqueda;
	int  num = 0; // Variables usadas para comprobar si una matricula es valida es decir  NNNNLLL con  las letras tanto mayusculas como minusculas (Si estan en minusculas las pasa a mayusculas) (Tampoco acepta vocales, ya que las matriculas actuales no las usan)

	float coste; // Coste en relacion a la diferencia entre entrada y salida, multiplicada por la tarifa, en este caso 5 cents/s para coche y 3 cents/s para moto

	//Fija la condicion de libre para todas las plazas

	inicializar(parking, NPLAZAS);

	//Comprueba que el usuario esta registrado




		for (i = 0; i < 3; i++) {
			system("cls");
			if (bucle != 1) {
				printf("Introduce tu username\n");
				gets(username);

				for (j = 0; j <= NUSERS; j++) {
					if (existeUsuario(persona[j], username, password) == 1) {
						printf("Introduce tu contrase%ca\n",164); // 164 para poner la letra ñ
						gets(password);

						if (existeUsuario(persona[j], username, password) == 2) {
							bucle = 1;
							system("cls");
							printf("Iniciando el programa...\n");
							Sleep(1500);
							break;
						}
						else {
							printf("Contrase%ca incorrecta\n",164);
							system("pause");
						}
						break;
					}
				}
				if (existeUsuario(persona[j], username, password) != 1 && existeUsuario(persona[j], username, password) !=2) {
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

				if (buscarPlazaLibre(parking, NPLAZAS, vehiculo) == -1){
					printf("Todas las plazas ocupadas\n");

				}
		
				else {

					num = 0;
					for (i = 0; i <= NPLAZAS/2; i++) {
						if (parking[i].estado == 'L') {
							printf("Introduzca la matricula de su coche:\n\n");
							scanf_s("%s", &parking[i].matricula, 8);
							getchar();

							if (esMatriculaValida(parking[i].matricula) == 1) {

								strcpy_s(CompMatricula, 8, parking[i].matricula);

								for (j = 0; j <= NPLAZAS; j++) {	//Comprueba que una matricula no este registrada en otra plaza, ya sea de moto o coche
									if (strcmp(CompMatricula, parking[j].matricula) == 0) {
										num = num + 1;
									}
								}
								if (num > 1) {
									printf("Esa matricula ya esta registrada\n");
									memset(parking[i].matricula, 0, 8); //Limpia la cadena
									break;
								}
								else {
									printf("Matricula valida\n\n");
									Sleep(1500);
									printf("El coche con la matricula %s esta en la plaza %d\n", parking[i].matricula, i + 1);
									parking[i].estado = 'O';
									parking[i].HoraE = time(NULL);
								}

							}
							else
								printf("Matricula invalida\n");
							break;


						}

					}
				}
				break;

			case 'M':
			case 'm':

				if (buscarPlazaLibre(parking, NPLAZAS, vehiculo) == -1) {
					printf("Todas las plazas ocupadas\n");
				}
				else {

					num = 0;
					for (i = NPLAZAS / 2; i <= NPLAZAS; i++) {
						if (parking[i].estado == 'L') {
							printf("Introduzca la matricula de su moto:\n\n");
							scanf_s("%s", &parking[i].matricula, 8);
							getchar();


							if (esMatriculaValida(parking[i].matricula) == 1) {

								strcpy_s(CompMatricula, 8, parking[i].matricula);

								for (j = 0; j <= NPLAZAS; j++) {
									if (strcmp(CompMatricula, parking[j].matricula) == 0) {
										num = num + 1;
									}
									
								}
								if (num > 1) {
									printf("Esa matricula ya esta registrada\n");
									memset(parking[i].matricula, 0, 8);
									break;
								}
								else {

									printf("Matricula valida\n\n");
									Sleep(1500);
									printf("La moto con la matricula %s esta en la plaza %d\n", parking[i].matricula, i + 1);
									parking[i].estado = 'O';
									parking[i].HoraE = time(NULL);
								}
							}

							else {
								printf("Matricula invalida\n");
								Sleep(1500);
							}
							break;
						}


					}
				}
				break;

			default:
				system("cls");
				system("color 0C");
				printf("Opcion no valida.\n");

				Sleep(1500);



				system("pause");
			}
			system("pause");
			break;
		
		case 'A':
		case 'a':


				printf("Has seleccionado abandonar una plaza.\n");
				printf("Introduzca su matricula\n");
				scanf_s("%s", &BuscarMatricula, 8);

				if (esMatriculaValida(BuscarMatricula) == 1) {

					//Comprueba si una matricula esta en una plaza de coche o de moto y la saca de ahi

					for (i = 0; i < NPLAZAS; i++) {

						if (strcmp(BuscarMatricula, parking[i].matricula) == 0) {

							break;
						}
					}

					if (strcmp(BuscarMatricula, parking[i].matricula) == 0) {
						if (i < NPLAZAS / 2) {
							printf("El coche con matricula %s ha abandonado la plaza %d\n", parking[i].matricula, i + 1);
							parking[i].estado = 'L';
							parking[i].HoraS = time(NULL);
							printf("La tarifa es de 5 centimos por segundo\n");
							coste = 0.05*(parking[i].HoraS - parking[i].HoraE);
							printf("El total a abonar son %.2f euros\n", coste);
						}
						else {
							printf("La moto con matricula %s ha abandonado la plaza %d\n", parking[i].matricula, i + 1);
							parking[i].estado = 'L';
							parking[i].HoraS = time(NULL);;
							printf("La tarifa es de 3 centimos por segundo\n");
							coste = 0.03*(parking[i].HoraS - parking[i].HoraE);
							printf("El total a abonar son %.2f euros\n", coste);
						}
						memset(BuscarMatricula, 0, 8);
						memset(parking[i].matricula, 0, 8);
					}

					else {
						printf("No hay ningun vehiculo con la matricula %s en el aparcamiento\n", BuscarMatricula);
						memset(BuscarMatricula, 0, 8);
					}

				}
				else
					printf("Matricula invalida\n");

				Sleep(1500);
				system("pause");
				getchar();


				break;

		case 'E':
		case 'e':
				system("color 0D");
				printf("Has seleccionado ver el estado del aparcamiento.\n\n");

				recuento(parking, NPLAZAS, &CLibres, &MLibres);
				printf("%d plazas libres de coche y %d plazas libre de moto\n", CLibres, MLibres);

				printf("Plazas de coche:\n");
				for (i = 0; i < NPLAZAS/2; i++) {
					if (parking[i].estado == 'L')
						printf("Plaza %d - Libre\n", i + 1);

					else {
						printf("Plaza %d - Coche - %s\n", i + 1, parking[i].matricula);
					}
				}

				printf("\nPlazas de moto:\n");
				for (i = NPLAZAS/2; i < NPLAZAS; i++) {
					if (parking[i].estado == 'L')
						printf("Plaza %d - Libre\n", i + 1);

					else {
						printf("Plaza %d - Moto - %s\n", i + 1, parking[i].matricula);
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

				if (esMatriculaValida(BuscarMatricula) == 1) {

					busqueda = buscarVehiculo(parking, NPLAZAS, BuscarMatricula);

					if (busqueda == -1) {
						printf("La matricula %s no esta registrada\n", BuscarMatricula);
						memset(BuscarMatricula, 0, 8);
					}
					else if (busqueda < NPLAZAS / 2) {
						printf("El coche con  matricula %s se encuentra en la plaza %d\n", parking[busqueda].matricula, busqueda + 1);
						memset(BuscarMatricula, 0, 8);
					}
					else {
						printf("La moto con matricula %s se encuentra en la plaza  %d\n", parking[busqueda].matricula, busqueda + 1);
						memset(BuscarMatricula, 0, 8);
					}
				}
				else
					printf("Matricula invalida\n");

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

void menu(){

	char opcion;
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
}

	int esDigitoValido(char caracter) {
		if (48 <= caracter && caracter <= 57) {
			return 1;
		}
		return 0;
	}

	int esLetraValida(char caracter) {
		int aux = 0;
		if (98 <= caracter && caracter <= 122) {
			caracter = caracter - 32;
		}
		if (66 <= caracter && caracter <= 90 && caracter != 69 && caracter != 73 && caracter != 79 && caracter != 85) {
			aux = 1;
		}
		return aux;
	}
	int esMatriculaValida(char matricula[8]) {
		int esDigitoValido(char caracter);
		int esLetraValida(char caracter);

		int i, aux = 0, aux2 = 0, bol = 0;

		for (i = 4; i < 7; i++) {
			if (98 <= matricula[i] && matricula[i] <= 122) {
				matricula[i] -= 32;
			}
		}
		for (i = 0; i < 4; i++) {
			if (esDigitoValido(matricula[i]) == 1) {
				aux = aux + 1;
			}

			if (aux == 4) {
				for (i = 4; i < 7; i++) {
					if (esLetraValida(matricula[i]) == 1) {
						aux2 = aux2 + 1;
					}
				}
			}
		}
		if (aux2 == 3)
			bol = 1;

		return bol;
	}
	int existeUsuario(struct TUsuario usuarioValido, char username[], char password[]) {

		int valido;

		if ((strcmp(username, usuarioValido.user)) == 0) {
			valido = 1;
			if ((strcmp(password, usuarioValido.contrasena)) == 0)
				valido = 2;
		}
		else {
			valido = 0;
		}

		return valido;
	}
	void inicializar(struct TPlaza parking[], int dim) {
		int i;
		int j;

		for (i = 0; i < dim/2; i++) {
			parking[i].estado = 'L';
			parking[i].tipo = 'C';
		}

		for (i = dim/2; i < dim; i++) {
			parking[i].estado = 'L';
			parking[i].tipo = 'M';
		}


	}
	int buscarPlazaLibre(struct TPlaza parking[], int dim, char tipo){
	
		int i;
		if (tipo == 'C') {
			for (i = 0; i < dim/2; i++) {
				if (parking[i].estado == 'O')
					return i;
			}
			return -1;
		}
		else if (tipo == 'M') {
			for (i = dim/2; i < dim; i++) {
				if (parking[i].estado == 'O')
					return i;
			}
			return -1;
		}
	}


	void recuento(struct TPlaza parking[], int dim, int *nLibresCoches, int *nLibresMotos) {

		int i;
		*nLibresCoches = 0;
		*nLibresMotos = 0;

		for (i = 0; i < NPLAZAS / 2; i++) {
			if (parking[i].estado == 'L')
				*nLibresCoches = *nLibresCoches + 1;
		}
		for (i = NPLAZAS/2; i < NPLAZAS; i++) {
			if (parking[i].estado == 'L')
				*nLibresMotos = *nLibresMotos + 1;

		}

	}
	int buscarVehiculo(struct TPlaza parking[], int dim, char matricula[]) {
		
		int i;
		
		for (i = 0; i < dim; i++) {
			if (strcmp(matricula, parking[i].matricula) == 0)
				return i;
		}

		return -1;
	}