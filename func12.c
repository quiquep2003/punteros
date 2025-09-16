#include <stdio.h>

int entero(int r);

int main(void)
{
	int m=8;
	m=entero(m);
	printf("m=%i\n", m);

	return 0;
}

int entero(int r)
{
	int i=20;
	r=i;
	return r;
}

/*

la funcion entero() admite una variable
entera y retorna otra.. en este caso
la misma.

la funcion no puede devolver valor con
un puntero usando memoria reservada
 de manera local porque su contenido
 se elimina tras ser invocada
*/
