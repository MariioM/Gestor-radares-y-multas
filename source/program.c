#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 8

typedef struct {
	int dia;
	int mes;
	int anio;
}T_FECHA;

typedef struct {
	T_FECHA fecha;
	int id_radar;
	char matricula[N];
	int velocidad;
	float multa;
}T_MULTA;

typedef struct {
		int id_radar;
		int velocidad_limite;
		int umbral20;
		int umbral40;
		int umbral_resto;
}T_RADAR;

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

int main(void){
	T_RADAR *radares;
	T_MULTA *multas;
	int num_radares;
	int num_multas;
	float total_multas;
	FILE *pf_radares;
	FILE *pf_multas;
	int tipo_carga;

	do{
        printf("\nElija tipo carga: \n  0) Manualmente.\n  1) Automáticamente.\n  2) Salir del programa.\n");
        scanf("%d",&tipo_carga);

        switch(tipo_carga) {
            case 0:
            //Carga Manual de Radares y Multas

            //Para poder asignar memoria dinámica a un vector, hemos de saber el tamaño que usaremos. Esto es, el número de radares y de multas que se registrarán.
            do{ 
                printf("\nIntroduce el numero de radares: "); 
                scanf("%d",&num_radares); 
                if (num_radaress<0){ 
                printf("\nERROR"); 
                }    
            }while(num_radares<0); 
			//Asignacion de m. d. al vector radares

            do{ 
                printf("\nIntroduce el numero de multas: "); 
                scanf("%d",&num_multas); 
                if (num_multas<0){ 
                printf("\nERROR"); 
                }    
            }while(num_multas<0);
			//Asignacion de m. d. al vector multas
            
            break;

            case 1:
            //Carga Automática de Radares y Multas
            break;

            default:
            program = false;
            printf("\nSaliendo del programa...");
            break;
        }
    }while(program);

	return 0;
}


void CargaRadaresFichero(FILE *pf_radares, T_RADAR *radares){
	   /*A rellenar por el alumno*/
}

void CalculaNumRadares(FILE *pf_radares,int *num_radares){
	   /*A rellenar por el alumno*/
}

void CalculaNumMultas(FILE *pf_multas,int *num_multas){
	   /*A rellenar por el alumno*/
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
