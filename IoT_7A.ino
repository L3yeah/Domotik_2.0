#include "IoT_7A.h"

void setup ( void ) {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  RTC.RTC_init ( );
  ACT.lcd_init ( );
}

void loop ( void ) {
  
  TASKS.actualizar_tareas ( );
  TASKS.tarea_rtc ( );
  TASKS.tarea_lcd ( );
  // put your main code here, to run repeatedly:
  delay(10); // this speeds up the simulation
}
