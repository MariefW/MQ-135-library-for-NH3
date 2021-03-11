#include <NH3.h>
#define sensorPin A0
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); 

NH3 nh3(sensorPin);
void setup() {
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);
  nh3.nilai_Ro(55); //Set max Ro value

  for (int times = 5 ;times > 0; times--) {
    lcd.setCursor(0, 0);
    lcd.print("  pre heating");
    lcd.setCursor(3, 1);
    lcd.print(times);
    lcd.print(" seconds");
    Serial.print(times);
    Serial.println(" seconds");
    delay(1000);
  }
  lcd.clear();
}

void loop() {
//  Serial.println("Nilai Sensor : ");
//  nh3.nilai_sensor();
//  Serial.println("Nilai VRL : ");
//  nh3.nilai_vrl();
  Serial.println("Nilai ppm : ");
  nh3.nilai_ppm();
  
  lcd.setCursor(3, 0);
  lcd.print("NH3 amonia");
  lcd.setCursor(4, 1);
  lcd.print(nh3.ppm);
  lcd.print(" PPM");
  lcd.print("  ");

  delay(1000);

}
