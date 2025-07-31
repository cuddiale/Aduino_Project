//Arduino datalogger con SD Card e DHT-11 per memorizzare 
//i dati di temperatura e umidità su SD Card.
//Per maggiori info: www.progettiarduino.com

// libreria sensore DHT-11
#include <DHT.h>  
// librerie già presenti di default nell`Arduino IDE
#include <SPI.h>
#include <SD.h>

// Variabili globali
int DHTPIN = 2;
const int chipSelect = 4;
unsigned long Secs=0;
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);


void setup() {
  // Aprire la comunicazione seriale
  Serial.begin(9600);
  while (!Serial) {
    ; // Attendere l`apertura della comunicazione seriale
  }

  dht.begin();

  Serial.print("Inizializzazione SD card...");

  // Se la card è presente inizia
  if (!SD.begin(chipSelect)) {
    Serial.println("SD Card non valida o non presente");
    // non eseguire più il codice
    return;
  }
  Serial.println("SD Card inizializzazione.");
}

void loop() {
  // crea una stringa per assemblare i dati di log
  String dataString = "";
  int h = dht.readHumidity();
  // Leggi la temperatura in Celsius (di default)
  int t = dht.readTemperature(false); // true= fahrenheit   false= celsius
  unsigned long Secs=millis();

  // Aprire il file. Da notare che puòessere apertoun solo file alla volta,
  // quindi bisogna chiudere questa prima di aprirne un'altra.
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // Se è presente il file, scrivi su i millisecondi,umidità, temperatura:
  if (dataFile) {
    dataFile.println(String(Secs)+","+String(h)+","+String(t));
    dataFile.close();
    // Scrivi sul monitor seriale i millisecondi,umidità, temperatura:
    Serial.println(String(Secs)+","+String(h)+","+String(t));
    delay(10000);  // Ogni 10 secondi
  }
  // Se il file non è aperto, scrivi sul monitor seriale:
  else {
    Serial.println("Errore apertura datalog.txt");
  }
}





