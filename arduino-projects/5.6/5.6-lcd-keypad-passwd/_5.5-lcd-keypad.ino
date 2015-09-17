#include <Keypad.h>
#include <LiquidCrystal.h>
#include <string.h>

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

char mypasswd[5] = {'1','2','1','1',0};
char getpasswd[5];
int i=0;

void setup() {
    lcd.begin(16,2);
    
}

void loop() {
      char key = mykeypad.getKey() ;
      if ((key != NO_KEY) && (i<4)){
        getpasswd[i++]=key;        
        lcd.setCursor(0,1);
        lcd.print(key);
      }  
    getpasswd[4]=0; //append NULL char
 
    if (strcmp( getpasswd, mypasswd ) == 0){
      lcd.setCursor(0,0);
      lcd.print("password matched");
      pinMode(A0, OUTPUT); //using analog input pin as digital
      digitalWrite(A0, HIGH);
      
    }
  }


