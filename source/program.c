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
	//Se declaran las varibales generales
	T_RADAR *radares;
	T_MULTA *multas;
	int num_radares;
	int num_multas;
	float total_multas;
	FILE *pf_radares;
	FILE *pf_multas;
	int tipo_carga;
	//Se inicializan el numero de multas y radares a 0
	num_multas = 1;
	num_radares = 1;
	printf("Elija tipo carga\n");
	scanf("%d",&tipo_carga);
	if (tipo_carga == 0) //Carga manual
    {
      /*A rellenar por el alumno*/
		CalculaNumRadares(pf_radares, &num_radares);
    }
    else if(tipo_carga == 1){ //Carga automática

	   /*A rellenar por el alumno*/
	

    }else{

	}

	return 0;
}


void CargaRadaresFichero(FILE *pf_radares, T_RADAR *radares){
	   /*A rellenar por el alumno*/
}

void CalculaNumRadares(FILE *pf_radares,int *num_radares){
	//Se declara una variable que controlará si el fichero ha finalizado o continua
	char control;
	//Se abre el fichero de los radares en modo lectura
	pf_radares = fopen("../data/radares.txt","r");
	//Se controla que el fichero se abra correctamente
	if(pf_radares == NULL){
		*num_radares = 0;
		printf("Error al abrir el fichero.");
		fclose(pf_radares);
	}
	//Se inicia un bucle que leerá el fichero hasta que no haya más información
	while (control != EOF)
	{
		control = fgetc(pf_radares);
		if(control == '\n'){ //Un salto de línea es indicativo de que hay un radar para añadir
			*num_radares += 1;
		}
	}
	printf("%d", *num_radares);
	scanf("%c", &control);
	fclose(pf_radares);
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
