 /**
 
  ARDUINO ROBOT CON CONTROLLO TELECOMANDO IR

  Autore Fancello Salvatore
 
 Per maggiori info: http://www.progettiarduino.com

 **/

#include <IRremote.h>

int remoteInputPin = 2;
IRrecv receiver(remoteInputPin);
decode_results results;

int motorD   = 8;
int motorS   = 9;

void setup() {
  Serial.begin(9600);
  receiver.enableIRIn();

  pinMode(motorD, OUTPUT);
  pinMode(motorS, OUTPUT);
 
}

void avanti() {
  digitalWrite(motorD, HIGH);
  digitalWrite(motorS, HIGH);
  
}


void sinistra() {
  digitalWrite(motorD, HIGH);
  digitalWrite(motorS, LOW);

}

void destra() {
  digitalWrite(motorD, LOW);
  digitalWrite(motorS, HIGH);
  
}

void Stop() {
  digitalWrite(motorS, LOW);
  digitalWrite(motorD, LOW);
   
}

void loop() {
  if (receiver.decode(&results)) {
    Serial.println(results.value, HEX);

    if (results.value == 0xD7E84B1B) {
      Serial.println("AVANTI");
      avanti();
    } 
      else if (results.value == 0xF076C13B) {
      Serial.println("SINISTRA");
      sinistra();
    } 
      else if (results.value == 0xA3C8EDDB) {
      Serial.println("DESTRA");
      destra();
    } 
      else if (results.value == 0x20FE4DBB) {
      Serial.println("STOP");
      Stop();
    }

    receiver.resume();
  }
}
