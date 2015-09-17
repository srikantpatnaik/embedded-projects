void setup() {
  // put your setup code here, to run once:
pinMode(A0, INPUT);
pinMode(3,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 int ldr=analogRead(A0);
 Serial.println(ldr);
 delay(100);
 if (ldr>900){
  digitalWrite(3,HIGH);
  }
  else {
    digitalWrite(3,LOW);
  }
}
