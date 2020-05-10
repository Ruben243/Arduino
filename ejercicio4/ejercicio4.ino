int led1=10;
int led2=11;
int boton1=8;
int boton2=9;




void setup() {
Serial.begin(9600);
int valor1=LOW;
int valor2=LOW;
pinMode(boton1,INPUT);
pinMode(boton2,INPUT);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
}

void loop() {
int  valor1=digitalRead(boton1);
 int  valor2=digitalRead(boton2);

 
    if(valor1==HIGH){
     Serial.println("ENCENDIDO led1");
      digitalWrite(led1,HIGH);
  
     }else{
      Serial.println("APAGADO led1");
      digitalWrite(led1,LOW);
      }
    if(valor2==HIGH){
      Serial.println("ENDENDIDO led2");
      digitalWrite(led2,HIGH);

      }else{
        Serial.println("ENCENDIDO led2");
      digitalWrite(led1,LOW);
        }
delay(1000);
}
