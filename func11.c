#include <stdio.h>

void entero(int *r);

int main(void)
{
	int m=8;
	entero(&m);
	printf("m=%i\n", m);

	return 0;
}

void entero(int *r)
{
	int i=20;
	*r=i;
}

/*
la funcion entero() admite un puntero
por argumento una direccion de memoria
 y asigna un valor diferente

en la declaracion de su argumento
(int *r) admite la dirección de
un espacio de memoria de tipo int

en este caso m es una variable,
entoces le paso su dirección...
equivale a asignar r=&m en el
agumento de la funcion entero().

dentro de la funcion *r=i;
le asigna a m el contenido de i.
m=i; porque el puntero r apunta
 a la direccion de la variable
 entera m

no necesito retornarlo, ya se ha asignado
*/
