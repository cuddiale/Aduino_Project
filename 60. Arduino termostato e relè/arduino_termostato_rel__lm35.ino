////////////////////////////////////////////

// ARDUINO TERMOSTATO CON RELÈ, DISPLAY E LM35

// Autore Fancello Salvatore

// Per maggiori info: http://www.progettiarduino.com 

/////////////////////////////////////////////

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int reading = 0;
int sensorPin = A0;
int relay =7;
void setup() {
  
  lcd.begin(16, 2);
  pinMode(relay,OUTPUT);
}
 
void loop() {
  reading = analogRead(sensorPin);
  int celsius = reading/2;
  lcd.setCursor(0, 0);
  lcd.print("Temperatura: "); 
  lcd.setCursor(0,1);
  lcd.print(celsius, DEC);
  lcd.print((char)223);
  lcd.print("C");
  
  if (celsius >28) { 
    //modificare la temperatura desiderata, 
    //inserire > se attivo superiore a 28C°
    //e < se attivo inferiore a 28C°
    
    digitalWrite(7,HIGH);
     lcd.print("    ON");
  } else {
    digitalWrite(7,LOW);
    lcd.print("   OFF");
  }
  delay(500);
  lcd.clear();
}
