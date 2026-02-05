/*
  Författare: Omar Sultanzoy & Siye Abera
  Kurs: Inbäddade System IOT
  Kursansvarig: Mikael Hasselmalm & Jan-Erik Jonsson
  Senast ändrat: 2026-02-05
*/

const int buttonPin = 7;  //pin 7
const int R = 6;          //pin 6
const int B = 5;          //pin 5
const int G = 3;          //pin 3
const int MAX = 255;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  //9600baud
  pinMode(buttonPin, INPUT);
  pinMode(R, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(G, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) {
    for (int i = 0; i <= MAX; i++) {
      analogWrite(G, i);
      delay(15);
    }
    delay(250);
    analogWrite(G, 0);


    for (int i = 0; i <= MAX; i++) {
      analogWrite(B, i);
      delay(15);
    }
    delay(250);
    analogWrite(B, 0);

    for (int i = 0; i <= MAX; i++) {
      analogWrite(R, i);
      delay(15);
    }
    delay(250);
    analogWrite(R, 0);
  }
}
