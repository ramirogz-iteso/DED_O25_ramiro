#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Luis Fernando Fernandez Garcia

/* EXAMEN PARCIAL 2: Programacion Estructurada 

  INSTRUCCIONES
  Lee primero TODO el archivo, de inicio a fin.
  Completa o realiza los ejercicios necesarios
  La funcion MAIN tiene el driver para correr todos los ejercicios
  y todos valen lo mismo (15 pts c/u) examen sobre 105.

  Recuerda que las respuestas van en los bloques:
  // INICIO DE RESPUESTA
     <<< Aqui va tu respuesta >>>
  // FIN DE RESPUESTA

  Es posible que te falten algunos prototipos de funciones.
  Recuerda que todo el archivo debe de compilar, descomenta los ejercicios
  que vayas terminando del metodo main.

*/
void gato();
void print_gato(int gato[3][3]);
void calculadora();
void el_for();
void calificacion();
void canicas();
void unir(char s1[], char s2[], char destino[]);
void copia(char destino[], char origen[]);

int ret;

int main()
{
  printf("==== Ejercicio 01, Gato ===== \n");
  //gato();
  printf("==== Ejercicio 02, Calculadora ===== \n");
  //calculadora();

  printf("==== Ejercicio 03, strcpy_manual ===== \n");
  /* =====    E J E R C I C I O   :   3  ======*/
  /* Implementa tu propia funcion strcpy y copia el string 
     "str_a_copiar" a un string nuevo "str_copiado"
     Declara el String receptor, manda a llamar tu funcion y pruebalo aqui
     en el main 
     
  */
  char str_a_copiar[] = "Aprendi a usar la libreria String";
  char str_copia[50];
  //INICIO RESPUESTA
  //copia(str_copia, str_a_copiar);
  //FIN DE RESPUESTA

  printf("==== Ejercicio 04, el for ===== \n");
  //el_for();

  printf("==== Ejercicio 05, Calificaciones ===== \n");
  //calificacion();

  printf("==== Ejercicio 06, Canicas ===== \n");
  //canicas();


  printf("==== Ejercicio 07, Lib string ===== \n");
  /* =====    E J E R C I C I O   :   7 ======*/
  /*
  AHORA SI, APOYANDOTE DE LA LIBRERIA DE STRINGS: 
  Crea una funcion "concat" que reciba 2 cadenas, las concatene y el resultado
  lo copie a una nueva cadena destino.

  Se usaria asi:
  concat("La vida es ", cadena2, destino);

  printf("%s", destino);
  Salida: "La vida es un carnaval"
  (obviamente cadena2 contiene "un carnaval")

  Utiliza strlen para crear el string de destino del tamanio justo y no
  desperdiciar memoria. 

  */
  char s2[] = "Se lo lleva la corriente";
  char s1[] = "Camaron que se duerme";

  //INICIO RESPUESTA
  char destin[strlen(s2)+strlen(s1)];
  //prueba tu funcion aqui:
  unir(s1,s2, destin);

  //FIN DE RESPUESTA

}


/* =====    E J E R C I C I O   :   1  ======*/
/* Completa el siguiente programa:

CODIGO EXISTENTE: 
Gato para 1 jugador: 
En un ciclo whie, se captura por entrada del usuario las coordenas 
de donde marcar X,Y  

El juego marca con un con "1" (uno, entero) la posicion.
  ie: 
          1   0   0
          0   1   0
          0   0   0

  La funcion gato, tiene un ciclo infinito que captura la entrada y 
  redibuja el resultado

  TU TAREA ES: 
  Deten el ciclo el infinito e imprime 
   "JUEGO TERMINADO" cuando se logre una linea de gato completa 
   (horizontal o vertical, no te preocupes por diagonales)

  La funcion print_gato, redibuja el juego, no debes modificarla.
*/
void gato()
{
  int gato[3][3]={{0,0}, {0,0}, {0,0}};
  int x,y;
  print_gato(gato);

  while(1)
  {

    printf("Coordenadas X,Y: ");
    ret = scanf("%d,%d", &x,&y);
    getchar();
    gato[x][y] = 1;
    print_gato(gato);
    int win=0;

    // INICIO DE RESPUESTA
    for(int i=0;i<3;i++)
    {
      if(gato[i][0]==1 && gato[i][1]==1 && gato[i][2]==1)
      {
        printf("Juego terminado\n");
        return;
      }
    }

    for(int i=0;i<3;i++)
    {
      if(gato[0][i]==1 && gato[1][i]==1 && gato[2][i]==1)
      {
        printf("Juego terminado\n");
        return;
      }
    }
    // FIN DE RESPUESTA
  }
  printf("JUEGO TERMINADO\n");
}

// NO TOCAR print_gato =)
void print_gato(int gato[3][3])
{
  printf("\n");
  printf("      %d   |    %d    |    %d\n",
    gato[0][0], gato[0][1], gato[0][2]);
  printf("   ___________________________\n");
  printf("      %d   |    %d    |    %d\n",
    gato[1][0], gato[1][1], gato[1][2]);
  printf("   __________________________\n");
  printf("      %d   |    %d    |    %d\n\n",
    gato[2][0], gato[2][1], gato[2][2]);
}

/* =====    E J E R C I C I O   :   2  ======*/
/* Completa el codigo de la calculadora */
void calculadora()
{
  char operacion;
  float num1, num2, resultado = 0.0;

  printf("CALCULADORA\n");
  printf("Ingresa [num1] [+ - * /] [num2]\n");

  // Lee de usuario: numero1 operador numero2
  // OJO con los espacios, por ejemplo:
  //    8 * 5.5
  //   10.5 / 3.5
  //   11 + 1
  ret = scanf("%f %c %f", &num1, &operacion, &num2);

  /* Utilizando un switch case, completa la calculadora
  para resolver sumas, restas, multiplicacion y division.
  Agrega un default para cualquier otra operacion invalida */

  // INICIO DE RESPUESTA
  switch(operacion)
  {
    case '+':
      resultado = num1 + num2;
      break;
    case '-':
      resultado = num1 - num2;
      break;
    case '*':
      resultado = num1 * num2;
      break;
    case '/':
      if (num2!=0)
      {
        resultado = num1 / num2;
      }
      else
      {
        printf("No se puede dividir entre el numero 0\n");
      }
      
      break;
  }



  // FIN DE RESPUESTA

  //Impresion de resultado
  printf("%.2f %c %.2f = %.2f\n", 
    num1, operacion, num2, resultado);
}

/* =====    E J E R C I C I O   :   3  ======*/
// INICIO RESPUESTA
void copia(char destino[], char origen[])
{
  int i=0;
  while(origen[i]!='\0')
  {
    destino[i]=origen[i];
    i++;
  }
  for(int j=0;j<i;j++)
  {
    printf("%c", destino[j]);
  }
}

// FIN DE RESPUESTA


/* =====    E J E R C I C I O   :   4  ======*/
void el_for()
{
  /* utiliza ciclos fors para crear un programa que se
  vea como el siguiente ejemplo:
  Introduce un numero positivo: 5
  1
  1 2
  1 2 3
  1 2 3 4
  1 2 3 4 5
  */

  // INICIO DE RESPESTA 
  int n;
  printf("Introduce un numero positivo: ");
  ret = scanf("%d", &n);
  for (int i=1;i<=n;i++)
  {
    for (int j=1;j<=i;j++)
    {
      printf("%d ", j);
    }
    printf("\n");
  }

  // FIN DE RESPUESTA
}


/* =====    E J E R C I C I O   :   5  ======*/
//INICIA RESPUESTA
int sacarcalif(int cal[], int num)
{
  return cal[num-1];
}


//TERMINA RESPUESTA

void calificacion()
{
  /* La calificación de un grupo de alumnos esta guardada en 
   un arreglo de 10 elementos donde cada posicion representa un
   alumno y estan en orden de lista.
   Crea una función que reciba   :
      -el arreglo de calificaciones
      -el numero de lista del alumno a retornar [1-10] (no existe alumno 0)
   devuelva : 
      -la calificacion del alumno.

    Para probar, crear el arreglo de 10 calificaciones (enteras,)
    Dale valores iniciales al arreglo y utilizalo en tu funcion con el
    alumno que tu quieras.
  */
  int cal_grupo[10];
  cal_grupo[0]=8;
  int numero_de_lista = 1;
  int cal_alumno;

  
  // INICIO DE RESPUESTA 
  //descomenta la linea de abajo y termina

  cal_alumno = sacarcalif(cal_grupo, numero_de_lista);
  // FIN DE RESPUESTA
  
  printf("La calificacion del alumno %d es: %d\n",
         numero_de_lista, cal_alumno);
}


/* =====    E J E R C I C I O   :   6  ======*/
void canicas()
{
  /* Vas a capturar 2 numeros por el usuario: 
    # de canicas totales
    # canicas que se usan y se rompen en cada juego

  Utilizando el ciclo while completa la impresion para que se vea
  como el siguiente ejemplo:

  Hay un total de 50 canicas
  Se rompen 8 canicas por juego

    Juego #1 : Quedan 42
    Juego #2 : Quedan 34
    Juego #3 : Quedan 26
    Juego #4 : Qeudan 18 
    Juego #5 : Quedan 10
    Juego #6 : Quedan 2
    Ya no se puede jugar :(, no hay canicas sufcientes.
  */

  int canicas;
  int rotas_p_juego;

  printf("Introduce [canicas y  rotas_p_juego]  ej:   50 8 : ");
  ret = scanf("%d %d", &canicas, &rotas_p_juego);

  printf("Hay un total de %d canicas\n", canicas);
  printf("Se rompen %d canicas por juego\n", rotas_p_juego);

  // INICIO DE RESPUESTA
  /* hasta aaqui llege, lo comente para opder continuar
  int juego=1;
  while(canicas>=rotas_p_juego)
  {
    canicas=canicas-rotas_p_juego;
    printf( "Juego #%d : Quedan %d\n", juego, canicas);
    juego++;
  }
  if (canicas<rotas_p_juego)
  {
  */
   
  // FIN DE RESPUESTA  
}

/* =====    E J E R C I C I O   :   7 ======*/

// INICIO DE RESPUESTA
void unir(char s1[], char s2[],char destino[])
{
  int len1=strlen(s1);
  int len2=strlen(s2);

  strcat(s1,s2);
  strcpy(destino,s1);
  puts(destino);
}

// FIN DE RESPUESTA  