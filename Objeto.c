#include <stdio.h>
#include "lista.h"
#include "Objeto.h"
#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })
#define clear() printf("\033[H\033[J") 
#define MAX 202

//El peso MAX de la mochila sera de 20

void verListas(LinkedList* this)
{
	Node* it = this->first;
	while (it != NULL) 
	{
		printf("PESO: %d & ",it->peso);
		printf("VALOR: %d\n",it->valor);
		it = it->siguiente;
	}
}

void CreaListProductos(LinkedList* this, int noObj)
{
	int peso, valor;
	for (size_t i = 0; i < noObj; ++i)
	{
		printf("Ingrese el peso del Objeto %d:\n->",i);
		scanf("%d",&peso);
		printf("Ingrese el valor del Objeto %d:\n->>",i);
		scanf("%d",&valor);
		LinkedList_Insert(this, peso, valor);
	}
}


#if 1
void MochilaPD(LinkedList* this, LinkedList* sol, int n, int w)
{
	//declarando arreglos de peso y valor
	int peso[n];
	int valor[n];
	int i = 0;
	int dp[50][50];
	//recuperando los datos del NODO
	Node* it = this->first;
	while (it != NULL) 
	//while (i<=n) 
	{
		peso[i] = it->peso;
		valor[i]= it->valor;
		i++;
		printf("w->: %d & ",it->peso);
		printf("val: %d\n",it->valor);
		it = it->siguiente;
	}

printf("\n");
	//inicializando tabla
	dp[n+1][w+1];
	int m = w;

	//inicializando filas y columas en 0
	for (size_t i = 0; i < n; ++i){ dp[i][0] = 0; }
	for (size_t i = 0; i < m; ++i){ dp[0][i] = 0; } 

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (peso[i-1] <= j)
			{
				dp[i][j] = max(dp[i-1][j],valor[i-1] + dp[i-1][j-peso[i-1]]);
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}


	printf("EL VALOR MAX ES: %d\n",dp[n][m]);

	printf("IMPRIMIENDO TABLA ANALITICA\n");

	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			printf("| %d |",dp[i][j]);
		}
		printf("\n");
	}

	printf("Imprimiendo conjunto solucion:\n");
	int j = w;
	for (int i = n; i > 0; --i)
	{
		if (dp[i][j] == dp[i-1][j])
		{
			
		}
		else
		{
			printf("%d\n",peso[i-1]);
			j-= peso[i-1];
			LinkedList_Insert(sol, peso[i-1], valor[i-1]);
		}
	}
}
#endif

int main(int argc, char const *argv[])
{
	clear();
/*
	int  peso[4] = {2,3,4,5};
	int valor[4] = {3,4,5,6};
 */
	//creando objetos
	LinkedList* objetos  = LinkedList_Create ();
	LinkedList* solucion = LinkedList_Create();
	int noObj, wMochila;

	printf("Ingrese el Numero de Objetos:\n->");
	scanf("%d",&noObj);
	printf("Ingrese el Peso MAXIMO de la mochila:\n->");
	scanf("%d",&wMochila);
	//llenando la lista de prodicto
	CreaListProductos(objetos, noObj);
	MochilaPD(objetos, solucion, noObj, wMochila);
	printf("SOLUCION\n");
	verListas(solucion);
	return 0;
}