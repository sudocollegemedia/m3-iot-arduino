#include <Arduino.h>
#include <ArduinoJson.h>

const int LDR_PIN = A0;
const int LED_D3 = D3;
const int LED_D5 = D5;
const int LED_D6 = D6;

int laagste = 1023;
int hoogste = 0;

bool isWeinigLicht(int waarde) {
    return waarde < 500;
}

void checkLichtNiveau(int waarde) {
    if (waarde >= 500 && waarde < 700) {
        digitalWrite(LED_D5, HIGH);
    } else {
        digitalWrite(LED_D5, LOW);
    }

    if (waarde >= 700) {
        digitalWrite(LED_D6, HIGH);
    } else {
        digitalWrite(LED_D6, LOW);
    }
}

void setup() {
    Serial.begin(115200);

    pinMode(LED_D3, OUTPUT);
    pinMode(LED_D5, OUTPUT);
    pinMode(LED_D6, OUTPUT);

    digitalWrite(LED_D3, LOW);
    digitalWrite(LED_D5, LOW);
    digitalWrite(LED_D6, LOW);
}

void loop() {
    int waarde = analogRead(LDR_PIN);

    // Update min/max
    if (waarde < laagste) laagste = waarde;
    if (waarde > hoogste) hoogste = waarde;

    // Functie 1: weinig licht → D3 aan
    if (isWeinigLicht(waarde)) {
        digitalWrite(LED_D3, HIGH);

        int delayTime = random(100, 501);
        digitalWrite(LED_D3, HIGH);
        delay(delayTime);
        digitalWrite(LED_D3, LOW);
        delay(delayTime);
    } else {
        digitalWrite(LED_D3, LOW);
    }

    checkLichtNiveau(waarde);

    StaticJsonDocument<200> doc;
    doc["huidige"] = waarde;
    doc["laagste"] = laagste;
    doc["hoogste"] = hoogste;

    serializeJson(doc, Serial);
    Serial.println();

    delay(500);
}
