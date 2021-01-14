#include "NH3.h"
#define RL 47  //value of Load Resistance in datasheet
#define m -0.417 //Calculated Gradient 
#define b 0.425 //Calculated intercept
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
  pinMode(pin, INPUT); 
}

void NH3::sensorValue() {
  Serial.println(analogRead(pin)); //print sensor value
}

void NH3::ppmValue() {
  Rs = (5.0 / VRL - 1)*RL; //formula to get Rs value without load resistance applied
  ratio = Rs / Ro; //formula to get ratio
  ppm = pow(10, ((log10(ratio) - b) / m)); //use formula to calculate ppm
  Serial.println(ppm); //print ppm value
}

void NH3::vrlValue() {
VRL = analogRead(pin) * (5.0 / 1023.0); //Measure the voltage drop and convert to analog
Serial.println(VRL); //print voltage drop value
}
