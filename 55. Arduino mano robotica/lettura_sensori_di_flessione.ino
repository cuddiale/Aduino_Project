void setup() {
  
pinMode(A3, INPUT);
Serial.begin(9600);
pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int val = analogRead(A3);
Serial.println(val);
delay(200);
if(val<=600) {
  digitalWrite(13, HIGH);
}
else {
  digitalWrite(13, LOW);

}
}
