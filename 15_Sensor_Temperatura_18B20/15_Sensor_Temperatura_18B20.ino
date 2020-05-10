/*  Sketch 15: Sensor Temperatura DS18B20
 *  Curso Intensivo de Arduino (2019)
 *  Impartido por MakeProjects (www.makeprojects.es)
 *  Sketch que lee la temperatura a traves del sensor DS18B20
 *  Nota: El DS18B20 puede medir temperaturas entre -55ºC y 125ºC.
 *----------------------------------------------------------------
 *  Librerias:
 *    OneWire by Jim Stud (y +) Version 2.3.5
 *    DallasTemperature by Miles Burton (y +) Version 3.8.0
 *----------------------------------------------------------------
 *  Conexiones:
 *    DS18D20:
 *        VCC                5V
 *        DI                 D9 + PULLUP (4.7K)
 *        GND                GND
 *    LED:
 *        Patilla larga (+)  D10 + RESISTENCIA (0.220K)
 *        Patilla corta (-)  GND
 *----------------------------------------------------------------
 */

#include <OneWire.h>
#include <DallasTemperature.h>

//Declaramos una variable de tipo entero donde almacenaremos el valor del pin donde conectamos el sensor
int pinSensor = 9;
//Declaramos una variable de tipo entero donde almacenaremos el valor del pin donde conectamos el led
int ledPin = 10;
//Declaramos una variable de tipo float donde almacenaremos el valor leido por el sensor
float temperatura = 0;

//Declaramos un objeto onewire para la comunicacion arduino-sensor (necesario para dallas temperature)
OneWire gestionComunicacion(pinSensor);
//Declaramos un objeto dallas temperature (sensor) para manejar el sensor
DallasTemperature sensor(&gestionComunicacion);
 
void setup() {
    //Iniciamos la comunicación por el puerto serie
    Serial.begin(9600);
    //Iniciamos el sensor (inicia internamente el modo del pin)
    sensor.begin();
    //Configuramos el pin del led como salida
    pinMode(ledPin, OUTPUT);
    //Encendemos el led
    digitalWrite(ledPin, HIGH);
    //Detenemos la ejecucion del programa durante 1 segundo
    delay(1000);
    //Apagamos el led
    digitalWrite(ledPin, LOW);
}
 
void loop() {
    //Mostramos por el puerto serie un mensaje
    Serial.println("Mandando comandos a los sensores");
    //Pedimos la temperatura al sensor
    sensor.requestTemperatures();
    // Leemos y mostramos por puerto serie los datos del sensor
    Serial.print("Temperatura del sensor: ");
    temperatura = sensor.getTempCByIndex(0);
    Serial.print(temperatura);
    Serial.println(" C");
    //Añadimos mas mensajes por pantalla según sea de alta la temperatura
    if(temperatura > 28.0) { //Si la temperatura es mayor de 28 grados ...
      Serial.println("Temperatura alta, esto ya no ye Asturies!!!");
      digitalWrite(ledPin, HIGH);  
    }
    else { //Si la temperatura es menor de 28 grados ...
      digitalWrite(ledPin, LOW); 
    }
    //Detenemos la ejecudion del programa 1 segundo
    delay(1000); 
}
