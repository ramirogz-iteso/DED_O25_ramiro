#include <stdio.h>
#include <stdlib.h>
#define CLEAR printf("\033[0;0H\033[2J");

/* USE THE CODE SEEN IN THE CLASS SLIDES TO COMPLETE THE FOLLOWING EXERCISE 
   TIP, code everything in the following order:
   1) printlist. As this function only traverses the list without modifying
   2) add      . adds to the end, follow the printlist logic to get to the end
                 and just attach the new node to the last node

   all the other functions
   
   */

/* The node */
typedef struct node {
  int value;
  struct node *next;
} node;

node *header = NULL;  //<--- this is our first linked list! :) 

/* Our header is called "header" and is a GLOBAL variable  initialized to NULL
   All functions in this exercise will consider "header" as the head of the 
   only list that exists here.  
   In reality, there should be many lists, and functions should receive the 
   list to apply operations to, but we will see that later. */

//Pending:
node *newNode(int n) 
{
  //Remember the code to this is on the slides
  node *new_node = (node*) malloc(sizeof(node));
  new_node->value = n;
  new_node->next = NULL;
  return(new_node);
}


//Pending:
void printlist(node *list) 
{

}

//Pending:
/* Function that receives a number to add, then adds this node to the END
   of the linked list. Be careful with corner cases, what happens if the list
   is NULL (empty list?)
   node does not exist, we should create the node  */
void add(int num) 
{

}

//Pending:
/* Function that inserts a node N after X
   Finds the first node with value X and inserts N immediately after..

   Returns 1 if it was inserted, or 0 if not 
   The return code is used by the caller to determine if the created node
   needs to be freed or not (the one this function failed to insert )*/

int insertafter(int new_num, int n)
{
  return 0;
}

//Pending:
/* Function that inserts a node N before X
   Finds the first node with value X and inserts
   N immediately before...

   Returns 1 if it was inserted, or 0 if not 
   The return code is used by the caller to determine if the created node
   needs to be freed or not (the one this function failed to insert )*/

int insertbefore(int new_num, int n)
{
  return 0;
}

//Pending
/* Function to delete the node that contains number N */
void delete(int n)
{

}

//Pending
/* Function to search for a node containing number N. If found,
   it should print the memory address where it resides; 
   if not found, it should print "NULL" */

void search(int to_search)
{

}

int main() 
{
  /* #1 :
  Create a function newNode(n) that creates a new node with value n
  and returns a pointer to the newly created node */

  /* #2:
  Using this function, create a new node to act as the first
  element "header" of our list */

  node *n = newNode(50);
  header = n;

  /* #3:
  Create 5 additional nodes, so that we have a total list of 5 nodes
  properly linked together. Write a function
  add() that receives a node (created with newNode()) and
  adds this node to the end of the list.

  Use a FOR loop to fill the 5 nodes */
  for (int x = 1; x <= 2; x++) 
  {
    add(x+1);
  }

  /* #4:
  Create a print function to print the entire linked list.
  It should look like this:
    1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> NULL
  */
  //printlist(header);

  /* #5:
  Create a menu (inside an infinite while loop), with the following functionalities:
    1) Delete a node
    2) Insert after a given node
    3) Insert before a given node
    4) Search for a node
    6) Insert at the end of the list
  */

  int selection, todel, toinsert, tosearch, putafter, putbefore;
  node *new_node;
  int r;
}

/* #6 Once everything is working, make a copy of this file and  
   name it: doublelinkedlist.c. Add the element "back" to the structure  
   and create a doubly linked list. All functionality must persist.

   The print function should print the list "forward" using `next` and  
   "backward" using `back`, and it should look like this:

     1 -> 2 -> 3 -> 4 -> ... 10 -> 9 -> 8 -> 7 -> ..... 1 -> NULL
*/