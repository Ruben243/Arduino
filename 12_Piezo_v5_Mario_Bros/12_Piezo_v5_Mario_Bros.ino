/*  Sketch 12: Piezo_v5
 *  Curso Intensivo de Arduino (2020)
 *  Impartido por MakeProjects (www.makeprojects.es)
 *  Sketch que emite la cancion de Mario Bros
 *--------------------------------------------------------------------------------
 *  Conexiones:
 *    PIEZO:
 *        VCC     5V
 *        DI      D8
 *        GND     GND
 *--------------------------------------------------------------------------------
 *  Nota: El buzzer funciona invertido, un HIGH apaga el buzzer y un LOW lo activa
 *--------------------------------------------------------------------------------
 */
 
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

//Declaramos una variable de tipo entero y le asignamos el numero de pin al que conectamos el piezo
int piezoPin = 8;

//Array con laa notas de la melodia normal de Mario Bros
int melodia_normal[] = { NOTE_E7, NOTE_E7, 0, NOTE_E7, 0, NOTE_C7, NOTE_E7, 0, NOTE_G7, 0, 0,  0, NOTE_G6, 0, 0, 0, NOTE_C7, 0, 0, NOTE_G6, 0, 0, NOTE_E6, 0, 0, NOTE_A6, 0, NOTE_B6, 0, NOTE_AS6, NOTE_A6, 0, NOTE_G6, NOTE_E7, NOTE_G7, NOTE_A7, 0, NOTE_F7, NOTE_G7, 0, NOTE_E7, 0, NOTE_C7, NOTE_D7, NOTE_B6, 0, 0, NOTE_C7, 0, 0, NOTE_G6, 0, 0, NOTE_E6, 0, 0, NOTE_A6, 0, NOTE_B6, 0, NOTE_AS6, NOTE_A6, 0, NOTE_G6, NOTE_E7, NOTE_G7, NOTE_A7, 0, NOTE_F7, NOTE_G7, 0, NOTE_E7, 0, NOTE_C7, NOTE_D7, NOTE_B6, 0, 0 };
//Array con las duraciones de cada nota en la melodia normal de Mario Bros
int tempo_normal[] = { 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 9, 9, 9, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 9, 9, 9, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12 };
//Array con las notas de la melodia underworld de Mario Bros
int melodia_underworld[] = { NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4, NOTE_AS3, NOTE_AS4, 0, 0, NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4, NOTE_AS3, NOTE_AS4, 0, 0, NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4, NOTE_DS3, NOTE_DS4, 0, 0, NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4, NOTE_DS3, NOTE_DS4, 0, 0, NOTE_DS4, NOTE_CS4, NOTE_D4, NOTE_CS4, NOTE_DS4, NOTE_DS4, NOTE_GS3, NOTE_G3, NOTE_CS4, NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4, NOTE_GS4, NOTE_DS4, NOTE_B3, NOTE_AS3, NOTE_A3, NOTE_GS3, 0, 0, 0 };
//Array con las duraciones de cada nota en la melodia underworld de Mario Bros
int tempo_underworld[] = { 12, 12, 12, 12, 12, 12, 6, 3, 12, 12, 12, 12, 12, 12, 6, 3, 12, 12, 12, 12, 12, 12, 6, 3, 12, 12, 12, 12, 12, 12, 6, 6, 18, 18, 18, 6, 6, 6, 6, 6, 6,  18, 18, 18, 18, 18, 18, 10, 10, 10, 10, 10, 10, 3, 3, 3 };
//Variable en la que almacenaremos el numero de melodia que se está ejecutando
int cancion = 0;

void setup(void) {
  //Configuramos el pin del piezo como salida
  pinMode(8, OUTPUT);//buzzer
}

void loop() {
  //Ejecutamos las funciones que componen la melodia
  //Tema normal
  cantar(1);
  //Tema normal
  cantar(1);
  //Tema underworld
  cantar(2);
}
 
//Ejecuta la melodia 
void cantar(int tema) {
  //Asignamos a la variable cancion el tema que va a sonar
  cancion = tema;
  if (cancion == 2) { //Si la cancion es la numero 2 (Tema underworld)
    //Mostramos por el puerto serie el tema que va a sonar
    Serial.println("Tema underworld");
    //Calculamos la cantidad de elementos que hay en el array
    int tamano = sizeof(melodia_underworld) / sizeof(int);
    //Recorremos el array mientra no lleguemos al final
    for (int i = 0; i < tamano; i++) {
      //Calculamos la duracion de la nota (1 segundo / tipo de nota)
      int duracionNota = 1000 / tempo_underworld[i];
      //Ejecutamos la nota
      nota(piezoPin, melodia_underworld[i],duracionNota);
      // Para distinguir las notas pausar un tiempo entre ellas (duracion de la nota + 30%)
      int pausaEntreNotas = duracionNota * 1.30;
      //Detenemos la ejecucion del programa el tiempo de pausa entre las notas
      delay(pausaEntreNotas);
      //Detener la reproduccion de la nota
      nota(piezoPin, 0, duracionNota);
    }
 }
 else { //Si la cancion es la numero 1 (Tema normal)
    //Mostramos por el puerto serie el tema que va a sonar
    Serial.println("Tema Mario normal");
    //Calculamos la cantidad de elementos que hay en el array
    int size = sizeof(melodia_normal) / sizeof(int);
    //Recorremos el array mientra no lleguemos al final
    for (int i = 0; i < size; i++) {
      //Calcular la duracion de la nota (1 segundo / tipo de nota)
      int duracionNota = 1000 / tempo_normal[i];
      //Ejecutamos la nota
      nota(piezoPin, melodia_normal[i], duracionNota);
      // Para distinguir las notas pausar un tiempo entre ellas (duracion de la nota + 30%)
      int pausaEntreNotas = duracionNota * 1.30;
      //Detenemos la ejecucion del programa el tiempo de pausa entre las notas
      delay(pausaEntreNotas);
      //Detener la reproduccion de la nota
      nota(piezoPin, 0, duracionNota);
     }
  }
}
 
void nota(int pinDestino, long frecuencia, long longitud) {
  // Calcular la espera entre transiciones
  // Un segundo de microsegundos, dividido por la frecuencia, luego dividido por la mitad (porque hay dos fases en cada ciclo)
  long valorEspera = 1000000 / frecuencia / 2;
  // Calcular el numero de ciclos para cada momento
  long numeroCiclos = frecuencia * longitud / 1000;
  //Multiplicar la frecuencia, que son ciclos por segundo, por el número de segundos para obtener el número total de ciclos que se producen
  for (long i = 0; i < numeroCiclos; i++) {
    //Hacer sonar el piezo
    digitalWrite(pinDestino, LOW);
    //Parar la ejecucion el tiempo calculado
    delayMicroseconds(valorEspera);
    //Parar de sonar el piezo
    digitalWrite(pinDestino, HIGH);
    //Parar la ejecucion el tiempo calculado
    delayMicroseconds(valorEspera);
  }
}
