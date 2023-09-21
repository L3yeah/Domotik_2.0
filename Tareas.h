#ifndef Tareas_h
#define Tareas_h
/*****************************************************************************************
*      DESCRIPCIÓN DE LA LIBRERÍA: El objetivo de esta librería es generar tiempos de    *
*       espera de ejecución sin la implementación de la función "delay()".               *
******************************************************************************************/

#define TIEMPO1 1000                 // Constante para indicar 1 segundo (1000 ms).
#define TIEMPO_RTC 1000
#define TIEMPO_LCD 2000
#define TIEMPO2 2000                 // Constante para indicar 2 segundos (2000 ms).
#define TIEMPO3 3000                 // Constante para indicar 3 segundos (3000 ms).
class millis_tasks {

  public:
    uint64_t tiempo_anterior1 = 0,   // Contador de tiempo que tendrá múltiplos de TIEMPO1.
             tiempo_anterior2 = 0,   // Contador de tiempo que tendrá múltiplos de TIEMPO2.
             tiempo_anterior3 = 0,   // Contador de tiempo que tendrá múltiplos de TIEMPO3.
             tiempo_anterior_rtc = 0,
             tiempo_anterior_lcd = 0,
             tiempo_actual = 0;      // Contador de tiempo que tendrá múltiplos de TIEMPO.
    
  public:

    void tarea1 ( void );            // Función que ejecuta una acción cada segundo.
    void tarea_rtc ( void );
    void tarea2 ( void );            // Función que ejecuta una acción cada dos segundos.
    void tarea3 ( void );            // Función que ejecuta una acción cada tres segundos.
    void actualizar_tareas (void );  // Función que actualiza el conteo obtenido de la función "millis()".
    void tarea_lcd ( void );
};

/*
   Al arranque del sistema la variable "tiempo_anterior1" tendrá el valor de 0, 
   cuando "tiempo_actual" sea igual a "TIEMPO1" es decir cuando hayan pasado
   1000 ms, "tiempo_anterior" tomará el valor de "tiempo_actual", para que la
   diferencia entre ellos siempre se cumpla cuando pase el tiempo asignado en "TIEMPO1".
*/


/*~~~~~~~~~~~~~~~~~~~~~~~~ tarea1 - Función que se ejecuta cada TIEMPO1( 1 SEGUNDO) ~~~~~~~~~~~~~~~~~~~~~~~~ */
void millis_tasks :: tarea1 ( void ) {

  /*
      _____________________________________________
      | tiempo_actual | tiempo_anterior1 | TIEMPO1 |
      ----------------------------------------------
      |       0       |       0          |  1000   |
      ----------------------------------------------
      |       1       |       0          |  1000   |
      ----------------------------------------------
      |       2       |       0          |  1000   |
      ----------------------------------------------
      ----------------------------------------------
      |       3       |       0          |  1000   |
      ----------------------------------------------
      ----------------------------------------------
      | . . 1000      |       0          |  1000   |   Se cumple la condicional 1000 - 0 = 1000.
      ----------------------------------------------
      ----------------------------------------------
      |    10001      |       1000       |  1000   |
      ----------------------------------------------

  */

  if ( ( tiempo_actual - tiempo_anterior1 ) >= TIEMPO1 ){
    
    Serial.println ( "1.- Ejecutando tarea 1" );
    tiempo_anterior1 = tiempo_actual;

  }

}
/* Función que permite obtener y mostrar la fecha */
void millis_tasks :: tarea_rtc ( void ) {

  if ( ( tiempo_actual - tiempo_anterior_rtc ) >= TIEMPO_RTC ){
     
     RTC.get_time ();
     RTC.show_time ( );
     Serial.println ( "Reloj ejecutado" );
     tiempo_anterior_rtc = tiempo_actual;

  }
 
}

/* Función que permite obtener y mostrar la fecha */
void millis_tasks :: tarea_lcd ( void ) {

  if ( ( tiempo_actual - tiempo_anterior_lcd ) >= TIEMPO_LCD ){
     
    ACT.printfila_0();
    ACT.printfila_1();
     tiempo_anterior_lcd = tiempo_actual;

  }
 
}

/*~~~~~~~~~~~~~~~~~~~~~~~~ tarea2 - Función que se ejecuta cada TIEMPO2 ( 2 SEGUNDOS ) ~~~~~~~~~~~~~~~~~~~~~~~~ */
void millis_tasks :: tarea2 ( void ) {
  if ( ( tiempo_actual - tiempo_anterior2 ) >= TIEMPO2 ){

     Serial.println ( "2.- Ejecutando tarea 2" );
     tiempo_anterior2 = tiempo_actual;

  }
 
}

/*~~~~~~~~~~~~~~~~~~~~~~~~ tarea3 - Función que se ejecuta cada TIEMPO3 ( 3 SEGUNDOS ) ~~~~~~~~~~~~~~~~~~~~~~~~ */
void millis_tasks :: tarea3 ( void ) {

  if ( ( tiempo_actual - tiempo_anterior3 ) >= TIEMPO3 ){

     Serial.println ( "3.- Ejecutando tarea 3" );
     tiempo_anterior3 = tiempo_actual;

  }
  
}

/*~~~~~~~~~~~~~~~~~~~~~~~~ actualizar_tareas - Función que actualiza el contador de "millis()" ~~~~~~~~~~~~~~~~~~~~~~~~ */
void millis_tasks :: actualizar_tareas ( void ) {

  tiempo_actual = millis( );

}

#endif