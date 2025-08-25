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

  int result; 
  //result = blackjack( /*COMPLETE*/ );

  //Validate that the flag was correctly set, try it with different
  //numbers.
  
  return 0;
}