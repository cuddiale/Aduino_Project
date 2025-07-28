/*  ARDUINO MENU selezionabile con 4 OPZIONI e Display LCD I2C
 *   
 *  (Temperatura, Led Verde, Led Rosso, Relè)
 *  
 *  Per maggiori info visitate www.progettiarduino.com
 *  
 *  Autore Fancello Salvatore
 */


#define butUp     12     //pulsante SU al pin 12
#define butDown   11     //Pulsante GIU al pin 11
#define butP    10       //Pulsante SELEZIONA al pin 10
#define butM       9     //non utilizzato in questo esempio
#define LampRed   13     //LED Rosso al pin 13
#define LampRed2    1    //LED Verde al pin 1
#define LampRele     8   //Relè al pin 8
#define PhotoSensor A0   // sensore temperatura al pin analogico A0

//Funzioni dei vari cicli 
void changeMenu();
void dispMenu();
void mostraMsg();
void controlLed();
void controlLed2();
void controlRele();
void temperatura();


//Variabili globali
char menu = 0x01;
char set1 = 0x00, set2 = 0x00 , set3 = 0x00;
boolean t_butUp, t_butDown, t_butP, t_butM;
int sensorValue = 0;
int reading = 0;
int sensorPin = A0;

//DISPLAY Mappa Hardware

#include <LiquidCrystal.h>

LiquidCrystal lcd ( 2,   //RS
                    3,  //EN
                    4,  //D4
                    5,  //D5
                    6,  //D6
                    7); //D7 

void setup() {
  
  lcd.begin(16, 2);
  for (char i=9; i<13; i++){        //Ingresso dei pulsanti
    
      pinMode(i, INPUT_PULLUP);
    
  }
  
  pinMode(LampRed, OUTPUT);         //LED ROSSO
  pinMode(LampRed2, OUTPUT);        //LED VERDE
  pinMode(LampRele, OUTPUT);        //RELÈ
              
  digitalWrite (LampRele, HIGH);    //Imposto inizialmente il relè allo stato Alto (Attivo)
  
  t_butUp   = 0x00;             //Inizializza le variabili come ZERO
  t_butDown = 0x00;
  t_butP  = 0x00;
  t_butM  = 0x00;
  

}

void loop() {
  
  
  changeMenu();               //Menu di scambio
  
  dispMenu();               //Selezionare il menu
  

}


//Funzioni

void changeMenu(){
  
  if(digitalRead(butUp) == 0x00){       //Setta la variabile in 1 se si preme il pulsante UP
    
    t_butUp = 0x01;
    
  }
  
   if(digitalRead(butDown) == 0x00){      //Setta la variabile in 1 se si preme il pulsante DOWN
    
    t_butDown = 0x01;
    
  }
  
  if(digitalRead(butUp) && t_butUp){
    
    t_butUp = 0x00;
    
    lcd.clear();        //Cancella Schermo lcd
    
    menu++;
     
    if(menu > 0x04){
      
      menu = 0x01;
    }
  }
  
  if(digitalRead(butDown) && t_butDown){
    
    t_butDown = 0x00;
    
    lcd.clear();
    
    menu--;
     
    if(menu < 0x01){
      
      menu = 0x04;
    }
  }    
  
}



void dispMenu(){
  
  switch(menu){
    
    case 0x01:
        controlLed();              //Funzione controllo  led1
      break;
    case 0x02:
      controlRele();               //Funzione controllo  relè
      break;
    case 0x03:
      temperatura();               //Funzione controllo  temperatura
      break;
    case 0x04:
        controlLed2();             //Funzione controllo  led2
      break;
  }
}


                         /*Ciclo per la funzione controllo LED1*/
void controlLed(){
 
  lcd.setCursor(0,0);
  lcd.print("ACCENSIONE LED 1");
  
  if(digitalRead(butP) == 0x00){
   
    t_butP = 0x01;
    
  }
  
  if(digitalRead(butM) == 0x00){
   
    t_butM = 0x01;
    
  }
  
  if(digitalRead(butP) && t_butP){
    
    t_butP = 0x00;
    set1++;

    
    if(set1 > 2){
      
      set1 = 0x01;
    }
    
    switch(set1){
      
      case 0x01:
        lcd.clear();
        lcd.setCursor(0,1);
        digitalWrite (LampRed, HIGH);  //Accendo il Led Rosso
        lcd.print("LED ROSSO ON");
        break;
      case 0x02:
        lcd.clear();
        lcd.setCursor(0,1);
        digitalWrite (LampRed, LOW);  //Spengo il Led Rosso
        lcd.print("LED ROSSO OFF");
      break;
    }
  }
}


                         /*Ciclo per la funzione controllo Relè*/
void controlRele(){
  
    
  lcd.setCursor(0,0);
  lcd.print("RELE");
  
  if(digitalRead(butP) == 0x00){
   
    t_butP = 0x01;
    
  }
  
  if(digitalRead(butM) == 0x00){
   
    t_butM = 0x01;
    
  }
  
  if(digitalRead(butP) && t_butP){
    
    t_butP = 0x00;
    set2++;

    
    if(set2 > 2){
      
      set2 = 0x01;
    }
    
    switch(set2){
      
      case 0x01:
        lcd.clear();
        lcd.setCursor(0,1);
        digitalWrite (LampRele, LOW);
        lcd.print("RELE ON");
        break;
      case 0x02:
        lcd.clear();
        lcd.setCursor(0,1);
        digitalWrite (LampRele, HIGH);
        lcd.print("RELE OFF");
      break;
    }
  }
}

                         /*Ciclo per la funzione controllo TEMPERATURA*/
void temperatura(){
  reading = analogRead(sensorPin);
  int celsius = reading/2;
  lcd.setCursor(0, 0);
  lcd.print("Temperatura: "); 
  lcd.setCursor(0,1);
  lcd.print(celsius, DEC);
  lcd.print((char)223);
  lcd.print("C");
  
}


                         /*Ciclo per la funzione controllo Led Verde*/
void controlLed2(){
 
  
  lcd.setCursor(0,0);
  lcd.print("ACCENSIONE LED 2");
  
  if(digitalRead(butP) == 0x00){
   
    t_butP = 0x01;
    
  }
  
  if(digitalRead(butM) == 0x00){
   
    t_butM = 0x01;
    
  }
  
  if(digitalRead(butP) && t_butP){
    
    t_butP = 0x00;
    set3++;

    
    if(set3 > 2){
      
      set3 = 0x01;
    }
    
    switch(set3){
      
      case 0x01:
        lcd.clear();
        lcd.setCursor(0,1);
        digitalWrite (LampRed2, HIGH);
        lcd.print("LED VERDE ON");
        break;
      case 0x02:
        lcd.clear();
        lcd.setCursor(0,1);
        digitalWrite (LampRed2, LOW);
        lcd.print("LED VERDE OFF");
      break;
    }
  }
}
  
  
  
