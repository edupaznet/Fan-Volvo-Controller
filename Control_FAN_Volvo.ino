
//  Seteo de valores max y min de los sensores  
//sensor de ADMISION parametros ******************************************************
const int Ad_bajo= 300;
const int Ad_alto=236 ;   // Equivale a 80°C
const int Ad_advertencia=210 ; // Equivale a 90°C
const int Ad_peligro=140 ;    // Equivale a 100°C
const int Ad_limite=72 ;     // Equivale a 125°C
// sensor de Agua parametros ***********************************************************
const int Ag_bajo=300;
const int Ag_alto = 236; // Equivale a 80°C
const int Ag_advertencia =210; // Equivale a 90°C   Estos Valores se deben ajustar en funcion de los parametros  
const int Ag_peligro =140;  // Equivale a 100°C     de trabajo del motor.
const int Ag_limite =72;  // Equivale a 125°C
// Sensor Hidraulico parametros*********************************************************
const int Hid_bajo=300 ;
const int Hid_alto =236 ; // Equivale a 80°C
const int Hid_advertencia =210 ;// Equivale a 90°C
const int Hid_peligro =140 ;// Equivale a 100°C
const int Hid_limite =72 ;// Equivale a 125°C
//***************************************************************************************
int Salpwm = 10; 
int LecturaAire=0 , LecturaAgua=0 , LecturaHid=0;
int SensorAire = A2;
int SensorAgua= A1;
int SensorHid=A3;
;
void setup()
{
  pinMode(Salpwm, OUTPUT);// sets the pin as output
  Serial.begin(9600);
}

      
void loop() {

  LecturaAire= analogRead(SensorAire);  // Lectura Sensor de Temp Admicion 
  delay(10);
  LecturaAgua= analogRead(SensorAgua); // Lectura Sensor de Temp Agua
  delay(10);
  LecturaHid= analogRead(SensorHid);   // Lectura Sensor Temp Hidraulico
  delay(10);
  // triple comparacion del estado de los sensores y accionamiento de La Salida de control del Ventilador Hidraulico
  if (LecturaAire >= Ad_bajo && LecturaAgua >= Ag_bajo && LecturaHid >= Hid_bajo ){analogWrite(Salpwm,0);}
  if(LecturaAire <=Ad_alto && LecturaAire > Ad_advertencia || LecturaAgua <=Ag_alto && LecturaAgua > Ag_advertencia || LecturaHid <=Hid_alto && LecturaHid > Hid_advertencia) {analogWrite(Salpwm,64);}
   if(LecturaAire <=Ad_advertencia && LecturaAire > Ad_peligro ||  LecturaAgua <=Ag_advertencia && LecturaAgua > Ag_peligro ||  LecturaHid <= Hid_advertencia && LecturaHid > Hid_peligro){analogWrite(Salpwm,128);}
    if(LecturaAire <=Ad_peligro && LecturaAire > Ad_limite || LecturaAgua <=Ag_peligro && LecturaAgua > Ag_limite ||  LecturaHid <=Hid_peligro && LecturaHid > Hid_limite){analogWrite(Salpwm,244);}
    if(LecturaAire < Ad_limite || LecturaAgua < Ag_limite ||  LecturaHid < Hid_limite){analogWrite(Salpwm,244);}
 //  Serial.print("Valor Aire= ");Serial.print(LecturaAire); Serial.print("   Valor Agua= ");Serial.print(LecturaAgua);Serial.print("    Valor Hidraulico= ");Serial.print(LecturaHid);
//  Serial.print("  ----Valor PWM = ");Serial.println(Salpwm);
   delay(300);
}
