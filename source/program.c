#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define N 8

typedef struct {
	int dia;
	int mes;
	int anio;
} T_FECHA;

typedef struct {
	T_FECHA fecha;
	int id_radar;
	char matricula[N];
	int velocidad;
	float multa;
} T_MULTA;

typedef struct {
	int id_radar;
	int velocidad_limite;
	int umbral20;
	int umbral40;
	int umbral_resto;
} T_RADAR;

/// @brief Controla la entrada de datos manual de los radares.
/// @param radares Array de radares a rellenar.
/// @param num_radares Entero que representa el número total de
/// 				   radares que se desean introducir.
void cargaRadaresManual (T_RADAR *radares, int num_radares);
/// @brief Controla la entrada de datos manual de las multas.
/// @param radares Array de multas a rellenar.
/// @param num_radares Entero que representa el número total de
/// 				   multas que se desean introducir.
void cargaMultasManual(T_MULTA *multas, int num_multas);
double CalculaMultas(T_MULTA *multas, int num_multas, T_RADAR *pradares, int num_radares);
void CalculaNumRadares(FILE *pf_radares,int *num_radares);
void CalculaNumMultas(FILE *pf_multas,int *num_multas);
void CargaRadaresFichero(FILE *pf_radares, T_RADAR *radares, int num_rads);
void CargaMultasFichero(FILE *pf_multas, T_MULTA *multas, int num_multas);
/// @brief Permite al usuario rellenar las diferentes características de los radares.
/// @param p_radar Radar cuyas características se van a introducir.
void RellenarUnRadar(T_RADAR *p_radar);
/// @brief Permite al usuario rellenar las diferentes características de las multas.
/// @param p_radar Multa cuyas características se van a introducir.
void RellenarUnaMulta(T_MULTA *p_multa);
int BuscarRadar(int identificador_radar, T_RADAR *pradares, int num_radares);

int main(void)
{
	// Se declaran las varibales generales.
	T_RADAR *radares;
	T_MULTA *multas;
	int num_radares;
	int num_multas;
	float total_multas;
	FILE *pf_radares;
	FILE *pf_multas;
	int tipo_carga, opcion, idRadarBuscado, posicion_buscada;

	num_multas = 1;
	num_radares = 1;

	do {
        printf("\n  Elija tipo carga: \n\t 0) Manualmente.\n\t 1) Automáticamente.\n\t 2) Salir del programa.\n  => ");
        scanf("%d",&tipo_carga);

        switch(tipo_carga) {
            case 0:
            // Carga Manual de Radares y Multas

            // Para poder asignar memoria dinámica a un vector, hemos de saber el tamaño que usaremos. 
			//	Esto es, el número de radares y de multas que se registrarán.
            do{ 

                printf("\n  Introduzca el numero de radares: "); 
                scanf("%d",&num_radares); 

                if (num_radares < 0)
				{ 
                	printf("\nError! El valor introducido debe ser mayor que 0."); 
                }    

            } while(num_radares < 0); 

			// Asignacion de m. d. al vector radares
			radares = (T_RADAR *)malloc(num_radares * sizeof(T_RADAR));
			cargaRadaresManual(radares, num_radares);

            do { 
                printf("\n  Introduzca el numero de multas: "); 
                scanf("%d",&num_multas); 

                if (num_multas < 0)
				{ 
                	printf("\nError! El valor introducido debe ser mayor que 0."); 
                }   
				
            } while(num_multas < 0);

			// Asignacion de m. d. al vector multas
            multas = (T_MULTA *)malloc(num_multas * sizeof(T_MULTA));
			cargaMultasManual(multas, num_multas);

            break;

            case 1:
				// Se llama a las funciones que calculan el número de radares y de multas en los ficheros.
				CalculaNumRadares(pf_radares, &num_radares);
                radares = (T_RADAR *)malloc(num_radares * sizeof(T_RADAR));
                CargaRadaresFichero(pf_radares, radares, num_radares);
                
				CalculaNumMultas(pf_multas, &num_multas);
				multas = (T_MULTA *)malloc(num_multas * sizeof(T_MULTA));
				CargaMultasFichero(pf_multas, multas, num_multas);

				break;

			case 2:
				printf("\nSaliendo del programa...");
				scanf("%c"); // Pulsar enter para continuar.
				exit(1);
				break;

            default:
				printf("\nOpción incorrecta.");
            	break;
        }



		


		printf("\n  Elija una operación: \n\t 0) Calcular la Suma Total de las multas registradas.\n\t 1) Buscar un Radar mediante su ID..\n\t 2) Salir del programa.\n  => ");
        scanf("%d",&opcion);

        switch(opcion) {
            case 0:
            //CalculaMultas
			//Dicha función se encargará de aplicar las sanciones correspondientes a cada vehiculo, y de sumar el importe total de todas ellas juntas.
            CalculaMultas(multas, num_multas, radares, num_radares);

            break;

            case 1:
				//BuscarRadar
				//El usuario tecleará por pantalla el id del radar que desea buscar, se le mostrará
				//si existe o no, y se le mostrará su información.

				//Pedimos ID al usuario
				printf("\nIntroduzca el id del radar que quiere buscar: ");
				scanf("%d", &idRadarBuscado);

				//La variable existe registrará si existe o no el radar que se busca
				posicion_buscada = BuscarRadar(idRadarBuscado, radares, num_radares);
				if(posicion_buscada != -1){
					printf("\nEl radar con id: %d existe.\n", idRadarBuscado);
					for(int i = 0; i < num_radares; i++){
						if(i == posicion_buscada){
							//Se muestran los datos que contiene el radar buscado.
							printf("\nLa velocidad límite del radar es: %d.", (*radares).velocidad_limite);
							printf("\nLa sancion del umbral de 0-20 porciento del radar es: %d.", (*radares).umbral20);
							printf("\nLa sancion del umbral de 20-40 porciento del radar es: %d.", (*radares).umbral40);
							printf("\nLa sancion del umbral de +40 porciento del radar es: %d.\n\n", (*radares).umbral_resto);
						}
						else{
							radares++; //Si no es la posición que buscamos, necesito que el puntero apunte al siguiente radar del vector radares.
						}
					}
					radares = radares - posicion_buscada; //Una vez encontrado el radar que buscamos, devolvemos el puntero a la primera posición, por si lo utilizamos de nuevo más adelante.
				}
				else{
					printf("El radar con el id: %d no existe.", idRadarBuscado);
				}

				break;

			case 2:
				printf("\nSaliendo del programa...");
				scanf("%c"); // Pulsar enter para continuar.
				exit(1);
				break;

            default:
				printf("\nOpción incorrecta.");
            	break;
        }
    } while(true);
	return 0;
}
void CargaMultasFichero(FILE *pf_multas, T_MULTA *multas, int num_multas){
	int control = -2;
    //Se abre el fichero en modo de lectura para extraer la información.
	pf_multas = fopen("../data/multas.txt", "r");
    //Controlaré entonces si se ha abierto exitosamente.
    if(pf_multas == NULL){
        printf("Errores al abrir el fichero.");
        exit(1);
    }
	
    for(int i = 0; i < num_multas; i++){
        control = fscanf(pf_multas, "%d %d %d %d %s %d %f ", &(*multas).fecha.dia, &(*multas).fecha.mes, &(*multas).fecha.anio, &(*multas).id_radar, &(*multas).matricula, &(*multas).velocidad, &(*multas).multa);
        multas++;
    }
}
void CargaRadaresFichero(FILE *pf_radares, T_RADAR *radares, int num_rads)
{
    int control = -2;
    //Se abre el fichero en modo de lectura para extraer la informació.
	pf_radares = fopen("../data/radares.txt", "r");
    //Controlaré entonces si se ha abierto exitosamente.
    if(pf_radares == NULL){
        printf("Errores al abrir el fichero.");
        exit(1);
    }
	
    for(int i = 0; i < num_rads; i++){
        control = fscanf(pf_radares, "%d %d %d %d %d", &(*radares).id_radar, &(*radares).velocidad_limite, &(*radares).umbral20, &(*radares).umbral40, &(*radares).umbral_resto);
        radares++;
    }
    
}

void CalculaNumRadares(FILE *pf_radares,int *num_radares)
{
	//Se declara una variable que controlará si el fichero ha finalizado o continúa.
	char control;
	//Se abre el fichero de los radares en modo lectura.
	pf_radares = fopen("../data/radares.txt","r");
	//Se controla que el fichero se abra correctamente.
	if(pf_radares == NULL)
	{
		*num_radares = 0;
		printf("Error al abrir el fichero.");
		fclose(pf_radares);
	}
	//Se inicia un bucle que leerá el fichero hasta que no haya más información.
	while (control != EOF)
	{
		control = fgetc(pf_radares);
		if(control == '\n')
		{ //Un salto de línea es indicativo de que hay un radar para añadir
			*num_radares += 1;
		}
	}

	fclose(pf_radares);
}

void CalculaNumMultas(FILE *pf_multas,int *num_multas)
{
	//Se declara una variable que controlará si el fichero ha finalizado o continúa
	char control = 'a';
	//Se abre el fichero de las multas en modo lectura
	pf_multas = fopen("../data/multas.txt","r");
	//Se controla que el fichero se abra correctamente
	if(pf_multas == NULL)
	{
		*num_multas = 0;
		printf("Error al abrir el fichero.");
		fclose(pf_multas);
	}
	//Se inicia un bucle que leerá el fichero hasta que no haya más información
	while (control != EOF)
	{
		control = fgetc(pf_multas);
		if(control == '\n'){ //Un salto de línea es indicativo de que hay una multa para añadir
			*num_multas += 1;
		}
	}

	fclose(pf_multas);
}

double CalculaMultas(T_MULTA *pmultas, int num_multas, T_RADAR *pradares, int num_radares)
{
	
}


int BuscarRadar(int identificador_radar, T_RADAR *pradares, int num_radares)
{
	int indice = 0; /*Esta variable nos ayudará a ir guardando la posición en la que estamos en 
					cada caso. Se inicializa en 0 para que en la primera vuelta del radar lea el primer radar, ya que el puntero siempre apunta a la primera posición.*/
	int indice_buscado = -1; //Me interesa guardar la posicion en la que se encuentra el radar, por lo que se enviará al main es el índice del radar buscado. 
							//Lo inicializo en -1, por si no se encuentra el id buscado, saber que el valor -1 me dice que no existe.
	for(int i = 0; i < num_radares; i++){
		if(identificador_radar == (*pradares).id_radar){
			/*Si coincide, guardamos en indice buscado el indice en el que estamos. Una vez encontrado, 
			el indice buscado se quedará en la misma posición durante el resto del bucle*/
			indice_buscado = indice;
		}else{
			/*Si el id buscado no coincide con el del radar estudiado, 
			se pasa al siguiente radar disponible en el vector, y aumentamos el índice en 1 para poder guardarlo en el caso de que el siguiente radar sea el buscado*/
			pradares++;
			indice++;
		}

	}
	return indice_buscado;
}

void cargaRadaresManual (T_RADAR *radares, int num_radares)
{
	for (int i = 0; i < num_radares; i++)
	{
		RellenarUnRadar(&radares[i]);
	}
}

void cargaMultasManual(T_MULTA *multas, int num_multas)
{
	for (int i = 0; i < num_multas; i++)
	{
		RellenarUnaMulta(&multas[i]);
	}
}

void RellenarUnRadar(T_RADAR *p_radar)
{
	printf("\n  Introduzca la información del radar:\n");
	printf("\t* ID del radar: ");
	scanf("%d", &(*p_radar).id_radar);
	printf("\t* Velocidad limite (km/h): ");
	scanf("%d", &(*p_radar).velocidad_limite);
	printf("\t* Umbral 0-20%c %c: ", 37, 128);
	scanf("%d", &(*p_radar).umbral20);
	printf("\t* Umbral 20-40%c %c: ", 37, 128);
	scanf("%d", &(*p_radar).umbral40);
	printf("\t* Umbral >40%c %c: ", 37, 128);
	scanf("%d", &(*p_radar).umbral_resto);
	printf("  Radar almacenado correctamente!\n");
}

void RellenarUnaMulta(T_MULTA *p_multa)
{
	printf("\n  Introduzca la información de la multa:\n");
	printf("\t* Día: ");
	scanf("%d", &(*p_multa).fecha.dia);
	printf("\t* Mes: ");
	scanf("%d", &(*p_multa).fecha.mes);
	printf("\t* Año: ");
	scanf("%d", &(*p_multa).fecha.anio);
	printf("\n\t* ID del radar: ");
	scanf("%d", &(*p_multa).id_radar);
	printf("\t* Matrícula (8 caracteres): ");
	scanf("%s", &(*p_multa).matricula);
	printf("\t* Velocidad (km/h): ");
	scanf("%d", &(*p_multa).velocidad);
	printf("\t* Multa: ", 37, 128);
	scanf("%f", &(*p_multa).multa);
	printf("  Multa almacenada correctamente!\n");
}