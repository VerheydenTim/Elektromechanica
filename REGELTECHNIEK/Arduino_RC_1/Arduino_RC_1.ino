 //Analoge ingang (A0)
 int sensorvalue;
  float fAnalogValue;

  //wenswaarde regelaar
  float fWensWaarde=120;

//PID instellingen => eventueel te koppelen met potentiometer
  byte P=1;
  byte I=1;
  byte D;
  
  //PID regelaar 
  byte byP;
  byte byI;
  byte byI_old;
  byte byD;
  byte byD_old;
  byte byPID;
  byte e;

  //Tijd
  int iTijdNu;
  int iTijdVorigeCyclus;
  float fTijdVerschil;

   //PWM uitgang (pin 9)
  int iDigitalOutput = 9;

void setup() {
  // put your setup code here, to run once:
  //seriele monitor activeren
  Serial.begin(9600);
   
}

void loop() {
  // put your main code here, to run repeatedly:
  //Inlezen analoge waarde
  sensorvalue=analogRead(A1);
  fAnalogValue=sensorvalue/4;
  //foutberekening
  e =fWensWaarde-fAnalogValue;
  
 //Berekening P
 byP=P*e;
 //Tijdsopname
 iTijdVorigeCyclus=iTijdNu;
 iTijdNu=millis();
 
 fTijdVerschil=1.0;

 
 //Berekening I
 byI=I*e*fTijdVerschil+byI_old;
 byI_old=byI;
 //Berekening D
 byD=D*e/fTijdVerschil+byD_old;
 byD_old=byD;

 byPID=(byP+byI+byD);

 analogWrite(iDigitalOutput,byPID);

 
 

 delay(100);
  Serial.print(fWensWaarde);
 Serial.print("\t");
 Serial.print(fAnalogValue);
 Serial.print("\t");
 Serial.println(fTijdVerschil);
}
