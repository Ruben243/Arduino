/*  Sketch 26: Ultrasonidos
 *  Curso Intensivo de Arduino (2020)
 *  Impartido por MakeProjects (www.makeprojects.es)
 *  Sketch que mide la distancia a un objeto a traves del sesnor de ultrasonido
 *---------------------------------------------------------------------------
 *  Conexiones:
 *    ULTRASONIDO SR-04:
 *      VCC       5V
 *      TRIGGER   D9
 *      ECHO      D10
 *      GND       GND
 *---------------------------------------------------------------------------
 */


//Declaramos dos constantes de tipo byte y les asignamos los pines de conexion del ultrasonido
const byte PIN_TRIGGER = 9;
const byte PIN_ECHO = 10;

void setup() {
  //Configuramos el pin de echo y trigger con input y output respectivamente
  pinMode(PIN_TRIGGER, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  //Iniciamos el puerto serie
  Serial.begin(9600); 
}

void loop() {
  //Inicializamos el pin trigger a low durante 4 microsegundos
  digitalWrite(PIN_TRIGGER, LOW);
  delayMicroseconds(4);
  
  //Ponemos a pin trigger a HIGH durante 10 milisegundos y luego lo apagamos
  digitalWrite(PIN_TRIGGER, HIGH);
  delayMicroseconds(1000);
  digitalWrite(PIN_TRIGGER, LOW);
  
  //Leemos el pin de echo, que devuelve el tiempo de viaje de la onda de sonido en milisegundos y lo asignamos a una vriabla
  int duracion = pulseIn(PIN_ECHO, HIGH);
  
  // Calculamos la distancia 0.034 es la velocidad del sonido y es la mitad porque la onda recorre el doble de distancia (ida y vuelta)
  int distancia = duracion*0.034/2;

  //Mostramos el resultado por el puerto serie
  Serial.print("Distancia: ");
  Serial.println(distancia);
}
