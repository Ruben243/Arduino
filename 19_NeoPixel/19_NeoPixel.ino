/*  Sketch 19: NeoPixel
 *  Curso Intensivo de Arduino (2020)
 *  Impartido por MakeProjects (www.makeprojects.es)
 *  Sketch que muestra un ejemplo de iluminacion de un anillo de NeoPixels
 *------------------------------------------------------------------------------------------------------
 *  Librerias:
 *      Adafruit Neopixel by Adafruit Version 1.3.4
 *------------------------------------------------------------------------------------------------------
 * Conexiones:
 *    Neopixel:
 *      VIN   5V
 *      DI    D6
 *      GND   GND
 *------------------------------------------------------------------------------------------------------
 *  Nota: La conecion DO sirve para conectar otro anillo en serie
 *------------------------------------------------------------------------------------------------------
 */

#include <Adafruit_NeoPixel.h>

//Declaramos una constante de tipo byte y le asignamos el valor del pin al que conectamos el neopixel
const byte PIN_NEOPIXEL = 6;
//Declaramos una constante de tipo byte y le asignamos el numero de neopixels que vamos a manejar
const byte NUM_PIXELS = 16;
//Declaramos un objeto MFRC522 para manejar el actuador
Adafruit_NeoPixel anillo = Adafruit_NeoPixel(NUM_PIXELS, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);
//Declaramos una variable de tipo entero y le asignamos el tiempo de espera entre encendido entre neopixels en milisegundos
int espera = 500; 

void setup() {
  //Inicializar el anillo de neopixels
  anillo.begin();
}

void loop() {
  //Recorremos los pixeles que componen el anillo de neopixels uno a uno
  for(int i=0;i<NUM_PIXELS;i++) {
    // Fijamos el color del neopixel correspondiente a verde con intensidad media -> pixels.Color toma valores RGB, desde 0,0,0 hasta 255,255,255
    anillo.setPixelColor(i, anillo.Color(0,128,0));
    //anillo.setPixelColor(i, anillo.Color(random(0,255),random(0,255),random(0,255)));
    //Mostramos los neopixels con los colores modificados (hasta que no se ejecuta esta orden no cambian los neopixels)
    anillo.show();
   //Detenemos la reproduccion del programa durante el tiempo establecido en la variable
    delay(espera); 
  }
}
