#include <stdio.h>
#include "lista.h"
#include "Objeto.h"
#define clear() printf("\033[H\033[J") 
#define TAM_MAX_BACKPACK 20
//El peso MAX de la mochila sera de 20

void verMochila(LinkedList* this)
{
	Node* it = this->first;
	while (it != NULL) 
	{
		printf("PESO: %d & ",it->peso);
		printf("VALOR: %d\n",it->valor);
		it = it->siguiente;
	}
}

int main(int argc, char const *argv[])
{
	//creando objetos
	LinkedList* objetos  = LinkedList_Create ();
	LinkedList* solucion = LinkedList_Create();
	
	//Definiendo el pero maximo de la mochola

	//ingresando proudtos a la lista
	// Peso / Valor
	LinkedList_Insert(objetos, 2, 5);
	LinkedList_Insert(objetos, 4, 6);
	LinkedList_Insert(objetos, 6, 1);
	verMochila(objetos);
	return 0;
}