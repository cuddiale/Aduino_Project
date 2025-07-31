/* In questo esempio mostreremo come selezionare 
il led da accendere con due pulsanti Up e Down */

// www.ProgettiArduino.com

// Definizione dei pin
int led1 = 11;
int led2 = 12;
int led3 = 13;

int buttonUp = 2;
int buttonDown = 3;

// Definizione delle variabili
int led = 1;  // led da accendere

void setup () {
  // Impostazione dei pin come uscite
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  // Impostazione dei pin come ingressi
  pinMode (buttonUp, INPUT);
  pinMode (buttonDown, INPUT);
  // Abilitazione delle resistenze di PullUp interne sugli ingressi
  digitalWrite (buttonUp, HIGH);
  digitalWrite (buttonDown, HIGH);
}

void loop () {

  if (digitalRead (buttonUp) == 0){   //se il pulsante è premuto
    led++;       // Incrementa la variabile led
    if (led>3) {   // Se la variabile supera il valore 3
      led=1;       // Riporta la variabile a 1
    }
    delay (500);   // Pausa per antirimbalzo
  }

   if (digitalRead (buttonDown) == 0){   //se il pulsante è premuto
    led--;         // Decrementa la variabile led
    if (led<1) {   // Se la variabile è inferiore al valore 1
      led=3;       // Riporta la variabile a 3
    }
    delay (500);   // Pausa per antirimbalzo
   }

   if (led==1) {
    digitalWrite (led1, HIGH);   // Accendi il led1
    digitalWrite (led2, LOW);    // Spegni il led2
    digitalWrite (led3, LOW);    // Spegni il led3
   }

   if (led==2) {
    digitalWrite (led1, LOW);    // Spegni il led1
    digitalWrite (led2, HIGH);   // Accendi il led2
    digitalWrite (led3, LOW);    // Spegni il led3
   }

   if (led==3) {
    digitalWrite (led1, LOW);    // Spegni il led1
    digitalWrite (led2, LOW);    // Spegni il led2
    digitalWrite (led3, HIGH);   // Accendi il led3
   }
}

