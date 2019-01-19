#include "DHT.h"
#include <Wire.h>
#define DHTPIN A0     // what pin we're connected to
#include <U8g2lib.h>
#define DHTTYPE DHT11   // DHT 11 
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);


DHT dht(DHTPIN, DHTTYPE);
float t, h;

void setup()
{
  Serial.begin(9600);
  dht.begin();
  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB12_tr);
}
void getReading() {
  h = dht.readHumidity();
  t = dht.readTemperature();
  if (isnan(t) || isnan(h))
  {
    Serial.println("Failed to read from DHT");
  }
  else
  {
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.println(" *C");
    displayReadings(t, h);

  }
}
void displayReadings(float tv, float hv) {
  u8g2.clearBuffer();
  u8g2.drawStr(0, 20, "Temp: ");
  u8g2.setCursor(54, 20);
  u8g2.print(tv, 2);
  u8g2.drawStr(0, 40, "Hum: ");
  u8g2.setCursor(54, 40);
  u8g2.print(hv, 2);
  u8g2.sendBuffer();
}
void loop()
{
  getReading();
  delay(2000);

}
