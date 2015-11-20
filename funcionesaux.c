#include "intensamenteClases.h"

//FUNCIONES AXILIARES//

//GENERALES//
void convertir_recuerdo_en_pensamiento_central (NENA * const unaNena, RECUERDO * const unRecuerdo)
{		list_add((unaNena->pensamientosCentrales), unRecuerdo);
		int * x;
		*x= 1;
		unRecuerdo->esCentral= x;
}


void disminuir_felicidad_en(NENA * unaNena, float coeficiente)
{
	unaNena->nivelDeFelicidad= calcularPorcentaje(unaNena->nivelDeFelicidad, coeficiente);
}

float calcular_porcentaje(float valor1, float valor2)
{
	return((valor2*100)/valor1);
 } 
 

void asentar_recuerdo_alegre(NENA * const unaNena, RECUERDO * unRecuerdo)
{	if(unaNena->nivelDeFelicidad > 500.00)
		convertir_recuerdo_en_pensamiento_central(unaNena, unRecuerdo);
}	


void asentar_recuerdo_triste(NENA * const unaNena, RECUERDO * unRecuerdo)
{
	convertir_recuerdo_en_pensamiento_central(unaNena, unRecuerdo);
	disminuirFelicidadEn(unaNena, 10.0);
	
}

