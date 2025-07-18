/*
  www.diymakers.es
  by A.García
  Crear App para Arduino con App Inventor
  Tutorial en: http://diymakers.es/crear-app-para-arduino-con-app-inventor/
*/
 
#include <SoftwareSerial.h> //Librería que permite establecer comunicación serie en otros pins
 
//Aquí conectamos los pins RXD,TDX del módulo Bluetooth.
SoftwareSerial BT(10,11); //10 RX, 11 TX.
 
int ledred=3; //Pin LED Red
int ledgreen=5;//Pin LED Green
int ledblue=6; //Pin LED Blue





 
void setup()
{
 
  BT.begin(9600);  //Velocidad del puerto del módulo Bluetooth
 
  pinMode(ledred,OUTPUT);
  pinMode(ledgreen,OUTPUT);
  pinMode(ledblue,OUTPUT);
}
 
void loop()
{
    //Cuando haya datos disponibles
    while (BT.available()>0)
    {
        int red = BT.parseInt(); //Leemos el primer valor entero (Red) y lo almacenamos en la variable
 
        int green = BT.parseInt(); //Leemos el segundo valor entero (Green) y lo almacenamos en la variable
 
        int blue = BT.parseInt(); //Leemos el último valor entero (Blue) y lo almacenamos en la variable
 
        //Cuando lea el carácter fin de línea ('\n') quiere decir que ha finalizado el envío de los tres valores
        if (BT.read() == '\n')
        {
          //Enviamos los valores de los tres colores al LED RGB através de PWM
          analogWrite(ledred,red);
          analogWrite(ledgreen,green);
          analogWrite(ledblue,blue);
        }
  }
}
