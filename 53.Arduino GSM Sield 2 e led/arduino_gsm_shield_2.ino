
// ITA: Inizializzazione delle librerie
// ENG: Initialize the library instances
GSM gsmAccess;
GSM_SMS sms;

// ITA: Assegno i pin ai led
 
int ledRosso=10;
int ledVerde=12;

void setup() 
{
  // ENG: Setup pins for OUTPUT
  // ITA: Imposto i pin come OUTPUT
  
  pinMode(ledRosso, OUTPUT);
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
String accendi="on";
String spegni="off";
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
    
    if(casting.equals(accendi)) 
    {
       digitalWrite(ledRosso,HIGH);
       i=0;
       pulisciStringa(ricevuto,10);
       
    }
      
    if(casting.equals(spegni)) 
    {
        digitalWrite(ledRosso,LOW);
        i=0;
       pulisciStringa(ricevuto,10);
     }
      
    i=0;
    pulisciStringa(ricevuto,10);
    
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


