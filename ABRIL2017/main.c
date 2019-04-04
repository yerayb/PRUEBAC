#include "persona.h"
#include "censo.h"
#include <stdio.h>
#include<stdlib.h>

void crearInforme(GrupoPersonas gp,char* fichero){ //*fichero = cadena de caracteres
	FILE *f; //creamos tipo file
	f = fopen(fichero,"w"); //lo llamo como lo mete el usuario por parametro, w-> lo crea

	fprintf(f,"%s \n %s","CENSO DE JOVENES","----------------\n");
	int i;
	for(i=0;i<gp.numero;i++){
		fprintf(f,"[Nombre: %s  Edad: %i]\n",(gp.personas+i)->nombre,(gp.personas+i)->edad); //al tratarse de un array de punteros, el puntero indica al primer elemento del array y tendre que sumar 1 al mismo puntero

	}
	fprintf(f,"Media: %.2f",gp.media);

	fclose(f);


}

int main(void)
{
	//array de la estructura Persona
	Persona personas[5]; //array de personas
	personas[0].nombre="Hodei"; personas[0].edad=6;
	personas[1].nombre="Anita"; personas[1].edad=41;
	personas[2].nombre="Aitor"; personas[2].edad=12;
	personas[3].nombre="Idoia"; personas[3].edad=31;
	personas[4].nombre="Maite"; personas[4].edad=24;

	imprimirPersona(personas[0]);

	/*
	 * Juego de ensayo
	 */
	GrupoPersonas g;
	printf("JUEGO DE ENSAYO\n");
	int adolescente = cuantasPersonas(personas,5,15);
	printf("Personas menores de 15 años = %i\n",adolescente);
	printf("Grupo de personas menores de 30 años: \n ");
	g = recuperarJovenes(personas,5);
	float media = g.media;
	printf("\nMedia: %.2f",media);
	printf("\n La persona mas joven es: ");
	recuperarYogurin(personas,5);


	crearInforme(g,"jovenes.txt");

	/*
	 * Juego de ensayo parte 3
	 *
	 */

	listadoNombres(personas,5,'M');

	return 0;
}
