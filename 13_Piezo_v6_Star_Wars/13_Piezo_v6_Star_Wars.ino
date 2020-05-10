/*  Sketch 13: Piezo_v6
 *  Curso Intensivo de Arduino (2020)
 *  Impartido por MakeProjects (www.makeprojects.es)
 *  Sketch que emite la cancion de Star Wars
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

//Constantes con el valor de las notas a usar
const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;

//Declaramos una variable de tipo entero y le asignamos el numero de pin del piezo
int piezoPin = 8;
 
void setup(){
  //Configuramos el pin del piezo como salida
  pinMode(piezoPin, OUTPUT);
}
 
void loop() {
  //Reproducir primera parte
  primeraParte();
  //Reproducir segunda parte
  segundaParte();
  //Reproducir primera variacion
  primeraVariacion();
  //Repetir la segunda parte
  segundaParte();
  //Reproducir segunda variacion
  segundaVariacion();
}
 
void pitar(int nota, int duracion) {
  //Reproducir el tono en el piezo
  tone(piezoPin, nota, duracion);
  //Parar reproduccion del piezo
  noTone(piezoPin);
  delay(50);
}
 
void primeraParte() {
  pitar(a, 500);
  pitar(a, 500);    
  pitar(a, 500);
  pitar(f, 350);
  pitar(cH, 150);  
  pitar(a, 500);
  pitar(f, 350);
  pitar(cH, 150);
  pitar(a, 650);
  delay(500);
  pitar(eH, 500);
  pitar(eH, 500);
  pitar(eH, 500);  
  pitar(fH, 350);
  pitar(cH, 150);
  pitar(gS, 500);
  pitar(f, 350);
  pitar(cH, 150);
  pitar(a, 650);
  delay(500);
}
 
void segundaParte() {
  pitar(aH, 500);
  pitar(a, 300);
  pitar(a, 150);
  pitar(aH, 500);
  pitar(gSH, 325);
  pitar(gH, 175);
  pitar(fSH, 125);
  pitar(fH, 125);    
  pitar(fSH, 250);
  delay(325);
  pitar(aS, 250);
  pitar(dSH, 500);
  pitar(dH, 325);  
  pitar(cSH, 175);  
  pitar(cH, 125);  
  pitar(b, 125);  
  pitar(cH, 250);  
  delay(350);
}

void primeraVariacion() {
  pitar(f, 250);
  pitar(gS, 500);
  pitar(f, 350);
  pitar(a, 125);
  pitar(cH, 500);
  pitar(a, 375);
  pitar(cH, 125);
  pitar(eH, 650);
  delay(500);
}

void segundaVariacion() {
  pitar(f, 250);
  pitar(gS, 500);
  pitar(f, 375);
  pitar(cH, 125);
  pitar(a, 500);
  pitar(f, 375);
  pitar(cH, 125);
  pitar(a, 650);
  delay(650);
}
