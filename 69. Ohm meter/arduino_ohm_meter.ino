// Arduino Ohm meter, Misura resistenze
// Autore Fancello Salvatore
// Per maggiori info: www.progettiarduino.com

int analogPin= 0; // Pin Analogico A0
int raw= 0;  
int Vin= 5;  // Volt in uscita dal Pin 5V di Arduino
float Vout= 0;
float R1= 1000; // impostare il valore della resistenza nota in Ohm
float R2= 0;
float buffer= 0;

#include <Wire.h>     // Libreria wire già presente in Arduino ide      
#include <LiquidCrystal_I2C.h> // Libreria display I2C

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 

void setup()
{
  lcd.begin(16, 2); //Inizializzazione display
Serial.begin(9600); //Apro la comunicazione seriale
}

void loop()
{
raw= analogRead(analogPin);
if(raw) 
{
buffer= raw * Vin;
Vout= (buffer)/1024.0;
buffer= (Vin/Vout) -1;
R2= R1 * buffer;
Serial.print("Vout: ");
Serial.println(Vout);
Serial.print("R2: ");
Serial.println(R2);
lcd.print("OHM METER");
lcd.setCursor(0, 1);
lcd.print("R2:  ");
lcd.print(R2);
delay(1000);
lcd.clear();
}
}
