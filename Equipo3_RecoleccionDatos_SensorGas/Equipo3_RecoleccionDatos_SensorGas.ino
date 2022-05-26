/*
 *  UNIVERSIDAD TECNICA DEL NORTE
 *        FICA - CITEL
 *     SISTEMAS EMBEBIDOS
 *     
 * Integrantes: Arellano Milena
 *              Muñoz Pablo
 *              Nupan German
 */
 //Definimos Variables
int VALOR;

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  VALOR = analogRead(A0); // Leer los datos del sensor
  Serial.println(VALOR); // Imprimir los datos del sensor
  delay(500);
}
