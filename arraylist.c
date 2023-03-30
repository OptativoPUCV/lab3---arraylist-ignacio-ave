#include "arraylist.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*En este laboratorio implementaremos una lista. Para ello usaremos la siguiente
 * estructura (arreglo no circular):*/
typedef struct ArrayList {
  void **data;  // un arreglo dinámico para almacenar punteros a los datos
  int capacity; // el tamaño actual del arreglo
  int size;     // la cantidad de datos válidos almacenados en la lista
} ArrayList; // Se recomienda que el tamaño del arreglo (capacity) sea mayor a
             // la cantidad de datos (size) de la lista. De esta manera, no es
             // necesario expandir el arreglo cada vez que se insertan nuevos
             // datos.

/*
Implemente la función ArrayList *createList(). Esta función crea un nuevo dato
de tipo ArrayList inicializando sus variables. Considere que la capacidad incial
es de 2 casillas para el arreglo.

    Recuerde reservar memoria para el ArrayList y también para el arreglo
dinámico data.
*/
ArrayList *createList(void) {
  ArrayList *nuevo = (ArrayList *)malloc(sizeof(ArrayList));
  nuevo->data = (void **)malloc(sizeof(void *) * 2);
  nuevo->capacity = 2;
  nuevo->size = 0;

  return nuevo;
}
/*
Implemente la función void append(ArrayList * l, void * data). Esta función
agrega el dato al final de la lista (es decir, en la posición size).

    Si el arreglo está lleno aumente la capacidad al doble usando la función
realloc así: data = realloc(data, nueva_capacidad)

    Recuerde aumentar el valor de la variable size.

*/
*/
void doblarcapacity(ArrayList *l) {
  l->data = realloc(l->data, sizeof(void *) * 2 * l->capacity);
  if (l->data == NULL)
    return;
  l->capacity *= 2;
}

void append(ArrayList *l, void *data) {
  if (l->size == l->capacity)
    doblarcapacity(l);
  l->data[l->size] = data;
  l->size += 1;
}


/*

Implemente la función void push(ArrayList * l, void * data, int i). Esta función
ingresa el dato en la i-ésima posición de la lista (i=0 es la primera posición).

    Si el arreglo está lleno, primero debe aumentar su capacidad al doble.

    Recuerde mover los elementos siguientes una casilla a la derecha.

    Si i es mayor a size, la función no debe hacer nada.

*/
void push(ArrayList *l, void *data, int i) {}

/*

Implemente la función void* pop(ArrayList * l, int i). Esta función elimina y
retorna el dato de la posición i de la lista. Valores negativos corresponden a
los datos obtenidos desde el final al principio de la lista (vea la función
get).

    Recuerde que al eliminar un dato, debe mover los elementos que se encuentran
a la derecha, una casilla hacia la izquierda

*/
void *pop(ArrayList *l, int i) { return NULL; }

/*Implemente la función void* get(ArrayList * l, int i). Esta función retorna el
 * dato de la posición i de la lista. Si i>=size, entonces retorna NULL. Además,
 * si i<0 los valores son obtenidos desde el final hacia el principio de la
 * lista.
 */
void *get(ArrayList *l, int i) { return NULL; }

int get_size(ArrayList *l) { return l->size; }

/*

    Implemente la función void clean(ArrayList * list). Esta función inicializa
   la capacidad y tamaño de la lista a sus valores iniciales y reduce el arreglo
   data a su tamaño inicial (2).

*/
void clean(ArrayList *l) {}
