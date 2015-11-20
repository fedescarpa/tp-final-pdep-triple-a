#include "intensamenteClases.h"
#include "cspec.h"


context(demo) {

	describe("Vivir") {
		
		float * felicidad;
		* felicidad = 200;
		NENA * riley = nena_create("alegre", felicidad );
		
		
			it("Vivir un evento") {

			vivi_un_evento( riley, "cumpleanios de 15");
			vivi_un_evento( riley, "ir a la plaza");
			vivi_un_evento( riley, "cenar con mama y papa");
			
			
			should_int(list_size(riley->pensamientosDelDia)) be equal to(3);

			}end






			it("Asentar un recuerdo") {
			
				
			
			RECUERDO * unRecuerdo = recuerdo_create("cumpleaños de 15", "alegre");
			
			asenta_un_recuerdo(riley, unRecuerdo);
			
			
			should_int(list_size(riley->pensamientosCentrales)) be equal to(0);

			}end
			
			
			
			
			
			
			it("Recuerdos recientes") {

			vivi_un_evento( riley, "cumpleanios de 15");
			vivi_un_evento( riley, "ir a la plaza");
			vivi_un_evento( riley, "cenar con mama y papa");
			vivi_un_evento( riley, "salir con mis amigas");
			vivi_un_evento( riley, "descripcion random");
			vivi_un_evento( riley, "ni siqueira vi la pelicula");


			t_list * recuerdosRecientes = recuerdos_recientes_deldia(riley);
			RECUERDO * ultimoRecuerdo = list_get(recuerdosRecientes, 0);
			
			
			should_string(ultimoRecuerdo->descripcion) be equal to("ni siqueira vi la pelicula");

			}end
			
			
			
			
			

	}end

}


