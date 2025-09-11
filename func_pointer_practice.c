#include <stdio.h>
#include <unistd.h>
#include <string.h>

/* This function is called when student has a non probatory grade */
void mad (char * name, int grade)
{
  printf("Hey %s, you are a Bad boy you better study\n" 
         "your grade is %d!\n",
          name, grade);
  
  printf("Calling parents... \n");
  for(int x = 0; x<3; x++)
  {
    printf("ring...\n");
    sleep(1); // this funcion is inside unistd.h!!
  }
  printf("Thank you, go home.\n");
}

/* This is the regular funcion for any normal student with a normal grade */
void normal (char * name, int grade)
{
  printf("Hey %s, Your grade is %d!\n",
         name, grade);
}

/* Use this funcion to refer to the BEST of the BEST of your class */
void happy (char * name, int grade)
{
  printf("Congrats! %s, Your grade is %d you are the best!\n",
         name, grade);
}

typedef void (* greeting) (char* name, int grade);

/* CHALLENGE: 
  On the main method, create an ARRAY of 3 function pointers
  Store each one of the function pointers in the following positions :  */
#define MAD 0
#define NORMAL 1
#define BEST 2

/* Complete the function "process_student_grade" so it receives this arrays.
  the student, and the grade.

  The function should, depending on the student, call the right function
  following this rules:

    Grade 100, run function store at BEST positon
    Grade < 60, run MAD.
    For everyone else, run NORMAL.
*/
                  //.       chorizo fun ptr,   char *  ,  int 
void process_student_grade(greeting *f, char *name, int grade)
{
  if(grade < 60)
    f[MAD](name, grade);
  else if (grade >= 60 && grade < 100)
    f[NORMAL](name, grade);
  else
    f[BEST](name, grade);
}
  
int main()
{
  char student[10] = "Ramiro";
  int grade;
  printf("Enter your grade... ");
  int ret = scanf("%d", &grade);

  /* PART #1 Complete the instructions provided: 
     create the function pointer  and call process_student_grade */
  // greeting f1 = happy
  //f1(name, grade);
  
  greeting iteso_greetings_fun[3] = {mad, normal, happy};

  process_student_grade( iteso_greetings_fun,  student, grade );


  /* ========================================================*/
  /* PART #2 Now that we think about, would it be nice for the 
  function to be embeeded inside a student structure? 
  
  |--student---|
  | name  ..
  | grade .. 
  | func ----------> ()

  Enhance the program to create a simple student struct, and
  store the relevant function pointer in the struct. 

  Now create a NEW process_student() function, that receives a 
  student struct pointer and executes the function in it.

  NOTE: this is different from the old process_student_grade
  do not modify the one from part 1

  Here you will learn that funcitons pointers can be stored
  inside another object. Use pointers 
  */

  //YOUR CODE HERE:
  //process_student(/*COMPLETE*/);


}