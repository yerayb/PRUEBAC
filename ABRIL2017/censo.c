#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "censo.h"

//funciones desarrolladas

/*
 * Calcula cuantas personas menores de la edad indicada hay en el array
 */
int cuantasPersonas(Persona ap[],int tamanyo,int edad){
	int nPersonas=0;
	int i;

	for(i=0;i<tamanyo;i++){
		if(ap[i].edad<edad){
			nPersonas++;
		}
	}



	return nPersonas;
}

/*
 * Busca en el array de personas aquellas cuya edad sea menor que 30 años
 * Crea y devuelve un grupo de personas con esas personas y la media de edad del grupo
 */
GrupoPersonas recuperarJovenes(Persona ap[],int tamanyo){
	GrupoPersonas g;
	int i; //contador del array global de personas
	int j=0; //contador para los jovenes
	int sumEdad=0;

	g.numero = cuantasPersonas(ap,tamanyo,30); //numero de personas menores a 30 años
	g.personas = (Persona*)malloc(g.numero* sizeof(Persona)); //reservo memoria igualando el array a malloc

	for(i=0;i<tamanyo;i++){
		if(ap[i].edad<30){
			g.personas[j] = ap[i]; //array dinamico!!!!!
			sumEdad+=ap[i].edad;
			printf("\n[Nombre: %s, Edad: %i]",ap[i].nombre,ap[i].edad);
			j++;
		}
	}



	g.media = sumEdad/g.numero;





	return g;
}

Persona recuperarYogurin(Persona ap[],int tamanyo){
	Persona p;
	int i;

	p = ap[0];//cojo el primer elemento del array
	for(i=0;i<tamanyo;i++){
		if(ap[i].edad<p.edad){ //si un elemento es menor al de la variable se ira actualizando hasta recorrer todos
			p = ap[i];

		}
	}
	printf("\n[Nombre:%s, Edad: %i]",p.nombre,p.edad);



	return p;
}

int cuantosNombres(Persona ap[],int tamanyo,char letra){
	int cont=0;
	int i;
	for(i=0;i<tamanyo;i++){
		if(ap[i].nombre[0]==letra){
			cont++;
		}
	}

	return cont;


}

char** listadoNombres(Persona ap[],int tamanyo,char letra){

	int n  = cuantosNombres(ap,tamanyo,letra);
	char **nombre=(char**) malloc(n* sizeof(char*)); //char *nombre = char nombre[] -- char **nombre = char *nombre[] -> array de strings dinamico
	//reservo cuantos  nombres * lo que ocupa un string
	int i;
	int j=0;
	for(i=0;i<tamanyo;i++){
		if(ap[i].nombre[0]==letra){
			nombre[j] = ap[i].nombre;
			j++;
		}
	}
	for(i=0;i<n;i++){
		printf("\n %s \n",nombre[i]);
	}

	//char **nombre = array de strings
	//reservar memoria = malloc(numero de elementos * sizeof(char*)) nelementos*sizeof(string)
	//se meten y se imprimen datos de la misma forma
	//nombre[i]

	return nombre;
}


