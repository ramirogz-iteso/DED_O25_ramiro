#include <stdio.h>

int main() {
  
  	// A variable
    int var = 10;
  
    // Pointer to int
    int *ptr1 = &var;
  
    // Pointer to pointer (double pointer)
    int **ptr2 = &ptr1;  

    printf("var: %d\n", var);          
    printf("*ptr1: %d\n", *ptr1);
    printf("**ptr2: %d\n", **ptr2);

    printf("\n"); getchar();

    printf("contents:\n");
    printf("var: %d\n", var);
    printf("ptr1 %p\n", ptr1);
    printf("ptr2 %p\n", ptr2);

    printf("\n"); getchar();

    printf("where they live?\n");
    printf("var: %p\n", &var);
    printf("ptr1 %p\n", &ptr1);
    printf("ptr2 %p\n", &ptr2);

    return 0;
}