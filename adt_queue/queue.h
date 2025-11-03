#ifndef QUEUE_H_
  #define QUEUE_H_
  
  typedef int boolean;
  
  #define TRUE 1
  #define FALSE 0
  
  typedef struct queue_str queue;
  
  queue * queue_create();
  void  queue_destroy(queue *);
  
  int   queue_size(queue *);
  boolean  queue_isEmpty(queue *);
  
  // enqueue, formarse en la fila
  void queue_enqueue(queue *, void *);  
  // consultar quien esta al frente (sin remover)
  void * queue_peek(queue *);        
  // dequeue, sacar de la queue (fila)
  void * queue_dequeue (queue *);	  	  
#endif /* QUEUE_H_ */
