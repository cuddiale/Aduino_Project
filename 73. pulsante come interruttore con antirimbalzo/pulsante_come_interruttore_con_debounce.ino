/* ARDUINO PULSANTE COME INTERRUTTORE CON ANTIRIMBALZO O DEBOUNCE */

// www.ProgettiArduino.com

/* Imposto le variabili Globali) */
int ledPin = 13;
int pulsantePin = 7;
int ledStato = LOW;
int pulsanteStato = LOW;
int attesaDebounce = 50;
unsigned long ultimoTempoDebounce = 0;
int ultimaLettura = LOW;

/* Impostazioni Pin*/
void setup(){ 
  pinMode(ledPin, OUTPUT);
  pinMode(pulsantePin, INPUT);
  digitalWrite(ledPin, ledStato);
}

/* inizio ciclo programma */
void loop(){  
  int lettura = digitalRead(pulsantePin);  // (int lettura = Variabile locale) leggo lo stato del pulsante
  if(lettura != ultimaLettura){            // se lo stato del pin è il contrario dell`ultima lettura
    ultimoTempoDebounce = millis();        // assegno il conteggio in millisecondi
  }

  if((millis() - ultimoTempoDebounce) > attesaDebounce){   // se ilconteggio è superiore a 50 millisecondi
    if(lettura != pulsanteStato and lettura == HIGH){      // se il pin7 non è uguale allo stato del pulsante e il pulsante è premuto
      ledStato = !ledStato;                                // cambio lo stato del pin 13
      digitalWrite(ledPin, ledStato);                      // Imposto al pin13 lo stato di ledStato
    }
    pulsanteStato = lettura;                               // assegno lo stato del pulsante al pin7
  }

  ultimaLettura = lettura;                                 // assegno l`ultima lettura allo stato del pulsante
  delay(10);                                               // Ritardo 10 millis
}
