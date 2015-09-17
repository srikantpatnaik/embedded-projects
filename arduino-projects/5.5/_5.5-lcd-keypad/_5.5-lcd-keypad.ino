#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
char keys[4][4] = { //declare an array
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[4] = {7, 6, 5, 4}; 
byte colPins[4] = {3, 2, 1, 0};
//initialize an instance of class Keypad
Keypad mykeypad = Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);

void setup() {
    lcd.begin(16,2);
}

void loop() {
      char key = mykeypad.getKey() ;
      if (key != NO_KEY) {        
//        lcd.setCursor(0,0);
        lcd.leftToRight();
        lcd.print(key);
      }  
}


