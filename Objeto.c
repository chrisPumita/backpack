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

void CreaListaObj(LinkedList* this, int noObj)
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
#endif


int main(int argc, char const *argv[])
{
	clear();
	printf("\tBienvenido al programa de la mochila. :D\n");

	//creando los conjuntos en memoria dinamica
	LinkedList* objetos  = LinkedList_Create ();
	LinkedList* solucion = LinkedList_Create();
	
	//El usuario decide cuantos objetos ingresar y el peso MAX de la mochila
	int noObj, wMochila;

	printf("Ingrese el Numero de Objetos:\n->");
	scanf("%d",&noObj);
	printf("Ingrese el Peso MAXIMO de la mochila:\n->");
	scanf("%d",&wMochila);
	//llenando la lista de objetos.
	CreaListaObj(objetos, noObj);

	//Funcion que calcula por programacion dinámica 
	MochilaPD(objetos, solucion, noObj, wMochila);

	//Imprimo las listas tanto como las de objestos como la de solcion
	printf("OBJETOS ALMACENADOS:\n");
	verListas(objetos);
	printf("\n");
	printf("SOLUCION\n");
	verListas(solucion);
	printf("\n\n\n");
				printf("\E[0;4;37;41;1;33m\t\tC R E D I T O S:\E[00m\n\n");
				printf("\E[43;5;1;32;8m\tPROGRAMADOR: Pioquinto Hernandez Christian René  \E[00m  ");
				printf("\E[1;42m  \E[00m\E[37;41m▓▓\E[00m\E[37;41m  \E[00m  \n\t\t\E[1;42mHecho\E[00m\E[1;37;47;0men\E[00m\E[37;41mMéxico\E[00m\n");

	//LIberando memoria dinamica
	LinkedList_Destroy(objetos);
	LinkedList_Destroy(solucion);
	return 0;
}