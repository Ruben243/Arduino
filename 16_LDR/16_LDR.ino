/*  Sketch 16: Sensor Luz LDR
 *  Curso Intensivo de Arduino (2020)
 *  Impartido por MakeProjects (www.makeprojects.es)
 *  Sketch que lee la luz ambiental con un sensor LDR
 *----------------------------------------------------
 *  Conexiones:
 *    LDR:
 *        Patilla A          5V
 *        Patilla B          A0 + PULLUP (10K)
 *    LED:
 *        Patilla larga (+)  D10 + RESISTENCIA (0.220K)
 *        Patilla corta (-)  GND
 *--------------------------------------------------
 */

//Declaramos una variable de tipo entero donde almacenaremos el valor del pin donde conectamos el led
int ledPin = 10;
//Declaramos una variable de tipo entero donde almacenaremos el valor del pin donde conectamos el sensor
int ldrPin = 14;  //Pin 14 = Pin A0
//Declaramos una variable de tipo integer y le asignamos el valor umbral que queremos para la deteccion de luz (entre 0 y 1023)
int umbral = 200;

void setup() {
  //Iniciamos la comunicación a través del puerto serie
  Serial.begin(9600);
  //Configuramos el pin de LDR como entrada
  pinMode(ldrPin, INPUT);
  //Configuramos el pin del led como salida
  pinMode(ledPin, OUTPUT);
  //Encendemos el led
  digitalWrite(ledPin, HIGH);
}
 
void loop() {
  //Obtenemos la lectura del sensor LDR y la almacenamos en una variable de tipo integer
  int lectura_LDR = analogRead(ldrPin);
  //Mostramos por puerto serie el valor obtenido
  Serial.println(lectura_LDR);
  //Detenemos la ejecucion del programa 1 segundo
  delay(1000);

  if(lectura_LDR <= umbral) { //Si el valor leido es menor o igual que el umbral (mas luz)
    //Apagar el led
    digitalWrite(ledPin, LOW); 
  }
  else {  //Si el valor leido es mayor que el umbral (menos luz)
    //Encender el led
    digitalWrite(ledPin, HIGH); 
  }
}
