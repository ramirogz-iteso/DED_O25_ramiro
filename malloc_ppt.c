#include <stdio.h>
#include <stdlib.h>

int global_a;
int global_b;

void prueba()
{
    printf("Hi, test function\n");
}

int main()
{
  //----------------------- PART 1-------------------------------
  printf("Hello world, lets see where everything lives\n\n");

  int s_int1 = 100;
  int s_int2;

  char c_1;
  char * c1_ptr;

  c1_ptr = (char *)malloc(sizeof(char) * 20);

  printf("\tAddress of global_a %p\n", &global_a);
  printf("\tAddress of global_b %p\n\n", &global_b);
  printf("\tAddress of s_int1 %p\n", &s_int1);
  printf("\tAddress of s_int2 %p\n", &s_int2);
  printf("\tAddress of c_1 %p\n", &c_1);
  printf("\tAddress of c1_ptr [the pointer] %p\n", &c1_ptr);
  printf("\tAddress of c1_ptr [the data it points to] %p\n\n\n", c1_ptr);

  printf("\tAddress of c_1ptr[0] %p\n", &c1_ptr[0]);
  printf("\tAddress of c_1ptr[1] %p\n", &c1_ptr[1]);
  printf("\tAddress of c_1ptr[2] %p\n\n\n", &c1_ptr[2]);

  printf("\tmain %p\n", &main);
  printf("\tprueba %p\n", &prueba);

  getchar();

  //-------------------- PART 2a, b c and d------------------------------
  int * ptr = NULL;
  for (int i = 0; i < 10; i++)
  {
      ptr = malloc(64 * sizeof(int));
      //2d
      //ptr = calloc(64, sizeof(int));
      //printf("after malloc = %d\n ", ptr[10]);

      ptr[10] = 5000;
      printf("ptr addr: %p ptr[0]: %p ptr[10] addr|val: %p|%d",
              &ptr, &ptr[0], &ptr[10], ptr[10]);

      //2b
      //what if we free the memory? run and verify the results
      free(ptr);
      //2c
      printf("ptr[10] after free: %d \n", ptr[10]);
  }

  /* Expected conclusions:
  If free is not called, new memory blocks are used, leaking memory
  Malloc will not zero out the memory, just get you that block
  Calloc will clean up and make sure the memory is zero
  free does not clean up the memory
  reading after free, is undermined, sometimes you see the previous value */

getchar();
}
