/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CLEAR printf("\033[0;0H\033[2J");

void ex01();
void ex02();
void upper_to_lower(char*);
//void ex03();
//void ex04();

int main()
{
  //RUN/try your functions here:
 
  return 0;
}

void ex01()
{
  /* Excerice 01:
  Create an array of 10 integers, set their value (whatever you want)
  Using pointer arithmetic and a for loop traverse and print all the array

  DO NOT USE BRACKETS [ ]
  
  Print both the value and the address.
  
  ie
    int array = [ 2 , 3 , 5 , 6]

    array[0] = 2 -> addr = 0x00001
    array[1] = 3 -> addr = 0x00004
    array[2] = 5 -> addr = 0x00008
    array[3] = 6 -> addr = 0x0000B
*/
}

void ex02()
{
  /* Excercise 02:
  Implement a function mylenght() that returns the size of the passed 
  string (char array). DO NOT USE strlen(), use only pointer arithmetic.

  DO NOT USE BRACKETS [ ]

  TIP: all strings are array of chars, terminated by '\0' character.
*/
  char name[400];
  int ret;
  
  //TRY ME HERE:

}

/* More practice excerises (similar to Ex02)

  NOTA :  DO NOT USE [BRACKETS] in any function
  
  Excercise 03
  Implement a function that receives an array, traverses the array
  chaging all letters in CAPs to Lowercase.
  The array must be printed in the main loop to verify the results.
  TIP: See ASCII table
  
*/

/* Exercise 04
  Implement an isBinary function that receives a string and determines
  if its a binary number (must be formed of only 1s and 0s).
*/
  
