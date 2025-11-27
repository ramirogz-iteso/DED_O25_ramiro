#include <stdlib.h>
#include "pq.h"

struct pq_str {
  void ** heap;		/* heap es el arreglo que almacenará los datos 
                     a manera de un heap */
  int capacity;	  /* capacidad/tamaño físico del arreglo **/
  int size;				/* tamaño lógico de la cola de prioridad 
                     <--> posición del siguiente elemento a insertar */
  CompareFunc compare;	/* Función de comparación entre dos datos */
};

pq * pq_create(int initialCapacity, CompareFunc compare) {
  pq * queue = (pq * ) malloc(sizeof(struct pq_str));
  if(initialCapacity < 1) initialCapacity = 1;
  queue->capacity     = initialCapacity;
  queue->size         = 0;
  queue->compare      = compare;
  queue->heap         = (void *) malloc(initialCapacity * sizeof(void *));
  return queue;
}

int parent(int child) 
{
  //if(child == 0) return -1;
  return (child - 1) / 2;   // (0 - 1) / 2 = -1 / 2 = 0
}

void swap(void ** a, void ** b) {
  void * c = *a;
  *a = *b;
  *b =  c;
}

void pq_offer(pq * q, void * data)
{
  int current_idx = q->size;    // el actual indice donde se inserta
  int parent_idx;               // se usara solo si se necesita 
  q->heap[current_idx] = data;
  q->size++;

  /* no hay nada mas que hacer, si apenas insertamos el primer elemento */
  if(q->size == 1)
    return;

  /* Para todos los demas, debemos revisar que el heap siga cumpliendo con
     todas sus propiedades y subir el valor insertado a su lugar final de 
     ser necesario : 
    current = el indice actual donde se encuentra el elemento a instertar
              por default, se inserta siempre al final (en el slot size)
    parent  = el nodo padre, del current.
    Ambos indices se actualizaran hasta poner el dato en su lugar  */
  
  parent_idx = parent(current_idx);

  /* mientras current tenga mas prioridad que su padre, intercambiar */
  while(q->compare(q->heap[current_idx], q->heap[parent_idx]) < 0) 
  {
    swap(&q->heap[current_idx], &q->heap[parent_idx]);
    current_idx = parent_idx;
    parent_idx = parent(parent_idx);

    /* si current llega al indice 0, ya no hay mas intercambios que hacer */
    if(current_idx == 0)
     break;  
  }
}

void * pq_peek(pq * q)
{
  if(q->size == 0) return NULL;
  else return q->heap[0];

}

int left(int parent) {
  return 2 * parent + 1;
}

int right(int parent) {
  return 2 * parent + 2;
}

void * pq_poll(pq * q) 
{
  /* si el heap esta vacio, nada que retornar */
  if(q->size == 0) return NULL;

  /* la raiz siempre tendra el elemento de mayor prioridad y ese se retorna */
  void * toPoll = q->heap[0];
  q->size --;

  /* si era el unico elemento, no hay ningun arbol que arreglar, aqui
  terminamos */
  if(q->size == 0) return toPoll;

  /* si habia mas nodos, en el heap, tenemos que asegurarnos que 
     siga compliendo todas las propiedades */

  /* paso 1: subir el ultimo elemento insertado como nueva raiz */
  q->heap[0] = q->heap[q->size];
  int current_idx = 0;
  boolean stop_swapping = FALSE;

  /* paso 2, bajar ese elemento hasta que encuentre su lugar, intercambiandose
  por el hijo de mayor prioridad */
  while(!stop_swapping) 
  {
    int toSwap = current_idx;
    int left_idx = left(current_idx);
    int right_idx = right(current_idx);
    
    /* encuentra el nodo con mayor priodad de los hijos de current idx */
    if(left_idx < q->size &&
       q->compare(q->heap[left_idx], q->heap[current_idx]) < 0)
    {
      toSwap = left_idx;
    }
    if(right_idx < q->size && 
       q->compare(q->heap[right_idx], q->heap[toSwap]) < 0)
    {
      toSwap = right_idx;
    }

    /* si el valor de toSwap se movio, tenemos que hacer un intercambio */
    if(toSwap != current_idx) 
    {
      swap(&q->heap[current_idx], &q->heap[toSwap]);
      current_idx = toSwap;
    }
    else 
    {
      stop_swapping = TRUE;
    }
  }
  return toPoll;
}

int pq_size(pq * q) 
{
  return q->size;
}
