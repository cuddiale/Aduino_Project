const int motor1Pin = 3;    // H-bridge leg 1 (pin 2, 1A)
const int motor2Pin = 4;    // H-bridge leg 2 (pin 7, 2A)
const int enablePin = 9;    // H-bridge enable pin
const int ledPin = 13;      // LED
  
int incomingByte;      // a variable to read incoming serial data into
  
  
void setup() {
  Serial.begin(9600); // open serial port to receive data
  
  
  // set all the other pins you're using as outputs:
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  // set enablePin high so that motor can turn on:
  digitalWrite(enablePin, LOW);
  
}
  
void loop() {
  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    // if it's a capital H (ASCII 72), turn on the LED:
    if (incomingByte == 'H') {
      digitalWrite(enablePin, HIGH);  // accende  il motore
      digitalWrite(motor1Pin, LOW);   // set leg 1 of the H-bridge low
      digitalWrite(motor2Pin, HIGH);  // set leg 2 of the H-bridge high
    }
    else if (incomingByte == 'J') {
      digitalWrite(enablePin, HIGH);  // accende il motore
      digitalWrite(motor1Pin, HIGH);   // set leg 1 of the H-bridge low
      digitalWrite(motor2Pin, LOW);  // set leg 2 of the H-bridge high
    }     
    else if (incomingByte == 'L') {
      digitalWrite(enablePin, LOW);  // spegne il motore
    }
  
  }
  
}

