#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

Servo servo1; 
Servo servo2; 
Servo servo3;  
Servo servo4;
Servo servo5;  

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 

int posservo1 =0; 
int posservo2 =0;    
int posservo3 =0;    
int posservo4 =0;
int posservo5 =0; 
char com = 0;
int tempo=6000;
int tnorm=500;

void setup() {
pinMode(2, OUTPUT);

lcd.begin(16,2); 
lcd.backlight();
  
Serial.begin(9600);
 
 servo1.attach(11); //BIANCO
 servo2.attach(10); //ROSSO 
 servo3.attach(9);  //VIOLA
 servo4.attach(6);  //GIALLO
 servo5.attach(5);//BLU

}

void loop() {
int sensorValue = analogRead(A0);
int valorecomparato=(sensorValue*5/1024);

if (valorecomparato>3)
{
  servo1.write(0);
  servo2.write(90);
  servo3.write(55);
  servo4.write(15);
  servo5.write(168);
  delay(500);
  
  lcd.setCursor(0,0);
  lcd.print("Posizionamento");
  
      for (posservo4 = 15; posservo4 <= 59 ;posservo4 += 1) {  //1
    servo4.write(posservo4);              
    delay(30);
    };
   delay(tnorm);
  for (posservo3 = 55; posservo3 <= 135 ;posservo3 += 1) { //2
    servo3.write(posservo3);             
    delay(30);
    };
  delay(tnorm);
   
  lcd.clear();
   lcd.setCursor(0,1);
  lcd.print("Presa Corpo");
  
  for (posservo1 = 0; posservo1 <= 70 ;posservo1 += 1) {  //3
    servo1.write(posservo1);              
    delay(20);
    };
    delay(tnorm);
  for (posservo4 = 59; posservo4 >= 45 ;posservo4 -= 1) {  //1
    servo4.write(posservo4);              
    delay(30);
    };
   delay(tnorm);
     delay(1000);
     for (posservo5 = 168; posservo5 >= 142 ;posservo5 -= 1) {   //5
    servo5.write(posservo5);              
    delay(30);
    };
     delay(tnorm);
      for (posservo3 = 135; posservo3 <= 180 ;posservo3 += 1) { //2
    servo3.write(posservo3);             
    delay(30);
    };
  delay(tnorm);
     for (posservo4 = 45; posservo4 <= 59 ;posservo4 += 1) {  //1
    servo4.write(posservo4);              
    delay(30);
    };
   delay(tnorm);
  
  lcd.clear();
  lcd.print("Posizionamento");
  lcd.setCursor(0,1);
  lcd.print("1 Sede");
    
    
    delay(tnorm);
     for (posservo2 = 90; posservo2 <= 180 ;posservo2 += 1) {  //6
    servo2.write(posservo2);              
    delay(10);
    };
     delay(tnorm);
    for (posservo4 = 59; posservo4 <= 80 ;posservo4 += 1) {   //7
    servo4.write(posservo4);              
    delay(30);
    };
    delay(tnorm);
    for (posservo3 = 180; posservo3 >= 72 ;posservo3 -= 1) {   //7.1
    servo3.write(posservo3);              
    delay(20);
    };
    delay(tnorm);
     for (posservo5 = 142; posservo5 >= 131 ;posservo5 -= 1) {   //7.2
    servo5.write(posservo5);              
    delay(20);
    };
        delay(tnorm);
    for (posservo4 = 80; posservo4 <= 100 ;posservo4 += 1) {   //8
    servo4.write(posservo4);              
    delay(10);
    };
    delay(tnorm);
    for (posservo3 = 72; posservo3 >= 68 ;posservo3 -= 1) {   //8.1
    servo3.write(posservo3);              
    delay(20);
    };
  lcd.clear();
  lcd.print("1 Lavorazione");
  lcd.setCursor(0,1);
  lcd.print("Ins Tampone");
  delay (1000);
  digitalWrite(2, HIGH);
  delay(1000);
  digitalWrite(2, LOW);
  delay(tnorm);
    for (posservo3 = 68; posservo3 <= 72 ;posservo3 += 1) {   //8.2
    servo3.write(posservo3);              
    delay(20);
    };
    delay(tempo);
     for (posservo4 = 100; posservo4 >= 80 ;posservo4 -= 1) {  //9
    servo4.write(posservo4);             
    delay(20);
    };
      delay(tnorm);

lcd.clear();
  lcd.print("Posizionamento");
  lcd.setCursor(0,1);
  lcd.print("2 Sede");
    
    delay(tnorm);
    for (posservo5 = 131; posservo5 >= 102 ;posservo5 -= 1) { //10
    servo5.write(posservo5);             
    delay(20);
    };
    
    delay(tnorm);
    for (posservo4 = 80; posservo4 <= 107 ;posservo4 += 1) { //11
    servo4.write(posservo4);             
    delay(10);
    };

lcd.clear();
  lcd.print("2 Lavorazione");
  lcd.setCursor(0,1);
  lcd.print("Ins Tappo");
     delay (1000);
  digitalWrite(2, HIGH);
  delay(1000);
  digitalWrite(2, LOW);
    delay(tempo);
       for (posservo4 = 107; posservo4 >= 85 ;posservo4 -= 1) {   //12
    servo4.write(posservo4);              
    delay(20);
    };
    delay(tnorm);
        
    lcd.clear();
  lcd.print("Posizionamento");
  lcd.setCursor(0,1);
  lcd.print("3 Sede");
  
    delay(tnorm);
    for (posservo2 = 180; posservo2 >= 0 ;posservo2 -= 1) {  //13
    servo2.write(posservo2);             
    delay(20);
    };
    delay(tnorm);
    for (posservo5 = 102; posservo5 >= 72 ;posservo5 -= 1) { //14
    servo5.write(posservo5);              
    delay(20);
    };
    delay(tnorm);
    for (posservo4 = 85; posservo4 <= 100 ;posservo4 += 1) {   //15
    servo4.write(posservo4);            
    delay(10);
    };
 
lcd.clear();
  lcd.print("3 Lavorazione");
  lcd.setCursor(0,1);
  lcd.print("Ins Pennino");
     delay (1000);
  digitalWrite(2, HIGH);
  delay(1000);
  digitalWrite(2, LOW);
    delay(tempo);    
    for (posservo4 = 100; posservo4 >= 85 ;posservo4 -= 1) {   //16
    servo4.write(posservo4);              
    delay(20);
    };

     lcd.clear();
  lcd.print("Posizionamento");
  lcd.setCursor(0,1);
  lcd.print("4 Sede");
    
     delay(tnorm);
     for (posservo5 = 72; posservo5 >= 46 ;posservo5 -= 1) {  //17
    servo5.write(posservo5);              
    delay(20);
    };
       delay(tnorm);
    for (posservo4 = 85; posservo4 <= 100 ;posservo4 += 1) {//18
    servo4.write(posservo4);              
    delay(10);
    };
    
    lcd.clear();
  lcd.print("4 Lavorazione");
  lcd.setCursor(0,1);
  lcd.print("Ins Cappuccio");
   delay (1000);
  digitalWrite(2, HIGH);
  delay(1000);
  digitalWrite(2, LOW);
    delay(tempo);
    for (posservo4 = 100; posservo4 >= 20 ;posservo4 -= 1) { //19
    servo4.write(posservo4);             
    delay(20);
    };
    lcd.clear();
  lcd.print("Riposizionamento");
    delay(tnorm);
    for (posservo5 = 46; posservo5 >= 20 ;posservo5 -= 1) {  //20
    servo5.write(posservo5);             
    delay(20);
    };
    delay(tnorm);
    for (posservo1 = 70; posservo1 >= 0 ;posservo1 -= 1) {  //21
    servo1.write(posservo1);              
    delay(20);
    };
  delay(tnorm);
  

  
 
  for (posservo5 = 20; posservo5 <= 167 ;posservo5 += 1) { //22
    servo5.write(posservo5);             
    delay(20);
    };
    for (posservo4 = 20; posservo4 >= 15 ;posservo4 -= 1) {//23
    servo4.write(posservo4);              
    delay(20);
    };
  for (posservo3 = 72; posservo3 <= 55 ;posservo3 += 1) {  //24
    servo3.write(posservo3);            
    delay(20);
    };
    lcd.clear();
    lcd.print("    Attesa");
  lcd.setCursor(0,1);
  lcd.print("    Comando");
  for (posservo2 = 0; posservo2 <= 90 ;posservo2 += 1) {  //25
    servo2.write(posservo2);             
    delay(20);
    };
       }
else{
 servo1.write(0);
  servo2.write(90);
  servo3.write(55);
  servo4.write(15);
  servo5.write(168);
  

  }
}


