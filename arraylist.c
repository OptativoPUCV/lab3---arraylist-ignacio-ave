//CODIGO LABORATORIO N3 IGNACIO ASTORGA. 
//replit: https://replit.com/join/pfczrqlope-ignacioastorga  (CODIGO SIN COMENTARIOS FINALES)

#include "arraylist.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayList {
  void **data;  
  int capacity; 
  int size;    
} ArrayList;
             
             
ArrayList *createList(void) { // crear un arraylist vacio
  ArrayList *nuevo = (ArrayList *)malloc(sizeof(ArrayList)); // reservar memoria para el arraylist
  nuevo->data = (void **)malloc(sizeof(void *) * 2); // reservar memoria para el array de punteros
    
  if (nuevo == NULL || nuevo->data == NULL) // si no se pudo reservar memoria
    exit(1);

  nuevo->capacity = 2; // capacidad inicial
  nuevo->size = 0; // tamaño inicial

  
  return nuevo;
}


void doblarcapacity(ArrayList *l) {  // doblar la capacidad del array
  l->data = realloc(l->data, sizeof(void *) * 2 * l->capacity); // doblar la capacidad del array
  if (l->data == NULL) // si no se pudo reservar memoria
    return;
  l->capacity *= 2; // doblar la capacidad
}

void append(ArrayList *l, void *data) { // agregar un elemento al final del array
  if (l->size == l->capacity) // si el array esta lleno
    doblarcapacity(l);
  l->data[l->size] = data; // agregar el elemento al final del array
  l->size += 1; // aumentar el tamaño del array
}


void push(ArrayList *l, void *data, int i) {
  if (l->size == l->capacity) // si el array esta lleno
    doblarcapacity(l);
  if (i > l->size) // si el indice es mayor al tamaño del array
    return;
  if (i == l->size) { // si el indice es igual al tamaño del array
    append(l, data);
    return;
  }

  // si el indice es menor al tamaño del array
  void *aux1 = NULL;  // variable auxiliar
  int resto = l->size - i ;
  for(int k = 0 ; k  < resto ; k++){ // recorrer el array desde el indice hasta el final
    aux1 = l->data[i+k]; // guardar el valor del elemento en aux1
    l->data[i+k] = data; // guardar el valor de data en el elemento
    data = aux1; // guardar el valor de aux1 en data
  }

}


void *pop(ArrayList *l, int i) { // eliminar un elemento del array
  if (i > l->size) // si el indice es mayor al tamaño del array
    return NULL;

  void *valor_eleminado = l->data[i]; // guardar el valor del elemento a eliminar

  if (i == l->size) { // si el indice es igual al tamaño del array
    l->data[l->size] = NULL;
    l->size--;
    return valor_eleminado;
  }

  l->data[i] = NULL; // eliminar el elemento
  int resto = l->size - i; // calcular el resto de elementos
  for (int j = 0; j < resto; j++) { // recorrer el resto de elementos
    l->data[i + j] = l->data[i + j + 1]; // mover los elementos
  }
  l->size--; // disminuir el tamaño del array
  return valor_eleminado;
}


void *get(ArrayList *l, int i) { // obtener un elemento del array
  if (i < 0) // si el indice es negativo
    i = l->size + i;

  if (i >= l->size) // si el indice es mayor al tamaño del array
    return NULL;

  return l->data[i]; // retornar el elemento
}

int get_size(ArrayList *l) {   // obtener el tamaño del array
  return l->size; 

}


void clean(ArrayList *l) { // limpiar el array de data
    // hacer un free de cada elemento del array y luego del array 
    // y por ultimo hacer un malloc de nuevo
  for (int i = 0; i < l->size; i++){
    free(l->data[i]);
  }
    // habia una alternativa que me soluciono el problema inicialmente l->data = NULL;
  l->data = (void **)malloc(sizeof(void *) * 2); // reservar memoria para el array de punteros
  l->capacity = 2; 
  l->size = 0;
    

}
