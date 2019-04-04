#ifndef CENSO_H_
#define CENSO_H_
#include "persona.h"

//ESTRUCTURA
typedef struct{
	int numero; //numero de personas que componen el grupo
	Persona *personas; //array dinamico de personas -> no sabemos a priori cuantas personas contiene el array
	float media;//media de la edad del grupo

}GrupoPersonas;


//FUNCIONES
int cuantasPersonas(Persona ap[],int tamanyo,int edad);
GrupoPersonas recuperarJovenes(Persona ap[],int tamanyo);
Persona recuperarYogurin(Persona ap[],int tamanyo);
int cuantosNombres(Persona ap[],int tamanyo,char letra);
char** listadoNombres(Persona ap[],int tamanyo,char letra);

#endif /* CENSO_H_ */
