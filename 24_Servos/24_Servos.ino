/*  Sketch 24: Servos
 *  Curso Intensivo de Arduino (2019)
 *  Impartido por MakeProjects (www.makeprojects.es)
 *  Sketch que gestiona el movimiento de un servo
 *---------------------------------------------------------------------------
 *  Librerias:
 *      Servo Built-In by Michael Margolis (y +) Version 1.1.6 (ya incluida)
 *---------------------------------------------------------------------------
 *  Conexiones:
 *    SERVOMOTOR:
 *      VCC (rojo)      5V
 *      GND (marron)    GND
 *      DIN (naranja)   D9
 *---------------------------------------------------------------------------
 */
 
#include <Servo.h>

//Declaramos un objeto de tipo Servo para manejar el servomotor
Servo miServoMotor;  
//Declaramos una constante de tipo byte donde almacenamos el pin al que conectamos el servomotor
const byte PIN_SERVO = 9;
//Declaramos una constante de tipo integer donde almacenamos el tiempo de espera entre movimientos del servomotor
const int ESPERA = 15;

void setup() {
  //Iniciamos el servomotor
  miServoMotor.attach(PIN_SERVO);
}

void loop() {
  //Incrementamos el angulo de 0 a 180º a razon de 1 unidad
  for (int i=0;i<=180;i++) {
    //Le decimos al servo que se mueva a la posicion indicada
    miServoMotor.write(i);
    //Esperamos 15 milisegundos
    delay(ESPERA);                      
  }
  //Detenemos la ejecucion del programa 1 segundo
  delay(1000);
  //Decrementamos el angulo de 180 a 0º a razon de 1 unidad
  for (int i=180;i>=0;i--) {
    //Le decimos al servo que se mueva a la posicion indicada
    miServoMotor.write(i);
    //Esperamos 15 milisegundos
    delay(ESPERA);                      
  }
  //Detenemos la ejecucion del programa 1 segundo
  delay(1000);
}
