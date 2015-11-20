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
	t_list * pensamientosDelDia;
	t_list * pensamientosCentrales;
	t_list * procesos;
	t_list * memoriaLargoPlazo;
} NENA;



// PROTOTYPES PRINCIPALES //

void vivi_un_evento (NENA * , char * );
void asenta_un_recuerdo (NENA * , RECUERDO * );
t_list * recuerdos_recientes_deldia(NENA * );
t_list * pensamientos_dificles_deexplicar(NENA * );
bool niega_un_recuerdo(NENA * , RECUERDO * );
void dormir(NENA * );
void asentar_recuerdos(NENA * );
void asentar_sicumple(NENA * , char * );
void profundizar_recuerdos(NENA * );
void control_hormonal(NENA * );
void restauracion_cognitiva(NENA * );
void liberar_recuerdos_deldia(NENA * );


// PROTOYPES SECUNDARIOS //

void convertir_recuerdo_en_pensamiento_central (NENA * , RECUERDO * );
void disminuir_felicidad_en(NENA * , float );
float calcular_porcentaje(float , float );
void asentar_recuerdo_alegre(NENA * , RECUERDO * );
void asentar_recuerdo_triste(NENA * , RECUERDO * );
void asignarLista(NENA * );
NENA * nena_create(char * , float * );
RECUERDO * recuerdo_create(char * , char * );
bool ordenar_recuerdos_porfecha_ascendente(RECUERDO * , RECUERDO * );
bool ordenar_recuerdos_porfecha_descendente(RECUERDO * , RECUERDO * );
bool recuerdo_dificil_deexplicar(void * );
bool estado_deanimo_niega_unrecuerdo(char * , RECUERDO * );
void aplicar_proceso (NENA * , void * funcion (NENA *));
void aplicar_procesos(t_list * lista, NENA * );
bool texto_contiene(void * , char * );
void enviar_recuerdo_largo_plazo(NENA * , RECUERDO * );
void profundizar_recuerdo(NENA * , RECUERDO * );
void perder_pensamientos_centrales_antiguos(NENA * , int );
bool esta_en_largoplazo(t_list * , t_list * );
bool recuerdo_repetido(NENA * );
bool todos_con_la_misma_emocion(t_list * );
bool recuerdos_son_emocionalmente_iguales(NENA * );


