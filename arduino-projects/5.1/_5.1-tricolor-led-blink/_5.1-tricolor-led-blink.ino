void setup() {
  // put your setup code here, to run once:
  pinMode(10, OUTPUT); //blue LED
  pinMode(11, OUTPUT); //green LED
  pinMode(12, OUTPUT); //red LED
  pinMode(4, INPUT); //push button
}
void loop() {
  if (digitalRead(4) == HIGH)
  {
  // put your main code here, to run repeatedly:
  digitalWrite(10, HIGH); //blue
  delay(100); //0.5 secs delay
  digitalWrite(10, LOW);
  delay(100); //0.5 secs delay

  digitalWrite(11, HIGH); //green
  delay(100); //0.5 secs delay
  digitalWrite(11, LOW);
  delay(100); //0.5 secs delay

  digitalWrite(12, HIGH); //red
  delay(100); //0.5 secs delay
  digitalWrite(12, LOW);
  delay(100); //0.5 secs delay
  }
}
