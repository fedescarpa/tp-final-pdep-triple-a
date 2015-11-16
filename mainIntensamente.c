#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "intensamenteClases.h"

//CREAR NENA//
NENA *nena_create(char *emocionDominante, float *nivelDeFelicidad)
;{	NENA *unaNena= malloc(size(NENA));
	asignarLista(unaNena);
	*unaNena->emocionDominante= emocionDominante;
	*unaNena->nivelDeFelicidad= nivelDeFelicidad;
	return unaNena;
	
}

//ASIGNAMOS LISTA A RECUERDOS Y PENSAMIENTOS CENTRALES//
void asignarLista(NENA *const unaNena)
{	t_list *recuerdos= list_create();
	t_list *pensamientosCentrales= list_create();
	unaNena->pensamientosCentrales= pensamientosCentrales;
	unaNena->unPrimerRecuerdo= recuerdos;

}
//CREAR RECUERDO//
RECUERDO *recuerdo_create(char *descripcion, char *emocion)
{	RECUERDO *unRecuerdo;
	*unRecuerdo->descripcion= malloc(50);
	*unRecuerdo->emocionDominanteInstante= malloc(50);
	*unRecuerdo->descripcion= *descripcion;
	*unRecuerdo->emocionDominanteInstante= *emocion;
	return unRecuerdo;
	}	
//*METODO VIVIUNEVENTO*//
void viviUnEvento (NENA *const unaNena, RECUERDO unRecuerdo)
{	list_add((unaNena->unPrimerRecuerdo), &unRecuerdo);
}


//*METODO ASENTAUNRECUERDO*//
void asentaUnRecuerdo (NENA *const unaNena, RECUERDO unRecuerdo)
{ 	if(unRecuerdo.emocionDominanteInstante == "alegre")
		{asentarRecuerdoAlegre(unaNena, unRecuerdo);}
	else
	{	if(unRecuerdo.emocionDominanteInstante == "triste")
		{asentarRecuerdoTriste(unaNena, unRecuerdo);}
		else
		{asentarRecuerdoOtro(unaNena, unRecuerdo);}
	}
}


void asentar_recuerdo_alegre(NENA *const unaNena, RECUERDO unRecuerdo)
{	if(unaNena->nivelDeFelicidad > 500.00)
		{convertirRecuerdoEnPensamientoCentral(unaNena, unRecuerdo);}	
}

void asentar_recuerdo_triste(NENA *const unaNena, RECUERDO unRecuerdo)
{
	convertirRecuerdoEnPensamientoCentral(unaNena, unRecuerdo);
	disminuirFelicidadEn(unaNena, 10.0);
	
}

void convertir_recuerdo_enpensamientoCentral(NENA *const unaNena, RECUERDO unRecuerdo)
{		list_add((unaNena->pensamientosCentrales), &unRecuerdo);
}

void disminuir_felicidad_en(NENA *const unaNena, float coeficiente)
{
	unaNena->nivelDeFelicidad= calcularPorcentaje(unaNena->nivelDeFelicidad, coeficiente);
}

float calcular_porcentaje(float valor1, float valor2)
{
	return((valor2*100)/valor1);
 } 
 
 
 




