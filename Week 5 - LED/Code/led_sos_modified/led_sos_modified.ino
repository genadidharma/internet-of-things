#include <Arduino.h>

#define GREEN_LED D600000000000000 //led warna hijau

int RED_LED = 2; //led warna merah
int BLUE_LED = 16; //led warna biru


void setup()
{
  Serial.begin(115200);
  pinMode(RED_LED, OUTPUT); //atur pin-pin digital sebagai output
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  Serial.println("Contoh Program LED SOS");
}

void loop()
{
  // 3 dits (3 titik atau huruf S)
  for (int x = 0; x < 3; x++)
  {
    digitalWrite(RED_LED, HIGH); // LED nyala
    delay(150);                  // delay selama 150ms
    digitalWrite(RED_LED, LOW); // LED mati
    delay(100);                  // delay selama 100ms
  }
  delay(100);

  // 3 dahs (3 garis atau huruf O)
  for (int x = 0; x < 3; x++)
  {
    digitalWrite(GREEN_LED, HIGH); // LED nyala
    delay(400);                  // delay selama 400ms
    digitalWrite(GREEN_LED, LOW); // LED mati
    delay(100);                  // delay selama 100ms
  }

  // 100ms delay to cause slight gap between letters
  delay(100);
  // 3 dits again (3 titik atau huruf S)
  for (int x = 0; x < 3; x++)
  {
    digitalWrite(BLUE_LED, HIGH); // LED nyala
    delay(150);                  // delay selama 150ms
    digitalWrite(BLUE_LED, LOW); // LED mati
    delay(100);                  // delay selama 100ms
  }

  // wait 5 seconds before repeating the SOS signal
  delay(5000);
}
