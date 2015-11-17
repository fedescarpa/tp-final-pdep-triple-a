#include "intensamenteClases.h"


void convertir_recuerdo_en_pensamiento_central (NENA * const unaNena, RECUERDO * const unRecuerdo)
{		list_add((unaNena->pensamientosCentrales), unRecuerdo);
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


//ASIGNAMOS LISTA A RECUERDOS Y PENSAMIENTOS CENTRALES//
void asignarLista(NENA * unaNena)
{	t_list * recuerdos= list_create();
	t_list * pensamientosCentrales= list_create();
	unaNena->pensamientosCentrales= pensamientosCentrales;
	unaNena->unPrimerRecuerdo= recuerdos;

}

//CREAR NENA//
NENA * nena_create(char * emocionDominante, float * nivelDeFelicidad){
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
	
	
//*METODO VIVIUNEVENTO*//
void vivi_un_evento (NENA * const unaNena, RECUERDO * unRecuerdo)
{	list_add((unaNena->unPrimerRecuerdo), unRecuerdo);
}


//*METODO ASENTAUNRECUERDO*//
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

//Conocer los recuerdos recientes del d�a: estos son los �ltimos 5 recuerdos//

bool ordenar_recuerdos_porfecha(void * dato1, void * dato2)
{ RECUERDO * recuerdo1= dato1;
	RECUERDO * recuerdo2= dato2;
	return(recuerdo1->fecha > recuerdo2->fecha);
}


void ordenar_lista(t_list * listita)
{(list_sort(listita,ordenar_recuerdos_porfecha));
}

t_list * recuerdos_recientes_deldia(NENA * const unaNena)
{	ordenar_lista(unaNena->unPrimerRecuerdo);
	return (list_take(unaNena->unPrimerRecuerdo, 5));
}
	
//Conocer los pensamientos centrales que sean dif�ciles de explicar. Un recuerdo es dif�cil de explicar cuando su descripci�n tiene m�s de 10 palabras//

bool recuerdo_dificil_deexplicar(void * data)
{
	RECUERDO * unRecuerdo= data;
	return (strlen(unRecuerdo->descripcion)> 10);
}

t_list * pensamientos_dificles_deexplicar(NENA * const unaNena)
{ return (list_filter(unaNena->pensamientosCentrales, recuerdo_dificil_deexplicar));
}

//DESCANSAR//
//Saber si Riley niega un recuerdo//

 estado_deanimo_niega_unrecuerdo(char * emocionDominante, RECUERDO * unRecuerdo)
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

/*
void aplicar(t_list * lista, NENA * const unaNena)
{
	t_link_element *element = lista->head;
	while (element != NULL) {
		
		void * funcion=(element->data);
		funcion(unaNena);
		element = element->next;
};
}

void aplicar_proceso(NENA * const unaNena)
{
	aplicar(unaNena->procesos, unaNena);
}

*/


void asentar_recuerdos( NENA * const unaNena)
{ 
	}
	
	
	
void profundizar_recuerdos(NENA * const unaNena){
	
	
	
	
	
}
