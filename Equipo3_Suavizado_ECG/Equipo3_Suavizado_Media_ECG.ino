/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 * FICA-CITEL
 * Integrantes: Arellano Milena, Muñoz Pablo, Nupan German
 */

//////////////////////TAMANO DE LAS SENALES//////////////////////////////////////////////////

#define tamano_se 75 //tamano senal 

//import signal to another .h file 
extern double ecg [tamano_se];

double SNR[tamano_se];
double salida_senial[tamano_se];

////////////////////////DEFINIR LA FUNCION///////////////////////////////////////////////////

void moving_average(double *se_in, double *salida_senial, int se_tamano, int filter);
void plot_senial(void);

void setup() {
  Serial.begin(9600);     //Inicializar la comunicacion serial 
}

void loop() {
  moving_average((double *)&ecg[0], (double *)&salida_senial[0], (int)tamano_se,9 ); //ventana de 11 el tiempo de cada una
  SNRecg();
  plot_senial();
  delay(100);
}

//////////////////////////////// SUAVIZADO /////////////////////////////////////////////////

/////////////MEDIA
void moving_average(double *se_in, double *salida_senial, int se_tamano, int filter){
  int i,j;
  for(i=floor(filter/2);i<se_tamano-floor(filter/2)/1;i++){
    salida_senial[i];
    for(j=-floor(filter/2); j<floor(filter/2);j++){
      salida_senial[i]=salida_senial[i]+se_in[i+j];
    }
    salida_senial[i]=salida_senial[i]/filter;
  }
}


//////////////////////////RELACION SENAL A RUIDO ///////////////////////////////////////////

void SNRecg(){
  double snr[tamano_se];
  double snr2[tamano_se];
  for(int i=0;i<tamano_se;i++){
    snr[i]=pow(ecg[i],2);
    snr2[i]=pow((ecg[i]-salida_senial[i]),2);
    SNR[i]=10*log(snr[i]/snr2[i]);
  }
}

/////////////////////////GRAFICAR EL RESULTADO /////////////////////////////////////////////

void plot_senial(void){       //el segundo void no necesita ningun parametro de entrada
  int i;
  for(i=0;i<tamano_se;i++){
    Serial.print(ecg[i]+600);
    Serial.print(",");
    Serial.print(salida_senial[i]+10);
    Serial.print(",");
    Serial.println(SNR[i]-400);
    delay(5);
  }
}
