void setup() {
  // put your setup code here, to run once:
pinMode(3, OUTPUT);
pinMode(A0, INPUT);
}

void loop() {
int digital_samples=analogRead(A0); // 10 bit ADC so upto 1024
float pwm_samples=digital_samples/4.0; // PWM is 8 bit so upto 256
Serial.begin(9600);
analogWrite(3, pwm_samples);

}
