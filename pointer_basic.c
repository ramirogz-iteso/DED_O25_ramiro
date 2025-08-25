/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CLEAR printf("\033[0;0H\033[2J");

void ex1_pointers_size();
void ex2_playing_with_pointers();

int main()
{
  CLEAR
  printf("Hello world\n");
  /* verify the size of the pointers */
  ex1_pointers_size();
  getchar();
  printf("=+=+=+ # # # # =+=+=+ # # # # =+=+=+ \n");
  // COMPLETE EXCERSICE ex_derefencing pointers HERE:
  printf("... complete your excersice ....\n");
  ex2_playing_with_pointers();
  printf("=+=+=+ # # # # =+=+=+ # # # # =+=+=+ \n\n");
  return 0;
}

void ex1_pointers_size()
{
  /* This excercise verifies that the size of the pointer
  is CONSTANT and does NOT change depending on where it points to.
  The size of the pointer is based on the platform, and it is the number
  of bytes required to address the memory space.

  In all 64 bit systems, this is always 8 bytes */

  printf(" = = = = = Ex 01 POINTERS BASICS = = = = = = \n");
  char c = 'A';
  char *ptr_c = &c;
  
  int  i = 1024;
  int *ptr_i = &i;

  /* Verify the size of the variables
     sizeof() returns the size in bytes of what you pass in as arg
     sizeof returns a long, so %ld is the right format option.
  */
  printf( "size of c %ld \n"
          "size of ptr_c %ld\n" 
          "size of i %ld\n" 
          "size of ptr_i %ld\n", 
         sizeof(c), sizeof(ptr_c), sizeof(i), sizeof(ptr_i));
  printf(" = = = = = = = = = = = = = = = = = = = \n");

  getchar();

  /* Pointers can point to any kind of variable, even STRUCTS : */
  //typedef
  struct node {
    int a;
    int b ;
    int c;
  } node;

  struct node mynode;
  struct node *ptr_node = &mynode;

  printf("how big is a pointer to a struct ??");
  getchar();
  
  printf("node size : %ld \n", sizeof (mynode));
  printf("ptr to node size : %ld \n", sizeof (ptr_node));
  printf(" = = = = = = = = = = = = = = = = = = = \n");

  /*  This node contains 3 ints:
    We know then its size must be sizeof(int) x 3 = 12 bytes.
    A pointer to node, is of size 8, just as ALL the pointers on this system. */
  getchar();
  
  /* lastly lets see where everything is in memory */
  printf("the address of variable i = %p \n", &i );
  printf("the value stored in ptr_i = %p \n", ptr_i);
  printf("the value inside i = %d \n", i);
  printf("the value that ptr_i points to = %d \n", *ptr_i);
                                                    //i
  printf(" = = = = = = = = = = = = = = = = = = = \n");
  getchar();

  /* how can I change the VALUE of i indirectly without usign the variable i */
  *ptr_i = 2048;
  printf("the new value of i is %d\n", i);
  getchar();

  /* we can do the same with chars */
  char letter;
  letter = 'A';
  
  char *char_ptr;
  char_ptr = &letter;

  *char_ptr = *char_ptr + 1;
  printf("letter = %c\n", letter);

  /* What you CAN'T do is assign a pointer to another of a different type */
  //char_ptr = ptr_i;
  
  //int a_number;
  //a_number = mynode;

  
}


/* Ex 2: Create a new function (call it from the main loop) 
that does the following:

Declare 3 int pointers variables.
Declare 1 int variable.
Modify the variable value by using a different pointer each time.

Step 1:
  Assign initial value of 10
Step 2:
  Multiply its value by 2.
Step 3:
  Add 5 and print

USE a different pointer in each step.
After each step, print the address of each pointer, the address to 
where it points to and its value:

OUTPUT sample
ptr1 lives in _____________ points to ____________ that cointains _______

see what happens if you use the * on a pointer that is not intialized

Finally print the value of the variable like normal.
*/
void ex2_playing_with_pointers()
{
  int * ptr1; 
  int * ptr2;
  int * ptr3;
  int value;
  printf(" = = = = = Ex02 = = = = = = \n");

  int *ptr5 = NULL;
  if(ptr5 != NULL)
  {
    int x = 10 + *ptr5;
    printf("%d\n", x);
  }

  /* Step 1 */
  ptr1 = &value;
  *ptr1 = 10;
  printf("ptr1 lives in %p points to %p that contains %d\n",
          &ptr1, ptr1, *ptr1);

  /* Step 2 */
  ptr2 = &value;
  *ptr2 = *ptr2 * 2;
   printf("ptr2 lives in %p points to %p that contains %d\n",
          &ptr2, ptr2, *ptr2);

  /* Step 3 */
  ptr3 = ptr2;
  *ptr3+=5;
  printf("ptr3 lives in %p points to %p that contains %d\n",
          &ptr3, ptr3, *ptr3);

  printf("Value = %d\n", value);

  value = 999999;

  int * ptr4 = ptr3;
  printf("printing a big int with an int pointer %d\n", *ptr4 );

  char * cptr = (char*) ptr4;
  printf("printing a big int with an char pointer by mistake %d\n", *cptr );
}