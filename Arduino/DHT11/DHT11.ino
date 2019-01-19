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
  u8g2.setFont(u8g2_font_ncenB08_tr);
}
void getReading() {
  h = dht.readHumidity();
  t = dht.readTemperature();
  if (isnan(t) || isnan(h))
  {
    Serial.println("Failed to read from DHT");
    u8g2.clearBuffer();
  }
  else
  {
    u8g2.clearBuffer();
    String arg1 = "H: "; arg1 += h; arg1 += " %"; arg1 += "T: "; arg1 += t; arg1 += " *C";
    char *x = arg1.c_str();
    u8g2.drawStr(0, 20, x);
    Serial.println(arg1);
    u8g2.sendBuffer();
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.println(" *C");

  }
}
void displayReadings(float tv, float hv) {

}
void loop()
{
  getReading();

  delay(2000);

}
