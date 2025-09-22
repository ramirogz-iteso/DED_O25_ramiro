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
  //char student[40] = "PUT YOUR FULL NAME HERE";
  //char short_name[20] = "your_alias";
  //printf("Hellow world, my name is %s and this is my exam\n", student);
  //printf("The professor just calls me: %s\n", short_name);

  //printf("-------ex 01 ----------\n");
  //excercise01();
  //printf("\n-------ex 02 ----------\n");
  excercise02();
}

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

  void **ptr = thing;

  *(char *)*ptr = 'Z';
  ptr++;
  *(int *)*ptr = 5;
  ptr++;
  strcpy((char*)*ptr , "NAVE");

  /*
  c = (char *) thing[0];
  *c = 'F';
  *(int *)thing[1] = 1;
  strcpy((char*)thing[2] , "Car");
  */

  /*void **ptr = thing; 

  char *letter = (char *)ptr[0];
  int  *nump   = (int *)ptr[1];
  char *name   = (char *)ptr[2];
  */

  /* using pointer math 
  void **ptr = thing;

  char *letter = (char *)*ptr;
  ptr++;
  int  *nump   = (int *)(*ptr);
  ptr++;
  char *name   = (char *)*ptr;
  */
  /*
  *letter = 'F';
  *nump = 1;
  strcpy(name, "Car");*/
}

typedef int (*foo)(int, int);

void f1(void ** p)
{
  int * n1 = (int *)p[0];  //void *. int *
  int * n2 = (int *)p[1];  //void *. int *
  char * n3 = (char *)p[2];  //void * char *
  foo fun1 = (foo )p[3];

  int res = fun1(*n1, *n2);

  printf("%d %d %c %d\n", *n1, *n2, *n3, res);


}
                 // typo dir primer
void print_numbers( int * arreglo)
{
  printf("num 1 = %d\n", arreglo[0]);
  printf("num 2 = %d\n", arreglo[1]);
}

int suma(int a, int b)
{
  return a+b;
}



void excercise02()
{

  int num = 10;
  int x = 5;
  char l = 'R';

                   //int*   int*  char*. *foo
  void * vptr[4] = {&num,   &x,  &l , suma };

  void ** dptr2 = vptr;

  f1(dptr2);



  return;



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
  void * array[3];

  // B
  array[0] = (void *)&letter;
  array[1] = (void *)&num2;
  array[2] = (void *)name;

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

