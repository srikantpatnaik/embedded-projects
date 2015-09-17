#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
int count=0;

void setup() {
  // put your setup code here, to run once
  lcd.begin(16,2);
  pinMode(8, INPUT);
  
    }

void loop() {
  // put your main code here,to run repeatedly
  
  if (digitalRead(8) == HIGH)
  { 
    lcd.setCursor(0,0);
    lcd.print(count++);
    while(digitalRead(8) == HIGH);
   }
 
  
}
