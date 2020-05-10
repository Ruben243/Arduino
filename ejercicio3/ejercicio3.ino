

int inputPin=11;
int value=0;
int led=12;

void setup() {
Serial.begin(9600);
pinMode(inputPin,INPUT);
}

void loop() {
  value=digitalRead(inputPin);
  if(value ==HIGH){
    Serial.println("Encendido");
    digitalWrite(led,HIGH);
    
    }else{
      Serial.println("APAGADO");
      digitalWrite(led,LOW);

      }
delay(1000);
}
