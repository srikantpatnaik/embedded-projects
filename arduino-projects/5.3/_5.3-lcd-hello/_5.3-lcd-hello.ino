#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  // put your setup code here, to run once
  lcd.begin(16,2);
  
  lcd.setCursor(0,0); //0th row and 0th column
  lcd.print("First row");
  lcd.setCursor(3,1); //1st row and 3th column
  lcd.print("Second row");
}

void loop() {
  // put your main code here,to run repeatedly
}
