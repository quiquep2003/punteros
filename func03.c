#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 100

char *pedir_cadena(void);

int main(void)
{
	char *s=pedir_cadena();

	if(!s)
	{
		fprintf(stderr, "error o memoria insuficiente.\n");
		return 1;
	}

	printf("cadena ingresada: %s\n", s);
	free(s);
	return 0;
}

char *pedir_cadena(void)
{
	char buffer[BUF];

	printf("ingrese una cadena: ");

	if(fgets(buffer, sizeof(buffer), stdin)==NULL)
		return NULL;

	size_t len=strlen(buffer);
	if(len>0 && buffer[len-1]=='\n')
		buffer[len-1]='\0';

	char *res=malloc(len+1);
	if(!res)
		return NULL;

	strcpy(res, buffer);
	return res;
}
