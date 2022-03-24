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
  Serial.print(conv_temp('r', c));
  Serial.print(F("°R "));
  Serial.print(conv_temp('k', c));
  Serial.print(F("K "));
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));

}

float conv_temp(char type, float temp){
  if(type == 'r'){
    return temp * 4 / 5;
  }else if(temp == 'k'){
    return temp + 273.15;
  }
}
