/*  Sketch 17: RFID Leer
 *  Curso Intensivo de Arduino (2020)
 *  Impartido por MakeProjects (www.makeprojects.es)
 *  Sketch que detecta una tarjeta RFID, y muestra su identificador por puerto serie.
 *------------------------------------------------------------------------------------------------------
 *  Librerias:
 *      MRFC522 by GithubCommunity Version 1.4.6
 *------------------------------------------------------------------------------------------------------
 * Conexiones:
 *    RFID:
 *      3.3V  3.3V
 *      RST   D9
 *      GND   GND
 *      MOSI  D11
 *      MISO  D12
 *      SCK   D13
 *      SDA   D10
 *------------------------------------------------------------------------------------------------------
 */

#include <MFRC522.h>

//Declaramos una constante de tipo entero y le asignamos el valor del pin al que conectamos el cable RST (reset)
const int RST_PIN = 9;
//Declaramos una constante de tipo entero y le asignamos el valor del pin al que conectamos el cable SDA (selector de esclavo)
const int SS_PIN = 10;
//Declaramos un objeto MFRC522 para manejar el actuador
MFRC522 mfrc522(SS_PIN, RST_PIN);

//Mostrar el contenido de un array por el puerto serie
void mostrarArray(byte *buffer, byte tamanobuffer) {
   //Recorremos el array completo
   for (byte i = 0; i < tamanobuffer; i++) {
      //Mostrar por puerto serie los datos que contiene la posicion del array correspondiente formateados
      Serial.print(buffer[i] < 0x10 ? " 0" : " ");
      Serial.print(buffer[i], HEX);
   }
   //Enviar al puerto serie un salto de linea
   Serial.println();
}
 
void setup() {
  //Inicializar la comunicacion con el puerto serie a 9600 baudios
  Serial.begin(9600);
  //Inicializar el actuador RFID
  mfrc522.PCD_Init();
}
 
void loop() {
  if (mfrc522.PICC_IsNewCardPresent()) { //Si una nueva tarjeta ha entrado en el area del actuador
    if (mfrc522.PICC_ReadCardSerial()) {  //Si la lectura de la tarjeta ha sido correcta
      //Mostrar por puerto serie el identificador unico de la tarjeta
      Serial.print(F("Card UID:"));
      mostrarArray(mfrc522.uid.uidByte, mfrc522.uid.size);
      //Finalizar la lectura actual del actuador
      mfrc522.PICC_HaltA();
    }
 }
 //Detener la reproduccion del programa durante 1/2 de segundo
 delay(500);
}
