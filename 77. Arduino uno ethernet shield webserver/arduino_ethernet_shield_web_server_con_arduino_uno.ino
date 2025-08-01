/*
 Created by Salvatore Fancello
 Visit: http://progettiarduino.com for more arduino projects

 Arduino Uno with Ethernet Shield Webserver
 */

#include <SPI.h>
#include <Ethernet.h>
int led1 = 2;          //relay1
int led2 = 3;          //relay2
int led3 = 4;          //relay3
int led4 = 5;          //relay4
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };   // mac address
byte ip[] = { 192, 168, 1, 89 };                      // configurate il vostro IP a vostra scelta("192.168.1.89")
byte gateway[] = { 192, 168, 1, 1 };                   // internet access router
byte subnet[] = { 255, 255, 255, 0 };                  //subnet mask
EthernetServer server(80);                             //server port     
String readString;

void setup() {
 // Apro la comunicazione seriale:
  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  //Imposto i pin come OUTPUT
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  // Inizio la comunicazione Ethernet con il server:
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}


void loop() {
  // Creo una connessione al client
  EthernetClient client = server.available();
  if (client) {
    while (client.connected()) {   
      if (client.available()) {
        char c = client.read();
     
        //Leggo i caratteri da HTTP
        if (readString.length() < 100) {
          //Inserisco i caratteri nella stringa 
          readString += c;
          //Serial.print(c);
         }

         //Se la richiesta HTTP è andata a buon fine
         if (c == '\n') {          
           Serial.println(readString); //scrivi sul monitor seriale per debugging
     
           client.println("HTTP/1.1 200 OK"); //Invio nuova pagina
           client.println("Content-Type: text/html");
           client.println();     
           client.println("<HTML>");
           client.println("<HEAD>");
           client.println("<meta name='apple-mobile-web-app-capable' content='yes' />");
           client.println("<meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />");
           client.println("<link rel='stylesheet' type='text/css' href='http://www.progettiarduino.com/uploads/8/1/0/8/81088074/style3.css' />");
           client.println("<TITLE>Controllo Dispositivi da Remoto</TITLE>");
           client.println("</HEAD>");
           client.println("<BODY>");
           client.println("<H1>Controllo Dispositivi da Remoto</H1>");
           client.println("<hr />");
           client.println("<br />");  
           client.println("<H2>Arduino UNO con Ethernet Shield</H2>");
           client.println("<br />");  
           client.println("<a href=\"/?button1on\"\">Accendi LED 1</a>");          //Modifica a tuo piacimento:"Accendi LED 1"
           client.println("<a href=\"/?button1off\"\">Spegni LED 1</a><br />");    //Modifica a tuo piacimento:"Spegni LED 1" 
           client.println("<br />");  
           client.println("<br />");
           client.println("<a href=\"/?button2on\"\">Accendi LED 2</a>");          //Modifica a tuo piacimento:"Accendi LED 2"
           client.println("<a href=\"/?button2off\"\">Spegni LED 2</a><br />");    //Modifica a tuo piacimento:"Spegni LED 2"
           client.println("<br />");   
           client.println("<br />");
           client.println("<a href=\"/?button3on\"\">Accendi LED 3</a>");          //Modifica a tuo piacimento:"Accendi LED 3"
           client.println("<a href=\"/?button3off\"\">Spegni LED 3</a><br />");    //Modifica a tuo piacimento:"Spegni LED 3"
           client.println("<br />");   
           client.println("<br />");
           client.println("<a href=\"/?button4on\"\">Accendi LED 4</a>");          //Modifica a tuo piacimento:"Accendi LED 4"
           client.println("<a href=\"/?button4off\"\">Spegni LED 4</a><br />");    //Modifica a tuo piacimento:"Spegni LED 4"
           client.println("<br />");   
           client.println("<p>Creato da Salvatore Fancello. Visita http://progettiarduino.com per altri progetti!</p>");  
                                            //Sostieni il blog visita: http://www.progettiarduino.com/sostieni-il-blog.html
           client.println("<br />"); 
           client.println("</BODY>");
           client.println("</HTML>");
     
           delay(1);
           client.stop();
           //Controlli su Arduino: Se è stato premuto il pulsante sul webserver
           if (readString.indexOf("?button1on") >0){
               digitalWrite(led1, HIGH);
           }
           if (readString.indexOf("?button1off") >0){
               digitalWrite(led1, LOW);
           }
           if (readString.indexOf("?button2on") >0){
               digitalWrite(led2, HIGH);  
           }
           if (readString.indexOf("?button2off") >0){
               digitalWrite(led2, LOW);
           }
           if (readString.indexOf("?button3on") >0){
               digitalWrite(led3, HIGH);  
           }
           if (readString.indexOf("?button3off") >0){
               digitalWrite(led3, LOW);
           }
           if (readString.indexOf("?button4on") >0){
               digitalWrite(led4, HIGH);  
           }
           if (readString.indexOf("?button4off") >0){
               digitalWrite(led4, LOW);
           }

            //Cancella la stringa una volta letta
            readString="";  
           
         }
       }
    }
}
}
