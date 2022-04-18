#include <Arduino.h>
#include <DHT.h>

#define LDR A0

#define DHTTYPE DHT11

#define RED_LED D2 //led warna merah
#define GREEN_LED D3 //led warna hijau
#define BLUE_LED D4 //led warnah biru

int intensity;
DHT dht(D1, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(115200);
  Serial.println("Contoh Penggunaan Sensor LDR, DHT, & LED");

  pinMode(RED_LED,OUTPUT);
  pinMode(GREEN_LED,OUTPUT);
  pinMode(BLUE_LED,OUTPUT);

  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(3000);

  float temperature = dht.readTemperature();
  Serial.print("Nilai Suhu : ");
  Serial.println(temperature);

  if(isnan(temperature)){
    Serial.println("Failed to read from DHT sensor!");
    return; 
  }
  
  intensity = analogRead(LDR);
  Serial.print("Nilai Intensitas Cahaya : ");
  Serial.println(intensity);

  if(intensity >= 512 && temperature <= 32){
    Serial.println("Gelap & Temperatur Rendah");
    Serial.println("Kedipkan Lampu");
    delay(500);
    
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
    delay(500);
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BLUE_LED, LOW);
    delay(500);
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, HIGH);
    delay(500);
  }else if(intensity < 512 && temperature > 32){
    Serial.println("Terang & Temperatur Tinggi");
    Serial.println("Nyalakan Lampu Merah");
    delay(500);
    
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
  }else{
    Serial.println("Tidak Sesuai");
    Serial.println("Matikan Lampu");

    delay(500);

    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
  }

  Serial.println("\n");

}
