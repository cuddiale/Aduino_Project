/////////////////////////////////////////////

// ARDUINO CONTATORE DI OGGETTI 

// Autore Fancello Salvatore

// Per maggiori info visita: http://www.progettiarduino.com

/////////////////////////////////////////////

#include <LiquidCrystal.h>

LiquidCrystal lcd ( 2,   //RS
                    3,  //EN
                    4,  //D4
                    5,  //D5
                    6,  //D6
                    7); //D7  
int state=LOW;
int lastState=LOW;
int count=0;

void setup(){
  
  lcd.begin(16, 2);          
  
Serial.begin(9600);
pinMode(8, INPUT);
state=digitalRead(8);
}
void loop(){
if (state==HIGH && lastState==LOW){
count++;
delay (100);
Serial.println(count);
lcd.setCursor(0, 0);     
    lcd.print("Num. Oggetti: ");  
    lcd.setCursor(0, 1);
    lcd.print(count);    

}
lastState=state;
state=digitalRead(8);
}
