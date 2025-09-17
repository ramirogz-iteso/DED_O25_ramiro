#include <stdio.h>
#include <string.h>
/* 
  Mini challenge, so we can test how hackerrank work
  to solve this you need to understand:
  arrays, void pointers and pointers
  
*/

void excercise01();
void excercise02();

int main()
{
  char student[40] = "PUT YOUR FULL NAME HERE";
  char short_name[20] = "your_alias";
  printf("Hellow world, my name is %s and this is my exam\n", student);
  printf("The professor just calls me: %s\n", short_name);

  printf("-------ex 01 ----------\n");
  excercise01();
  printf("\n-------ex 02 ----------\n");
  excercise02();
}

void holamundo()
{
  printf("ME LLAMARON!\n");
}

typedef void (*funcion)(void);

void excercise01()
{
  //Convert the following FOR loop, so it DOES NOT use brackets [ ].
  //if done correctly the screen should still print:
  /* 
  -------ex 01 ----------
  10 9 8 7 6 5 4 3 2 1

  */
  int numbers[10] = {10,9,8,7,6,5,4,3,2,1};
  int * n = numbers;
  
  for(int i = 0; i<10; i++, n++)
  {
    //printf("%d ", numbers[i]);
    printf("%d ", *n);
  }
  return;
}

void plane_to_car(void ** thing)
{
  char * c;
  int * i;
  char * n;
  funcion p;

  printf("Entrando a mi funcion plane to car\n");

  c = (char *) thing[0];
  *c = 'F';
  *(int *)thing[1] = 1;
  strcpy((char*)thing[2] , "Car");
  p = (funcion)thing[3];

  p();

  printf("saliendo a mi funcion plane to car\n");


}

void excercise02()
{
  char letter = 'B';
  int num2 = 2;
  char name[20] = "Bomber";

  printf("la direccion de letter es : %p\n", &letter);

  //.  void *   void *      void * 
  //  &char     &int        &char
  //     8        8            8
  // [  'B'.  ,    2 ,     "Bomber"       ]

  // a B2 Bomber from US ARMY!! Love that plan

  /* Create an array that contains all 3 components above:
    [0] the Letter
    [1] the Number
    [2] the name 

    Notice how each element is of different type! how do we make arrays of
    different types? is it even possible?

  Create a function plane_to_car() that returns nothing (void) and receives
  only this misterious new array. T
  
  he function should Convert our "B2 Bomber" into
  an "F1 Car" */

  // Create you array and CALL YOUR FUNCTION HERE:
  // START :
  //void *array[3] = {&letter, &num2, name};  A
  void * array[4];
  funcion f1 = holamundo;

  // B
  array[0] = (void *)&letter;
  array[1] = (void *)&num2;
  array[2] = (void *)name;
  array[3] = (void *)f1;

  void * ptr1;
  void * ptr2;
  void * ptr3;

  ptr1 = &letter;
  ptr2 = &num2;
  ptr3 = name;

  array[0] = ptr1; 
  array[1] = ptr2; 
  array[2] = ptr3;

  void ** dptr = array;


  plane_to_car(dptr);
  
  // IF done right, the following should print "F1 Car"
  // DO NOT MODIFY this print, notice how are printing the original variables?
  // there must be away our array store its references, and not its values.
  
  printf("%c%d %s\n", letter, num2, name);
}

