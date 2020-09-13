const int botonPin=7;
int valorPulsador=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(botonPin, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(3, LOW);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  valorPulsador=digitalRead(botonPin);
  digitalWrite(11, HIGH);
  digitalWrite(4, HIGH);

  if(valorPulsador==0){
      delay(1000);
      digitalWrite(4, LOW);
      digitalWrite(2, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH);
      delay(5000);
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      delay(5000);
      digitalWrite(13, LOW);
      digitalWrite(3,LOW);


    
  }

}
