#include <Arduino.h>
#include <DHT.h>

#define DHTTYPE DHT11

DHT dht(D1, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Menggunakan DHT11");

  dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  float h = dht.readHumidity();
  float c = dht.readTemperature();
  float f = dht.readTemperature(true);
  
  if (isnan(h) || isnan(c) || isnan(f))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(c, h, false);
  
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(c);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F "));
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));

}
