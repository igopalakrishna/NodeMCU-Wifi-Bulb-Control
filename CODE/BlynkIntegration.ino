#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_TEMPLATE_ID "TMPL3Bqqh0pyx"
#define BLYNK_TEMPLATE_NAME "ledblynk"
#define BLYNK_AUTH_TOKEN "izjuCCM2QnHiHdM29dGUQU9IWt5edRqd" 
#define BLYNK_PRINT Serial

#define PIN_BUTTON V0
#define TRANSISTOR_PIN D0

char auth[]=BLYNK_AUTH_TOKEN;
char ssid[] = "MVS27";//Enter your WIFI name
char pass[] = "keanu#GOD";//Enter your WIFI password



void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(TRANSISTOR_PIN, OUTPUT);
  digitalWrite(TRANSISTOR_PIN,LOW);
}
void loop() {
  Blynk.run();
}

BLYNK_WRITE(PIN_BUTTON) {
  int buttonState = param.asInt();

  if (buttonState == 255) {
    digitalWrite(TRANSISTOR_PIN, HIGH);
  } else {
    digitalWrite(TRANSISTOR_PIN, LOW);
  }
}