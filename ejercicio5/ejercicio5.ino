int z=8;





void setup() {
Serial.begin(9600);
pinMode(z,OUTPUT);

}

void loop() {
           
         delay(1000);
         digitalWrite(z,HIGH);
         delay(1000);
         digitalWrite(z,LOW);
         delay(1000);                                                                                                                                                                                                  
    
}
