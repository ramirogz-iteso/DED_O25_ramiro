#include <stdio.h>
#include <stdlib.h>

/*  Malloc / Free 

  Use only dynamic memory for this excercise.
  Remember, for EVERY malloc, there must exist a free */

int main()
{
  /* 1) create an int, and assign the value 10 to it. Print it to be sure */
  int x = 10; // this is static, not this
  int *iptr = malloc(sizeof(int));

  *iptr = 999;

  printf("The value stored in iptr is %d\n", *iptr);

  getchar();

  /* 2) create an array of 10 integers  */
  int array[10];  // this is static, not this
  int *darray = malloc(sizeof(int)*10);

  /* 2.1) fill every space with random numbers  */
  //verify with a print
  int * a = darray;
  for (int i =0; i<10; i++)
  {
    *a = i+100;
    a++;
    //darray[i]= i+100;
  }  

  for (int i =0; i<10; i++)
  {
    printf("%d ", darray[i]);
  }  
  printf("\n");
 

  /* 3) Create an array with 20 chars, and put your name in it, (request it to the user)
        and print it  */
  char name_s[20] = {"Ramiro"};   // this is static, not this
  char * name = malloc (sizeof(char)*20);

  printf("Input your name: ");
  int ret = scanf("%s", name);
  /* 3.1 imprimelo */
  printf("My name is : %s\n", name);



  /* 3.1 print it */

  /* before this simple program complete. What do we need to do? 
    Remember the golden rule! */
  
  // destroy the memory for the integer create at 1)
  free(iptr);

  // destory the memory for the array of integers created at 2)
  free(a);

  // destroy the memory for the array that contained your name.
  free(name);

  /* and who will release the memory for the pointers? We don't! because all
  of our pointers, were created with STATIC memory and the program will free that
  memory for us as soon as the scope of the variable ends. */

  /* ==================================================================== */
}