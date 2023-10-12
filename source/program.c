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

void cargaRadaresManual (T_RADAR *radares, int num_radares);
void cargaMultasManual(T_MULTA *multas, int num_multas);
double CalculaMultas(T_MULTA *multas, int num_multas, T_RADAR *pradares, int num_radares);
void CalculaNumRadares(FILE *pf_radares,int *num_radares);
void CalculaNumMultas(FILE *pf_multas,int *num_multas);
void CargaRadaresFichero(FILE *pf_radares, T_RADAR *radares);
void CargaMultasFichero(FILE *pf_multas, T_MULTA *multas);
void RellenarUnRadar(T_RADAR *p_radar);
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
	int tipo_carga;

	num_multas = 1;
	num_radares = 1;

	do {
        printf("\nElija tipo carga: \n\t  0) Manualmente.\n\t  1) Automáticamente.\n\t  2) Salir del programa.\n");
        scanf("%d",&tipo_carga);

        switch(tipo_carga) {
            case 0:
            // Carga Manual de Radares y Multas

            // Para poder asignar memoria dinámica a un vector, hemos de saber el tamaño que usaremos. 
			//	Esto es, el número de radares y de multas que se registrarán.
            do{ 

                printf("\nIntroduzca el numero de radares: "); 
                scanf("%d",&num_radares); 

                if (num_radares < 0)
				{ 
                	printf("\nError! El valor introducido debe ser mayor que 0."); 
                }    

            } while(num_radares < 0); 

			// Asignacion de m. d. al vector radares

            do{ 
                printf("\nIntroduce el numero de multas: "); 
                scanf("%d",&num_multas); 

                if (num_multas < 0)
				{ 
                	printf("\nError! El valor introducido debe ser mayor que 0."); 
                }   
				
            } while(num_multas < 0);

			//Asignacion de m. d. al vector multas
            
            break;

            case 1:
				// Se llama a las funciones que calculan el número de radares y de multas en el fichero
				CalculaNumRadares(pf_radares, &num_radares);
				CalculaNumMultas(pf_multas, &num_multas);
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

void CargaRadaresFichero(FILE *pf_radares, T_RADAR *radares)
{
	/*A rellenar por el alumno*/
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

double CalculaMultas(T_MULTA *pmultas, int num_multas, T_RADAR *pradares, int num_radares){
	/*A rellenar por el alumno*/
}


int BuscarRadar(int identificador_radar, T_RADAR *pradares, int num_radares){
	/*A rellenar por el alumno*/
}

void cargaRadaresManual (T_RADAR *radares, int num_radares)
{
	/*A rellenar por el alumno*/
}

void cargaMultasManual(T_MULTA *multas, int num_multas)
{
	/*A rellenar por el alumno*/
}
