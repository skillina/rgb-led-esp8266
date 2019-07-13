// Do not remove the include below
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "credentials.h"

WiFiUDP udp;
char udpbuf[256];

void setup() {
  Serial.begin(9600);
  Serial.println("Hello World");

  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED)
  {
	  delay(500);
	  Serial.print("...");
  }

  Serial.println();

  Serial.print("Connected, IP ");
  Serial.println(WiFi.localIP());

  udp.begin(4000);

}

void loop() {

  int packetSize = udp.parsePacket();
  if(packetSize)
  {
	Serial.printf("Received %d bytes");
	int len = udp.read(udpbuf, 255);
	if(len > 0)
	  udpbuf[len] = '\0';
	Serial.printf("Message: %s", udpbuf);
  }
}
