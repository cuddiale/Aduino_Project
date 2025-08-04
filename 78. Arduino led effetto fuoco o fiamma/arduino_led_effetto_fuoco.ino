// ARDUINO LED EFFETTO FUOCO O FIAMMA
// Per maggiori info e progetti: www.progettiarduino.com

// Indico le variabili globali
int Tempo = 140;
int TmpRandom = 150;
int Giallo_1 = 11;   
int Rosso = 10;
int Giallo_2 = 9;

// Settaggi pin di arduino
void setup()   
{
pinMode(Giallo_1, OUTPUT); //Led giallo1 come uscita
pinMode(Rosso, OUTPUT);    //Led rosso come uscita
pinMode(Giallo_2, OUTPUT); //Led giallo2 come uscita

}

void loop() {

//imposta l'uscita con un livello a caso da 0 a 150 come da variabili impostate  
analogWrite(Giallo_1, random(TmpRandom)+Tempo);   
analogWrite(Rosso, random(TmpRandom)+Tempo);      
analogWrite(Giallo_2, random(TmpRandom)+Tempo);
delay(random(100));    
}
