#ifndef NH3_H
#define NH3_H
#include <Arduino.h>

class NH3 {
  private:
    byte pin;
    float Ro;
  public:
	float ppm;
    NH3(byte pin);
    void init();
    void nilai_sensor();
    void nilai_vrl();
    void nilai_ppm();
    void nilai_Ro(float Ro);
    void lcd_ppm();
};
#endif
