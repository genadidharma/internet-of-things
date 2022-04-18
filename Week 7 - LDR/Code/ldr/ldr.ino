#define sensor_LDR A0
int nilai_sensor;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Contoh Penggunaan Sensor LDR");
  delay(3000);

}

void loop() {
  // put your main code here, to run repeatedly:
  nilai_sensor = analogRead(sensor_LDR);
  Serial.print("Nilai Sensor : ");
  Serial.println(nilai_sensor);
  delay(1000);

}
