#include <GSM.h>

// ITA: Inizializzazione delle librerie
// ENG: Initialize the library instances
GSM gsmAccess;
GSM_SMS sms;

// ITA: Assegno i pin ai led
int led4=4;
int led5=5;
int led6=6;
int led8=8;
int led9=9;
int led10=10;
int led11=11;
int led12=12;
int ledVerde=13;

void setup() 
{
  // ENG: Setup pins for OUTPUT
  // ITA: Imposto i pin come OUTPUT
  
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(led11, OUTPUT);
  pinMode(led12, OUTPUT);
  pinMode(ledVerde, OUTPUT); 
  
  boolean connessione = true;
  
  // ITA: Attivo la connessione GSM
  // ENG: Start GSM connection
  while(connessione)
  {
    if(gsmAccess.begin()==GSM_READY)
      connessione = false;
  }
  
   // ENG: GSM initialized
  // ITA: Il GSM è pronto per ricevere messaggi
  digitalWrite(ledVerde,HIGH);
}
//ENG: Variable declaration 
//ITA: Dichiarazione variabili 

int i=0;
char vettore[10];
char ricevuto[10];
/*added for relay 1. connect the relay 1 on pin 4 */
String on1="on1"; //send a text message that read: on1
String off1="off1"; //send a text message that read: off1
/*added for relay 2. connect the relay 2 on pin 5*/
String on2="on2"; //send a text message that read: on2
String off2="off2"; //send a text message that read: off2
/*added for relay 3. connect the relay 3 on pin 6*/
String on3="on3"; //send a text message that read: on3
String off3="off3"; //send a text message that read: off3
/*added for relay 4. connect the relay 4 on pin 8 */
String on4="on4"; //send a text message that read: on4
String off4="off4"; //send a text message that read: off4
/*added for relay 5. connect the relay 5 on pin 9*/
String on5="on5"; //send a text message that read: on5
String off5="off5"; //send a text message that read: off5
/*added for relay 6. connect the relay 6 on pin 10*/
String on6="on6"; //send a text message that read: on6
String off6="off6"; //send a text message that read: off6
/*added for relay 7. connect the relay 7 on pin 11*/
String on7="on7"; //send a text message that read: on7
String off7="off7"; //send a text message that read: off7
/*added for relay 8. connect the relay 8 on pin 12*/
String on8="on8"; //send a text message that read: on8
String off8="off8"; //send a text message that read: off8
String casting;

void loop() 
{
  char c;
  //ITA: Controllo se ci sono messaggi
  //ENG: If there are any SMSs available
  if (sms.available())
  {
   //ITA: Lettura sms
   //ENG: Read message
    while(c=sms.read())
    {
      Serial.print(c);
      vettore[i]=c;
      i++;
      
      
    }
    delay(1000);
    
    for(int j=0;j<i;j++)
    ricevuto[j]=vettore[j];
    
    casting=String(ricevuto);
    
    if(casting.equals(on1)) 
    {
       digitalWrite(led4,HIGH);
       i=0;
       pulisciStringa(ricevuto,10);
       
    }
      
    if(casting.equals(off1)) 
    {
        digitalWrite(led4,LOW);
        i=0;
       pulisciStringa(ricevuto,10);
     }
/*added for relay 2*/
    if(casting.equals(on2)) 
    {
       digitalWrite(led5,HIGH);
       i=0;
       pulisciStringa(ricevuto,10);
       
    }
      
    if(casting.equals(off2)) 
    {
        digitalWrite(led5,LOW);
        i=0;
       pulisciStringa(ricevuto,10);
     }
/*added for relay 3*/

    if(casting.equals(on3)) 
    {
       digitalWrite(led6,HIGH);
       i=0;
       pulisciStringa(ricevuto,10);
       
    }
      
    if(casting.equals(off3)) 
    {
        digitalWrite(led6,LOW);
        i=0;
       pulisciStringa(ricevuto,10);
     }
/*added for relay 4*/

    if(casting.equals(on4)) 
    {
       digitalWrite(led8,HIGH);
       i=0;
       pulisciStringa(ricevuto,10);
       
    }
      
    if(casting.equals(off4)) 
    {
        digitalWrite(led8,LOW);
        i=0;
       pulisciStringa(ricevuto,10);
     }
/*added for relay 5*/

    if(casting.equals(on5)) 
    {
       digitalWrite(led9,HIGH);
       i=0;
       pulisciStringa(ricevuto,10);
       
    }
      
    if(casting.equals(off5)) 
    {
        digitalWrite(led9,LOW);
        i=0;
       pulisciStringa(ricevuto,10);
     }
/*added for relay 6*/

    if(casting.equals(on6)) 
    {
       digitalWrite(led10,HIGH);
       i=0;
       pulisciStringa(ricevuto,10);
       
    }
      
    if(casting.equals(off6)) 
    {
        digitalWrite(led10,LOW);
        i=0;
       pulisciStringa(ricevuto,10);
     }
/*added for relay 7*/

    if(casting.equals(on7)) 
    {
       digitalWrite(led11,HIGH);
       i=0;
       pulisciStringa(ricevuto,10);
       
    }
      
    if(casting.equals(off7)) 
    {
        digitalWrite(led11,LOW);
        i=0;
       pulisciStringa(ricevuto,10);
     }

/*added for relay 8*/

    if(casting.equals(on8)) 
    {
       digitalWrite(led12,HIGH);
       i=0;
       pulisciStringa(ricevuto,10);
       
    }
      
    if(casting.equals(off8)) 
    {
        digitalWrite(led12,LOW);
        i=0;
       pulisciStringa(ricevuto,10);
     }
    
    // ITA: Cancello i messaggi dalla memoria
    // ENG: Delete message from modem memory
    sms.flush();
   
  }

  delay(1000);

}

void pulisciStringa(char* tmp,int dim) 
{

int x;
for (x=0; x < dim; x++)
tmp[x] = 0;

tmp[0] = '\0';
}


