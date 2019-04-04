#ifndef PERSONA_H_
#define PERSONA_H_

typedef struct
{
	char* nombre; //nombre de la persona (cadena de caracteres con *)
	int edad; //edad
} Persona;

void imprimirPersona(Persona p);

#endif /* PERSONA_H_ */
