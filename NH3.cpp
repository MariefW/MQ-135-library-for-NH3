#include "NH3.h"
#define RL 47  //value of resistor RL is 47K
#define m -0.263 //Calculated Slope 
#define b 0.42 //Calculated intercept
#define Ro 20 //Ro value

float VRL; //voltage drop across the MQ sensor
float Rs; //sensor resistance at gas concentration
float ratio; //define variable for ratio
float ppm; //define NH3 value

NH3::NH3(byte pin) {
  this->pin = pin;
  init();
}

void NH3::init() {
  pinMode(pin, INPUT); //define pin as INPUT
}

void NH3::sensorValue() {
  Serial.println(analogRead(pin));
}

void NH3::ppmValue() {
  Rs = ((5.0 * RL) / VRL) - RL; //Use formula to get Rs value
  ratio = Rs / Ro; // find ratio Rs/Ro
  ppm = pow(10, ((log10(ratio) - b) / m)); //use formula to calculate ppm
  Serial.println(ppm); //print ppm value
}

void NH3::vrlValue() {
VRL = analogRead(pin) * (5.0 / 1023.0); //Measure the voltage drop and convert to 0-5V
Serial.println(VRL); //print voltage drop value
}
