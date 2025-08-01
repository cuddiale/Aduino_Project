//Arduino Misuratore di potenzza e corrente elettrica con SCT-013-030

//Per il corretto funzionamento istallare la libreria EmonLib

 
#include "EmonLib.h" 
#include <Wire.h>     // Libreria wire già presente in Arduino ide      
#include <LiquidCrystal_I2C.h> // Libreria display I2C

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 
 
EnergyMonitor emon1;
 
//Inserire la tensione della vostra rete elettrica
int rede = 230.0; // Italia 230V in alcuni paesi 110V 
 
//Pin del sensore SCT su A1
int pin_sct = 1;
 
void setup() 
{
  lcd.begin(16, 2);//Inizializzazione display
  lcd.clear();
  Serial.begin(9600);   //Apro la comunicazione seriale
  //Pin, calibrazione - Corrente Const= Ratio/Res. Burder. 1800/62 = 29. 
  emon1.current(pin_sct, 29);
  //Informazioni iniziali display
  lcd.setCursor(0,0);
  lcd.print("Corr.(A):");
  lcd.setCursor(0,1);
  lcd.print("Pot. (W):");
} 
  
void loop() 
{ 
  //Calcolo della corrente  
  double Irms = emon1.calcIrms(1480);
  //Mostra il valore della Corrente
  Serial.print("Corrente : ");
  Serial.print(Irms); // Irms
  lcd.setCursor(10,0);
  lcd.print(Irms);
   
  //Calcola e mostra i valori della Potenza
  Serial.print(" Potenza : ");
  Serial.println(Irms*rede);//Scrivo sul monitor seriale Corrente*Tensione=Potenza
  lcd.setCursor(10,1);
  lcd.print("      ");
  lcd.setCursor(10,1);
  lcd.print(Irms*rede,1); //Scrivo sul display Corrente*Tensione=Potenza 
   
  delay(1000);
}
