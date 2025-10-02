#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define W 100

char **ingresar_lineas(int *nro_lineas_ingresadas);

int main(void)
{
	int n; // nro_lineas_ingresadas=&n
	char **lista=ingresar_lineas(&n);

	if(!lista && n==0) // bloque error
	{
		printf("no se ingresaron lineas o hubo un error.\n");
		return 1;
	}

	printf("\nLineas ingresadas: %d\n", n);

	for(int i=0;i<n;++i)
		printf("%d: %s\n", i+1, lista[i]);

	// liberar memoria
	for(int i=0;i<n;++i)
		free(lista[i]);
	free(lista);

	return 0;
}

// definicion de la funcion
char **ingresar_lineas(int *nro_lineas_ingresadas)
{
	int cant_inic_lineas = 4;
	int cant_lineas_guardadas = 0;
	char buffer_entrada[W + 1];

	char **lista = malloc(cant_inic_lineas * sizeof(char *));

	// error al reservar
	if(!lista)
	{
		perror("malloc");
		*nro_lineas_ingresadas = 0;

		return NULL;
	}

	while(1)
	{
		printf("ingrese una linea o 'n' para salir: ");

		if(fgets(buffer_entrada, sizeof(buffer_entrada), stdin)==NULL)
			break;

		// quitar '\n' final si existe
		size_t len=strlen(buffer_entrada);

		if(len>0 && buffer_entrada[len-1]=='\n')
			buffer_entrada[len-1]='\0';

		// condición de salida del bucle
		if(strcmp(buffer_entrada, "n")==0)
			break;

		// expande arreglo duplicando lineas
		if(cant_lineas_guardadas >= cant_inic_lineas)
		{
			cant_inic_lineas *= 2;
			char **tmp = realloc(lista, cant_inic_lineas * sizeof(char *));
			if(!tmp)
			{
				perror("realloc");
				for(int i=0;i<cant_lineas_guardadas;++i)
					free(lista[i]);
				free(lista);
				*nro_lineas_ingresadas = 0;
				return NULL;
			}

			lista = tmp;
		}

		// asignar espacio y copiar
		len = strlen(buffer_entrada);
		lista[cant_lineas_guardadas] = malloc(len + 1);

		// error al reservar memoria
		if(!lista[cant_lineas_guardadas])
		{
			perror("malloc");
			for(int i=0;i<cant_lineas_guardadas;++i)
				free(lista[i]);
			free(lista);

			*nro_lineas_ingresadas=0;

			return NULL;
		}

		// copia buffer entrada a lista
		strcpy(lista[cant_lineas_guardadas], buffer_entrada);
		++cant_lineas_guardadas; // lleva la cuenta
	}

	// bifurcacion, si hubo error libera
	// memoria y sale sino reasigna y copia
	if(cant_lineas_guardadas==0)
	{
		free(lista);
		lista=NULL;
	}
	else
	{
		char **tmp=realloc(lista, cant_lineas_guardadas * sizeof(char *));

		if(tmp)
			lista=tmp;
	}

	*nro_lineas_ingresadas=cant_lineas_guardadas;

	return lista;
}
