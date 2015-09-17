#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);


void setup() {
  pinMode(A0, INPUT); //used of LM35
  lcd.begin(16,2);
}

void loop() {
  float samples = analogRead(A0);
  //each digital sample has 5V/1024 Volts
  float analog_voltage_of_samples = samples * 5/1024;  
  //each 10mV(0.01V) given by LM35 is change in 1 deg C
  //how many such degree C in given voltage read from LM35
  float temp = analog_voltage_of_samples / 0.01;
  lcd.setCursor(0,0);
  lcd.print(temp);
  lcd.setCursor(7,0);
  lcd.print("deg C");
  delay(1000); //1s delay
}
