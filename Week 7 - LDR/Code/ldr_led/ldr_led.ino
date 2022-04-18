#include <Arduino.h>

#define LDR A0

#define RED_LED D2 //led warna merah
#define GREEN_LED D3 //led warna hijau
#define BLUE_LED D4 //led warnah biru

int nilai_sensor;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(115200);
  Serial.println("Contoh Penggunaan Sensor LDR & LED");

  pinMode(RED_LED,OUTPUT);
  pinMode(GREEN_LED,OUTPUT);
  pinMode(BLUE_LED,OUTPUT);
  
  delay(3000);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  nilai_sensor = analogRead(LDR);
  Serial.print("Nilai Sensor : ");
  Serial.println(nilai_sensor);

  if(nilai_sensor >= 512){
    Serial.println("Nyalakan Lampu");
    delay(500);
    
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BLUE_LED, LOW);
    Serial.println("Lampu Menyala");
  }else{
    Serial.println("Matikan Lampu");
    delay(500);
    
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
    Serial.println("Lampu Menyala");
  }

  Serial.println("\n");
  delay(3000);

}
