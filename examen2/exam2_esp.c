#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* INSTRUCCIÓN GENERAL:
   Siempre programa dentro de las secciones: */

   /* ----------  RESPUESTA ESPERADA:  --------------- */
        // tu código del examen
        // va en esta sección 
   /* ----------  RESPUESTA ESPERADA:  --------------- */

/* Coloca tu nombre aqui: _

   Crea una carpeta llamada: examen2
   Renombra este archivo: exam2_esp.c a nombrecorto_examen2.c
   ejemplo:  ramiro_exam2.c

   los 3 archivos : ramiro_exam2.c fugitive_dump.bin y matrix.txt viven
   dentro de la carpeta. SUERTE!
   
*/

/*  = = = = = = = Ejercicio 01: = = = = = =
    = = = = = = = = = = = = = = = = = = = =   
    Lee lo siguiente del archivo de texto "matrix.txt":
    Matrix is NxM        <===  número N = filas M = columnas
    a b c ...
    d e f ...
    g h i ...

    donde [a ... i] son números enteros.
    NOTA: hay un espacio entre N y M

    Ejemplo: 
    Matrix is 2x2    o    Matrix is 4x4 
    5 4                    1 2 3 4
    3 2                    5 6 7 8
                           9 1 2 3
                           4 5 6 7 

    Construye un arreglo dinámico 2D para guardar la información leída del archivo.
  
    Finalmente, escribe (con tu programa) tu nombre completo en una nueva línea
    debajo de la matriz en el mismo archivo.

    El archivo debe verse así:
    Matrix is 2x2
    5 4
    3 2
    Ramiro Garcia Zepeda

    TIP: si entre ejecuciones destruyes el archivo, te recomiendo reescribirlo
    a mano para que siempre tenga el formato de entrada correcto.

    VALOR 20 pts:
    a) (10 pts) Lectura y escritura de archivo
    b) (10 pts) Creación y liberación de memoria dinámica.
       NOTA: Si no puedes leer el archivo, pide los datos por consola,
       pero solo valdrá 10 pts.
*/
int e01()
{
  int col, row;
  int ** matrix;
  /* ----------  RESPUESTA ESPERADA:  --------------- */
  // 1) Lee archivo

  // 2) construye matrix


  // 3) escribe tu nombre al final del archivo
  

  /* ----------  RESPUESTA ESPERADA:  --------------- */

  /* verificar resultados  --  (No toques los for) --  */
  for (int j=0; j<col; j++)
  {
    for (int k=0; k<row; k++)
    {
      printf("m[%d][%d] = %d ", j,k, matrix[j][k]);
    }
    printf("\n");
  }
  /* verificar resultados  --  (No tocar) --  */
  /* ¿algo más por hacer? recuerda la regla de Malloc */ 
  /* ----------  RESPUESTA ESPERADA:  --------------- */
 
  /* ----------  RESPUESTA ESPERADA:  --------------- */
  return 0;
}

/*  = = = = = = = Ejercicio 02: = = = = = =
    = = = = = = = = = = = = = = = = = = = =  
  Crea una función llamada joinList que una 2 listas ligadas.
  La función recibe la lista A y la lista B.
    
  La única regla es que la lista con el primer elemento más pequeño
  irá primero. Las listas nunca deben separarse.

  ej. 
         Lista A      4-5-9-10
         Lista B      2-11-8

    new_header = joinList(A,B);
    printtList(new_header);
    2-11-8-4-5-9-10     

  Usa la función dada printList y verifica el resultado.
  Usa las listas de ejemplo L1 y L2 creadas.

  VALOR 20 pts
*/
struct node
{
  char value;
  struct node * next;
}typedef node;

void printlist(node * n)  // NO TOCAR
{
  while(n)
  {
    printf("%d ", n->value);
    n=n->next;
  }
  printf("\n");
}                        // NO TOCAR

/* ----------  RESPUESTA ESPERADA:  --------------- */


/* ----------  RESPUESTA ESPERADA:  --------------- */

/* NO TOCAR, inicialización de las listas de demostración L1 y L2 */
node *L1, *L2;
node L1n1, L1n2, L1n3, L1n4;
node L2n1, L2n2, L2n3;
/* NO TOCAR */

int e02()
{
  /* NO TOCAR, inicialización de las listas de demostración L1 y L2 */
  L1n1.value=1; L1n2.value=5; L1n3.value=9; L1n4.value=10;
  L1n1.next=&L1n2; L1n2.next = &L1n3; L1n3.next = &L1n4; L1n4.next = NULL;
  L2n1.value=3; L2n2.value=11; L2n3.value=8;
  L2n1.next=&L2n2; L2n2.next = &L2n3; L2n3.next = NULL;
  L1 = &L1n1; L2 = &L2n1;

  node * result;
  /* NO TOCAR */
 
  printlist(L1);
  printlist(L2);
  // DESCOMENTA ESTA LÍNEA CUANDO TENGAS TU FUNCIÓN
  //result = joinlist(L1, L2);
  printlist(result);
   /* NO TOCAR */
  return 0;
}

/*  = = = = = = = Ejercicio 03: = = = = = =
    = = = = = = = = = = = = = = = = = = = =  
  Junto con tu examen encontrarás el archivo fugitive_dump.bin. Este archivo 
  contiene un volcado de memoria de una antigua base de datos de fugitivos del FBI. 
  Gracias al análisis de inteligencia, se obtuvo parte de la 
  estructura usada para almacenar los datos:

  struct fugitive {
    char name[20];
    TIPO DE DATO DESCONOCIDO 10 bytes
    TIPO DE DATO DESCONOCIDO 4 bytes
    short age;
    POSIBLE ID, almacenado en una variable INT
  }
  Sabemos que cada archivo fugitive_dump contiene información de UN SOLO
  fugitivo. 
  
  Toda la estructura es desconocida, pero se cree que puede haber 
  información valiosa para ayudar a localizar a los fugitivos. 
  Se requerirá un equipo de ingeniería inversa para analizar los 14 bytes desconocidos.
  Esto es costoso y tomará tiempo.

  Tu tarea, si decides aceptarla, es ayudar al FBI creando una función para 
  extraer rápidamente la edad del fugitivo de este archivo binario. 
  Con tu programa, el espacio de búsqueda y análisis se reducirá 
  solo a aquellos archivos binarios que coincidan con la edad.

  VALOR 15 pts
*/
void e03()
{
  /* ----------  RESPUESTA ESPERADA:  --------------- */
 
  // EJECUTÉ EL PROGRAMA, Y 
  // LA EDAD DEL FUGITIVO EN ESTE DUMP ES _____ <= ¡escríbela aquí!
  /* ----------  RESPUESTA ESPERADA:  --------------- */
}

/*  = = = = = = = Ejercicio 04: = = = = = =
    = = = = = = = = = = = = = = = = = = = =  
  Pepito acaba de crear una lista ligada simple circular perfecta.
  Su lista está perfectamente hecha. No la toques.
  
  Pepito pensó que copiando el contenido de printlist
  del ejercicio 02 podría imprimir su lista,
  ¡pero parece tener un gran problema y nunca termina!
  Se queda atorada en un ciclo while infinito.
  
  Ayuda a Pepito a corregir su función.

  VALOR 15 pts
*/
void print_circular_list(node * n)
{
  while(n)
  {
    printf("%d ", n->value);
    n=n->next;
  }
  printf("\n");
}

int e04()
{
  /* NO TOCAR, inicialización de la lista circular de demostración L3 */
  node *L3;
  node L3n1, L3n2, L3n3;
  L3n1.value=1; L3n2.value=2; L3n3.value=3;
  L3n1.next=&L3n2; L3n2.next = &L3n3; L3n3.next = &L3n1;
  L3 = &L3n2;
  /* NO TOCAR, inicialización de la lista circular de demostración L3 */

  print_circular_list(L3);
  return 0;
}

/*  = = = = = = = Ejercicio 05: = = = = = =
    = = = = = = = = = = = = = = = = = = = =  
    Crea (con memoria dinámica) un arreglo de raíces para almacenar 
    10 listas ligadas.
    Por ahora, guarda las listas L1 y L2 en las primeras 2 posiciones
    del arreglo. Pruébalas con tu función printList.

    VALOR 20 pts
*/
int e05()
{
  /* ----------  RESPUESTA ESPERADA:  --------------- */

  /* ----------  RESPUESTA ESPERADA:  --------------- */
  return 0;
}

/*  = = = = = = = Ejercicio 06: = = = = = =
    = = = = = = = = = = = = = = = = = = = =  
    Usa la PILA (STACK) que vimos en clase
    para programar una función llamada reverse que invierta el contenido de un string.

    ej.
    char test[10] = {"ITESO"};

    printf("%s\n", test); //Debe imprimir "ITESO"
    reverse(test, strlen(test));
    printf("%s\n", test); //Debe imprimir "OSETI"

    VALOR 20 pts
  */

// NO TOCAR, NO SE REQUIEREN MODIFICACIONES AQUÍ
typedef struct stack_node {
    char info;
    struct stack_node *prev;
}stack_node;

// NO TOCAR, NO SE REQUIEREN MODIFICACIONES AQUÍ
/* PILA GLOBAL */
stack_node *stack_top = NULL;
int count = 0;

// NO TOCAR, NO SE REQUIEREN MODIFICACIONES AQUÍ
// Operación push() para agregar elementos a la pila 
void push(char data) 
{
  /* insertar siempre es posible, crea el nodo */
  stack_node *new_node  = (stack_node *)malloc(sizeof(stack_node));
  new_node->info = data;

  /* si es el primer nodo de la pila */
  if (stack_top == NULL)
  {
    stack_top = new_node;
    stack_top->prev = NULL;
  }
  else
  {
    new_node->prev = stack_top;
    stack_top = new_node;
  }
  count++;
}

// NO TOCAR, NO SE REQUIEREN MODIFICACIONES AQUÍ
// Para esta versión de la pila de enteros, regresa '0' si no hay nada que sacar (pop)
char pop() 
{
  stack_node *nptr = stack_top;

  if (nptr == NULL)
  {
      printf("\nStack Underflow\n");
      return '0';
  }
  else
  {
    nptr = nptr->prev;
  }

  int popped = stack_top->info;
  free(stack_top);
  stack_top = nptr;
  count--;
  return popped;
}

/* ----------  RESPUESTA ESPERADA:  --------------- */

/* ----------  RESPUESTA ESPERADA:  --------------- */

void e06()
{
  char test[10] = "ITESO";
  /* ----------  RESPUESTA ESPERADA:  --------------- */
  //Llama aquí a tu función y imprime para verificar que se invirtió:
  //reverse(test, strlen(test));
  
  /* ----------  RESPUESTA ESPERADA:  --------------- */
  printf("%s\n", test);
}

int main()
{
  printf("Midterm Exam 2 by : %s\n", "YOURNAMEHERE");
  printf("=== E01: Matrix \n");
  //e01();
  getchar();
  printf("=== E02: Join lists \n");
  //e02();
  printf("=== E03: Secret age \n");
  //e03();
  printf("=== E04: Stop the infinite loop (circular list) \n");
  //e04();
  printf("=== E05: Multiple lists (array of lists) \n");
  //e05();
  printf("=== E06: Stack \n");
  //e06();
  return 0;
}
