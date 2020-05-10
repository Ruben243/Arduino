

int ledPin=10;
const int espera=1000;
char valor;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);  
pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  valor=Serial.read();
  if(valor== 'A'){
    digitalWrite(ledPin,HIGH);
    delay(1000);
    digitalWrite(ledPin,LOW);
    Serial.println("Hola mundo");
    
    }

}
