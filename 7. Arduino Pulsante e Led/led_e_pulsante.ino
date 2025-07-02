int ledPin = 13;  //Il led è connesso al pin 13
int bottone = 7;  //Il pulsante è connesso al pin 7
int val = 0; 
void setup() {
  pinMode(ledPin, OUTPUT);  //Il pin del led è un'uscita 
  pinMode(bottone, INPUT);  //Il pin del pulsante è un'entrata 
  }
void loop() {
 
  val = digitalRead(bottone);  //Lettura del bottone  

  if (val == 1){  //Se il valore del bottone è 1                        
    digitalWrite(ledPin, HIGH);  //Accendi il led    
  }  
  else {  //Altrimenti:                                        
    digitalWrite(ledPin, LOW);  //Spegni il led   
  }  
}  
