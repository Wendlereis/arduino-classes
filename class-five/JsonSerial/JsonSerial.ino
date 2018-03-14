#include <ArduinoJson.h>

const int _LED = 3;
const int _LUZ = A1;
const int _TAMANHO = 200;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(10);
  pinMode(_LED, OUTPUT);
}

void loop() {
  if(Serial.available() > 0) {
    char texto[_TAMANHO];
    Serial.readBytesUntil('\n', texto, _TAMANHO);
    StaticJsonBuffer<_TAMANHO> jsonBuffer;
    JsonObject& json = jsonBuffer.parseObject(texto);

    if(json.success() && json.containsKey("led")) {
      analogWrite(_LED, json["led"]);
    }
  }

  StaticJsonBuffer<_TAMANHO> jsonBuffer;
  JsonObject& json = jsonBuffer.createObject();
  json["luz"] = analogRead(_LUZ);
  json.printTo(Serial);
  Serial.println();

  delay(300);
}
