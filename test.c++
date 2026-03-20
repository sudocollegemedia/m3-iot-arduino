int A, B, C, D;

void setup() {
  Serial.begin(9600);

  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  randomSeed(analogRead(0)); // voor willekeurigheid
}

void loop() {
  // Maak 4 random getallen
  A = random(999);
  B = random(999);
  C = random(999);
  D = random(999);

  // Print waarden
  Serial.print("A: "); Serial.print(A);
  Serial.print(" B: "); Serial.print(B);
  Serial.print(" C: "); Serial.print(C);
  Serial.print(" D: "); Serial.println(D);

  // D3: A > B OF A < C
  if (A > B || A < C) {
    digitalWrite(3, HIGH);
  } else {
    digitalWrite(3, LOW);
  }

  // D5: C > A EN A < B
  if (C > A && A < B) {
    digitalWrite(5, HIGH);
  } else {
    digitalWrite(5, LOW);
  }

  // D6: B > C EN B > A EN C < A
  if (B > C && B > A && C < A) {
    digitalWrite(6, HIGH);
  } else {
    digitalWrite(6, LOW);
  }

  // Als D het grootste getal is → alle lampen knipperen
  if (D > A && D > B && D > C) {
    for (int i = 0; i < 10; i++) { // snel knipperen
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      delay(100);

      digitalWrite(3, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      delay(100);
    }
  }

  delay(10000); // wacht 10 seconden
}