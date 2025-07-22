/*
VOLTOMETRO DC CON ARDUINO DA 0 a 30 v
AUTORE FANCELLO SALVATORE
Per maggiori info: http://www.progettiarduino.com
*/

#include <Wire.h>                      
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 
int analogInput = 0;
float vout = 0.0;
float vin = 0.0;
float R1 = 100000.0; // inserire valore esatto resistenza R1 (100K) 
float R2 = 10000.0; // inserire valore esatto resistenza R2 (10K) 
int value = 0;

void setup(){
   pinMode(analogInput, INPUT);
   lcd.begin(16, 2);
   lcd.print("VOLTMETRO DC");
   Serial.begin(9600);
}
void loop(){
   value = analogRead(analogInput);
   
   vout = (value * 5.0) / 1024.0; 
   // inserire al posto di 5.0V l`uscita in volt tra i Pin 5V e GND del vostro Arduino
   
   vin = vout / (R2/(R1+R2)); 
   if (vin<0.09) {
   vin=0.0;
} 
lcd.setCursor(0, 1);
lcd.print("INPUT V= ");
lcd.print(vin);
delay(500);
}
