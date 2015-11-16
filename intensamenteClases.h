#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//*DEFINIMOS CLASES*//
typedef struct unRecuerdo
{
	void* descripcion;
	float fecha;
	void* emocionDominanteInstante;
} RECUERDO;

typedef struct unaNena 
{
	float nivelDeFelicidad; 
	char *emocionDominante;
	t_list *unPrimerRecuerdo;
	t_list *pensamientosCentrales;
} NENA;

//PROTOTIPOS DE FUNCIONES//

RECUERDO *recuerdo_create(char *, char *)
void viviUnEvento(NENA *, RECUERDO );
void asignarListaA(NENA *);
void asentaUnRecuerdo (NENA * , RECUERDO);
NENA *nena_create(char *, float *);
void asentar_recuerdo_alegre(NENA *, RECUERDO );
void asentar_recuerdo_triste(NENA *, RECUERDO );
void convertir_recuerdo_enpensamientoCentral(NENA *, RECUERDO);





