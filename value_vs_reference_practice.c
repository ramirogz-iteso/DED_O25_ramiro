#include <stdio.h>

/* 
  Excercise 1 : swap
  Create a function that "swaps" the contents of two variables.
  It should receive two intengers, return nothing and after it execution
  whatever what inside one variable should be inside the other and viceversa 
*/

/* Excercise 2 : blackjack

Create a blackjack function that:
  -receives 2 numbers and a FLAG (char)
  -returns 1 of the sum of the numbers is positive (greater than 0).
  -returns 0 if the sum of the numbers is negative.
  -Stores the sum of the two numbers in number2.
  -If the sum is 21, set the FLAG to = 'W' (winner)
*/

//prototypes:
// firma = que recibe, como se llama y que devuelve
int blackjack(int, int *, char *);

int main()
{

  /* Exercise 1:  swap num1 and num2 value */
  int num1 = 1;
  int num2 = 20;

  //CALL YOUR SWAP FUNCTION HERE:

  //Validate that the numbers were swaped:
  printf("num1 = %d num2 = %d\n", num1, num2);

  /* Exercise 2:  Blackjack 
    Call and test your program here */
  char flag = '0';  //init value

  int result = 100; 

  int a = -100;
  int b = 10;

  printf("la direccion de la variable b es %p\n", &b);

  result = blackjack( a, &b, &flag);

  //Validate that the flag was correctly set, try it with different
  //numbers.
  printf("funcion regreso %d , la suma fue %d  y %c\n", result, b, flag );
  
  return 0;
}

              //valor.     /referencia
int blackjack (int n, int *n2, char *letra)
{
  printf("argument: 1 %d\n", n);
  printf("argument: 2 %p y contiene %d\n", n2, *n2);
  printf("argument: 3 %p y contiene %c\n", letra, *letra);

  *n2 = n + *n2;
  (*n2 == 21) ? (*letra = 'W') : (*letra = 'L');
    
  if(*n2 > 0) //0x16dc9ee83
    return 1;
  else
    return 0;

  //  (si esto se cumple) ? lo quesi : lo que no;
}

/*
int blackjack (int n, int *n2, char *letra)
{
  printf("argument: 1 %d\n", n);
  printf("argument: 2 %p y contiene %d\n", n2, *n2);
  printf("argument: 3 %p y contiene %c\n", letra, *letra);

  int result = n + *n2;
  int to_return;
  if (result > 0)
    to_return = 1;
  else
    to_return = 0;

  *n2 = result;
  
  if (*n2 == 21)
    *letra = 'W';
  else
    *letra = 'L';

  return to_return;
}
*/