#include <stdio.h>
#include "adt_pq/pq.h"

int compareInts(void * t1, void * t2) {
  int* i1 = (int*) t1;
  int* i2 = (int*) t2;
  return *i1 - *i2;
}

int main() {
  int data[] = {6, 3, 7, 2, 5, 1, 8, 0, 4, -1, 9, -2, 10, -3, 11, -4, 0, 5, 1, -2};
  int N = sizeof(data) / sizeof(int);

  pq * pq1 = pq_create(20, compareInts);
  int i;
  int * peek_num;
  int *ptr = data;
  for(i = 0; i < N; i ++, ptr ++) 
  {
    pq_offer(pq1, ptr);
    printf("Added: %3d. ", *ptr);
    peek_num = (int*) pq_peek(pq1);  
    printf("Peek: %3d\n", *peek_num);
  }

  printf("All items have been added\n");
  printf("Lets poll while size>1 \n");
  getchar();

  int * min;
  while(pq_size(pq1) > 0) 
  {
    min = (int*) pq_poll(pq1);
    printf("Poll: %3d\n", *min);
    getchar();
  }
  return 0;
}
