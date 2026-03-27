const int ldrPin = A0;
// Voor Arduino Uno gebruik pin 3,4,5 (in plaats van NodeMCU D1,D2,D3)
const int ledPins[] = {3, 4, 5};
const int ledCount = sizeof(ledPins) / sizeof(ledPins[0]);

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
 
}

void loop() {
  int ldr_value = analogRead(ldrPin);
  Serial.print("LDR waarde: ");
  Serial.println(ldr_value);

  if (ldr_value < 500) {
    int delayMillis = random(100, 501); // 100..500 ms
    for (int i = 0; i < ledCount; i++) {
      digitalWrite(ledPins[i], HIGH);
    }
    delay(delayMillis);
    for (int i = 0; i < ledCount; i++) {
      digitalWrite(ledPins[i], LOW);
    }
    delay(delayMillis);
  } else {
    for (int i = 0; i < ledCount; i++) {
      digitalWrite(ledPins[i], LOW);
    }
    delay(500); // 2x per seconde uitlezen
  }

}
