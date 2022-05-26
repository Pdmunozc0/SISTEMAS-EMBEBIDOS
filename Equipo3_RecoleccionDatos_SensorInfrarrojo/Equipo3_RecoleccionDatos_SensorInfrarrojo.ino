/*
 * UNIVERSIDAD TÉNICA DEL NORTE
 * Integrantes: Arellano Milena, Muñoz Pablo, Nupan German
 * SENSOR INFRARROJO
 */


#include <infrarrojo.h>

int analogPin = A0;                    //VARIBLE QUE RECIBE EL DATO
int VALOR;


//CONFIGURACION DE SETUP
void setup (){
Serial.begin(9600);         //VELOCIDAD COMUNICACION SERIAL
}

//CODIGO PRINCIPAL
void loop(){
VALOR = analogRead(analogPin);                            //ALMACENA
//Serial.print ("\n leyendo estado sensor: \n");    //IMPRIME MENSAJE
Serial.print ("\n " );
Serial.print (VALOR);           //IMPRIME EL ESTADO DEL 
delay(500);                                       //PAUSA DE MEDIO SEGUNDO
}
