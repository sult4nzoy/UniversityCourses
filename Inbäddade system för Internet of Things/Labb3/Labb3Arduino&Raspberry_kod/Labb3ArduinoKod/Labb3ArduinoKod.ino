/*
  Författare: Omar Sultanzoy & Siye Abera
  Kurs: DT171G - Inbäddade system för Internet of Things
  Kursansvarig: Mikael Hasselmalm & Jan-Erik Jonsson
  Laboration 3
*/

void setup() {

  Serial.begin(300);
}

void loop() {

  Serial.write('A');

  delay(500);
}
