#include <dht.h>

#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

dht DHT;
void setup() {
  pinMode(A0, INPUT); // No digital pins are available so use Analog
  lcd.begin(16,2);
}

void loop() {
  DHT.read11(A0);
  lcd.setCursor(0,0);
  lcd.print(DHT.humidity);
  lcd.setCursor(5,0);
  lcd.print("% Humidity");
  lcd.setCursor(0,1);
  lcd.print(DHT.temperature);
  lcd.setCursor(6,1);
  lcd.print("deg C");
  delay(1000);
}
