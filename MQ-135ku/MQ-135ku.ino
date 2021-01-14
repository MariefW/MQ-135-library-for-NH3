#include <NH3.h>
#define sensorPin A0

NH3 nh3(sensorPin);
void setup() {
  Serial.begin(9600);
}

void loop() {
  nh3.sensorValue();
  nh3.nilai_vrl();
  nh3.nilai_ppm();
  delay(1000);

}
