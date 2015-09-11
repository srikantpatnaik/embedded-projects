// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setCursor(0,0); // 1st row
  // Print a message to the LCD.
  lcd.print("First row");
  lcd.setCursor(0,1); // 2nd row
  lcd.print("second row");
}

void loop() {}
