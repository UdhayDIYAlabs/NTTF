#include "DHT.h"

#define DHTPIN A0     // what pin we're connected to

#define DHTTYPE DHT11   // DHT 11 


DHT dht(DHTPIN, DHTTYPE);
float t, h;

void setup()
{
  Serial.begin(9600);
  dht.begin();

}


void loop()
{

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

  }
  delay(2000);

}
