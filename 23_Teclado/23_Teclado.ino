/*  Sketch 23: Teclado
 *  Curso Intensivo de Arduino (2020)
 *  Impartido por MakeProjects (www.makeprojects.es)
 *  Sketch que muestra por serial las teclas de un teclado de 4x4 de membrana
 *---------------------------------------------------------------------------
 *  Librerias:
 *      Keypad by Mark Stanley (y +) Version 3.1.1
 *---------------------------------------------------------------------------
 *  Conexiones:
 *    KEYPAD:
 *      Fila_1     D9
 *      Fila_2     D8
 *      Fila_3     D7
 *      Fila_4     D6
 *      Columna_1  D5
 *      Columna_2  D4
 *      Columna_3  D3
 *      Columna_4  D2
 *---------------------------------------------------------------------------
 */

#include <Keypad.h>

//Declaramos dos constantes de tipo byte para indicar las filas y columnas que tiene nuestro teclado
const byte FILAS = 4; 
const byte COLUMNAS = 4; 

//Simulamos el teclado en una constante array de tipo char de tamaño FILASxCOLUMNAS
const char teclas[FILAS][COLUMNAS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

//Declaramos 2 variables array de tipo byte a las que asignamos los pines de conexion del teclado
byte PIN_FILAS[FILAS] = {9, 8, 7, 6};
byte PIN_COLUMNAS[COLUMNAS] = {5, 10, 3, 2};

//Declaramos un objeto de tipo Keypad para acceder al teclado fisico
Keypad teclado = Keypad(makeKeymap(teclas), PIN_FILAS, PIN_COLUMNAS, FILAS, COLUMNAS);

void setup() {
  //Inicializar el puerto serie a una velocidad de 9600 baudios
  Serial.begin(9600);
}
  
void loop() {
  //Leemos si se pulsó una tecla en el teclado
  char teclaPulsada = teclado.getKey();
  if (teclaPulsada) { //Si hay un valor en teclaPulsada es que se pulsó una tecla
    Serial.println(teclaPulsada);
  }
}
