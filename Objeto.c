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



	int  peso[4] = {2,3,4,5};
	int valor[4] = {3,4,5,6};


	int dp[50][50];

	int n = 4, w = 5;
	dp[n+1][w+1];
	int m = w;
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
for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			printf("[%d]",dp[i][j]);
		}
		printf("\n");
	}

	int j = w;
	for (int i = n; i > 0; --i)
	{
		if (dp[i][j] == dp[i-1][j])
		{
			/* code */
		}
		else
		{
			printf("%d\n",peso[i-1]);
			j-= peso[i-1];
		}
	}

#if 0
	int Items[4][2] = 
					{  //w i
						{3,6},
						{5,7},
						{6,8}
					};

	int W = 6; // PESO MAX DE LA MOCHILA
	int n = 3; // ELEMENTO
	int V[W][n];

	//I elementos
	//W peso
		//llenando la V en TODO con ceros
		//
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= W; ++j)
		{
			V[i][j]= 0;
			printf("[%d]",V[i][j]);
		}
		printf("\n");
	}

int cont = 1;

	for (int i = 1; i <= n; ++i)
	{
		printf("\n");
		for (int w = 1; w <= W; ++w)
		{
			printf("CASO %d\n",cont);
			// comparacion de los pesos
			printf("i = %d ",i);
			int bi = Items[i-1][1];
			printf("bi = %d ",bi); // El valor
			int wi = Items[i-1][0];
			printf("wi = %d ",wi); // el peso w
			printf("w = %d ",w);
			printf("w-wi = %d ",w-wi);
			if (wi<=w) // Elemento i puede ser parte de la solución
			{
				V[i][w] = V[i-1][w];
				if (bi + V[i-1][w-wi]>V[i-1][w])
				{
					V[i][w] = bi + V[i-1][w-wi];
				}
				else
				{
					V[i][w] = V[i-1][w];
				}
			printf("VAL DE V[%d][%d] = %d ::  ",i,w,V[i][w]);
			}
			else
			{
				V[i][w] = V[i-1][w]; // w1 > w
				printf("VAL DE V[%d][%d] = %d ::  ",i,w,V[i][w]);
				printf("  wi > w ");
			}
			cont++;
		}
	}
printf("\n");
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= W; ++j)
		{
			printf("[%d]",V[i][j]);
		}
		printf("\n");
	}
#endif

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