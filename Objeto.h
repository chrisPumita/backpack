#ifndef OBJETO_INC
#define OBJETO_INC value

#include "lista.h"
/*----------------------------------------------------
 *  Implementación del ADT Objeto: Objeto.c
 *----------------------------------------------------*/

void getListas(LinkedList* this);

/**
 * [ListaSet Pide los valores para llenar la lista]
 * @param this  [Direccion de la lista de donde se obtendra la infomación]
 * @param noObj [Cantidad de objetos que se van a introducir]
 */
void ListaSet(LinkedList* this, int noObj);

/**
 * [MochilaPD Funcion que resuelve el prolema de la mochila con programacion dinamica]
 * @param this [Apuntador de la lista de objetos]
 * @param sol  [Apuntador a la lista de soliciones]
 * @param n    [numero de objetos de la lista]
 * @param w    [peso maximo de la lista]
 */
void MochilaPD(LinkedList* this, LinkedList* sol, int n, int w);

/**
 * [crearLista Crea memoria dinamica para almacenar listas]
 * @return [regresa la direccion de la lista creada en memoria]
 */
LinkedList * crearLista();

/**
 * [destruyeLista Invoca a la funcion destruir de la lista dinamica para liberar memoria]
 * @param this [Apuntador a la lista]
 */
void destruyeLista(LinkedList* this);
#endif