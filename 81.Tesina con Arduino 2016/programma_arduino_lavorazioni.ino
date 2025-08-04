#include <Servo.h>
Servo servolav1;  
Servo servolav2;  
Servo servolav3;
Servo servolav4;
const int avviolavoraz = A5;//avviolavorazione ricevuto da arduino braccio
int valavviolavoraz=0;//avviolavoraz ricevuto da arduino braccio

const int microD1 = 2; //micro didietro    //  1
const int microA1 = 3; //micro davanti
const int senslav1 = A0;// sensore




int valmicroD1 = 0;//micro didietro          // 1
int valmicroA1 = 0;//micro davanti
int valsenslav1 = 0;// sensore




int avanti1 = 97;                       //       1
int fermo1 = 88;
int indietro1= 75;



const int microD2 = 4; //micro didietro      2
const int microA2 = 5; //micro davanti
const int senslav2 = A1;// sensore




int valmicroD2 = 0;//micro didietro           2
int valmicroA2= 0;//micro davanti
int valsenslav2 = 0;// sensore





int avanti2 = 98;                         //     2
int fermo2 = 93.5;
int indietro2= 89;



const int microD3 = 7; //micro didietro      3
const int microA3 = 8; //micro davanti
const int senslav3 = A2;// sensore




int valmicroD3 = 0;//micro didietro           3
int valmicroA3= 0;//micro davanti
int valsenslav3 = 0;// sensore





int avanti3 = 93;                         //     3
int fermo3= 85;                           // 90 oppure 83.5
int indietro3= 75;


const int microD4 = 12; //micro didietro      4
const int microA4 = 13; //micro davanti
const int senslav4 = A3;// sensore




int valmicroD4 = 0;//micro didietro           4
int valmicroA4= 0;//micro davanti
int valsenslav4= 0;// sensore





int avanti4 = 100;                         //    4
int fermo4= 92;
int indietro4= 87;

void setup() {
 Serial.begin(9600);
servolav1.attach(6);
servolav2.attach(9);
servolav3.attach(10);
servolav4.attach(11);


 servolav1.write(indietro1);
 servolav2.write(indietro2);
  servolav3.write(indietro3);
  servolav4.write(indietro4);
}

void loop() {
  valavviolavoraz = (analogRead(avviolavoraz)*5/1023);

  valmicroD1 = digitalRead(microD1);
  valmicroA1 = digitalRead(microA1);
  valsenslav1 = (analogRead(senslav1)*5/1023);

  valmicroD2 = digitalRead(microD2);
  valmicroA2 = digitalRead(microA2);
  valsenslav2= (analogRead(senslav2)*5/1023);

    valmicroD3 = digitalRead(microD3);
  valmicroA3= digitalRead(microA3);
  valsenslav3= (analogRead(senslav3)*5/1023);
  
   valmicroD4 = digitalRead(microD4);
  valmicroA4= digitalRead(microA4);
  valsenslav4= (analogRead(senslav4)*5/1023);

  if((valsenslav1 >2) && (valavviolavoraz>2)) //avviolav ricevuto da arduino braccio
  {delay(1000);
    servolav1.write(avanti1);
    };
 if(valmicroA1==HIGH) 
  {servolav1.write(fermo1);
    servolav1.write(indietro1);
   };
  if(valmicroD1==HIGH) 
  {servolav1.write(fermo1);
        delay(200);
  servolav1.write(100);
      delay(100);
      servolav1.write(fermo1);
 };

 if((valsenslav2 >2) && (valavviolavoraz>2)) //avviolav ricevuto da arduino braccio
  {delay(1000);
    servolav2.write(avanti2);
    };
 if(valmicroA2==HIGH) 
  {servolav2.write(fermo2);
    servolav2.write(indietro2);
   };
  if(valmicroD2==HIGH) 
  {servolav2.write(fermo2);
        delay(200);
  servolav2.write(100);
      delay(200);
      servolav2.write(fermo2);
 };

 if((valsenslav3 >2) && (valavviolavoraz>2)) //avviolav ricevuto da arduino braccio
  {delay(1000);
    servolav3.write(avanti3);
    };
 if(valmicroA3==HIGH) 
  {servolav3.write(fermo3);
    servolav3.write(indietro3);
   };
  if(valmicroD3==HIGH) 
  {servolav3.write(fermo3);
        delay(200);
  servolav3.write(95);
      delay(100);
      servolav3.write(fermo3);
 };

 if((valsenslav4 >2) && (valavviolavoraz>2)) //avviolav ricevuto da arduino braccio
  {delay(1000);
    servolav4.write(avanti4);
    };
 if(valmicroA4==HIGH) 
  {servolav4.write(fermo4);
    servolav4.write(indietro4);
   };
  if(valmicroD4==HIGH) 
  {servolav4.write(fermo4);
        delay(200);
  servolav4.write(95);
      delay(200);
      servolav4.write(fermo4);
 };
 }

