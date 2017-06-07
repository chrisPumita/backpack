
#define TAM_TEXT 100
#define TAM_BARRA 20


#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "Bool.h"

 struct Node_Type
 {
 	int peso;
 	int valor
 // datos
 	struct Node_Type* siguiente;
 // apuntador al siguiente nodo
 };
 typedef struct Node_Type Node;

 /*--------- Estructura del LA LISTA ------------*/

/*--------- Estructura de la lista Enlazada ------------*/
 
 /**
 * [Contiene los apuntadores a los nodos contiguos]
 * @first [Es la dirección del primer nodo]
 * @last  [Es la dirección del último nodo]
 **/
 struct LinkedList_Type
 {
	Node* first;
 // apuntador al primer nodo
 	Node* last;
 // apuntador al último nodo
 };
 typedef struct LinkedList_Type LinkedList;

/*--------- Estructura de la lista Enlazada ------------*/


//-----------------FUNCIONES PROVADAS--------------*/

 static Node* newNode (int peso, int valor)
 {
 	Node* n = (Node *)malloc (sizeof (Node));
 	if (n) {
 		//Creando el nodo en memoria
 		n-> peso  = peso;
 		n-> valor = valor;
		n->siguiente = NULL;
	 }
 	return n;
 }

 static void deleteNode (Node* n)
 {
	 if (n) {
		 free (n);
	 }
 }
 
 
/*--------- Estructura del nodo ------------*/
	/* Funciones de la Listas */


LinkedList* LinkedList_Create ();


void LinkedList_Destroy (LinkedList* this);


 void LinkedList_Remove(LinkedList* this);

Bool LinkedList_Insert (LinkedList* this, int peso, int valor);

Bool LinkedList_FindIf (LinkedList* this, int val);

Node* LinkedList_Search(LinkedList* this, int val);
