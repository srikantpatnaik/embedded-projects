#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int count=0;
int pbutton = 7;
void setup() {
  // put your setup code here, to run once
  lcd.begin(16,2);
  pinMode(pbutton, INPUT);
  }
void loop() {
    if (digitalRead(pbutton) == HIGH)  {
    lcd.setCursor(5,0); // set cursor to column 6
    lcd.print(count++);
    while(digitalRead(pbutton) == HIGH);
    }
  }
