/*
DEL 2
Författare: Omar Sultanzoy & Siye Abera
Kursansvarig: Mikael Hasselmalm & Jan-Erik Jonsson
Senast ändrat: 2026-02-02
*/

const int bitOne = 11;
const int bitTwo = 10;
const int bitFour = 9;
const int bitEight = 8;
const int buttonPin = 7;

int count = 0;
int r = 1; // Riktning: 1 för upp, -1 för ner

void setup() {
  Serial.begin(9600);
  pinMode(bitOne, OUTPUT);
  pinMode(bitTwo, OUTPUT);
  pinMode(bitFour, OUTPUT);
  pinMode(bitEight, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Kolla om knappen trycks för att byta riktning
  if (digitalRead(buttonPin) == HIGH) {
    Serial.println("Knappen trycktes nu");
    if (r == 1) {
      r = -1;
    } else {
      r = 1;
    }
    delay(300); // Hindrar att den växlar 100 ggr på ett tryck
  }

  count = count + r;

  if (count > 15) {
    count = 0;
  }
  if (count < 0) {
    count = 15;
  }
  
  Serial.println(count);

  int temp = count;

  // Bit 4 (8)
  if (temp >= 8) {
    digitalWrite(bitEight, HIGH);
    temp -= 8;
  } else {
    digitalWrite(bitEight, LOW);
  }

  // Bit 3 (4)
  if (temp >= 4) {
    digitalWrite(bitFour, HIGH);
    temp -= 4;
  } else {
    digitalWrite(bitFour, LOW);
  }

  // Bit 2 (2)
  if (temp >= 2) {
    digitalWrite(bitTwo, HIGH);
    temp -= 2;
  } else {
    digitalWrite(bitTwo, LOW);
  }

  // Bit 1 (1)
  if (temp >= 1) {
    digitalWrite(bitOne, HIGH);
  } else {
    digitalWrite(bitOne, LOW);
  }

  delay(1000);
}