

int inputPin=11;
int value=0;

void setup() {
Serial.begin(9600);
pinMode(inputPin,INPUT);
}

void loop() {
  value=digitalRead(inputPin);
  if(value ==HIGH){
    Serial.println("Encendido");
    
    }else{
      Serial.println("APAGADO");
      }
delay(1000);
}
