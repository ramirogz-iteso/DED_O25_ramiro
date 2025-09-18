#include <stdio.h>
/*
  Alumno (nombre corto): 
  Instrucciones:
  Lee cuidadosamente todo el archivo, resuelve donde se te pida.
*/

/* ============================================================ 
  EJERCICIO 1)  (20 pts)
Realiza en tu cuaderno los siguientes ejercicios, no te brinques pasos del 
procedimiento o la respuesta no tendra valor alguno.
Considere el tamaño de los tipos de datos de las variables para la 
longitud de las cadenas resultantes.

  Exprese el resultado de la variable 'z' despues de las operaciones tanto 
  en binario, decimal y en hexadecimal

  1a) unsigned short z = 'Z' + 'A' * 2;

  1b) short z = -129
      
  1c) unsigned short   c = 8 ;
      unsigned char    d = 2 ;
      unsigned int     res = z | d;  //<- expresa solo z
      

  1d) unsigned char   z = 0xA1 << 2;
        
Al terminar los ejercicios, tomale una foto a la hoja con tu celular y enviala a
ramirogz@iteso.mx (PD. NO OLVIDES PONER TU NOMBRE A LA HOJA!) */

/* ============================================================
  EJERCICIO 2)   (5 pts): 
Define el prototipo de funcion para:
Una funcion que recibe la letra inicial del Mes y el numero de mes [1-12]
e imprime el Mes con letra. */

// INICIO DE RESPUESTA
                         
// FIN DE RESPEUSTA 

/* ============================================================ 
  EJERCICIO 3) (15 pts)

   Crea una funcion ejercicio03 que reciba 1 numero:
   Determina si ese numero es numero divisible entre 3, pero
   que no sea 9 porque es de mala suerte.
   Si si cumple con la condicion, regresa 1, sino regresa 0. 
   Prueba tu funcion desde el MAIN.
*/
// INICIO DE RESPUESTA

// FIN DE RESPUESTA

/* ============================================================ 
  EJERCICIO 4) (20 pts)
  Define y codifica la funcion ejercicio04 para que reciba 3 numeros enteros
  e imprima cual de los 3 numeros es el mas chico */
// INICIO DE RESPUESTA


// FIN DE RESPUESTA

/* ============================================================ 
  EJERCICIO 5) (20 pts)
  Completa la funcion para que capture de pantalla
  lo siguiente:

      bruto = 105.10 impuesto = 10 pct

  Lee el valor numerico tanto del sueldo, como del impuesto.
  Calcula el sueldo neto, restando el impuesto y muestralo en pantalla:

      Sueldo neto = $94.5900

  Nota: 
    siempre se muestran 4 decimales.
*/
void ejercicio05()
{
  // INICIO DE RESPUESTA:

  // FIN DE RESPUESTA
}
 
/* ============================================================ 
  EJERCICIO 6) (10 pts)
Corre la siguiente funcion y veras que tiene algun BUG (defecto), tu tarea es 
encontrarlo y repararlo. Sig*/

void ejercicio06()
{

  int dinero = 510;
  int precio_chicle = 110;
  int cliente_feliz = 0;

  if(dinero > precio_chicle)
  {
    printf("Chicle Comprado\n");
    cliente_feliz = 1;
  }

  if((cliente_feliz == 1))
  {
    printf("Que buen chicle, puedo morir en paz\n");
  }
  else
    printf("Morire sin un chicle, no me alcanza\n");
}

/* ============================================================ 
  EJERCICIO 7 (10 pts)
  Crea una mascara para evaluar si el 1ro y el 6to bit de un char.
  Si tu mascara es correcta, veras "sucess en la impresion"
*/
void ejercicio07()
{
  int mascara;
  int valor_a_probar = 169;

  // INICIO DE RESPUESTA

  // FIN DE RESPUESTA
  
  int res = valor_a_probar & mascara;
  (res == mascara) ? (printf("success\n")) : (printf("fail\n"));
  printf("mascara %x\n", mascara);
}

/* ============================================================ 
  EJERCICIO 8 (10 pts)
  */
void ejercicio08()
{
  int estudie = 0;
  int hice_tarea = 0;
  int tengo_suerte = 1;

  int me_fue_bien = 0;
  int calificacion = 0;

  /* Convierte TODOS los operadores ternarios de esta funcion en 
     ifs y elses simples */
  (estudie && hice_tarea) ? (me_fue_bien = 1) 
    : ((tengo_suerte) ? (me_fue_bien = 1) : (me_fue_bien = 0));

  printf("Original:\tMe fue %s!\n", me_fue_bien ? "BIEN" : "MAL");
  
  // INICIO DE RESPUESTA parte 1
  
  // FIN DE RESPUESTA parte 1
  printf("New:\t\tMe fue %s!\n\n", me_fue_bien ? "BIEN" : "MAL");

  /* ahora lo inverso, convierte el siguiente bloque if/else
    en un operador ternario con un twist, esta prohibido usar el operador '==' */

  if(hice_tarea == 0)
  {
    calificacion = 60;
  }
  else
  {
    calificacion = 100;
  }
 printf("saque %d\n", calificacion);

  // INICIO DE RESPUESTA parte 2
  
  // FIN DE RESPUESTA parte 2  
 printf("saque %d\n\n", calificacion);                                
}

int main()
{
  printf("\e[1;1H\e[2J");  
  printf("\t\t ============  Ejercicio 1: ========================== \n");
  printf("  Representacion binaria, enviar foto a ramirogz@iteso.mx\n");
  
  printf("\t\t ============  Ejercicio 2: ========================== \n");
  printf("  Solo pon el Protipo de funcion requerido \n");
  
  printf("\t\t ============  Ejercicio 3: ========================== \n");
  // Prueba tu funcion recien creada aqui, que se vea que funciona:
  
  
  printf("\t\t ============  Ejercicio 4: ========================== \n");
  //ejercicio04(100, 550 ,59);   //prueba con otros numeros, verifica! ;) 
  
  printf("\t\t ============  Ejercicio 5: ========================== \n");
  ejercicio05();
  
  printf("\t\t ============  Ejercicio 6: ========================== \n");
  ejercicio06();
  
  printf("\t\t ============  Ejercicio 7: ========================== \n");
  ejercicio07();
  
  printf("\t\t ============  Ejercicio 8: ========================== \n");
  ejercicio08();
  
}