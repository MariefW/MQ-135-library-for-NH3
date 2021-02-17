#include <NH3.h>
#define sensorPin A0

NH3 nh3(sensorPin);
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Nilai Sensor : ");
  nh3.nilai_sensor();
  Serial.println("Nilai VRL : ");
  nh3.nilai_vrl();
  Serial.println("Nilai ppm : ");
  nh3.nilai_ppm();
  delay(1000);

}
