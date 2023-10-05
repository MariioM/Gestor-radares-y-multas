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

	printf("Elija tipo carga\n");
	scanf("%d",&tipo_carga);
	if (tipo_carga == 0) //Carga manual
    {
      /*A rellenar por el alumno*/

    }
    else{

	   /*A rellenar por el alumno*/
	

    }

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
