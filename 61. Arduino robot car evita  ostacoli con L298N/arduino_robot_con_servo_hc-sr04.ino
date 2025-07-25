////////////////////////////////////////////////

// Progetto ARDUINO ROBOT CAR EVITA OSTACOLI CON SERVO E HC-SR04

// Autore FANCELLO SALVATORE

// Per maggiori info: http://www.progettiarduino.com

/////////////////////////////////////////////////

#include <Servo.h> 
Servo servo1;
int pos = 0; 
int posprec = 0;  
int gradi = 0;  
int incremento = 1;  
int ENA=11; 
int IN1=10; 
int IN2=9; 
int IN3=8;  
int IN4=7; 
int ENB=6; 
int gap = 0; 
int velocita = 255; // velocità motori (min 120 max 255, gap compreso) 
int rotazione90 = 500; 
float cm; 
void avanti (void) 
{ 
digitalWrite(IN1,0); 
digitalWrite(IN2,1); 
digitalWrite(IN3,1); 
digitalWrite(IN4,0); 
analogWrite(ENA, velocita + gap); // Attiva il motore A 
analogWrite(ENB, velocita ); // Attiva il motore B 
} 
void sx90 (void) 
{ 
digitalWrite(IN1,1); 
digitalWrite(IN2,0);  
digitalWrite(IN3,1); 
digitalWrite(IN4,0); 
analogWrite(ENA, velocita + gap); 
analogWrite(ENB, velocita ); 
delay (rotazione90); 
analogWrite(ENA,0); // blocca il motore A 
analogWrite(ENB,0); // blocca il motore B 
} 

void dx90 (void) 
{ 
digitalWrite(IN1,0); 
digitalWrite(IN2,1); 
digitalWrite(IN3,0); 
digitalWrite(IN4,1); 
analogWrite(ENA, velocita + gap); 
analogWrite(ENB, velocita ); 
delay (rotazione90); 
analogWrite(ENA,0); 
analogWrite(ENB,0); 
} 

void sensore (void)  
{ 
gradi = posprec; 
incremento = 1; 
if (pos <= posprec) 
incremento = -1; 
for(posprec = gradi; posprec != pos; posprec = posprec + incremento) 
{ 
servo1.write(posprec);  
delay(15);  
} 
digitalWrite(2, LOW);  
delayMicroseconds(2); 
digitalWrite(2, HIGH); 
delayMicroseconds(10);  
digitalWrite(2, LOW);
cm = pulseIn(3, HIGH) / 58.0; 
} 

void setup() 
{ 
delay (3000); 
servo1.attach(5); 
servo1.write (90);
posprec = 90;
pinMode(ENA,OUTPUT);  
pinMode(ENB,OUTPUT); 
pinMode(IN1,OUTPUT); 
pinMode(IN2,OUTPUT); 
pinMode(IN3,OUTPUT); 
pinMode(IN4,OUTPUT); 
pinMode(2, OUTPUT);
pinMode(3, INPUT);  
analogWrite(ENA,0); // blocca il motore A 
analogWrite(ENB,0); // blocca il motore B 
} 

void loop() 
{ 
pos = 90; 
sensore ();  

if (cm > 30) 
{ 
avanti(); 
} 
else 
{ 
analogWrite(ENA,0); // blocca il motore A 
analogWrite(ENB,0); // blocca il motore B 
pos = 0; 
sensore (); 
if (cm > 30)  
{ 
dx90 ();  
} 
else 
pos = 180;  
sensore (); 
if (cm > 30) 
{ 
sx90 ();  
} 
else 
{ 
sx90 ();  
sx90 (); 
   }     
   }   
   } 

