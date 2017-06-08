#ifndef LISTA_INC
#define LISTA_INC

#include <stdio.h>
#include <stdlib.h>
#include "Bool.h"

 struct Node_Type
 {
 	int peso;
 	int valor;
 // datos
 	struct Node_Type* siguiente;
 // apuntador al siguiente nodo
 };
 typedef struct Node_Type Node;
  /**
 * @brief Estructura de la lista en memoria dinamica
 *
 * @param peso Valor del peso del objeto
 * @param valor El valor que se le da al objeto
 * @param siguiente apuntador al siguiente nodo
 */

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


//-----------------FUNCIONES PRIVADAS--------------*/

/**
 * [newNode  Crea un nuevo nodo y le agrega la información]
 * @param  peso  [Es el peso tipo entero del objeto]
 * @param  valor [Es el valor del objeto de tipo entero]
 * @return       [Regresa la dirección del nodo]
 */
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

/**
 * [deleteNode  Borra el nodo]
 * @param n [Es la dirección del nodo a borrar]
 */
 static void deleteNode (Node* n)
 {
	 if (n) {
		 free (n);
	 }
 }
 
 
/*--------- Estructura del nodo ------------*/
	/* Funciones de la Listas */

/**
 * [Crea una lista enlazada]
 * @return [Regresa la dirección de la lista enlazada creada]
 */
LinkedList* LinkedList_Create ();

/**
 * [Destruye la lista enlazada]
 * @param this [Es la dirección de la lista enlazada a destruir]
 */
void LinkedList_Destroy (LinkedList* this);

/**
 * [LinkedList_Remove Remueve el ultimo elemento de la lista]
 * @param this [Es la direcion de la lista]
 */
void LinkedList_Remove(LinkedList* this);

/**
 * [Inserta un nodo en la lista enlazada]
 * @param  peso  [Es el peso tipo entero del objeto]
 * @param  valor [Es el valor del objeto de tipo entero]
 * @return
 */
Bool LinkedList_Insert (LinkedList* this, int peso, int valor);

#if 0 //SIn utilizar
Bool LinkedList_FindIf (LinkedList* this, int val);

Node* LinkedList_Search(LinkedList* this, int val);
 #endif

#endif /* -----ifndef LISTA_INC ------*/