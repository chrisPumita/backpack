#include <stdio.h>
#include "Objeto.h"
#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })
   //Definido para calcular el maximo de dos números

/*----------------------------------------------------
 *  Implementación del ADT Objeto: Objeto.c
 *----------------------------------------------------*/

void getListas(LinkedList* this)
{
	Node* it = this->first;
	while (it != NULL) 
	{
		printf("PESO: %d & ",it->peso);
		printf("VALOR: %d\n",it->valor);
		it = it->siguiente;
	}
}

void ListaSet(LinkedList* this, int noObj)
{
	int peso, valor;
	for (size_t i = 0; i < noObj; ++i)
	{
		printf("Ingrese el peso del Objeto %d:\n->",i+1);
		scanf("%d",&peso);
		printf("Ingrese el valor del Objeto %d:\n->>",i+1);
		scanf("%d",&valor);
		LinkedList_Insert(this, peso, valor);
	}
}

void MochilaPD(LinkedList* this, LinkedList* sol, int n, int w)
{
	//declarando arreglos de peso y valor
	int peso[n];
	int valor[n];
	int i = 0;
	int Matriz[50][50];
	//recuperando los datos del NODO
	Node* it = this->first;
	while (it != NULL) 
	//while (i<=n) 
	{
		peso[i] = it->peso;
		valor[i]= it->valor;
		i++;
//		printf("w->: %d & ",it->peso);
//		printf("val: %d\n",it->valor);
		it = it->siguiente;
	}

	printf("\n");
	//inicializando tabla
	Matriz[n+1][w+1];
	int m = w;

	//inicializando la 1ra fila y columa en 0
	for (size_t i = 0; i < n; ++i){ Matriz[i][0] = 0; }
	for (size_t i = 0; i < m; ++i){ Matriz[0][i] = 0; } 

	for (int i = 1; i <= n; ++i)
	{
		//Para cada elemeno, recorrerlo de forma horizontal
		for (int j = 1; j <= m; ++j)
		{
			//Comparando el peso con el el peso MAX de la mochila
			if (peso[i-1] <= j)
			{
				//Si el peso es menor, entonces es posible solucion
				Matriz[i][j] = max(Matriz[i-1][j],valor[i-1] + Matriz[i-1][j-peso[i-1]]);
			}
			else
			{
				//Copio el elemnto de arriba de la tabla
				Matriz[i][j] = Matriz[i-1][j];
			}
		}
	}

	//Mostrando resultados obtenidos
	printf("EL VALOR MAX ES: %d\n",Matriz[n][m]);

	printf("IMPRIMIENDO TABLA ANALITICA\n");

	for (int i = 0; i <= n; ++i)
	{
		printf("|");
		for (int j = 0; j <= m; ++j)
		{
			printf("\E[0;1;32m\t%d\E[00m",Matriz[i][j]);
			//printf("\t%d",Matriz[i][j]);
		}
		printf("\t|\n");
		printf("\n");
	}

	//Almacenando en Conjunto solución
	int j = w;
	for (int i = n; i > 0; --i)
	{
		if (Matriz[i][j] == Matriz[i-1][j])
		{
			
		}
		else
		{
			j-= peso[i-1];
			LinkedList_Insert(sol, peso[i-1], valor[i-1]);
		}
	}
}

LinkedList * crearLista()
{
	LinkedList * newList =  LinkedList_Create();
	return newList;
}

void destruyeLista(LinkedList* this)
{
	LinkedList_Destroy(this);
}

#if 0
void Ordena(LinkedList* this, int Nelementos)
{
		//DE MENOR A MAYOR (Ascendente)
	printf("ORDENAMIENTO\n");
	Node* it = this->first;
	int i,j;                //Variables contadoras del ciclo.

	int temp=0;             //Variable temporal.

	for (i=1;i<Nelementos;i++)
	{
	       for (j=0; j <= Nelementos-i ;j++) // for(j=0; j < Nelementos-i; j++) es menor y no menor igual
	       {
	          if (it->peso > ++it->peso)//Condicion mayor-menor
	          {
	            temp = it->peso;
	            it->peso= ++it->peso;
	            ++it->peso;
	            it->peso=temp;
	          }
	       }
	}
	//Para cambiar el modo de ordenamiento solo debemos cambiar la condicion < ó >

}

#endif