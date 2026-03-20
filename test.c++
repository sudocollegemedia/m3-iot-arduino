int A, B, C, D;

int led1 = 0;   // D3 = GPIO0
int led2 = 14;  // D5 = GPIO14
int led3 = 12;  // D6 = GPIO12

void setup() {
  Serial.begin(9600);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  randomSeed(analogRead(A0));
}

void loop() {
  A = random(999);
  B = random(999);
  C = random(999);
  D = random(999);

  Serial.print("A = "); Serial.print(A);
  Serial.print(" | B = "); Serial.print(B);
  Serial.print(" | C = "); Serial.print(C);
  Serial.print(" | D = "); Serial.println(D);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);

  if (A > B || A < C) {
    digitalWrite(led1, HIGH);
  }

  if (C > A && A < B) {
    digitalWrite(led2, HIGH);
  }

  if (B > C && B > A && C < A) {
    digitalWrite(led3, HIGH);
  }

  if (D > A && D > B && D > C) {
    for (int i = 0; i < 10; i++) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      delay(100);

      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      delay(100);
    }
  }

  delay(10000);
}