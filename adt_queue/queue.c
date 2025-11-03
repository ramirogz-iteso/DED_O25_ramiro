#include "queue.h"
#include <stdlib.h>

/* Queues (Colas) */
struct node_str {
  void * data;
  struct node_str * next;
};

typedef struct node_str node;

struct queue_str {
  node * head;  // first
  node * tail;  // last
  int size;
};

/* Crea la estructura queue con todos sus apuntadores (head y tail) 
apuntando a NULL asi como tamanio 0 */
queue * queue_create() {
  queue * q = (queue *) malloc(sizeof(queue));
  q->head = NULL;
  q->tail = NULL;
  q->size = 0;
  return q;
}

void queue_destroy(queue * q) {
  node * current = q->head;
  while(current != NULL) {
    node * next = current->next;
    free(current);
    current = next;
  }
  free(q);
}

int queue_size(queue * q) 
{
  return q->size;
}

/* Regresa TRUE o FALSE si la queue esta vacia, esta funcion
no solo se exporta al cliente sino que la aprovecharemos
nosotros mismos */
boolean queue_isEmpty(queue * q) 
{
  if(q->size == 0)
    return TRUE;
  else
    return FALSE;
}

/* Forma los elementos conforme llegan, cada nuevo elemento se
va al final de la queue (tail) y el primer elemento se forma
al frente (head). Solo la funcion dequeue podra sacar elementos
del head */

void queue_enqueue(queue * q, void * data) 
{
  node * n = (node *) malloc(sizeof(struct node_str));
  n->data = data;
  n->next = NULL;
  if(queue_isEmpty(q)) 
  {
    q->head = n;
  } 
  else 
  {
    q->tail->next = n;
  }
  q->tail = n;
  q->size ++;
}

/* Nos permite ver el elemento siguiente a procesar de nuestra
queue, pero NO se remueve */
void * queue_peek (queue * q) 
{
  if(queue_isEmpty(q)) return NULL;
  return q->head->data;
}

/* Procesa y remueve un elemento de la queue, siempre remueve
el que esta a medio adelante (head) y lo remueve dado que ya se
proceso (se elimina el nodo) */
void * queue_dequeue(queue * q) 
{
  if(queue_isEmpty(q)) return NULL;
  node * n = q->head;
  q->head = q->head->next;
  void * data = n->data;
  free(n);
  q->size --;
  return data;
}