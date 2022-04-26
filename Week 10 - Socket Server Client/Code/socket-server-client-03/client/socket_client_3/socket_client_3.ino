#include <Arduino.h>
#include <ESP8266WiFi.h>

#define LED D1

const char *ssid = "Ginaya House"; // nama SSID untuk koneksi Anda
const char *password = "jadensam18"; // password akses point WIFI Anda
const uint16_t port = 9000; // diganti dengan port serve Anda
const char *host = "168.138.11.244";//diganti dengan host server Anda, bisa ip ataupun domain

WiFiClient client;

void connect_wifi()
{
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");
  delay(250);
}

void connect_server()
{
  while (!client.connect(host, port))
  {
    Serial.printf("\n[Connecting to %s ... ", host);
    delay(1000);
    return;
  }
  Serial.println("connected]");
  delay(1000);
}

void setup()
{
  Serial.begin(115200);
  Serial.println("Contoh penggunaan socket client dengan LED");

  pinMode(LED, OUTPUT);
  
  connect_wifi();
  connect_server();
}

void loop()
{
  if (client.connected())
  {
    Serial.println("[Sending a request]");

    const char date[] = __TIME__;
    client.print(date);

    Serial.println("[Response:]");
    String line = client.readStringUntil('\n');

    if(line.equalsIgnoreCase("evening") || line.equalsIgnoreCase("night")){
      digitalWrite(LED, HIGH);
      Serial.print("Good " + line + ", lights are on");
    }else{
      digitalWrite(LED, LOW);
      Serial.print("Good " + line + ", lights are off");
    }

  } else {
    connect_server();
  }
  Serial.println("\n");
  delay(1000);
}
