/*  Sketch 25: Reles
 *  Curso Intensivo de Arduino (2020)
 *  Impartido por MakeProjects (www.makeprojects.es)
 *  Sketch que abre y cierra dos reles (mostrando informacion de ello por Serial)
 *---------------------------------------------------------------------------
 *  Conexiones:
 *    RELE:
 *      VCC   5V
 *      IN1   D2
 *      IN2   D3
 *      GND   GND
 *---------------------------------------------------------------------------
 */

//Declaramos dos variables donde almacenamos los pines de conexion de los electroimanes
const byte PIN_ELECTROIMAN_1 = 2;
const byte PIN_ELECTROIMAN_2 = 3;
//Declaramos una variable 
int espera = 3000;

void setup() {
  //Iniciamos el puerto serie a 9600 baudios de velocidad
  Serial.begin(9600);
  //Configuramos los pines de conexion de los electroimanes como salida
  pinMode(PIN_ELECTROIMAN_1, OUTPUT);
  pinMode(PIN_ELECTROIMAN_2, OUTPUT);

  // Desactivamos los electroimanes poniendolos a 1 (HIGH)
  digitalWrite(PIN_ELECTROIMAN_1, HIGH);
  digitalWrite(PIN_ELECTROIMAN_2, HIGH);
}

void loop() {
  //Activamos y desactivamos el rele 1 esperando el tiempo definido anteriormente entre cambios y mostramos su estado por el puerto serie
  Serial.println("Activando rele 1");
  digitalWrite(PIN_ELECTROIMAN_1, LOW);
  delay(espera);
  Serial.println("Desactivando rele 1");
  digitalWrite(PIN_ELECTROIMAN_1, HIGH);
  delay(espera);
  //Activamos y desactivamos el rele 2 esperando el tiempo definido anteriormente entre cambios y mostramos su estado por el puerto serie
  Serial.println("Activando rele 2");
  digitalWrite(PIN_ELECTROIMAN_2, LOW);
  delay(espera);
  Serial.println("Desactivando rele 2");
  digitalWrite(PIN_ELECTROIMAN_2, HIGH);
  delay(espera);
}
