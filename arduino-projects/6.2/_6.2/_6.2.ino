void setup() {
pinMode(3,OUTPUT);
Serial.begin(9600);
  }


void loop() {
if (Serial.available()>0) {
  int a = Serial.parseInt();
  Serial.println(a);
  switch (a) {  
  case 1: 
    digitalWrite(3,HIGH);
    break;
  case 0: 
    digitalWrite(3,LOW);
    break;
  } 
  }
}
