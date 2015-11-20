#include "intensamenteClases.h"
#include "funcionesaux.c"



//ASIGNAMOS LISTA A RECUERDOS Y PENSAMIENTOS CENTRALES//
void asignarLista(NENA * unaNena)
{	t_list * recuerdos= list_create();
	t_list * pensamientosCentrales= list_create();
	unaNena->pensamientosCentrales= pensamientosCentrales;
	unaNena->pensamientosDelDia= recuerdos;

}

//CREAR NENA//
NENA * nena_create(char * emocionDominante, float * nivelDeFelicidad)
{
	NENA * unaNena= malloc(sizeof(NENA));
	asignarLista(unaNena);
	unaNena->emocionDominante= emocionDominante;
	unaNena->nivelDeFelicidad= *nivelDeFelicidad;
	return unaNena;
	
}


//CREAR RECUERDO//
RECUERDO * recuerdo_create(char * descripcion, char * emocion)
{	RECUERDO * unRecuerdo;
	unRecuerdo->descripcion= malloc(50);
	unRecuerdo->emocionDominanteInstante= malloc(50);
	memcpy(unRecuerdo->descripcion, descripcion, 50);
	memcpy(unRecuerdo->emocionDominanteInstante, emocion, 50);
	return unRecuerdo;
	}	
	
	
//*METODO VIVI_UN_EVENTO*//
void vivi_un_evento (NENA * const unaNena, char * descripcion)
{	
	RECUERDO * unRecuerdo = recuerdo_create(descripcion, unaNena->emocionDominante);
	list_add((unaNena->pensamientosDelDia), unRecuerdo);
}


//*METODO ASENTA_UN_RECUERDO*//
void asenta_un_recuerdo (NENA * const unaNena, RECUERDO * unRecuerdo)
{ 	if(unRecuerdo->emocionDominanteInstante == "alegre")
		{asentar_recuerdo_alegre(unaNena, unRecuerdo);}
	else
	{	if(unRecuerdo->emocionDominanteInstante == "triste")
		{asentar_recuerdo_triste(unaNena, unRecuerdo);}
		else
		{asentar_recuerdo_otro(unaNena, unRecuerdo);}
	}
}

//Conocer los recuerdos recientes del día: estos son los últimos 5 recuerdos//

bool ordenar_recuerdos_porfecha_ascendente(RECUERDO * recuerdo1, RECUERDO * recuerdo2)
{ 
	return(recuerdo1->fecha > recuerdo2->fecha);
}

bool ordenar_recuerdos_porfecha_descendente(RECUERDO * recuerdo1, RECUERDO * recuerdo2)
{ 
	return(recuerdo1->fecha < recuerdo2->fecha);
}



//	RECUERDOS RECIENTES //

t_list * recuerdos_recientes_deldia(NENA * const unaNena)
{	ordenar_lista_ascendente(unaNena->pensamientosDelDia);
	return (list_take(unaNena->pensamientosDelDia, 5));
}
	
//Conocer los pensamientos centrales que sean difíciles de explicar. Un recuerdo es difícil de explicar cuando su descripción tiene más de 10 palabras//

bool recuerdo_dificil_deexplicar(void * data)
{
	RECUERDO *unRecuerdo= data;
	return (strlen(unRecuerdo->descripcion)> 10);
}

t_list * pensamientos_dificles_deexplicar(NENA * const unaNena)
{ return (list_filter(unaNena->pensamientosCentrales, recuerdo_dificil_deexplicar));
}

//DESCANSAR//
//Saber si Riley niega un recuerdo//

bool estado_deanimo_niega_unrecuerdo(char * emocionDominante, RECUERDO * unRecuerdo)
 {	if (emocionDominante== "alegre")
 		{return(unRecuerdo->emocionDominanteInstante != "alegre"); }
 	else if(emocionDominante== "triste") 
 		{	{return(unRecuerdo->emocionDominanteInstante =="alegre"); }}
 		else {return (0); } 
		  };
 

bool niega_un_recuerdo(NENA * const unaNena, RECUERDO * unRecuerdo)
{	return ( estado_deanimo_niega_unrecuerdo(unaNena->emocionDominante, unRecuerdo));
}

//Enviar a Riley a dormir, desencadenando todos sus procesos mentales//



void aplicar_proceso (NENA * const unaNena, void * funcion (NENA *))
{

funcion(unaNena);

};



void aplicar_procesos(t_list * lista, NENA * const unaNena)
{
	t_link_element *element = lista->head;
	while (element != NULL) {
		
		aplicar_proceso(unaNena,element->data);
		element = element->next;
	};
}


// DORMIR //


void dormir(NENA * const unaNena)
{
	aplicar_procesos(unaNena->procesos, unaNena);
}



// ASENTAR RECUERDOS //


void asentar_recuerdos( NENA * const unaNena)
{ 

	t_list * recuerdos = unaNena->pensamientosDelDia;
	t_link_element * element = recuerdos->head;
	while (element != NULL) {
		
		asenta_un_recuerdo(unaNena,element->data);
		element = element->next;
	};

}
	
//ASENTAMIENTO SELECTIVO//

bool texto_contiene(void * descripcion, char * palabra)
{	char * point;
	point= strstr(descripcion, palabra);
	return(point != NULL);
}

void asentar_sicumple(NENA * const unaNena, char * palabraClave)
{
	
	t_list * recuerdos = unaNena->pensamientosDelDia;
	t_link_element * element = recuerdos->head;
	
	while (element != NULL) {
		RECUERDO * recuerdo = element->data ;
		if(texto_contiene((recuerdo->descripcion), palabraClave))
		{
			asenta_un_recuerdo(unaNena, recuerdo);
		};
		element = element->next;
	};
	
}
	
	
	
	
//PROFUNDIZAR RECUERDOS//	


void enviar_recuerdo_largo_plazo(NENA *const unaNena, RECUERDO * unRecuerdo)
{ list_add(unaNena->memoriaLargoPlazo, unRecuerdo);}

void profundizar_recuerdo(NENA * const unaNena, RECUERDO * unRecuerdo)
{	int * x;
	* x = 1;
	if((unRecuerdo->esCentral != x) && (!niega_un_recuerdo(unaNena, unRecuerdo)))
		{ enviar_recuerdo_largo_plazo(unaNena, unRecuerdo);}
}


void profundizar_recuerdos(NENA * const unaNena)
{
	t_list * recuerdos = unaNena->pensamientosCentrales;
	t_link_element * element = recuerdos->head;
	
	while (element != NULL) {
		profundizar_recuerdo(unaNena, element->data);
		element = element->next;
	};
	
	
}

//CONTROL HORMONAL//  
						

void perder_pensamientos_centrales_antiguos(NENA * const unaNena, int valor)
	{	int * posicion, contador=1;
		*posicion=list_size(unaNena->pensamientosCentrales);
		for(contador; contador <=3; contador++)
		{	list_remove((unaNena->pensamientosCentrales), *posicion);
			*posicion--;	
		}
	}


bool esta_en_largoplazo(t_list * pensamientosCentrales, t_list * memoriaLargoPlazo)
{
 t_link_element * element = pensamientosCentrales->head;
	while (element != NULL) {
		t_link_element * element2 = memoriaLargoPlazo->head;
		while (element2 != NULL) {
			if ((element->data) == (element2->data)){
			return (1);
			};
		element2 = element2->next;
		};
	element = element->next;	
	}
		
}


bool recuerdo_repetido(NENA * const unaNena)
{	
t_list * pensamientos = unaNena->pensamientosCentrales;
t_list * memoria = unaNena->memoriaLargoPlazo;

	t_link_element * element = pensamientos->head;
	while (element != NULL) {
		
		if(esta_en_largoplazo(element->data, memoria))
		{ return (1);
		};
		element = element->next;
	};
}


//  CONTROL HORMONAL //

bool todos_con_la_misma_emocion(t_list * pensamientosDelDia)
{
	t_link_element * element = pensamientosDelDia->head;
	RECUERDO * emocionDelDia = element->data;
	while (element != NULL)
	{
		RECUERDO * emocionDelRecuerdo = element->data;
		if( (emocionDelDia->emocionDominanteInstante) != (emocionDelRecuerdo->emocionDominanteInstante)  )
		{ return (0);
		};
		element = element->next;
	}
	return (1);
}


bool recuerdos_son_emocionalmente_iguales(NENA * const unaNena)
{ return(todos_con_la_misma_emocion(unaNena->pensamientosDelDia));
}


void control_hormonal(NENA * const unaNena)
{	if((recuerdo_repetido(unaNena)) || recuerdos_son_emocionalmente_iguales(unaNena))
	{	disminuir_felicidad_en(unaNena,15);
		perder_pensamientos_centrales_antiguos(unaNena, 3);
	}
}

//RESTAURACION COGNITIVA//
void restauracion_cognitiva(NENA * const unaNena)
{	unaNena->nivelDeFelicidad= (unaNena->nivelDeFelicidad) + 100;
}

//LIBERACION DE RECUERDOS DEL DIA//
void liberar_recuerdos_deldia(NENA * const unaNena)
{	
	list_clean(unaNena->pensamientosDelDia);
}
