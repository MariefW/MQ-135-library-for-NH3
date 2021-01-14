#ifndef NH3_H
#define NH3_H
#include <Arduino.h>
class NH3 {
  
  private:
    byte pin;
    
  public:
    // Setup pin NH3 and call init()
    NH3(byte pin);
    void init();
    void sensorValue();
    void vrlValue();
    void ppmValue();
};
#endif
