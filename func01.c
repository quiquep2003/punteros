#include <stdio.h>

int *entero(int *r);

int main(void)
{
	int m=8;
	m=*entero(&m);
	printf("m=%i\n", m);

	return 0;
}

int *entero(int *r)
{
	int i=20;
	*r=i;
	return r; // innecesario redundante
}

/*
al pasar &m a la funcion, no necesito
 retornarlo porque estoy pasando una
direccion de memoria

la funcion entero() admite un puntero
y retorna otro puntero.. en este caso
el mismo. en otras palabras recibe por
argumento una direccion de memoria y
retorna un contenido

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

la funcion retorna un puntero, esto
quiere decir que retorna una
 direccion de memoria, return r;
porque r es un puntero, y los
punteros tratan directamente con
 direcciones de memoria.

/*
