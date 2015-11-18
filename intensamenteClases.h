#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

//*DEFINIMOS CLASES*//
typedef struct unRecuerdo
{
	void * descripcion;
	float fecha;
	void * emocionDominanteInstante;
	int * esCentral;
} RECUERDO;

typedef struct unaNena 
{
	float nivelDeFelicidad; 
	char * emocionDominante;
	t_list * unPrimerRecuerdo;
	t_list * pensamientosCentrales;
	t_list * procesos;
	t_list * memoriaLargoPlazo;
} NENA;







