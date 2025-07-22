//ARDUINO ROBOT EVITA OSTACOLI CON HC-SR04

//Autore Fancello Salvatore

//Per maggiori info: http://www.progettiarduino.com

/////////////////////////////////////////////////

 int MOTORD=8;
 int MOTORS=9;
#define echoPin 2 // Pin che riceve la pulsazione echo
#define trigPin 3

void setup(){
  Serial.begin(9600);
pinMode(MOTORD,OUTPUT);
pinMode(MOTORS,OUTPUT);
pinMode(echoPin, INPUT);// setto echopin come input
pinMode(trigPin, OUTPUT);// setto trigger come output
}
void loop(){
  
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int distance = pulseIn(echoPin, HIGH);        
  distance= distance/58;                       
   Serial.println(distance);
   // se ho un ostacolo a 25 cm di distanza gira a destra tenedo ferma la ruota destra
  if((distance<25)&&(distance!=0)){  // a volte arrivano degli zeri e quelli non li devo prendere in considerazione
  digitalWrite(MOTORS,HIGH); // accendo un motore e spengo l'altro così posso girare
  digitalWrite(MOTORD,LOW);
  delay(500);
  }
   else{ // vado dritto
  digitalWrite(MOTORS,HIGH);
  digitalWrite(MOTORD,HIGH);
  
  }
  
}

