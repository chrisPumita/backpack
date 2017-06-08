#include <stdio.h>
#include "lista.h"
#include "Objeto.h"
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

#if 0
LinkedList* MochilaPD(LinkedList *obj, int w)
{
	LinkedList* solucion = LinkedList_Create();
	//Creamos la lista de solcuiones vacia (SIN NODOS)

	//obj, son los objetos que ya existen en otra lista y que iremos comparado
	// recorremos todos los productos hasta el ultimo
	Node* it = obj->first;
	int pesoAct= 0;
	while (it != NULL) 
	{
		while(pesoAct<w)
		{

		}
		if (it->peso<w)
		{
			// Puede entrar en la mochila
			LinkedList_Insert (solucion, it->peso, it->capacidad);
			pesoMochila += it->peso
		}

		/*
		printf("PESO: %d & ",it->peso);
		printf("VALOR: %d\n",it->valor);
		 */
		it = it->siguiente;
	}
}
#endif

int main(int argc, char const *argv[])
{
	clear();
	int Items[4][2] = 
					{  //w i
						{2,3},
						{3,4},
						{4,5},
						{5,6}
					};

	int W = 5; // PESO MAX DE LA MOCHILA
	int n = 4; // ELEMENTO
	int V[W][n];

	//I elementos
	//W peso
	for (size_t w = 0; w < W; ++w) {V[0][w] = 0;} // fila
	for (size_t i = 1; i < n; ++i) {V[i][0] = 0;} // columna
		//llenando la V en las primeras columnas con ceros


	for (size_t i = 1; i < n; ++i)
	{
		for (size_t w = 1; w < W; ++w)
		{
			// comparacion de los pesos
			printf("i = %d - ",i);
			printf("bi = %d - ",Items[i-1][1]); // El valor
			printf("wi = %d - ",Items[i-1][0]); // el peso w
			printf("w = %d - ",w);
			printf("i = %d\n",w-Items[i-1][0]);
			if (V[i][w]<=w)
			{
				if (Items[i-1][1] + V[i-1][w-Items[i-1][0]]>V[i-1][w])
				{
					V[i][w] = Items[i-1][1] + V[i-1][w-Items[i-1][0]];
				}
				else
				{
					V[i][w] = V [i-1][w];
				}
			}
			else
			{
				V[i][w] = V[i-1][w]; // w1 > w
			}
		}
	}

for (size_t i = 0; i < n; ++i)
{
	for (size_t j = 0; j < W; ++j)
	{
		printf("[%d]",V[i][j]);
	}
	printf("\n");
}

#if 0


	//creando objetos
	LinkedList* objetos  = LinkedList_Create ();
	LinkedList* solucion = LinkedList_Create();
	


	//Definiendo el pero maximo de la mochola

	//ingresando proudtos a la lista
	// Peso / Valor
	LinkedList_Insert(objetos, 10, 20);
	LinkedList_Insert(objetos, 20, 30);
	LinkedList_Insert(objetos, 30, 66);
	LinkedList_Insert(objetos, 40, 40);
	LinkedList_Insert(objetos, 50, 60);
	printf("Soluciones\n OBJETOS TODOS");
	verListas(objetos);

	printf("Solucion MOCHILA\n", );
	verListas(solucion);
#endif
	return 0;
}