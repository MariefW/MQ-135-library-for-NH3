#include "NH3.h"
#define RL 10  //The value of resistor RL is 10K
#define m -0.417 //Calculated Slope 
#define b 0.858 //Calculated intercept

float VRL; //Voltage drop across the MQ sensor
float Rs; //Sensor resistance at gas concentration
float ratio; //Define variable for ratio Rs/Ro
//float ppm; //Ammonia value
float MaxRo = 0; //Sensor Resistance at air concentration

NH3::NH3(byte pin) {
  this->pin = pin;
  init();
}

void NH3::init() {
  pinMode(pin, INPUT);
}
void NH3::nilai_Ro(float Ro){
	this->Ro = Ro;
}
void NH3::nilai_ppm() {
  VRL = analogRead(pin) * (5.0 / 1023.0); //Measure the voltage drop and convert to 0-5V
  Rs = ((5.0 * RL) / VRL) - RL; //Formula to get Rs value
  ratio = Rs / Ro; // find ratio Rs/Ro
  ppm = pow(10, ((log10(ratio) - b) / m)); //use formula to calculate ppm
  Serial.println(ppm);
}
void NH3::nilai_vrl() {
	Serial.println(VRL);
}
void NH3::nilai_sensor() {
  Serial.println(analogRead(pin));
}
