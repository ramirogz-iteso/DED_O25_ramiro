/*
   PLEASE, rename this file as follows:
      warmup_shortname.c

      like: warmup_ramiro.c

   =========================  WELCOME  ===============================
   You should have see all this in the last semester! its a good idea
   to take this first days to catch up if you find this too difficult.
   Please take advantage of tutoring sessions! (ASESORIAS)

   IMPORTANT: USE THE TERMINAL!!!! :
   Remember, compile with:
   gcc source_file.c -o binary_name.exe      [exe is really optional]
    
   run with:   ./binary_name

   ============================= THEORY =============================
   In C, you’ll use control flow (if/else) to make decisions, and loops
   (for/while) to repeat work. Functions let you split tasks into named
   pieces and pass inputs by value (C’s default), meaning callees get copies
   of the arguments. Arrays store multiple values of the same type in
   contiguous memory; you typically pass the array along with its length
   so functions know how much to process.

   Structs group related fields into a single type, and typedef lets you
   give types readable names. This practical checks that you can: branch with
   if/else, iterate with for & while, pass arguments to functions (by value),
   manipulate arrays, and define/use typedef’d structs in simple, realistic
   tasks.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLEAR printf("\033[0;0H\033[2J")

/* ======= Prototypes for the 5 exercises ======= */
int  exam01(void);
int  exam02(void);
int  exam03(void);
int  exam04(void);
int  exam05(void);

/* ============================== MAIN ==================================== */
int main(void)
{
    CLEAR;
    char name[32] = "Ramiro";
    printf("Intro C Prereqs Practical Exam\n\tStudent: %s\n\n", name);

    printf("---- EX01 -------------------------------------\n");
    exam01();
    printf("---- EX02 -------------------------------------\n");
    exam02();
    printf("---- EX03 -------------------------------------\n");
    exam03();
    printf("---- EX04 -------------------------------------\n");
    exam04();
    printf("---- EX05 -------------------------------------\n");
    exam05();
    printf("\nAll exercises invoked. Good luck!\n");
    return 0;
}

/* ########################   EX01: If/Else   ###############################
   Classify an integer temperature (Celsius) as:
     "COLD" if t < 10
     "WARM" if 10 <= t <= 25
     "HOT"  if t > 25

     It should print something like:
     temperature is 18 it feels WARM

*/
int exam01(void)
{
    int temperature = 18; /* you can change this to test */

    printf("temperature = %d it feels ", temperature);
    if (temperature < 10) {
        printf("COLD\n");
    } else if (temperature <= 25) {
        printf("WARM\n");
    } else {
        printf("HOT\n");
    }
    return 0;
}

/* ####################   EX02: While loop (digits)   #######################
   Using a while loop, count how many decimal digits are in x.
*/
int exam02(void)
{
    int x = 9302;
    int digits = 0;

    if (x == 0) {
        digits = 1;
    } else {
        int t = x;
        while (t > 0) {
            digits++;
            t /= 10;
        }
    }

    printf("Digits in %u = %d\n", x, digits);
    return 0;
}

/* ####################   EX03: Arrays (avg & max)   ########################
   Given an integer array scores[], compute average and max.
*/
int exam03(void)
{
    int scores[] = {72, 85, 90, 66, 95, 88};
    int n = (int)(sizeof(scores)/sizeof(scores[0]));

    int sum = 0;
    int maxv = scores[0];
    for (int i = 0; i < n; ++i) {
        sum += scores[i];

        printf("checking if scores[%d] is greater than %d\n",
                scores[i], maxv );
                //getchar();
    
        if (scores[i] > maxv) 
        {
          maxv = scores[i];
          printf("Updating MAX VAL : %d\n", maxv);
        }
    }
    double avg = (double)sum / (double)n;

    printf("Average = %.2f, Max = %d\n", avg, maxv);
    return 0;
}

/* #############   EX04: typedef + struct (grocery line total)   ##########

   Create a typedef’d struct called GroceryItem with fields:
     - name[16]   (char array)
     - price      (float)
     - qty        (int)

   Implement a function called line_total, that receives a GroceryItem
   and returns the total price = price * qty (float).
   In exam05(), create one item and test your function.

   ATTENTION: You need to create the struct, typedef and declare a new
   function, then test it inside EX04
*/
typedef struct {
    char  name[16];
    float price;
    int   qty;
} GroceryItem;

float line_total(GroceryItem it)
{
    float precio_tot = it.price * (float)it.qty;
    return precio_tot;
}

int exam04(void)
{
    GroceryItem milk = { "Milk", 2.50f, 2 };
    float total = line_total(milk);

    printf("%s x%d -> $%.2f\n", milk.name, milk.qty, total);
    return 0;
}

/* #############   EX05: NEW FUNCTION #2 (arrays + search)   ############### */
/*   

   Implement a funciton called find_first() that:

        receives an integer array
        the size of the array
        a number to search, inside the array

        Returns the INDEX of the first occurrence, or -1 if not present.
    
    Brute force OK, but do you remember Binary search and Algorithm 
    complexity?
*/
int find_first(const int arr[], int n, int target)
{
    for (int i = 0; i < n; ++i) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int exam05(void)
{
    int data[] = {4, 9, 1, 9, 2, 9};
    int n = (int)(sizeof(data)/sizeof(data[0]));
    int target = 9;
    int idx = find_first(data, n, target);
    printf("First %d at index %d\n", target, idx);
    return 0;
}