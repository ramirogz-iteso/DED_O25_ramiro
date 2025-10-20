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
  node *aux = list;
  printf("Current list elements:\n\t");
  while (aux != NULL) 
  {
    printf("[%d]->", aux->value);
    aux = aux->next;
  }
  printf("NULL\n\n");

}

//Pending:
/* Function that receives a number to add, then adds this node to the END
   of the linked list. Be careful with corner cases, what happens if the list
   is NULL (empty list?)
   node does not exist, we should create the node  */
void add(int num) 
{
  node *nptr = header;

  // handle the case where there is no list, header will be null
  // just update header.
  if(nptr == NULL)
  {
    header = newNode(num);
    return;
  }
   
  // cases for adding node n, at the end of a existing list.
  while (nptr->next != NULL) 
  {
    nptr = nptr->next;
  }
  nptr->next = newNode(num);
}

//Pending:
/* Function that inserts a node N after X
   Finds the first node with value X and inserts N immediately after..

   Returns 1 if it was inserted, or 0 if not 
   The return code is used by the caller to determine if the created node
   needs to be freed or not (the one this function failed to insert )*/

int insertafter(int new_num, int n)
{
  node *nptr = header;
  node *next = NULL;
  node *new;

  printf("\t\t(insertafter): number to find: %d\n", n);
  while (nptr != NULL) {
    if (nptr->value == n) 
    {
      printf("\t\t(insertafter): found it!: %d\n", n);
      next = nptr->next;
      new = newNode(new_num);
      nptr->next = new;
      new->next = next;
      return 1;
    } else 
    {
      printf("\t\t(insertafter): not yet, %d\n", nptr->value);
      nptr = nptr->next;
    }
  }
  printf("\t\t(insertafter): failed to find %d, return 0\n", n);
  /* If we reach this, we failed to insert */
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
  node * nptr = header;
  node * back = NULL;
  node * new;
  printf("\t\t(insertbefore): number to find: %d\n", n);
  while(nptr->next != NULL)
  {
    if(nptr->value == n)
    {
      if(nptr == header)
      {
        node *next = nptr;
        new = newNode(new_num);
        header = new;
        header->next = next;
        printf("\t\t(insertbefore): done, replaced header\n");
        return 1;
      }
      else
      { 
        new = newNode(new_num); 
        back->next = new;
        new->next = nptr;
        printf("\t\t(insertbefore): done\n");
        return 1;
      }
    }
    else
    { 
      back = nptr;
      nptr = nptr->next;
    }
  }
  printf("\t\t(insertbefore): failed to find %d, return 0\n", n);
  /* If we reach this, we failed to insert */
  return 0;
}

//Pending
/* Function to delete the node that contains number N */
void delete(int n)
{
  node * nptr = header;
  node * back = NULL;
  printf("\t\t(delete): number to delete: %d\n", n);
  while(nptr != NULL)
  {
    if(nptr->value == n)
    {
      if(nptr == header)
      {
        // Found element in header, update header and delete
        printf("\t\t(delete): found elem %d at Head... update header\n", nptr->value);
        header = nptr->next;
        free(nptr);
        return;
      }  
      else
      {  
        printf("\t\t(delete): found elem %d\n", nptr->value);
        // Delete a non-header node
        node *next = nptr->next;
        free(nptr);
        back->next = next;
        printf("\t\t(delete): element deletion completed\n");
        return;
      }
    }
    else
    {
      // Not this node, continue searching (keeping a pointer
      // to the previous node)
      printf("\t\t(delete): not found (%d)... next\n", nptr->value);
      back = nptr;
      nptr = nptr->next;
    }
  }
}

//Pending
/* Function to search for a node containing number N. If found,
   it should print the memory address where it resides; 
   if not found, it should print "NULL" */

void search(int to_search)
{
  node * n = header;
  while(n->next != NULL)
  {
    if(n->value == to_search)
    {
      printf("\t\t(search): found node [%d] at %p\n", to_search, n);
      return;
    }
    else
    {  
      n = n->next;
    }
  }
  printf("NULL\n\n");
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
  add() that receives the new num
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
  while (1) 
  {
    printlist(header);
    printf("\n");
    printf("Select option:\n 1) Delete\n 2) Insert after\n 3) Insert before\n"
           " 4) Search\n 5) add-to-end\n");
    printf("\topc: ");
    r = scanf("%d", &selection);
    switch (selection) {
    case 1:
      printf("\tNumber to delete: ");
      r = scanf("%d", &todel);
      delete(todel);
      break;
    case 2:
      printf("\tNumber to insert: ");
      r = scanf("%d", &toinsert);
      printf("\tInsert after which node?: ");
      r = scanf("%d", &putafter);
      insertafter(toinsert, putafter);
      break;

    case 3:
      printf("\tNumber to insert: ");
      r = scanf("%d", &toinsert);
      printf("\tInsert before which node?: ");
      r = scanf("%d", &putbefore);
      
      insertbefore(toinsert, putbefore);
      break;

    case 4:
      printf("\tNumber to search: ");
      r = scanf("%d", &tosearch);
      search(tosearch);
      break;
    case 5:
      printf("\tNumber to add: ");
      r = scanf("%d", &toinsert);
      add(toinsert);
      break;
    }
    getchar();
    printf("press enter to continue\n");
    getchar();
    CLEAR
  }
}

/* #6 Once everything is working, make a copy of this file and  
   name it: doublelinkedlist.c. Add the element "back" to the structure  
   and create a doubly linked list. All functionality must persist.

   The print function should print the list "forward" using `next` and  
   "backward" using `back`, and it should look like this:

     1 -> 2 -> 3 -> 4 -> ... 10 -> 9 -> 8 -> 7 -> ..... 1 -> NULL
*/