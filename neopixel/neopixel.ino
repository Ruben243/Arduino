#include <Adafruit_NeoPixel.h>;
int PIN = 6;
int NUMPIXELS = 16;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int retraso = 20;
int colores[][3]= {{255,0,0},{255,127,0},{255,255,0},{0,255,0},{0,0,255},{75,0,130},{143,0,255}};

void setup() {
  // put your setup code here, to run once:
   pixels.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  //Arcoiris hacia adelante
  for (int i = 0; i<23; i++){
    for (int j = 0; j<7; j++){
      if (i<16 and i-j>=0){
        pixels.setPixelColor(i-j, pixels.Color(colores[j][0],colores[j][1],colores[j][2]));
        pixels.show();
        delay (retraso);
      }else if (i>15 and i-j<16){
        pixels.setPixelColor(i-j, pixels.Color(colores[j][0],colores[j][1],colores[j][2]));
        pixels.show();
        delay (retraso);
      }
    }
    //Apagamos la cola que sobra
    if (i>6){
      pixels.setPixelColor(i-7, pixels.Color(0,0,0));
      pixels.show();
      delay (retraso);
    }
  }
  delay(5*retraso);
  //Arcoiris Hacia Atras
  for (int i = 15; i>=-7; i--){
    for (int j = 0; j<7; j++){
      if (j+i<16){
        pixels.setPixelColor(i+j, pixels.Color(colores[6-j][0],colores[6-j][1],colores[6-j][2]));
        pixels.show();
        delay (retraso);
      }else if (i<0 and i+j>=0){
        pixels.setPixelColor(i+j, pixels.Color(colores[6-j][0],colores[6-j][1],colores[6-j][2]));
        pixels.show();
        delay (retraso);
      }
    }
    //Apagamos la cola que sobra
    if (i<9){
      pixels.setPixelColor(i+7, pixels.Color(0,0,0));
      pixels.show();
      delay (retraso);
    }
  }
  delay(5*retraso);
  //Encendemos todos 
  for (int i=0; i<7; i++){
    for (int j=0; j<16; j++){
        pixels.setPixelColor(j, pixels.Color(colores[i][0],colores[i][1],colores[i][2]));
        pixels.show();
        //delay (retraso);
    }
    delay (10*retraso);
  }
  //Apagamos Todos
  for (int j=0; j<16; j++){
      pixels.setPixelColor(j, pixels.Color(0,0,0));
      pixels.show();
  }
  delay(retraso*20);
}
