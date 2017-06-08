/********************************************************************************
Nombre del Archivo:			
	mochila.c
Fecha:					
	8 de junio del 2007
Programador(es):			
	Pioquinto Hernández Christian René
Compilador Utilizado:			
	gcc -std=c99 GNU LINUX
Que hace el Programa?		
	 -Programa que pide al usuario una cantidad de elementos para guardar en una lista dinamica
	-Pide un tamaño maximo para la mochila y comienza a introducir los valores de
	peso (w) y de valor (n)
	Mediante programacion dinamica guarda la informacon en una tala (MATRIZ)
	Compara los valores para obtener los mas optimos y los almacena en un conjunto solucion en memoria dinamica

	Se imprime la lista de los objetos ingresados, la tala de resultados intermedios junto con el conjunto solución.
********************************************************************************/
#include <stdio.h>
#include "Objeto.h"
#define clear() printf("\033[H\033[J") 

/*----------------------------------------------------------------
 *                           Driver program
 *----------------------------------------------------------------*/
int main(int argc, char const *argv[])
{
	clear();
	printf("\tBienvenido al programa de la mochila. :D\n");

	//creando los conjuntos en memoria dinamica
	LinkedList* objetos  = crearLista();
	LinkedList* solucion = crearLista();
	
	//El usuario decide cuantos objetos ingresar y el peso MAX de la mochila
	int noObj, wMochila;

	printf("Ingrese el Numero de Objetos:\n->");
	scanf("%d",&noObj);
	printf("Ingrese el Peso MAXIMO de la mochila:\n->");
	scanf("%d",&wMochila);

	//llenando la lista de objetos.
	ListaSet(objetos, noObj);

	//Funcion que calcula por programacion dinámica 
	MochilaPD(objetos, solucion, noObj, wMochila);

	//Imprimo las listas tanto como las de objestos como la de solcion
	printf("OBJETOS ALMACENADOS:\n");
	getListas(objetos);
	printf("\n");
	printf("SOLUCION\n");
	getListas(solucion);
	printf("\n\n\n");
				printf("\E[0;4;37;41;1;33m\t\tC R E D I T O S:\E[00m\n\n");
				printf("\E[43;5;1;32;8m\tPROGRAMADOR: Pioquinto Hernandez Christian René  \E[00m  ");
				printf("\E[1;42m  \E[00m\E[37;41m▓▓\E[00m\E[37;41m  \E[00m  \n\t\t\E[1;42mHecho\E[00m\E[1;37;47;0men\E[00m\E[37;41mMéxico\E[00m\n");

	//LIberando memoria dinámica
	destruyeLista(objetos);
	destruyeLista(solucion);
	return 0;
}