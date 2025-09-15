#include <stdio.h>

int entero(int *r);

int main(void)
{
	int m=8;
	m=entero(&m);
	printf("m=%i\n", m);

	return 0;
}

int entero(int *r)
{
	int i=20;
	*r=i;
	return *r;
}


/*
la funcion entero() admite un puntero
y retorna un entero.

en la declaracion de su argumento
(int *r) admite la dirección de
un espacio de memoria de tipo int

en este caso m es una variable,
entoces le paso su dirección...
esto equivale r=&m al invocar la
funcion entero().

dentro de la funcion *r=i;
le asigna a m el contenido de i.
m=i; porque el puntero r apunta
 a la direccion de la variable
 entera m

la funcion retorna un entero, esto
quiere decir que retorna un una
 variable entera, o más bien un valor
entero... return *r;
porque r es un puntero, y los
punteros tratan directamente con
 direcciones de memoria, entonces
 para obtener el valor contenido
 en el espacio de memoria apuntado
 desreferenciamos con asterisco.
	m=entero(&m);

/*
