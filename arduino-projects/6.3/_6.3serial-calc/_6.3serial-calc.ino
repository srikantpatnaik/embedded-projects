#include "math.h"

void setup() {
  Serial.begin(9600);
  Serial.println("Select operation by typing 1 or 2");
  Serial.println("1) Square root");  
  Serial.println("2) Power of integer"); 
  Serial.println("-----------------------------------");
}

int readFromPC() { 
  while(Serial.available() == 0); //wait until data from PC
  //parseInt() returns long integer value(unlike Serial.read() 
  // which returns only one byte)
  return Serial.parseInt(); 
}  

void loop() {        
    
    switch(readFromPC()) {
      case 1:
      Serial.print("1) Enter value for square root:");           
      Serial.println(sqrt(readFromPC()));   
      Serial.println("-----------------------------------");
      break;     
   
     case 2:
      Serial.print("2) Enter base value:");   
      float base = readFromPC();       
      Serial.println(base);  
      
      Serial.print("   Enter power value:");  
      float power = readFromPC();         
      Serial.println(power);  
            
      Serial.print("Power of given value is:");
      float result = pow(base,power);
      Serial.println(result);
      Serial.println("-----------------------------------");
      }
    delay(5);  
}

