#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    char name[100];
    int age;
    int id;
    float weight;
  } student;

typedef int dinero;
//TYPEDEF {knownTYPE} [NEW_INVENTED_TYPE]

void dump_student(student * s)
{
  printf("El student: %s, tiene %d anios\n",
          s->name, s->age);

  s->age = 100;

  printf("La nueva edad es %d\n", s->age);

}

//PROTOTYPE FUNCTION
int sum(int, int);
char convertLowerToUpper(char);

//{ RETURN_TYPE [FUNC_NAME] ([ARGUMENTOS...])}
//Lista de tipos
int main()
{

  int num1 = 100;
  int num2 = 200;
  int result;

  char minuscula = 'f';
  char mayuscula = convertLowerToUpper(minuscula);
  printf("%c\n", mayuscula);

  result = sum(num1, num2);
  printf("result = %d\n", result);

  getchar();

  // Datos primarios
  int x;
  //
  int arrname[200];
  //{TYPE} NAME_ARRAY [NUM_ELEMENTS];

  char y;
  float z;
  long a;

  // Datos compuesto
  int numeros[10];  //arreglo de 10 enteros
  char myname[200]; //arreglo de 200 char 

  //struct:
  // Agrupacion de multiples tipos de datos

  student s1;

  s1.age = 25;
  s1.id = 2025;
  s1.weight = 70.5;
  strcpy(s1.name, "Ramiro");

  // arreglo de students
  //{TYPE} NAME_ARRAY [NUM_ELEMENTS];
  student iteso[25000]; 
 
  student * pointer_to_s = &s1;

  dump_student(pointer_to_s);
  printf("El student: %s, tiene %d anios\n",
          s1.name, s1.age);


  return 0;
}

int sum(int n1, int n2)
{
  int result = n1 + n2;
  //printf("result = %d\n", result);
  return result;
  //n1 + n2;
}

char convertLowerToUpper(char lower)
{
  return lower - 32;
}