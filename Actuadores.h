#ifndef Actuadores_h
#define Actuadores_h

#include <Wire.h>               /*~ Librería I2C ~*/
#include <LiquidCrystal_I2C.h>  /*~ Librería LCD ~*/

LiquidCrystal_I2C lcd ( 0x27, 16, 2 );  /*~ Instancia de la clase para el manejo de la pantalla ( Dirección I2C, columnas, filas ) ~*/

class actuadores{

  public:
    void lcd_init ( void );
    void lcd_clean ( void );
    void printfila_0 (void);
    void printfila_1 (void);


};

void actuadores::lcd_init ( void ) {

  lcd.init ( ); 					 	/*~ Inicializar la pantalla LCD ~*/
  Serial.println( F ( "Se ha iniciado la pantalla LCD ") );
  lcd.backlight ( );     		/*~ Encender la luz de fondo. ~*/

}

void actuadores::printfila_0 ( void ) {

  lcd.setCursor ( 0, 0 );   	/*~ ( columnas, filas) Ubicamos el cursor en la primera posición(columna:0) de la primera línea(fila:0) ~*/
  lcd.print ( "Primer fila" ); /*~ Mostrar una cadena de texto (no exceder 16 caracteres por línea)~*/

} 

void actuadores::printfila_1 ( void ) {

  lcd.setCursor ( 0, 1 );   	/*~ ( columnas, filas) Ubicamos el cursor en la primera posición(columna:0) de la primera línea(fila:0) ~*/
  lcd.print ( "Segunda fila" ); /*~ Mostrar una cadena de texto (no exceder 16 caracteres por línea)~*/

}

void actuadores::lcd_clean ( void ) {

  lcd.clear ( );				/*~ Limpiar pantalla ~*/  

}
#endif