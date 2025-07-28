/* -----------------------------------------------------------------------------------
 Accende e spegne un RELE a secondo dell'SMS inviato:
 ON  => Accende il RELE
 OFF => Spegne il RELE
 STATO => Stato del pin
 Altro => Messaggio di errore sul Serial Monitor

 Per maggiori info: www.progettiarduino.com
 ---------------------------------------------------------------------------------- */
#include "SIM900.h"
#include <SoftwareSerial.h> // necessaria alla libreria gsm.h richiamata in sms.h
// #include "inetGSM.h"     // necessaria per l'uso di HTTP
#include "sms.h"            // Libreria per la gestione degli SMS

SMSGSM sms;
int rele = 12; // Il Pin 12 è quello connesso al relè
int numdata;
boolean started=false;
char smsbuffer[160];
char Mittente[20];

void setup() 
{
  Serial.begin(9600);
  Serial.println("ESEMPIO INVIO/RICEZIONE SMS");
  pinMode(rele, OUTPUT);   // imposta il pin 12 come pin di OUTPUT.
  digitalWrite(rele, LOW); // spegne inizialmente il led
  // Inizializzo la connessione GSM impostando il baudrate
  // Per l'utilizzo di HTTP è opportuno usare 4800 baud o meno
  if ( gsm.begin(2400) )
  {
     Serial.println("STATUS Modulo GSM = PRONTO");
     started=true;  
  }
  else 
     Serial.println("STATUS Modulo GSM = INATTIVO");
};

// legge una stringa dal Serial Monitor
//   Questa procedura serve solo nella fase di TEST ovvero 
//   quando provo a simulare i comandi SMS tramite il SERIAL MONITOR
boolean SerialRead(char s[])
{
  int i=0;
  if (Serial.available() > 0)
  {            
    while (Serial.available() > 0) 
    {
      s[i]=Serial.read();
      delay(10);
      i++;      
    }
  }
  s[i]='\0'; // Metto il terminatore di stringa
  return (i!=0);
}
// legge una stringa dal Serial Monitor
//    Questa è la versione proposta da Arduino Lab
// int readSerial(char result[])
// {
//    int i = 0;
//    while(1)
//    {
//       while (Serial.available() > 0)
//       {
//          char inChar = Serial.read();
//          if (inChar == '\n') // Line Feed
//          {
//             result[i] = '\0';
//             Serial.flush();
//             return 0;
//           }
//           if(inChar!='\r') // Scarta i Carriage Return
//           {
//              result[i] = inChar;
//              i++;
//            }
//       }
//    }
//  }

void loop() 
{
  char inSerial[50];
  char position;
  if (started)
  {
     // -- Righe commentate poichè utilizzate per nei test
     // strcpy(Mittente,"3380000000");
     // if (SerialRead(smsbuffer))
     // ------------------------------------------------------
    // Legge se ci sono messaggi disponibili sulla SIM Card
    // e li visualizza sul Serial Monitor.
    position = sms.IsSMSPresent(SMS_ALL); // Valore da 1..20
    if (position) 
    {
      // Leggo il messaggio SMS e stabilisco chi sia il mittente
      sms.GetSMS(position, Mittente, smsbuffer, 160);
      Serial.print("Comando Ricevuto [tel. "+String(Mittente)+String("]: ") + String(smsbuffer));
      if (strcmp(smsbuffer,"ON")==0)
      {
         digitalWrite(rele, HIGH);   // Accende il RELE impostando il voltaggio a HIGH
         Serial.println(" => Accendo il RELE");
      }
      else if (strcmp(smsbuffer,"OFF")==0)
      {
         digitalWrite(rele, LOW);    // Spengo il RELE impostando il voltaggio a LOW
         Serial.println(" => Spengo il RELE");
      }
      else if (strcmp(smsbuffer,"STATO")==0)
      {
          if (digitalRead(rele)==HIGH)
          {
             sms.SendSMS(Mittente, "STATUS: RELE Acceso"); // restituisce true se invia l'SMS
             Serial.println(" => il RELE e' Acceso");
          }
          else
          {
             sms.SendSMS(Mittente, "STATUS: RELE Spento"); // restituisce true se invia l'SMS
             Serial.println(" => il RELE e' Spento");
          }
      }
      else
         Serial.println(" => non riconosciuto!");
      sms.DeleteSMS(position); // Elimina l'SMS appena analizzato
    }
    delay(1000);
  }
};

