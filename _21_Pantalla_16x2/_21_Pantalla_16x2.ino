/*  Sketch 21: Pantalla 16x2
 *  Curso Intensivo de Arduino (2019)
 *  Impartido por MakeProjects (www.makeprojects.es)
 *  Sketch que muestra un ejemplo de utilizacion de la pantalla de 16x2
 */

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
}


void loop()
{
  lcd.setCursor(3,0);
  lcd.print("Hola a todos ");
  lcd.setCursor(2,1);
  lcd.print("Este video es");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("De Arduino por");
  lcd.setCursor(0,1);
  lcd.print("Ruben Gines");
  delay(3000);
  lcd.clear();
}
